#pragma once

#include "frpch.h"
#include "FWindow.h"
#include "FGUIWindow.h"
#include "FApp.h"
#include "Fractured/Scene/FScene.h"

#include "Fractured/Physiscs/FPhysicsManager.h"

namespace FracturedInternal
{
	namespace Render
	{
		class FSpriteRenderer;
		class FRenderingManager;
		class SpriteRenderer;
	}

	class FEngine
	{
	public:
		~FEngine() = default;

		static std::unique_ptr<FEngine> &GetInstance();

		void Run(const std::shared_ptr<FApp> app);

		void DisplayFPS();
		void Quit();

		int GetFPS();
		
		std::shared_ptr<FApp> GetApp() { return mApp; }
		std::unique_ptr<FWindow>& GetWindow() { return mWindow; }
		std::unique_ptr<Render::FRenderingManager>& GetRenderer() { return mRenderingManager; }
		std::unique_ptr<Render::FSpriteRenderer>& GetSpriteRenderer() { return mSpriteRenderer; }
		std::shared_ptr<Scene::FScene> GetScene() { return mFScene; }
		std::unique_ptr<Physics::FPhysicsManager>& GetPhysicsManager() { return mPhysicsManager; }
	private:
		FEngine() = default;
	private:
		static std::unique_ptr<FEngine> sInstance;

		std::unique_ptr<FWindow> mWindow;
		std::shared_ptr<FApp > mApp;
#ifdef FR_DEBUG
		std::unique_ptr<Core::FGUIWindow> mGuiWindow;
#endif
		std::unique_ptr<Render::FRenderingManager> mRenderingManager;
		std::unique_ptr<Render::FSpriteRenderer> mSpriteRenderer;
		std::shared_ptr<Scene::FScene> mFScene;
		std::unique_ptr<Physics::FPhysicsManager> mPhysicsManager;


		std::string mVersion = "1.0.0";
		bool bDisplayFps = false;

		float mDeltaTime = 0;
		float mLastFrameTime = static_cast<float>(glfwGetTime());

		int mFrames = 0;
	};
}


