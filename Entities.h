#pragma once

#include "MiscDefinitions.h"
#include "ClientRecvProps.h"
#include "offsets.h"
#include "Vector.h"

#define TEAM_CS_T 2
#define TEAM_CS_CT 3

#define BONE_USED_BY_HITBOX			0x00000100



class IClientRenderable;
class IClientNetworkable;
class IClientUnknown;
class IClientThinkable;
class IClientEntity;
class CSWeaponInfo;

typedef CSWeaponInfo& (__thiscall* GetCSWpnDataFn)(void*);

enum CSWeaponType
{
	WEAPONTYPE_KNIFE = 0,
	WEAPONTYPE_PISTOL,
	WEAPONTYPE_SUBMACHINEGUN,
	WEAPONTYPE_RIFLE,
	WEAPONTYPE_SHOTGUN,
	WEAPONTYPE_SNIPER_RIFLE,
	WEAPONTYPE_MACHINEGUN,
	WEAPONTYPE_C4,
	WEAPONTYPE_GRENADE,
	WEAPONTYPE_UNKNOWN
};

struct CHudTexture
{
	char	szShortName[64];	//0x0000
	char	szTextureFile[64];	//0x0040
	bool	bRenderUsingFont;	//0x0080
	bool	bPrecached;			//0x0081
	char	cCharacterInFont;	//0x0082
	BYTE	pad_0x0083;			//0x0083
	int		hFont;				//0x0084
	int		iTextureId;			//0x0088
	float	afTexCoords[4];		//0x008C
	int		iPosX[4];			//0x009C
}; //Size=0x00AC

class CSWeaponInfo
{
public:
	/*virtual void Function0(); //
	virtual void Function1(); //
	virtual void Parse(KeyValues *pKeyValuesData, const char *szWeaponName); //
	virtual void RefreshDynamicParameters(void); //
	virtual void Function4(); //
	virtual void Function5(); //
	virtual void Function6(); //
	virtual void Function7(); //
	virtual void Function8(); //*/

	/*char pad_0x0004[0x2]; //0x0004
	char m_pszName[32]; //0x0006 
	char pad_0x0026[0x7E]; //0x0026
	__int16 N0000002E; //0x00A4 
	char m_pszModelName[32]; //0x00A6 
	char pad_0x00C6[0x6DE]; //0x00C6
	BYTE m_IsFullAuto; //0x07A4 
	char pad_0x07A5[0x7]; //0x07A5
	__int32 m_iPrice; //0x07AC 
	float m_flArmorRatio; //0x07B0 
	char pad_0x07B4[0x10]; //0x07B4
	float m_flPenetration; //0x07C4 
	__int32 m_iDamage; //0x07C8 
	float m_flRange; //0x07CC 
	float m_flRangeModifier; //0x07D0 
	char pad_0x07D4[0x4]; //0x07D4
	float m_flCycleTime; //0x07D8 */

	char _0x0000[2036];
	bool m_IsFullAuto;
	char _0x0001[11];
	float m_flArmorRatio; //0x0800 
	char _0x0804[16];
	float m_flPenetration; //0x0814 
	__int32 m_iDamage; //0x0818 
	float m_flRange; //0x081C 
	float m_flRangeModifier; //0x0820 

};

