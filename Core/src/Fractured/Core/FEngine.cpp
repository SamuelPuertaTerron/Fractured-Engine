#include "FEngine.h"

#include "glad/glad.h"

namespace FracturedInternal
{
	std::unique_ptr<FEngine> FEngine::sInstance;

	std::unique_ptr<FEngine> &FEngine::GetInstance()
	{
		if(!sInstance)
		{
			sInstance.reset(new FEngine());
		}

		return sInstance;
	}

	void FEngine::Run(const std::shared_ptr<FApp> app)
	{
		mApp = app;

		glfwInit();

		mWindow = std::make_unique<FWindow>();

		if(mWindow->WindowInit(mApp->GetWindowSettings()))
		{
			if (gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
			{
				glViewport(0, 0, app->GetWindowSettings().width, app->GetWindowSettings().height);

				app->OnAppCreate();

				while (!glfwWindowShouldClose(mWindow->mGlfwWindow))
				{
					app->OnAppUpdate();
					glfwPollEvents();
					glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
					glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
					app->OnAppRender();
					glfwSwapBuffers(mWindow->mGlfwWindow);
				}
			}
		}
	}
}
