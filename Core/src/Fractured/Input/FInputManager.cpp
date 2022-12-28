#include "frpch.h"
#include "FInputManager.h"

#include "Fractured/Core/FEngine.h"
#include "GLFW/glfw3.h"

namespace FracturedInternal::Input
{
	//Public 

	bool FInputManager::IsKeyPressed(const FKeyCode key)
	{
		return KeyPress(key);
	}
	bool FInputManager::IsMouseButtonPressed(const FMouseCode mouse)
	{
		return MousePress(mouse);
	}

	void FInputManager::SetShowMouseCursor(const bool value)
	{
		if (value)
			glfwSetInputMode(FEngine::GetInstance()->GetWindow()->GetGLFWWindow(), GLFW_CURSOR, GLFW_CURSOR_NORMAL);
		else if (!value)
			glfwSetInputMode(FEngine::GetInstance()->GetWindow()->GetGLFWWindow(), GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
	}


	//Private

	bool FInputManager::KeyPress(const FKeyCode key)
	{
		return glfwGetKey(FEngine::GetInstance()->GetWindow()->GetGLFWWindow(), static_cast<int>(key));
	}
	bool FInputManager::MousePress(const FMouseCode mouse)
	{
		return glfwGetMouseButton(FEngine::GetInstance()->GetWindow()->GetGLFWWindow(), static_cast<int>(mouse));
	}
}