enum class CSGOClassID
{
	CAK47 = 0,
	CBaseAnimating = 1,
	CBaseAnimatingOverlay = 2,
	CBaseAttributableItem = 3,
	CBaseButton = 4,
	CBaseCombatCharacter = 5,
	CBaseCombatWeapon = 6,
	CBaseCSGrenade = 7,
	CBaseCSGrenadeProjectile = 8,
	CBaseDoor = 9,
	CBaseEntity = 10,
	CBaseFlex = 11,
	CBaseGrenade = 12,
	CBaseParticleEntity = 13,
	CBasePlayer = 14,
	CBasePropDoor = 15,
	CBaseTeamObjectiveResource = 16,
	CBaseTempEntity = 17,
	CBaseToggle = 18,
	CBaseTrigger = 19,
	CBaseViewModel = 20,
	CBaseVPhysicsTrigger = 21,
	CBaseWeaponWorldModel = 22,
	CBeam = 23,
	CBeamSpotlight = 24,
	CBoneFollower = 25,
	CBreakableProp = 26,
	CBreakableSurface = 27,
	CC4 = 28,
	CCascadeLight = 29,
	CChicken = 30,
	CColorCorrection = 31,
	CColorCorrectionVolume = 32,
	CCSGameRulesProxy = 33,
	CCSPlayer = 34,
	CCSPlayerResource = 35,
	CCSRagdoll = 36,
	CCSTeam = 37,
	CDEagle = 38,
	CDecoyGrenade = 39,
	CDecoyProjectile = 40,
	CDynamicLight = 41,
	CDynamicProp = 42,
	CEconEntity = 43,
	CEconWearable = 44,
	CEmbers = 45,
	CEntityDissolve = 46,
	CEntityFlame = 47,
	CEntityFreezing = 48,
	CEntityParticleTrail = 49,
	CEnvAmbientLight = 50,
	CEnvDetailController = 51,
	CEnvDOFController = 52,
	CEnvParticleScript = 53,
	CEnvProjectedTexture = 54,
	CEnvQuadraticBeam = 55,
	CEnvScreenEffect = 56,
	CEnvScreenOverlay = 57,
	CEnvTonemapController = 58,
	CEnvWind = 59,
	CFEPlayerDecal = 60,
	CFireCrackerBlast = 61,
	CFireSmoke = 62,
	CFireTrail = 63,
	CFish = 64,
	CFlashbang = 65,
	CFogController = 66,
	CFootstepControl = 67,
	CFunc_Dust = 68,
	CFunc_LOD = 69,
	CFuncAreaPortalWindow = 70,
	CFuncBrush = 71,
	CFuncConveyor = 72,
	CFuncLadder = 73,
	CFuncMonitor = 74,
	CFuncMoveLinear = 75,
	CFuncOccluder = 76,
	CFuncReflectiveGlass = 77,
	CFuncRotating = 78,
	CFuncSmokeVolume = 79,
	CFuncTrackTrain = 80,
	CGameRulesProxy = 81,
	CHandleTest = 82,
	CHEGrenade = 83,
	CHostage = 84,
	CHostageCarriableProp = 85,
	CIncendiaryGrenade = 86,
	CInferno = 87,
	CInfoLadderDismount = 88,
	CInfoOverlayAccessor = 89,
	CItem_Healthshot = 90,
	CKnife = 91,
	CKnifeGG = 92,
	CLightGlow = 93,
	CMaterialModifyControl = 94,
	CMolotovGrenade = 95,
	CMolotovProjectile = 96,
	CMovieDisplay = 97,
	CParticleFire = 98,
	CParticlePerformanceMonitor = 99,
	CParticleSystem = 100,
	CPhysBox = 101,
	CPhysBoxMultiplayer = 102,
	CPhysicsProp = 103,
	CPhysicsPropMultiplayer = 104,
	CPhysMagnet = 105,
	CPlantedC4 = 106,
	CPlasma = 107,
	CPlayerResource = 108,
	CPointCamera = 109,
	CPointCommentaryNode = 110,
	CPoseController = 111,
	CPostProcessController = 112,
	CPrecipitation = 113,
	CPrecipitationBlocker = 114,
	CPredictedViewModel = 115,
	CProp_Hallucination = 116,
	CPropDoorRotating = 117,
	CPropJeep = 118,
	CPropVehicleDriveable = 119,
	CRagdollManager = 120,
	CRagdollProp = 121,
	CRagdollPropAttached = 122,
	CRopeKeyframe = 123,
	CSCAR17 = 124,
	CSceneEntity = 125,
	CSensorGrenade = 126,
	CSensorGrenadeProjectile = 127,
	CShadowControl = 128,
	CSlideshowDisplay = 129,
	CSmokeGrenade = 130,
	CSmokeGrenadeProjectile = 131,
	CSmokeStack = 132,
	CSpatialEntity = 133,
	CSpotlightEnd = 134,
	CSprite = 135,
	CSpriteOriented = 136,
	CSpriteTrail = 137,
	CStatueProp = 138,
	CSteamJet = 139,
	CSun = 140,
	CSunlightShadowControl = 141,
	CTeam = 142,
	CTeamplayRoundBasedRulesProxy = 143,
	CTEArmorRicochet = 144,
	CTEBaseBeam = 145,
	CTEBeamEntPoint = 146,
	CTEBeamEnts = 147,
	CTEBeamFollow = 148,
	CTEBeamLaser = 149,
	CTEBeamPoints = 150,
	CTEBeamRing = 151,
	CTEBeamRingPoint = 152,
	CTEBeamSpline = 153,
	CTEBloodSprite = 154,
	CTEBloodStream = 155,
	CTEBreakModel = 156,
	CTEBSPDecal = 157,
	CTEBubbles = 158,
	CTEBubbleTrail = 159,
	CTEClientProjectile = 160,
	CTEDecal = 161,
	CTEDust = 162,
	CTEDynamicLight = 163,
	CTEEffectDispatch = 164,
	CTEEnergySplash = 165,
	CTEExplosion = 166,
	CTEFireBullets = 167,
	CTEFizz = 168,
	CTEFootprintDecal = 169,
	CTEFoundryHelpers = 170,
	CTEGaussExplosion = 171,
	CTEGlowSprite = 172,
	CTEImpact = 173,
	CTEKillPlayerAttachments = 174,
	CTELargeFunnel = 175,
	CTEMetalSparks = 176,
	CTEMuzzleFlash = 177,
	CTEParticleSystem = 178,
	CTEPhysicsProp = 179,
	CTEPlantBomb = 180,
	CTEPlayerAnimEvent = 181,
	CTEPlayerDecal = 182,
	CTEProjectedDecal = 183,
	CTERadioIcon = 184,
	CTEShatterSurface = 185,
	CTEShowLine = 186,
	CTesla = 187,
	CTESmoke = 188,
	CTESparks = 189,
	CTESprite = 190,
	CTESpriteSpray = 191,
	CTest_ProxyToggle_Networkable = 192,
	CTestTraceline = 193,
	CTEWorldDecal = 194,
	CTriggerPlayerMovement = 195,
	CTriggerSoundOperator = 196,
	CVGuiScreen = 197,
	CVoteController = 198,
	CWaterBullet = 199,
	CWaterLODControl = 200,
	CWeaponAug = 201,
	CWeaponAWP = 202,
	CWeaponBaseItem = 203,
	CWeaponBizon = 204,
	CWeaponCSBase = 205,
	CWeaponCSBaseGun = 206,
	CWeaponCycler = 207,
	CWeaponElite = 208,
	CWeaponFamas = 209,
	CWeaponFiveSeven = 210,
	CWeaponG3SG1 = 211,
	CWeaponGalil = 212,
	CWeaponGalilAR = 213,
	CWeaponGlock = 214,
	CWeaponHKP2000 = 215,
	CWeaponM249 = 216,
	CWeaponM3 = 217,
	CWeaponM4A1 = 218,
	CWeaponMAC10 = 219,
	CWeaponMag7 = 220,
	CWeaponMP5Navy = 221,
	CWeaponMP7 = 222,
	CWeaponMP9 = 223,
	CWeaponNegev = 224,
	CWeaponNOVA = 225,
	CWeaponP228 = 226,
	CWeaponP250 = 227,
	CWeaponP90 = 228,
	CWeaponSawedoff = 229,
	CWeaponSCAR20 = 230,
	CWeaponScout = 231,
	CWeaponSG550 = 232,
	CWeaponSG552 = 233,
	CWeaponSG556 = 234,
	CWeaponSSG08 = 235,
	CWeaponTaser = 236,
	CWeaponTec9 = 237,
	CWeaponTMP = 238,
	CWeaponUMP45 = 239,
	CWeaponUSP = 240,
	CWeaponXM1014 = 241,
	CWorld = 242,
	DustTrail = 243,
	MovieExplosion = 244,
	ParticleSmokeGrenade = 245,
	RocketTrail = 246,
	SmokeTrail = 247,
	SporeExplosion = 248,
	SporeTrail = 249
};

