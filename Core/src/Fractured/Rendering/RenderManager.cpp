#include "frpch.h"
#include "RenderManager.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "stb_image.h"

#include "Fractured/Core/FEngine.h"
#include "Fractured/Core/FLogger.h"
#include "Fractured/Rendering/FColour.h"

namespace FracturedInternal::Render
{
	void FRenderingManager::CreateShader()
	{
		mSpriteShader = Shader();

		mSpriteShader.BuildShader("Resources\\Shaders\\sprite.vert",
			"Resources\\Shaders\\sprite.frag");
	}


	void FRenderingManager::BeginRender(FColour clearColour)
	{
		glClearColor(clearColour.r, clearColour.g, clearColour.b, clearColour.a);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		mSpriteShader.ActivateShader();
	}

	void FRenderingManager::EndRender()
	{
		glfwSwapBuffers(FEngine::GetInstance()->GetWindow()->GetGLFWWindow());
	}

	void FRenderingManager::GetAllTexturesFromFolder()
	{
		const std::string& path = "Resources\\Sprites";

		for (const auto& entry : std::filesystem::directory_iterator(path))
		{
			Texture texture;

			FR_LOG("Path: ", entry.path().string());

			int width, height, nrChannels = 4;

			stbi_set_flip_vertically_on_load(true);

			unsigned char* data = stbi_load(entry.path().string().c_str(), &width, &height, &nrChannels, STBI_rgb_alpha);
			texture.Generate(width, height, data);

			mTextures.push_back(texture);

			stbi_image_free(data);
		}
	}

}
