#include "UTIL Functions.h"
#include "Utilities.h"

#include "RenderManager.h"
#include <iostream>

void UTIL_TraceLine(const Vector& vecAbsStart, const Vector& vecAbsEnd, unsigned int mask,
	const IClientEntity* ignore, int collisionGroup, trace_t* ptr)
{
	if (!ignore || !ptr)
		return; // or handle error

	Ray_t ray;
	ray.Init(vecAbsStart, vecAbsEnd);

	CTraceFilter simple;
	simple.pSkip = &ignore;


	Interfaces::Trace->TraceRay(ray, mask, (CTraceFilter*)&simple, ptr);

}


void UTIL_ClipTraceToPlayers(const Vector& vecAbsStart, const Vector& vecAbsEnd, unsigned int mask, ITraceFilter* filter, trace_t* tr)
{
	static DWORD dwAddress = Utilities::Memory::FindPatternV2("client.dll", "53 8B DC 83 EC 08 83 E4 F0 83 C4 04 55 8B 6B 04 89 6C 24 04 8B EC 81 EC ?? ?? ?? ?? 8B 43 10");

	if (!dwAddress)
		return;

	_asm
	{
		MOV		EAX, filter
		LEA		ECX, tr
			PUSH	ECX
			PUSH	EAX
			PUSH	mask
			LEA		EDX, vecAbsEnd
			LEA		ECX, vecAbsStart
			CALL	dwAddress
			ADD		ESP, 0xC
	}
}

bool IsBreakableEntity(IClientEntity* ent)
{
	typedef bool(__thiscall* IsBreakbaleEntity_t)(IClientEntity*);
	IsBreakbaleEntity_t IsBreakbaleEntityFn = (IsBreakbaleEntity_t)Utilities::Memory::FindPattern("client.dll", (PBYTE)"\x55\x8B\xEC\x51\x56\x8B\xF1\x85\xF6\x74\x68", "xxxxxxxxxxx");
	if (IsBreakbaleEntityFn)
		return IsBreakbaleEntityFn(ent);
	else
		return false;
}

bool TraceToExit(Vector& end, trace_t& tr, Vector start, Vector vEnd, trace_t* trace)
{
	typedef bool(__fastcall* TraceToExitFn)(Vector&, trace_t&, float, float, float, float, float, float, trace_t*);
	static TraceToExitFn TraceToExit = (TraceToExitFn)Utilities::Memory::FindPattern("client.dll", (BYTE*)"\x55\x8B\xEC\x83\xEC\x2C\xF3\x0F\x10\x75\x00\x33\xC0", "xxxxxxxxxx?xx");

	if (!TraceToExit)
		return false;

	return TraceToExit(end, tr, start.x, start.y, start.z, vEnd.x, vEnd.y, vEnd.z, trace);
}

void GameUtils::NormaliseViewAngle(Vector &angle)
{

	while (angle.y <= -180) angle.y += 360;
	while (angle.y > 180) angle.y -= 360;
	while (angle.x < -89) angle.x = -89;
	while (angle.x > 89) angle.x = 89;


	if (angle.x > 89.0) angle.x = 89;
	if (angle.x < -89.0) angle.x = -89;
	if (angle.y < -180) angle.y = -179.999;
	if (angle.y > 180) angle.y = 179.999;

	angle.z = 0;
}

void GameUtils::ClampViewAngle(Vector &angle)
{
	CHECK_VALID(*angle);
	if (angle.x < -89.0f)
		angle.x = -89.0f;

	if (angle.x >  89.0f)
		angle.x = 89.0f;

	while (angle.y < -180.0f)
		angle.y += 360.0f;

	while (angle.y >  180.0f)
		angle.y -= 360.0f;

	angle.z = 0.0f;
}

void GameUtils::CL_FixMove(CUserCmd* pCmd, Vector viewangles)
{
	/*pCmd->forwardmove = DotProduct(forward * vForwardNorm, aimforward) + DotProduct(right * vRightNorm, aimforward) + DotProduct(up * vUpNorm, aimforward);
	pCmd->sidemove = DotProduct(forward * vForwardNorm, aimright) + DotProduct(right * vRightNorm, aimright) + DotProduct(up * vUpNorm, aimright);
	pCmd->upmove = DotProduct(forward * vForwardNorm, aimup) + DotProduct(right * vRightNorm, aimup) + DotProduct(up * vUpNorm, aimup);*/
}

