#pragma once
#include <memory>
#include <string>

#include "GLFW/glfw3.h"

namespace FracturedInternal
{
	struct WindowSettings
	{
		std::string title = "Frctured Application";
		int width = 1270;
		int height = 720;
	};

	class FWindow
	{
	public:
		bool WindowInit(const WindowSettings& settings);
	public:
		GLFWwindow* mGlfwWindow;
	};
}
