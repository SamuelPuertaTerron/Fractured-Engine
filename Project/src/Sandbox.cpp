#include "Sandbox.h"

#include "Fractured/Actor/FActor.h"
#include "Fractured/Input/FInputManager.h"
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
		windowSettings.canResize = true;
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
	void Sandbox::OnAppQuit()
	{
		FR_LOG_INFO("Quitting Application: ", GetWindowSettings().title);
	}
}


