#pragma once

#include "FWindow.h"

namespace FracturedInternal
{
	class FApp
	{
	public:
		virtual WindowSettings GetWindowSettings() { return mWindowSettings; }

		virtual void OnAppCreate() = 0;
		virtual void OnAppUpdate() = 0;
		virtual void OnAppRender() = 0;

	private:
		WindowSettings mWindowSettings;
	};
}


