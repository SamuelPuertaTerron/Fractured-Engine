#include "Sandbox.h"

#include "Fractured/Rendering/RenderManager.h"

namespace Sandbox
{
	WindowSettings Sandbox::GetWindowSettings()
	{
		WindowSettings windowSettings;
		windowSettings.title = "Fractured Application";
		windowSettings.width = 1280;
		windowSettings.height = 720;
		windowSettings.vsync = true;
		windowSettings.windowSettingsInternal.displayFps = true;
		return windowSettings;
	}

	void Sandbox::OnAppCreate()
	{

	}
	void Sandbox::OnAppUpdate(float DeltaTime)
	{
		
	}
	void Sandbox::OnAppRender()
	{

	}
}