enum class CSGOHitboxID
{
	Head = 0,
	Neck,
	NeckLower,
	Pelvis,
	Stomach,
	LowerChest,
	Chest,
	UpperChest,
	RightThigh,
	LeftThigh,
	RightShin,
	LeftShin,
	RightFoot,
	LeftFoot,
	RightHand,
	LeftHand,
	RightUpperArm,
	RightLowerArm,
	LeftUpperArm,
	LeftLowerArm
};

enum class CSPlayerBones : int {
	pelvis = 0,
	spine_0,
	spine_1,
	spine_2,
	spine_3,
	neck_0,
	head_0,
	clavicle_L,
	arm_upper_L,
	arm_lower_L,
	hand_L,
	finger_middle_meta_L,
	finger_middle_0_L,
	finger_middle_1_L,
	finger_middle_2_L,
	finger_pinky_meta_L,
	finger_pinky_0_L,
	finger_pinky_1_L,
	finger_pinky_2_L,
	finger_index_meta_L,
	finger_index_0_L,
	finger_index_1_L,
	finger_index_2_L,
	finger_thumb_0_L,
	finger_thumb_1_L,
	finger_thumb_2_L,
	finger_ring_meta_L,
	finger_ring_0_L,
	finger_ring_1_L,
	finger_ring_2_L,
	weapon_hand_L,
	arm_lower_L_TWIST,
	arm_lower_L_TWIST1,
	arm_upper_L_TWIST,
	arm_upper_L_TWIST1,
	clavicle_R,
	arm_upper_R,
	arm_lower_R,
	hand_R,
	finger_middle_meta_R,
	finger_middle_0_R,
	finger_middle_1_R,
	finger_middle_2_R,
	finger_pinky_meta_R,
	finger_pinky_0_R,
	finger_pinky_1_R,
	finger_pinky_2_R,
	finger_index_meta_R,
	finger_index_0_R,
	finger_index_1_R,
	finger_index_2_R,
	finger_thumb_0_R,
	finger_thumb_1_R,
	finger_thumb_2_R,
	finger_ring_meta_R,
	finger_ring_0_R,
	finger_ring_1_R,
	finger_ring_2_R,
	weapon_hand_R,
	arm_lower_R_TWIST,
	arm_lower_R_TWIST1,
	arm_upper_R_TWIST,
	arm_upper_R_TWIST1,
	leg_upper_L,
	leg_lower_L,
	ankle_L,
	ball_L,
	leg_upper_L_TWIST,
	leg_upper_L_TWIST1,
	leg_upper_R,
	leg_lower_R,
	ankle_R,
	ball_R,
	leg_upper_R_TWIST,
	leg_upper_R_TWIST1,
	weapon_bone,
	lh_ik_driver,
	lean_root,
	lfoot_lock,
	rfoot_lock,
	primary_jiggle_jnt,
	primary_smg_jiggle_jnt
};



