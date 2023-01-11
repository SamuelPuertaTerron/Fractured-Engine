#pragma once

#include "frpch.h"
#include "FWindow.h"
#include "FGUIWindow.h"
#include "FApp.h"
#include "Fractured/Scene/Scene.h"

namespace FracturedInternal
{
	namespace Render
	{
		class FRenderingManager;
		class SpriteRenderer;
	}

	class FEngine
	{
	public:
		~FEngine() = default;

		static std::unique_ptr<FEngine> &GetInstance();

		void Run(const std::shared_ptr<FApp> app);

		void DisplayFPS() const;

		std::unique_ptr<FWindow> &GetWindow() { return mWindow; }
		std::unique_ptr<Render::FRenderingManager>& GetRenderer() { return mRenderingManager; }
		std::unique_ptr<Render::SpriteRenderer>& GetSpriteRenderer() { return mSpriteRenderer; }
		std::shared_ptr<Scene::Scene> GetScene() { return mScene; }
	private:
		FEngine() = default;
	private:
		static std::unique_ptr<FEngine> sInstance;

		std::unique_ptr<FWindow> mWindow;
		std::shared_ptr<FApp > mApp;
		std::unique_ptr<Render::FRenderingManager> mRenderingManager;
		std::unique_ptr<Render::SpriteRenderer> mSpriteRenderer;
		std::shared_ptr<Scene::Scene> mScene;

		std::string mVersion = "1.0.0";
		bool bDisplayFps = false;

		float mDeltaTime = 0;
		float mLastFrameTime = static_cast<float>(glfwGetTime());
	};
}


