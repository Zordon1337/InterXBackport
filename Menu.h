#pragma once

#include "Gui.h"
#include "Controls.h"

class CRageBotTab : public CTab
{
public:
	void Setup();

	// Master Switch
	CLabel ActiveLabel;
	CCheckBox Active;

	// Aimbot Settings
	CGroupBox AimbotGroup;

	CCheckBox AimbotEnable;
	CCheckBox AimbotAutoFire;
	CSlider	  AimbotFov;
	CCheckBox AimbotSilentAim;
	CCheckBox AimbotPSilent;
	CCheckBox AimbotAutoPistol;
	CCheckBox AimbotAimStep;
	CCheckBox AimbotKeyPress;
	CKeyBind  AimbotKeyBind;
	CCheckBox AntiSpawnProtection;


	// Target Selection Settings
	CGroupBox TargetGroup;

	CComboBox TargetSelection;
	CCheckBox TargetFriendlyFire;
	CComboBox TargetHitbox;
	CComboBox TargetHitscan;
	CCheckBox AccuracyAutoWall;
	CSlider	  AccuracyMinimumDamage;

	// Accuracy Settings
	CGroupBox AccuracyGroup;
	CCheckBox AccuracySpread;
	CCheckBox AccuracyRecoil;
	CCheckBox AccuracyAutoCrouch;
	CCheckBox AccuracyAutoScope;
	CCheckBox AccuracySpreadLimit;
	CSlider	  AccuracyMinimumSpread;
	CCheckBox AccuracyAngleFix;
	CCheckBox AntiAntiAim;
	CCheckBox HitChance;
	CSlider HitChanceAmount;

	// Anti-Aim Settings
	CGroupBox AntiAimGroup;

	CCheckBox AntiAimEnable;
	CComboBox AntiAimPitch;
	CComboBox AntiAimYaw;
	CCheckBox AtTargets;
	CCheckBox EdgeAntiAim;
	CCheckBox EdgeOut;
};

class CLegitBotTab : public CTab
{
public:
	void Setup();

	// Master Switch
	CLabel ActiveLabel;
	CCheckBox Active;

	// Aimbot Settings
	CGroupBox AimbotGroup;

	CCheckBox AimbotEnable;
	CCheckBox AimbotAutoFire;
	CCheckBox AimbotFriendlyFire;
	CCheckBox AimbotKeyPress;
	CKeyBind  AimbotKeyBind;
	CCheckBox AimbotAutoPistol;
	CCheckBox AimbotChicken;
	CCheckBox AimbotSmokeCheck;
	
	// Main
	CGroupBox TriggerGroup;

	CCheckBox TriggerEnable;
	CCheckBox TriggerKeyPress;
	CKeyBind  TriggerKeyBind;
	CCheckBox TriggerHitChance;
	CSlider   TriggerHitChanceAmmount;
	CSlider   TriggerDelay;
	CSlider   TriggerBurst;
	CSlider   TriggerBreak;
	CCheckBox TriggerRecoil;

	// Trigger Filter
	CGroupBox TriggerFilterGroup;

	CCheckBox TriggerHead;
	CCheckBox TriggerChest;
	CCheckBox TriggerStomach;
	CCheckBox TriggerArms;
	CCheckBox TriggerLegs;
	CCheckBox TriggerTeammates;

	// Rifles
	CGroupBox WeaponMainGroup;

	CSlider   WeaponMainSpeed;
	CSlider   WeaponMainFoV;
	CSlider WeaponMainRecoil;
	CComboBox WeaponMainHitbox;
	CSlider WeaponMainAimtime;
	CSlider WeaoponMainStartAimtime;

	// Pistol
	CGroupBox WeaponPistGroup;

	CSlider   WeaponPistSpeed;
	CSlider   WeaponPistFoV;
	CSlider WeaponPistRecoil;
	CComboBox WeaponPistHitbox;
	CSlider WeaponPistAimtime;
	CSlider WeaoponPistStartAimtime;

	// Sniper
	CGroupBox WeaponSnipGroup;

