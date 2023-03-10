#pragma once
#include <memory>
#include <string>

#include "GLFW/glfw3.h"

namespace FracturedInternal
{
	struct WindowSettingsInternal
	{
		bool displayFps = false;
	};

	struct WindowSettings
	{
		std::string title = "Frctured Application";
		int width = 1270;
		int height = 720;
		bool vsync = true;
		bool canResize = true;
		WindowSettingsInternal windowSettingsInternal = WindowSettingsInternal();
	};

	class FWindow
	{
	public:
		bool WindowInit(const WindowSettings& settings);

		void Destroy();

		GLFWwindow* GetGLFWWindow() const { return mGlfwWindow; }

	private:
		GLFWwindow* mGlfwWindow;
	private:
		void WindowResize();
	};
}
