#pragma once

#include "../frpch.h"
#include "FWindow.h"
#include "FApp.h"

namespace FracturedInternal
{
	class FEngine
	{
	public:
		~FEngine() = default;

		static std::unique_ptr<FEngine> &GetInstance();

		void Run(const std::shared_ptr<FApp> app);
	private:
		FEngine() = default;

		std::unique_ptr<FWindow> mWindow;
		std::shared_ptr<FApp > mApp;
	private:
		static std::unique_ptr<FEngine> sInstance;
	};
}