//char shit[16];
//trace_t Trace;
//char shit2[16];
//IClientEntity* entCopy;

bool GameUtils::IsVisible(IClientEntity* pLocal, IClientEntity* pEntity, int BoneID)
{
	//if (BoneID < 0) return false;

	//entCopy = pEntity;
	//Vector start = pLocal->GetOrigin() + pLocal->GetViewOffset();
	//Vector end = GetHitboxPosition(pEntity, BoneID);//pEntity->GetBonePos(BoneID);
	//char shit3[32];

	////Interfaces::Trace->TraceRay(Ray,MASK_SOLID, NULL/*&filter*/, &Trace);
	//UTIL_TraceLine(start, end, MASK_SOLID, pLocal, 0, &Trace);

	//if (Trace.m_pEnt == entCopy)
	//{
	//	return true;
	//}

	//if (Trace.fraction == 1.0f)
	//{
	//	return true;
	//}

	//return false;
	auto LocalPlayer = Interfaces::EntList->GetClientEntity(Interfaces::Engine->GetLocalPlayer());

	Ray_t Ray;
	trace_t Trace;
	CTraceFilter TraceFilter;

	TraceFilter.pSkip = LocalPlayer;

	Ray.Init(LocalPlayer->GetEyePosition(), GetHitboxPosition(pEntity, BoneID));
	Interfaces::Trace->TraceRay(Ray, MASK_SHOT, &TraceFilter, &Trace);

	if (Trace.m_pEnt == pEntity) {
		if (Trace.fraction > 0.97f)
			return true;
	}

	return false;
}

bool GameUtils::IsKnife(void* weapon)
{
	if (weapon == nullptr) return false;
	IClientEntity* weaponEnt = (IClientEntity*)weapon;
	ClientClass* pWeaponClass = weaponEnt->GetClientClass();

	if (pWeaponClass->m_ClassID == (int)CSGOClassID::CKnife)
	{
		return true;
	}
	else if (pWeaponClass->m_ClassID == (int)CSGOClassID::CKnifeGG)
	{
		return true;
	}
	else if (pWeaponClass->m_ClassID == (int)CSGOClassID::CKnife && (int)CSGOClassID::CKnifeGG)
	{
		return true;
	}
	else
		return false;
}

bool GameUtils::IsBallisticWeapon(void* weapon)
{
	if (weapon == nullptr) return false;
	IClientEntity* weaponEnt = (IClientEntity*)weapon;
	ClientClass* pWeaponClass = weaponEnt->GetClientClass();

	if (pWeaponClass->m_ClassID == (int)CSGOClassID::CHEGrenade || pWeaponClass->m_ClassID == (int)CSGOClassID::CDecoyGrenade || pWeaponClass->m_ClassID == (int)CSGOClassID::CIncendiaryGrenade || pWeaponClass->m_ClassID == (int)CSGOClassID::CSmokeGrenade || pWeaponClass->m_ClassID == (int)CSGOClassID::CC4 || pWeaponClass->m_ClassID == (int)CSGOClassID::CMolotovGrenade)
		return false;
	else
		return true;
}

bool GameUtils::IsPistol(void* weapon)
{
	if (weapon == nullptr) return false;
	IClientEntity* weaponEnt = (IClientEntity*)weapon;
	ClientClass* pWeaponClass = weaponEnt->GetClientClass();

	if (pWeaponClass->m_ClassID == (int)CSGOClassID::CDEagle || pWeaponClass->m_ClassID == (int)CSGOClassID::CWeaponElite || pWeaponClass->m_ClassID == (int)CSGOClassID::CWeaponFiveSeven || pWeaponClass->m_ClassID == (int)CSGOClassID::CWeaponGlock || pWeaponClass->m_ClassID == (int)CSGOClassID::CWeaponHKP2000 || pWeaponClass->m_ClassID == (int)CSGOClassID::CWeaponP250 || pWeaponClass->m_ClassID == (int)CSGOClassID::CWeaponP228 || pWeaponClass->m_ClassID == (int)CSGOClassID::CWeaponTec9 || pWeaponClass->m_ClassID == (int)CSGOClassID::CWeaponUSP)
		return true;
	else
		return false;
}

