#include "frpch.h"
#include "FEngine.h"

#include "glad/glad.h"

#include "FLogger.h"
#include "Fractured/Rendering/FRenderManager.h"


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
#ifdef FR_DEBUG
		mGuiWindow = std::make_unique<Core::FGUIWindow>();
#endif
		mRenderingManager = std::make_unique<Render::FRenderingManager>();
		mSpriteRenderer = std::make_unique<Render::FSpriteRenderer>();
		mFScene = std::make_shared<Scene::FScene>();
		mPhysicsManager = std::make_unique<Physics::FPhysicsManager>();

		bDisplayFps = mApp->GetWindowSettings().windowSettingsInternal.displayFps;

		if(mWindow->WindowInit(mApp->GetWindowSettings()))
		{
			if (gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
			{
#ifdef FR_DEBUG
				mGuiWindow->Init();
#endif
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

					mFScene->Update();
					app->OnAppUpdate(mDeltaTime);

					mFScene->Render();
					
					app->OnAppRender();
#ifdef FR_DEBUG
					mGuiWindow->DisplayWindow();
#endif
					glfwPollEvents();
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
	void FEngine::DisplayFPS()
	{
		static int frames = 0;
		static double lastTime = 0;
		double currentTime = glfwGetTime();
		frames++;
		if (currentTime - lastTime >= 1.0) 
		{
			mFrames = frames;
			FR_LOG("FPS: ", std::to_string(frames));
			frames = 0;
			lastTime = currentTime;
		}
	}

	int FEngine::GetFPS()
	{
		return mFrames;
	}


	void FEngine::Quit()
	{
		mFScene.reset();
		mRenderingManager.reset();
		mSpriteRenderer.reset();
#ifdef FR_DEBUG
		mGuiWindow->Destroy();
#endif
		mWindow->Destroy();
		mWindow.reset();
		mApp.reset();
		glfwTerminate();
	}
}
