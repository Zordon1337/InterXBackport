#include "Visuals.h"
#include "Interfaces.h"
#include "RenderManager.h"

// Any init here
void CVisuals::Init()
{
	// Idk
}

// Don't really need to do anything in here
void CVisuals::Move(CUserCmd *pCmd, bool& bSendPacket) {}

// Main ESP Drawing loop
void CVisuals::Draw()
{
	if (Menu::Window.VisualsTab.OtherCrosshairType.GetIndex() == 0)
		Interfaces::Engine->ClientCmd_Unrestricted("crosshair 1");

	if (!hackManager.pLocal())
		return;

	// Crosshair
	if (Menu::Window.VisualsTab.OtherCrosshairType.GetIndex() > 0)
	{
		Interfaces::Engine->ClientCmd_Unrestricted("crosshair 0");

		if (Menu::Window.VisualsTab.OtherCrosshairType.GetIndex() == 1)
			DrawCrosshair();

		if (Menu::Window.VisualsTab.OtherCrosshairType.GetIndex() == 2)
			DrawRecoilCrosshair();
	}
}

// Draw a basic crosshair
void CVisuals::DrawCrosshair()
{
	// Crosshair
	RECT View = Render::GetViewport();
	int MidX = View.right / 2;
	int MidY = View.bottom / 2;

	if (Menu::Window.VisualsTab.OtherCrosshair.GetIndex() == 0)
	{
		Render::Line(MidX - 8, MidY - 8, MidX + 8, MidY + 8, Color(255, 0, 0, 255));
		Render::Line(MidX + 8, MidY - 8, MidX - 8, MidY + 8, Color(255, 0, 0, 255));
		Render::Line(MidX - 4, MidY - 4, MidX + 4, MidY + 4, Color(255, 0, 0, 255));
		Render::Line(MidX + 4, MidY - 4, MidX - 4, MidY + 4, Color(255, 0, 0, 255));
	}
	else if (Menu::Window.VisualsTab.OtherCrosshair.GetIndex() == 1)
	{
		Render::Line(MidX - 10, MidY, MidX + 10, MidY, Color(255, 0, 0, 255));
		Render::Line(MidX, MidY - 10, MidX, MidY + 10, Color(255, 0, 0, 255));
	}
	else if (Menu::Window.VisualsTab.OtherCrosshair.GetIndex() == 2)
	{
		Render::DrawCircle(MidX - 5, MidY - 5, 10, 10, Color(255, 0, 0, 255));
	}
	else if (Menu::Window.VisualsTab.OtherCrosshair.GetIndex() == 3)
	{
		Render::Outline(MidX - 5, MidY - 5, 10, 10, Color(255, 0, 0, 255));
	}

}

// Recoil crosshair
void CVisuals::DrawRecoilCrosshair()
{
	IClientEntity *pLocal = hackManager.pLocal();

	// Get the view with the recoil
	Vector ViewAngles;
	Interfaces::Engine->GetViewAngles(ViewAngles);
	ViewAngles += pLocal->localPlayerExclusive()->GetAimPunchAngle() * 2.f;

	// Build a ray going fowards at that angle
	Vector fowardVec;
	AngleVectors(ViewAngles, &fowardVec);
	fowardVec *= 10000;

	// Get ray start / end
	Vector start = pLocal->GetOrigin() + pLocal->GetViewOffset();
	Vector end = start + fowardVec, endScreen;

	if (Render::WorldToScreen(end, endScreen) && pLocal->IsAlive())
	{
		if (Menu::Window.VisualsTab.OtherCrosshair.GetIndex() == 0)
		{
			Render::Line(endScreen.x - 4, endScreen.y - 4, endScreen.x + 4, endScreen.y + 4, Color(255, 0, 0, 255));
			Render::Line(endScreen.x + 4, endScreen.y - 4, endScreen.x - 4, endScreen.y + 4, Color(255, 0, 0, 255));
			Render::Line(endScreen.x - 2, endScreen.y - 2, endScreen.x + 2, endScreen.y + 2, Color(255, 0, 0, 255));
			Render::Line(endScreen.x + 2, endScreen.y - 2, endScreen.x - 2, endScreen.y + 2, Color(255, 0, 0, 255));
		}
		else if (Menu::Window.VisualsTab.OtherCrosshair.GetIndex() == 1)
		{
			Render::Line(endScreen.x - 10, endScreen.y, endScreen.x + 10, endScreen.y, Color(255, 0, 0, 255));
			Render::Line(endScreen.x, endScreen.y - 10, endScreen.x, endScreen.y + 10, Color(255, 0, 0, 255));
		}
		else if (Menu::Window.VisualsTab.OtherCrosshair.GetIndex() == 2)
		{
			Render::DrawCircle(endScreen.x - 5, endScreen.y - 5, 10, 10, Color(255, 0, 0, 255));
		}
		else if (Menu::Window.VisualsTab.OtherCrosshair.GetIndex() == 3)
		{
			Render::Outline(endScreen.x - 5, endScreen.y - 5, 10, 10, Color(255, 0, 0, 255));
		}
	}
}