bool GameUtils::IsMP(void* weapon)
{
	if (weapon == nullptr) return false;
	IClientEntity* weaponEnt = (IClientEntity*)weapon;
	ClientClass* pWeaponClass = weaponEnt->GetClientClass();

	if (pWeaponClass->m_ClassID == (int)CSGOClassID::CWeaponMAC10 || pWeaponClass->m_ClassID == (int)CSGOClassID::CWeaponP90 || pWeaponClass->m_ClassID == (int)CSGOClassID::CWeaponUMP45 || pWeaponClass->m_ClassID == (int)CSGOClassID::CWeaponBizon || pWeaponClass->m_ClassID == (int)CSGOClassID::CWeaponMP7 || pWeaponClass->m_ClassID == (int)CSGOClassID::CWeaponMP9)
		return true;
	else
		return false;
}

bool GameUtils::IsSniper(void* weapon)
{
	if (weapon == nullptr) return false;
	IClientEntity* weaponEnt = (IClientEntity*)weapon;
	ClientClass* pWeaponClass = weaponEnt->GetClientClass();

	if (pWeaponClass->m_ClassID == (int)CSGOClassID::CWeaponAWP || pWeaponClass->m_ClassID == (int)CSGOClassID::CWeaponSSG08 || pWeaponClass->m_ClassID == (int)CSGOClassID::CWeaponSCAR20 || pWeaponClass->m_ClassID == (int)CSGOClassID::CWeaponG3SG1)
		return true;
	else
		return false;
}

bool GameUtils::IsShotgun(void* weapon)
{
	if (weapon == nullptr) return false;
	IClientEntity* weaponEnt = (IClientEntity*)weapon;
	ClientClass* pWeaponClass = weaponEnt->GetClientClass();

	if (pWeaponClass->m_ClassID == (int)CSGOClassID::CWeaponMag7 || pWeaponClass->m_ClassID == (int)CSGOClassID::CWeaponXM1014 || pWeaponClass->m_ClassID == (int)CSGOClassID::CWeaponSawedoff || pWeaponClass->m_ClassID == (int)CSGOClassID::CWeaponNOVA)
		return true;
	else
		return false;
}

bool GameUtils::IsMachinegun(void* weapon)
{
	if (weapon == nullptr) return false;
	IClientEntity* weaponEnt = (IClientEntity*)weapon;
	ClientClass* pWeaponClass = weaponEnt->GetClientClass();

	if (pWeaponClass->m_ClassID == (int)CSGOClassID::CWeaponNegev || pWeaponClass->m_ClassID == (int)CSGOClassID::CWeaponM249)
		return true;
	else
		return false;
}

void SayInChat(const char *text)
{
	char buffer[250];
	sprintf_s(buffer, "say \"%s\"", text);
	Interfaces::Engine->ClientCmd_Unrestricted(buffer);
}

Vector GetHitboxPosition(IClientEntity* pEntity, int Hitbox)
{
	matrix3x4 matrix[128];

	if (!pEntity->SetupBones(matrix, 128, 0x00000100, GetTickCount64()))
		return Vector(0, 0, 0);

	studiohdr_t* hdr = Interfaces::ModelInfo->GetStudiomodel(pEntity->GetModel());
	mstudiohitboxset_t* set = hdr->GetHitboxSet(0);

	mstudiobbox_t* hitbox = set->GetHitbox(Hitbox);

	if (!hitbox)
		return Vector(0, 0, 0);

	Vector vMin, vMax, vCenter, sCenter;
	VectorTransform(hitbox->bbmin, matrix[hitbox->bone], vMin);
	VectorTransform(hitbox->bbmax, matrix[hitbox->bone], vMax);
	vCenter = (vMin + vMax) *0.5f;
	return vCenter;
}

int GameUtils::GetPlayerCompRank(IClientEntity* pEntity)
{
	static DWORD m_iCompetitiveRanking = NetVar.GetNetVar(0x75671F7F);
	static DWORD GameResources = *(DWORD*)(Utilities::Memory::FindPattern("client.dll", (PBYTE)"\x8B\x3D\x00\x00\x00\x00\x85\xFF\x0F\x84\x00\x00\x00\x00\x81\xC7", "xx????xxxx????xx") + 0x2);

	return *(int*)((DWORD)GameResources + m_iCompetitiveRanking + (int)pEntity->GetIndex() * 4);
}

void ForceUpdate()
{
	auto cvar = Interfaces::CVar->FindVar("cl_fullupdate");
	cvar->nFlags &= FCVAR_CHEAT;
	cvar->SetValue("1");
}