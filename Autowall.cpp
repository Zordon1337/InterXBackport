#include "AutoWall.h"

#define    HITGROUP_GENERIC    0
#define    HITGROUP_HEAD        1
#define    HITGROUP_CHEST        2
#define    HITGROUP_STOMACH    3
#define HITGROUP_LEFTARM    4    
#define HITGROUP_RIGHTARM    5
#define HITGROUP_LEFTLEG    6
#define HITGROUP_RIGHTLEG    7
#define HITGROUP_GEAR        10

float GetHitgroupDamageMult(int iHitGroup)
{
	switch (iHitGroup)
	{
	case HITGROUP_GENERIC:
		return 1.0f;
	case HITGROUP_HEAD:
		return 4.0f;
	case HITGROUP_CHEST:
		return 1.0f;
	case HITGROUP_STOMACH:
		return 1.5f;
	case HITGROUP_LEFTARM:
		return 1.0f;
	case HITGROUP_RIGHTARM:
		return 1.0f;
	case HITGROUP_LEFTLEG:
		return 0.75f;
	case HITGROUP_RIGHTLEG:
		return 0.75f;
	case HITGROUP_GEAR:
		return 1.0f;
	default:
		break;
	}

	return 1.0f;
}

void ScaleDamage(int hitgroup, IClientEntity *enemy, float weapon_armor_ratio, float &current_damage)
{
	current_damage *= GetHitgroupDamageMult(hitgroup);

	int armor = enemy->ArmorValue();
	int helmet = enemy->HasHelmet();

	if (armor > 0)
	{
		if (hitgroup == HITGROUP_HEAD)
		{
			if (helmet)
				current_damage *= (weapon_armor_ratio * 1.5f);
		}
		else
		{
			current_damage *= (weapon_armor_ratio * 0.5f);
		}
	}
}

inline bool CGameTrace::DidHitWorld() const
{
	return m_pEnt->GetIndex() == 0;
}

inline bool CGameTrace::DidHitNonWorldEntity() const
{
	return m_pEnt != NULL && !DidHitWorld();
}

bool TraceToExit(Vector &end, trace_t *enter_trace, Vector start, Vector dir, trace_t *exit_trace)
{
	float distance = 0.0f;

	while (distance <= 90.0f)
	{
		distance += 4.0f;
		end = start + dir * distance;

		auto point_contents = Interfaces::Trace->GetPointContents(end, MASK_SHOT_HULL | CONTENTS_HITBOX, NULL);

		if (point_contents & MASK_SHOT_HULL && (!(point_contents & CONTENTS_HITBOX)))
			continue;

		auto new_end = end - (dir * 4.0f);

		Ray_t ray;
		ray.Init(end, new_end);
		Interfaces::Trace->TraceRay(ray, MASK_SHOT, 0, exit_trace);

		if (exit_trace->startsolid && exit_trace->surface.flags & SURF_HITBOX)
		{
			ray.Init(end, start);
			CTraceFilter filter;
			filter.pSkip = exit_trace->m_pEnt;
			Interfaces::Trace->TraceRay(ray, 0x600400B, &filter, exit_trace);

			if ((exit_trace->fraction < 1.0f || exit_trace->allsolid) && !exit_trace->startsolid)
			{
				end = exit_trace->endpos;
				return true;
			}
			continue;
		}

		if (!(exit_trace->fraction < 1.0 || exit_trace->allsolid || exit_trace->startsolid) || exit_trace->startsolid)
		{
			if (exit_trace->m_pEnt)
			{
				if (enter_trace->DidHitNonWorldEntity())
					return true;
			}
			continue;
		}

		if (((exit_trace->surface.flags >> 7) & 1) && !((enter_trace->surface.flags >> 7) & 1))
			continue;

		if (exit_trace->plane.normal.Dot(dir) <= 1.0f)
		{
			auto fraction = exit_trace->fraction * 4.0f;
			end = end - (dir * fraction);
			return true;
		}
	}
	return false;
}

