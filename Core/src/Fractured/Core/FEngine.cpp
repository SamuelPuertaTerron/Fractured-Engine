#include "frpch.h"
#include "FEngine.h"

#include "glad/glad.h"

#include "FLogger.h"
#include "imgui.h"
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
		mSpriteRenderer = std::make_unique<Render::SpriteRenderer>();
		mScene = std::make_shared<Scene::Scene>();
		mPhysicsManager = std::make_unique<Physics::PhysicsManager>();

		bDisplayFps = mApp->GetWindowSettings().windowSettingsInternal.displayFps;

		if(mWindow->WindowInit(mApp->GetWindowSettings()))
		{
			if (gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
			{
				mRenderingManager->CreateShader();
				mSpriteRenderer->BuildShape();

				mRenderingManager->GetAllTexturesFromFolder();

				mPhysicsManager->Init();

				glEnable(GL_BLEND);
				glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
				glViewport(0, 0, app->GetWindowSettings().width, app->GetWindowSettings().height);

				app->OnAppCreate();

				while (!glfwWindowShouldClose(mWindow->GetGLFWWindow()))
				{
					float const time = static_cast<float>(glfwGetTime());
					mDeltaTime = time - mLastFrameTime;
					mLastFrameTime = time;

					mRenderingManager->BeginRender(mRenderingManager->GetClearColour());

					mScene->Update();
					app->OnAppUpdate(mDeltaTime);

					glfwPollEvents();

					app->OnAppRender();
					mScene->Render();

					mRenderingManager->EndRender();
					
					if(bDisplayFps)
					{
						DisplayFPS();
					}
				}
			}
		}

		mApp->OnAppQuit();

		Quit();
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

	void FEngine::Quit()
	{
		mScene.reset();
		mRenderingManager.reset();
		mSpriteRenderer.reset();

		mWindow->Destroy();
		mWindow.reset();
		mApp.reset();
		glfwTerminate();
	}
}
