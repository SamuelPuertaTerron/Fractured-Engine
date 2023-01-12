#include "frpch.h"
#include "FWindow.h"

#include "FLogger.h"
#include "glad/glad.h"

namespace FracturedInternal
{
	bool FWindow::WindowInit(const WindowSettings& settings)
	{
		glfwDefaultWindowHints();
		glfwWindowHint(GLFW_SAMPLES, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); 
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_COMPAT_PROFILE, GLFW_OPENGL_CORE_PROFILE); 

		if (settings.canResize)
		{
			glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);
		}
		else
		{
			glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
		}

		mGlfwWindow = glfwCreateWindow(settings.width, settings.height, settings.title.c_str(), nullptr, nullptr);

		if (!mGlfwWindow)
		{
			FR_LOG_ERROR("Failed to create GLFW Window!");
			return false;
		}

		glfwMakeContextCurrent(mGlfwWindow);

		if (settings.vsync)
		{
			glfwSwapInterval(1);
		}
		else
		{
			glfwSwapInterval(0);
		}

		WindowResize();

		return true;
	}

	void FWindow::Destroy()
	{
		glfwDestroyWindow(mGlfwWindow);
	}

	void FWindow::WindowResize()
	{
		glfwSetWindowSizeCallback(mGlfwWindow, [](GLFWwindow* window, int width, int height)
		{
				glViewport(0, 0, width, height);
		});
	}
}