	CSlider   WeaponSnipSpeed;
	CSlider   WeaponSnipFoV;
	CSlider WeaponSnipRecoil;
	CComboBox WeaponSnipHitbox;
	CSlider WeaponSnipAimtime;
	CSlider WeaoponSnipStartAimtime;

	// MPs
	CGroupBox WeaponMpGroup;

	CSlider   WeaponMpSpeed;
	CSlider   WeaponMpFoV;
	CSlider WeaponMpRecoil;
	CComboBox WeaponMpHitbox;
	CSlider WeaponMpAimtime;
	CSlider WeaoponMpStartAimtime;

	// Shotguns
	CGroupBox WeaponShotgunGroup;

	CSlider   WeaponShotgunSpeed;
	CSlider   WeaponShotgunFoV;
	CSlider WeaponShotgunRecoil;
	CComboBox WeaponShotgunHitbox;
	CSlider WeaponShotgunAimtime;
	CSlider WeaoponShotgunStartAimtime;

	// Machineguns
	CGroupBox WeaponMGGroup;

	CSlider   WeaponMGSpeed;
	CSlider   WeaponMGFoV;
	CSlider WeaponMGRecoil;
	CComboBox WeaponMGHitbox;
	CSlider WeaponMGAimtime;
	CSlider WeaoponMGStartAimtime;
};

class CMiscTab : public CTab
{
public:
	void Setup();

	// Fake Lag Settings
	CGroupBox FakeLagGroup;
	CCheckBox FakeLagEnable;
	CSlider   FakeLagAmount;
	CCheckBox FakeLagWhileShooting;

	// Teleport
	CGroupBox TeleportGroup;
	CKeyBind TeleportKey;
	CKeyBind  OtherAirStuck;

	// Clan tags binds
	CGroupBox ClandTags;
	CKeyBind  ClanTag1;
	CKeyBind  ClanTag2;
	CKeyBind  ClanTag3;
	CKeyBind  ClanTag4;
	CKeyBind  ClanTag5;
	CKeyBind  ClanTag6;
	CKeyBind  ClanTag7;
	CKeyBind  ClanTag8;
	CKeyBind  ClanTag9;
	CKeyBind  ClanTag10;

	// Recoil Settings
	CGroupBox RecoilGroup;
	CCheckBox RecoilControlSystem;
	CCheckBox OtherNoVisualRecoil;

	// Other Settings
	CGroupBox OtherGroup;
	CCheckBox OtherBunnyhop;
	CCheckBox OtherAutoStrafe;

	// Spammers
	CGroupBox OtherSpammers;
	CComboBox OtherChatSpam;
	CCheckBox OtherEventSpam;
	CTextField2 OtherChatText;
	CCheckBox OtherAimware;
	CCheckBox OtherInterwebz;
	CCheckBox OtherClowns;
	CCheckBox OtherTeleportHack;
	CCheckBox OtherThirdperson;
	CSlider OtherThirdpersonRange;
	CSlider OtherFakeLag;

	CCheckBox OtherSafeMode;
	CCheckBox OtherAutoAccept;
};

class CVisualTab : public CTab
{
public:
	void Setup();

	// Master Switch
	CLabel ActiveLabel;
	CCheckBox Active;

	// Entities Settings
	CGroupBox OptionsGroup;

	CComboBox OptionsBox;
	CCheckBox OptionsName;
	CCheckBox OptionsHealth;
	CComboBox OptionsWeapon;
	CCheckBox OptionsInfo;
	CCheckBox OptionsCompRank;
	CComboBox OptionsChams;
	CCheckBox OptionsSkeleton;
	CCheckBox OptionsAimSpot;
	CCheckBox OptionsDilights;
	CCheckBox OptionsGlow;
	CCheckBox OtherViewDirection;
	CSlider GlowZ;

	// Filters Settings
	CGroupBox FiltersGroup;
	CCheckBox FiltersAll;
	CCheckBox FiltersPlayers;
	CCheckBox FiltersEnemiesOnly;
	CCheckBox FiltersWeapons;
	CCheckBox FiltersChickens;
	CCheckBox FiltersC4;

