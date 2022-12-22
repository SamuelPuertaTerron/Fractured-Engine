#include "FEngine.h"

#include "glad/glad.h"

#include "FLogger.h"
#include "Fractured/Rendering/RenderManager.h"


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
		FR_LOG_INFO("Version: ", mVersion);

		mApp = app;

		glfwInit();

		mWindow = std::make_unique<FWindow>();

		mRenderingManager = std::make_unique<Render::FRenderingManager>();

		bDisplayFps = mApp->GetWindowSettings().windowSettingsInternal.displayFps;

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

					mRenderingManager->BeginRender();
					app->OnAppRender();
					mRenderingManager->EndRender();

					

					if(bDisplayFps)
					{
						DisplayFPS();
					}
				}
			}
		}
	}
	void FEngine::DisplayFPS() const
	{
		static int frames = 0;
		static double lastTime = 0;
		double currentTime = glfwGetTime();
		frames++;
		if (currentTime - lastTime >= 1.0) 
		{
			FR_LOG("FPS: ", std::to_string(frames));
			frames = 0;
			lastTime = currentTime;
		}
	}
}