bool HandleBulletPenetration(CSWeaponInfo *wpn_data, FireBulletData &data)
{
	surfacedata_t *enter_surface_data = Interfaces::PhysProps->GetSurfaceData(data.enter_trace.surface.surfaceProps);
	int enter_material = enter_surface_data->game.material;
	float enter_surf_penetration_mod = *(float*)((DWORD)enter_surface_data + 76);

	data.trace_length += data.enter_trace.fraction * data.trace_length_remaining;
	data.current_damage *= pow((wpn_data->m_flRangeModifier), (data.trace_length * 0.002));

	if ((data.trace_length > 3000.f) || (enter_surf_penetration_mod < 0.1f))
		data.penetrate_count = 0;

	if (data.penetrate_count <= 0)
		return false;

	Vector dummy;
	trace_t trace_exit;
	if (!TraceToExit(dummy, &data.enter_trace, data.enter_trace.endpos, data.direction, &trace_exit))
		return false;


	surfacedata_t *exit_surface_data = Interfaces::PhysProps->GetSurfaceData(trace_exit.surface.surfaceProps);
	int exit_material = exit_surface_data->game.material;

	float exit_surf_penetration_mod = *(float*)((DWORD)exit_surface_data + 76);
	float final_damage_modifier = 0.16f;
	float combined_penetration_modifier = 0.0f;

	if (((data.enter_trace.contents & CONTENTS_GRATE) != 0) || (enter_material == 89) || (enter_material == 71))
	{
		combined_penetration_modifier = 3.0f;
		final_damage_modifier = 0.05f;
	}
	else
	{
		combined_penetration_modifier = (enter_surf_penetration_mod + exit_surf_penetration_mod) * 0.5f;
	}

	if (enter_material == exit_material)
	{
		if (exit_material == 87 || exit_material == 85)
			combined_penetration_modifier = 3.0f;
		else if (exit_material == 76)
			combined_penetration_modifier = 2.0f;
	}

	float v34 = fmaxf(0.f, 1.0f / combined_penetration_modifier);
	float v35 = (data.current_damage * final_damage_modifier) + v34 * 3.0f * fmaxf(0.0f, (3.0f / wpn_data->m_flPenetration) * 1.25f);
	float thickness = (trace_exit.endpos - data.enter_trace.endpos).Length();

	thickness *= thickness;
	thickness *= v34;
	thickness /= 24.f;

	float lost_damage = fmaxf(0.0f, v35 + thickness) - 1.6f;

	if (lost_damage > data.current_damage)
		return false;

	if (lost_damage >= 0.0f)
		data.current_damage -= lost_damage;

	if (data.current_damage < 1.0f)
		return false;

	data.src = trace_exit.endpos;
	data.penetrate_count--;

	return true;
}

bool SimulateFireBullet(IClientEntity *local, CBaseCombatWeapon *weapon, FireBulletData &data)
{
	data.penetrate_count = 4;
	data.trace_length = 0.0f;
	auto wpn_data = weapon->GetCSWpnData(weapon, 431);

	if (&wpn_data == NULL)
		return false;

	data.current_damage = (float)wpn_data.m_iDamage;

	while ((data.penetrate_count > 0) && (data.current_damage >= 1.0f))
	{
		data.trace_length_remaining = wpn_data.m_flRange - data.trace_length;

		Vector end = data.src + data.direction * data.trace_length_remaining;

		UTIL_TraceLine(data.src, end, 0x4600400B, local, 0, &data.enter_trace);
		UTIL_ClipTraceToPlayers(data.src, end + data.direction * 40.f, 0x4600400B, &data.filter, &data.enter_trace);

		if (data.enter_trace.fraction == 1.0f)
			break;

		if ((data.enter_trace.hitgroup <= 7) && (data.enter_trace.hitgroup > 0) && local->GetTeamNum() != data.enter_trace.m_pEnt->GetTeamNum())
		{
			data.trace_length += data.enter_trace.fraction * data.trace_length_remaining;
			data.current_damage *= pow(wpn_data.m_flRangeModifier, data.trace_length * 0.002);
			ScaleDamage(data.enter_trace.hitgroup, data.enter_trace.m_pEnt, wpn_data.m_flArmorRatio, data.current_damage);

			return true;
		}

		if (!HandleBulletPenetration(&wpn_data, data))
			break;
	}

	return false;
}

bool CanHit(const Vector &point, float *damage_given)
{
	float damage = 0.f;
	Vector dst = point;
	auto *local = Interfaces::EntList->GetClientEntity(Interfaces::Engine->GetLocalPlayer());
	auto data = FireBulletData(local->GetOrigin() + local->GetViewOffset());
	data.filter = CTraceFilter();
	data.filter.pSkip = local;

	Vector angles;
	CalcAngle(data.src, point, angles);
	AngleVectors(angles, &data.direction);
	VectorNormalize(data.direction);

	if (SimulateFireBullet(local, (CBaseCombatWeapon*)Interfaces::EntList->GetClientEntityFromHandle((HANDLE)local->GetActiveWeaponHandle()), data))
	{
		*damage_given = data.current_damage;
		return true;
	}

	return damage;
}