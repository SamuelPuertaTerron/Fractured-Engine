#pragma once
#include <memory>
#include <string>

#include "GLFW/glfw3.h"

namespace FracturedInternal
{
	struct WindowSettingsInternal
	{
		bool displayFps = false;
		bool capFps = true;
	};

	struct WindowSettings
	{
		std::string title = "Frctured Application";
		int width = 1270;
		int height = 720;
		WindowSettingsInternal windowSettingsInternal = WindowSettingsInternal();
	};

	class FWindow
	{
	public:
		bool WindowInit(const WindowSettings& settings);
	public:
		GLFWwindow* mGlfwWindow;
	private:
	};
}