class ScriptCreatedItem
{
public:
	CPNETVAR_FUNC(int*, ItemDefinitionIndex, 0xE67AB3B8); //m_iItemDefinitionIndex
	CPNETVAR_FUNC(int*, ItemIDHigh, 0x714778A); //m_iItemIDHigh
	CPNETVAR_FUNC(int*, ItemIDLow, 0x3A3DFC74); //m_iItemIDLow
};

class AttributeContainer
{
public:
	CPNETVAR_FUNC(ScriptCreatedItem*, m_Item, 0x7E029CE5);
};


class CBaseCombatWeapon
{
public:
	CNETVAR_FUNC(float, GetNextPrimaryAttack, 0xDB7B106E); //m_flNextPrimaryAttack
	CNETVAR_FUNC(int, GetAmmoInClip, 0x97B6F70C); //m_iClip1
	CNETVAR_FUNC(HANDLE, GetOwnerHandle, 0xC32DF98D); //m_hOwner
	CNETVAR_FUNC(Vector, GetOrigin, 0x1231CE10); //m_vecOrigin
	CPNETVAR_FUNC(int*, FallbackPaintKit, 0xADE4C870); // m_nFallbackPaintKit
	CPNETVAR_FUNC(int*, FallbackSeed, 0xC2D0683D); // m_nFallbackSeed
	CPNETVAR_FUNC(float*, FallbackWear, 0xA263576C); //m_flFallbackWear
	CPNETVAR_FUNC(int*, FallbackStatTrak, 0x1ED78768); //m_nFallbackStatTrak
	CPNETVAR_FUNC(int*, OwnerXuidLow, 0xAD8D897F);
	CPNETVAR_FUNC(int*, OwnerXuidHigh, 0x90511E77);
	CPNETVAR_FUNC(int*, ViewModelIndex, 0x7F7C89C1);
	CPNETVAR_FUNC(int*, ModelIndex, 0x27016F83);
	CPNETVAR_FUNC(int*, WorldModelIndex, 0x4D8AD9F3);
	CPNETVAR_FUNC(char*, szCustomName, 0x0);