	// Visual Misc Settings
	CGroupBox VisualMiscGroup;
	CCheckBox OtherNoSky;
	CCheckBox OtherNoFlash;
	CCheckBox OtherHitmarker;
	CCheckBox OtherNoSmoke;
	CComboBox OtherNoHands;
	CComboBox OtherCrosshair;
	CComboBox OtherCrosshairType;
	CCheckBox OtherSpectators;
	CCheckBox OtherWatermark;
	CGroupBox OtherOtherGroup;
	CCheckBox OtherRadar;
	CCheckBox OtherRadarEnemyOnly;
	CCheckBox OtherRadarVisibleOnly;
	CSlider	  OtherRadarScale;

	CSlider OtherRadarXPosition;
	CSlider OtherRadarYPosition;
};

class CSkinchangerTab : public CTab
{
public:
	void Setup();

	// Knife Changer/Skin Changer
	CLabel SkinActive;
	CCheckBox SkinEnable;
	CButton   SkinApply;

	// Knife
	CGroupBox KnifeGroup;
	CComboBox KnifeModel;
	CComboBox KnifeSkin;

	// Pistols
	CGroupBox PistolGroup;
	CComboBox GLOCKSkin;
	CComboBox USPSSkin;
	CComboBox DEAGLESkin;
	CComboBox MAGNUMSkin;
	CComboBox DUALSSkin;
	CComboBox FIVESEVENSkin;
	CComboBox TECNINESkin;
	CComboBox P2000Skin;
	CComboBox P250Skin;

	// MPs
	CGroupBox MPGroup;
	CComboBox MAC10Skin;
	CComboBox P90Skin;
	CComboBox UMP45Skin;
	CComboBox BIZONSkin;
	CComboBox MP7Skin;
	CComboBox MP9Skin;

	// Rifles
	CGroupBox Riflegroup;
	CComboBox M41SSkin;
	CComboBox M4A4Skin;
	CComboBox AK47Skin;
	CComboBox AUGSkin;
	CComboBox FAMASSkin;
	CComboBox GALILSkin;
	CComboBox SG553Skin;


	// Machineguns
	CGroupBox MachinegunsGroup;
	CComboBox NEGEVSkin;
	CComboBox M249Skin;

	// Snipers
	CGroupBox Snipergroup;
	CComboBox SCAR20Skin;
	CComboBox G3SG1Skin;
	CComboBox SSG08Skin;
	CComboBox AWPSkin;

	// Shotguns
	CGroupBox Shotgungroup;
	CComboBox MAG7Skin;
	CComboBox XM1014Skin;
	CComboBox SAWEDOFFSkin;
	CComboBox NOVASkin;

	// Skinsettings
	CGroupBox SkinsettingsGroup;
	CCheckBox StatTrakEnable;
	CTextField StatTrackAmount;
	CTextField2 SkinName;
	CTextField2 KnifeName;
};

class CColorsTab : public CTab
{
public:
	void Setup();
	CGroupBox RGBGroup;
	CSlider   MenuR;
	CSlider   MenuG;
	CSlider   MenuB;

	// Colors
	CGroupBox ColorsGroup;
	CSlider CTColorVisR;
	CSlider CTColorVisG;
	CSlider CTColorVisB;

	CSlider CTColorNoVisR;
	CSlider CTColorNoVisG;
	CSlider CTColorNoVisB;

	CLabel ColorSpacer;

	CSlider TColorVisR;
	CSlider TColorVisG;
	CSlider TColorVisB;

	CSlider TColorNoVisR;
	CSlider TColorNoVisG;
	CSlider TColorNoVisB;

	CSlider GlowR;
	CSlider GlowG;
	CSlider GlowB;
};

class MainWindow : public CWindow
{
public:
	void Setup();

	CRageBotTab RageBotTab;
	CLegitBotTab LegitBotTab;
	CVisualTab VisualsTab;
	CMiscTab MiscTab;
	CSkinchangerTab SkinchangerTab;
	CColorsTab ColorsTab;

	CButton SaveButton1;
	CButton LoadButton1;
	CButton SaveButton;
	CButton LoadButton;
	CButton UnloadButton;
	CButton PanicButton;
};

namespace Menu
{
	void SetupMenu();
	void DoUIFrame();

	extern MainWindow Window;
};