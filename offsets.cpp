#include "Offsets.h"

void Offsets::Initialise()
{
	// Modules
	Modules::Client = Utilities::Memory::WaitOnModuleHandle("client.dll");
	Modules::Engine = Utilities::Memory::WaitOnModuleHandle("engine.dll");
	Modules::VGUI2 = Utilities::Memory::WaitOnModuleHandle("vgui2.dll");
	Modules::VGUISurface = Utilities::Memory::WaitOnModuleHandle("vguimatsurface.dll");
	Modules::Material = Utilities::Memory::WaitOnModuleHandle("materialsystem.dll");
	Modules::VPhysics = Utilities::Memory::WaitOnModuleHandle("vphysics.dll");
	Modules::Stdlib = Utilities::Memory::WaitOnModuleHandle("vstdlib.dll");

	

	//------------------------------------------------------------------------
	// VTables
#pragma region VTables
	VMT::CHL_GetAllClasses = 8;

	VMT::Engine_GetScreenSize = 5;
	VMT::Engine_GetPlayerInfo = 8;
	VMT::Engine_GetLocalPlayer = 12;
	VMT::Engine_Time = 14;
	VMT::Engine_GetViewAngles = 18;
	VMT::Engine_SetViewAngles = 19;
	VMT::Engine_GetMaxClients = 20;
	VMT::Engine_IsConnected = 27;
	VMT::Engine_IsInGame = 26;
	VMT::Engine_WorldToScreenMatrix = 37;
	VMT::Engine_ClientCmd_Unrestricted = 114;

	VMT::Panel_GetName = 36;
	VMT::Panel_PaintTraverse = 41;

	VMT::Surface_DrawSetColorA = 13;
	VMT::Surface_DrawSetColorB = 14;
	VMT::Surface_DrawFilledRect = 15;
	VMT::Surface_DrawOutlinedRect = 17;
	VMT::Surface_DrawLine = 18;
	VMT::Surface_DrawSetTextFont = 22;
	VMT::Surface_DrawSetTextColorA = 23;
	VMT::Surface_DrawSetTextColorB = 24;
	VMT::Surface_DrawSetTextPos = 25;
	VMT::Surface_DrawPrintText = 27;
	VMT::Surface_DrawSetTextureRGBA = 36;
	VMT::Surface_DrawSetTexture = 37;
	VMT::Surface_CreateNewTextureID = 42;
	VMT::Surface_FontCreate = 70;
	VMT::Surface_SetFontGlyphSet = 71;
	VMT::Surface_GetTextSize = 78;
	VMT::Surface_DrawOutlinedCircle = 102;
	VMT::Surface_SurfaceGetCursorPos = 65;
	VMT::Surface_DrawTexturedPolygon = 105;

	VMT::Material_GetName = 0;
	VMT::Material_SetMaterialVarFlag = 30;
	VMT::Material_GetMaterialVarFlag = 31;
	VMT::Material_AlphaModulate = 28;
	VMT::Material_ColorModulate = 29;
	VMT::Material_IncrementReferenceCount = 14;

	VMT::MaterialSystem_FindMaterial = 83;
	VMT::MaterialSystem_CreateMaterial = 82;

	VMT::ModelRender_ForcedMaterialOverride = 1;
	VMT::ModelRender_DrawModelExecute = 21;

	VMT::ModelInfo_GetModelName = 3;
	VMT::ModelInfo_GetStudiomodel = 30;

	VMT::RenderView_SetBlend = 4;
	VMT::RenderView_SetColorModulation = 6;

#pragma endregion Contains the VTable Indexs

	// An update changed the VTable offset for GetSpread.
	// Just incase ;)

	VMT::Weapon_GetSpread = 460;

	

	// I cbf trying to get the KeyValues part of the SDK working solo, so we'll just
	// Do some dirty shit
	Functions::KeyValues_KeyValues = Utilities::Memory::FindPattern("client.dll", (PBYTE)"\x68\x00\x00\x00\x00\x8B\xC8\xE8\x00\x00\x00\x00\x89\x45\xFC\xEB\x07\xC7\x45\x00\x00\x00\x00\x00\x8B\x03\x56", "x????xxx????xxxxxxx?????xxx");
	Functions::KeyValues_KeyValues += 7;
	Functions::KeyValues_KeyValues = Functions::KeyValues_KeyValues + *reinterpret_cast< PDWORD_PTR >(Functions::KeyValues_KeyValues + 1) + 5;

	Functions::KeyValues_LoadFromBuffer = Utilities::Memory::FindPattern("client.dll", (PBYTE)"\xE8\x00\x00\x00\x00\x8A\xD8\xFF\x15\x00\x00\x00\x00\x84\xDB", "x????xxxx????xx");
	Functions::KeyValues_LoadFromBuffer = Functions::KeyValues_LoadFromBuffer + *reinterpret_cast< PDWORD_PTR >(Functions::KeyValues_LoadFromBuffer + 1) + 5;

	Functions::dwCalcPlayerView = Utilities::Memory::FindPattern("client.dll", (PBYTE)"\x84\xC0\x75\x08\x57\x8B\xCE\xE8\x00\x00\x00\x00\x8B\x06", "xxxxxxxx????xx");
}