	CPNETVAR_FUNC(AttributeContainer*, m_AttributeManager, 0xCFFCE089);

	float GetInaccuracy()
	{
		typedef float(__thiscall* oInaccuracy)(PVOID);
		return call_vfunc< oInaccuracy >(this, 484)(this);
	}

	float GetSpread()
	{
		typedef float(__thiscall* oWeaponSpread)(PVOID);
		return call_vfunc< oWeaponSpread >(this, 485)(this);
	}

	void UpdateAccuracyPenalty()
	{
		typedef void(__thiscall* oUpdateAccuracy)(PVOID);
		return call_vfunc<oUpdateAccuracy>(this, 486)(this);
	}

	float GetInaccuracy1()
	{
		typedef float(__thiscall* oGetSpread)(PVOID);
		return call_vfunc< oGetSpread>(this, Offsets::VMT::Weapon_GetSpread)(this);
	}

	float GetAccuracyPenalty()
	{
		return *(float*)((DWORD)this + 0x32B0);
	}

	float GetSpread1()
	{
		typedef float(__thiscall* oGetInac)(PVOID);
		return call_vfunc< oGetInac>(this, Offsets::VMT::Weapon_GetSpread + 1)(this);
	}

	void UpdateAccuracyPenalty1()
	{
		typedef void(__thiscall* oUpdateAccuracyPenalty)(PVOID);
		return call_vfunc< oUpdateAccuracyPenalty>(this, Offsets::VMT::Weapon_GetSpread + 2)(this);
	}

	CSWeaponInfo GetCSWpnData(CBaseCombatWeapon * pWeapon, int iIndex)
	{
		return ((GetCSWpnDataFn)((*(DWORD**)pWeapon)[iIndex]))(pWeapon);
	}

	int GetAmmoInClip2() {
		return *(int*)((DWORD)this + 0x000031F4);
	}
	int GetWeaponID2() {
		return *(int*)((DWORD)this + 0x00002F88);
	}

	/*CSWeaponInfo* GetCSWpnData()
	{
		static DWORD GetCSWpnDataAddr = Utilities::Memory::FindPattern("client.dll", (PBYTE)"\x55\x8B\xEC\x81\xEC\x00\x00\x00\x00\xB8\x00\x00\x00\x00\x57", "xxxxx????x????x");
		if (GetCSWpnDataAddr)
		{
			CSWeaponInfo* retData;
			__asm
			{
				mov ecx, this
				call GetCSWpnDataAddr
					mov retData, eax
			}
			return retData;
		}
		else
		{
			return nullptr;
		}
	}*/
};

class CCSBomb
{
public:
	CNETVAR_FUNC(HANDLE, GetOwnerHandle, 0xC32DF98D); //m_hOwner
	CNETVAR_FUNC(float, GetC4BlowTime, 0xB5E0CA1C); //m_flC4Blow
	CNETVAR_FUNC(float, GetC4DefuseCountDown, 0xB959B4A6); //m_flDefuseCountDown
};

class CLocalPlayerExclusive
{
public:
	CNETVAR_FUNC(Vector, GetViewPunchAngle, 0x68F014C0);//m_viewPunchAngle
	CNETVAR_FUNC(Vector, GetAimPunchAngle, 0xBF25C290);//m_aimPunchAngle
	CNETVAR_FUNC(Vector, GetAimPunchAngleVel, 0x8425E045);//m_aimPunchAngleVel
};

class CollisionProperty
{
public:
	CNETVAR_FUNC(Vector, GetMins, 0xF6F78BAB);//m_vecMins
	CNETVAR_FUNC(Vector, GetMaxs, 0xE47C6FC4);//m_vecMaxs
	CNETVAR_FUNC(unsigned char, GetSolidType, 0xB86722A1);//m_nSolidType
	CNETVAR_FUNC(unsigned short, GetSolidFlags, 0x63BB24C1);//m_usSolidFlags
	CNETVAR_FUNC(int, GetSurroundsType, 0xB677A0BB); //m_nSurroundType

