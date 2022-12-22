#include "RenderManager.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "Fractured/Core/FEngine.h"
#include "Fractured/Rendering/FColour.h"

namespace FracturedInternal::Render
{
	void FRenderingManager::BeginRender(FColour clearColour)
	{
		glClearColor(clearColour.r, clearColour.g, clearColour.b, clearColour.a);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void FRenderingManager::EndRender()
	{
		glfwSwapBuffers(FEngine::GetInstance()->GetWindow()->mGlfwWindow);
	}
	

}
