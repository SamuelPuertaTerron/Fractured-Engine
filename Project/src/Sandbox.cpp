#include "Sandbox.h"

namespace Sandbox
{
	WindowSettings Sandbox::GetWindowSettings()
	{
		WindowSettings windowSettings;
		windowSettings.title = "Fractured Application";
		windowSettings.windowSettingsInternal.displayFps = true;
		return windowSettings;
	}

	void Sandbox::OnAppCreate()
	{

	}
	void Sandbox::OnAppUpdate()
	{
		
	}
	void Sandbox::OnAppRender()
	{

	}
}