	bool IsSolid()
	{
		return (GetSolidType() != SOLID_NONE) && ((GetSolidFlags() & FSOLID_NOT_SOLID) == 0);
	}
};

class IClientRenderable
{
public:
	//virtual void*					GetIClientUnknown() = 0;
	virtual Vector const&			GetRenderOrigin(void) = 0;
	virtual Vector const&			GetRenderAngles(void) = 0;
	virtual bool					ShouldDraw(void) = 0;
	virtual bool					IsTransparent(void) = 0;
	virtual bool					UsesPowerOfTwoFrameBufferTexture() = 0;
	virtual bool					UsesFullFrameBufferTexture() = 0;
	virtual void					GetShadowHandle() const = 0;
	virtual void*					RenderHandle() = 0;
	virtual const model_t*				GetModel() const = 0;
	virtual int						DrawModel(int flags) = 0;
	virtual int						GetBody() = 0;
	virtual void					ComputeFxBlend() = 0;

	bool SetupBones(matrix3x4 *pBoneToWorldOut, int nMaxBones, int boneMask, float currentTime)
	{
		typedef bool(__thiscall* oSetupBones)(PVOID, matrix3x4*, int, int, float);
		return call_vfunc< oSetupBones>(this, 13)(this, pBoneToWorldOut, nMaxBones, boneMask, currentTime);
	}
};

class IClientNetworkable
{
public:
	virtual IClientUnknown*	GetIClientUnknown() = 0;
	virtual void			Release() = 0;
	virtual ClientClass*	GetClientClass() = 0;// FOR NETVARS FIND YOURSELF ClientClass* stuffs
	virtual void			NotifyShouldTransmit( /* ShouldTransmitState_t state*/) = 0;
	virtual void			OnPreDataChanged( /*DataUpdateType_t updateType*/) = 0;
	virtual void			OnDataChanged( /*DataUpdateType_t updateType*/) = 0;
	virtual void			PreDataUpdate( /*DataUpdateType_t updateType*/) = 0;
	virtual void			PostDataUpdate( /*DataUpdateType_t updateType*/) = 0;
	virtual void			unknown();
	virtual bool			IsDormant(void) = 0;
	virtual int				GetIndex(void) const = 0;
	virtual void			ReceiveMessage(int classID /*, bf_read &msg*/) = 0;
	virtual void*			GetDataTableBasePtr() = 0;
	virtual void			SetDestroyedOnRecreateEntities(void) = 0;
};

class IClientUnknown
{
public:
	virtual void*		GetCollideable() = 0;
	virtual IClientNetworkable*	GetClientNetworkable() = 0;
	virtual IClientRenderable*	GetClientRenderable() = 0;
	virtual IClientEntity*		GetIClientEntity() = 0;
	virtual IClientEntity*		GetBaseEntity() = 0;
	virtual IClientThinkable*	GetClientThinkable() = 0;
};

class IClientThinkable
{
public:
	virtual IClientUnknown*		GetIClientUnknown() = 0;
	virtual void				ClientThink() = 0;
	virtual void*				GetThinkHandle() = 0;
	virtual void				SetThinkHandle(void* hThink) = 0;
	virtual void				Release() = 0;
};

class __declspec (novtable)IClientEntity : public IClientUnknown, public IClientRenderable, public IClientNetworkable, public IClientThinkable
{
public:
	virtual void			Release(void) = 0;
	virtual void			blahblahpad(void) = 0;
	virtual Vector&	GetAbsOrigin(void) const = 0;//in broken place use GetOrigin Below
	virtual const Vector&	GetAbsAngles(void) const = 0;

	//---                 NetVars                  ---//

	CPNETVAR_FUNC(CLocalPlayerExclusive*, localPlayerExclusive, 0x7177BC3E);// m_Local
	CPNETVAR_FUNC(CollisionProperty*, collisionProperty, 0xE477CBD0);//m_Collision

