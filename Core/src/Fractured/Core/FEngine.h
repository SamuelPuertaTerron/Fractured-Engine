#pragma once

#include "../../frpch.h"
#include "FWindow.h"
#include "FApp.h"

namespace FracturedInternal
{
	namespace Render
	{
		class FRenderingManager;
	}

	class FEngine
	{
	public:
		~FEngine() = default;

		static std::unique_ptr<FEngine> &GetInstance();

		void Run(const std::shared_ptr<FApp> app);

		std::unique_ptr<FWindow> &GetWindow() { return mWindow; }
	private:
		FEngine() = default;

		void DisplayFPS() const;
	private:
		static std::unique_ptr<FEngine> sInstance;

		std::unique_ptr<FWindow> mWindow;
		std::shared_ptr<FApp > mApp;
		std::unique_ptr<Render::FRenderingManager> mRenderingManager;

		std::string mVersion = "0.0.1";
		bool bDisplayFps = false;
	};
}