namespace Offsets
{
	// Addresses of loaded game modules
	namespace Modules
	{
		DWORD Client;
		DWORD Engine;
		DWORD VGUI2;
		DWORD VGUISurface;
		DWORD Material;
		DWORD VPhysics;
		DWORD Stdlib;
	};

	// Virtual Method Table Indexes
	namespace VMT
	{
		//CHL Client
		DWORD CHL_GetAllClasses;

		//Engine Client
		DWORD Engine_GetScreenSize;
		DWORD Engine_GetPlayerInfo;
		DWORD Engine_GetLocalPlayer;
		DWORD Engine_Time;
		DWORD Engine_GetViewAngles;
		DWORD Engine_SetViewAngles;
		DWORD Engine_GetMaxClients;
		DWORD Engine_IsConnected;
		DWORD Engine_IsInGame;
		DWORD Engine_WorldToScreenMatrix;
		DWORD Engine_ClientCmd_Unrestricted;

		// Panels
		DWORD Panel_GetName;
		DWORD Panel_PaintTraverse;

		// Surface
		DWORD Surface_DrawSetColorA;
		DWORD Surface_DrawSetColorB;
		DWORD Surface_DrawFilledRect;
		DWORD Surface_DrawOutlinedRect;
		DWORD Surface_DrawLine;
		DWORD Surface_DrawSetTextFont;
		DWORD Surface_DrawSetTextColorA;
		DWORD Surface_DrawSetTextColorB;
		DWORD Surface_DrawSetTextPos;
		DWORD Surface_DrawPrintText;
		DWORD Surface_DrawSetTextureRGBA;
		DWORD Surface_DrawSetTexture;
		DWORD Surface_CreateNewTextureID;
		DWORD Surface_FontCreate;
		DWORD Surface_SetFontGlyphSet;
		DWORD Surface_GetTextSize;
		DWORD Surface_DrawOutlinedCircle;
		DWORD Surface_SurfaceGetCursorPos;
		DWORD Surface_DrawTexturedPolygon;

		DWORD Material_GetName;
		DWORD Material_SetMaterialVarFlag;
		DWORD Material_GetMaterialVarFlag;
		DWORD Material_AlphaModulate;
		DWORD Material_ColorModulate;
		DWORD Material_IncrementReferenceCount;

		DWORD MaterialSystem_FindMaterial;
		DWORD MaterialSystem_CreateMaterial;

		DWORD ModelRender_ForcedMaterialOverride;
		DWORD ModelRender_DrawModelExecute;

		DWORD ModelInfo_GetModelName;
		DWORD ModelInfo_GetStudiomodel;

		DWORD RenderView_SetBlend;
		DWORD RenderView_SetColorModulation;

		// Weapon entities
		DWORD Weapon_GetSpread;
	};

	// Addresses of engine functions to call
	namespace Functions
	{
		DWORD KeyValues_KeyValues;
		DWORD KeyValues_LoadFromBuffer;
		DWORD dwCalcPlayerView;
	};

};