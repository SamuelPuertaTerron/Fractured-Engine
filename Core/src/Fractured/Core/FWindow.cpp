#include "FWindow.h"

#include "glad/glad.h"

namespace FracturedInternal
{
	bool FWindow::WindowInit(const WindowSettings& settings)
	{
		glfwWindowHint(GLFW_SAMPLES, 4); // anti aliasing
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // openGL major version to be 3
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); // minor set to 3, which makes the version 3.3
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // for MAC OS only
		glfwWindowHint(GLFW_OPENGL_COMPAT_PROFILE, GLFW_OPENGL_CORE_PROFILE); //avoid using old openGL

		mGlfwWindow = glfwCreateWindow(settings.width, settings.height, settings.title.c_str(), nullptr, nullptr);
		if (!mGlfwWindow)
			return false;

		glfwMakeContextCurrent(mGlfwWindow);

		return true;
	}

}