	CNETVAR_FUNC(int, GetFlags, 0xE456D580); //m_fFlags
	CNETVAR_FUNC(Vector, GetOrigin, 0x1231CE10); //m_vecOrigin
	CNETVAR_FUNC(Vector, GetRotation, 0x6BEA197A); //m_angRotation
	CNETVAR_FUNC(int, GetTeamNum, 0xC08B6C6E); //m_iTeamNum
	CNETVAR_FUNC(int, GetMaxHealth, 0xC52E1C28); //m_iMaxHealth
	CNETVAR_FUNC(int, GetHealth, 0xA93054E3); //m_iHealth
	CNETVAR_FUNC(unsigned char, GetLifeState, 0xD795CCFC); //m_lifeState
	CNETVAR_FUNC(HANDLE, GetActiveWeaponHandle, 0xB4FECDA3); //m_hActiveWeapon
	CNETVAR_FUNC(int, GetTickBase, 0xD472B079); //m_nTickBase
	CNETVAR_FUNC(Vector, GetViewOffset, 0xA9F74931); //m_vecViewOffset[0]
	CNETVAR_FUNC(Vector, GetVelocity, 0x40C1CA24); //m_vecVelocity[0]
	CNETVAR_FUNC(bool, HasGunGameImmunity, 0x6AD6FA0D); //m_bGunGameImmunity
	CNETVAR_FUNC(bool, IsDefusing, 0xA2C14106); //m_bIsDefusing
	CNETVAR_FUNC(int, ArmorValue, 0x3898634); //m_ArmorValue
	CNETVAR_FUNC(bool, HasHelmet, 0x7B97F18A); //m_bHasHelmet
	CNETVAR_FUNC(bool, IsScoped, 0x61B9C22C); //m_bIsScoped
	CNETVAR_FUNC(int, GetMoney, 0xF4B3E183); //m_iAccount
	CNETVAR_FUNC(HANDLE, GetObserverTargetHandle, 0x8660FD83); //m_hObserverTarget
															   // ----------------------------------------------//

	bool IsAlive()
	{
		return (GetLifeState() == LIFE_ALIVE && GetHealth() > 0);
	}

	Vector GetBonePos(int i)
	{
		matrix3x4 boneMatrix[128];
		if (this->SetupBones(boneMatrix, 128, BONE_USED_BY_HITBOX, GetTickCount64()))
		{
			return Vector(boneMatrix[i][0][3], boneMatrix[i][1][3], boneMatrix[i][2][3]);
		}
		return Vector(0, 0, 0);
	}

	bool IsPlayer()
	{
		typedef bool(__thiscall *IsPlayer_t)(PVOID);
		return ((IsPlayer_t)(*(PDWORD)(*(PDWORD)(this) + 0x260)))(this);
	}

	Vector GetHeadPos() {
		return this->GetBonePos(6);
	}

	Vector GetOrigin2() {
		return *(Vector*)((DWORD)this + 0x00000134);
	}
	Vector GetViewAngles2() {
		return *(Vector*)((DWORD)this + 0x00000104);
	}

	Vector GetAbsOrigin2() {
		__asm {
			MOV ECX, this
				MOV EAX, DWORD PTR DS : [ECX]
				CALL DWORD PTR DS : [EAX + 0x28]
		}
	}
	Vector GetAbsAngles2() {
		__asm {
			MOV ECX, this;
			MOV EAX, DWORD PTR DS : [ECX];
			CALL DWORD PTR DS : [EAX + 0x2C]
		}
	}


	Vector GetEyePosition() {
		Vector Origin = *(Vector*)((DWORD)this + 0x00000134);
		Vector View = *(Vector*)((DWORD)this + 0x00000104);
		return(Origin + View);
	}
	Vector GetAimPunch() {
		return *(Vector*)((DWORD)this + 0x00003018);
	}
	bool IsImmune() {
		return *(bool*)((DWORD)this + 0x000038A0);
	}
	ClientClass *GetClientClass2() {
		PVOID Networkable = (PVOID)((DWORD)(this) + 0x8);
		using Original = ClientClass*(__thiscall*)(PVOID);
		return call_vfunc<Original>(Networkable, 2)(Networkable);
	}
	HANDLE GetWeaponHandle() {
		return *(HANDLE*)((DWORD)this + 0x00002EE8);
	}



};