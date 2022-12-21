#pragma once
#include "Fractured/Fractured.h"

using namespace FracturedInternal;

namespace Sandbox
{
	class Sandbox : public FApp
	{
	public:
		Sandbox() = default;
		virtual ~Sandbox() = default;

	public:
		WindowSettings GetWindowSettings() override;
		void OnAppCreate() override;
		void OnAppUpdate() override;
		void OnAppRender() override;
	};


}

std::shared_ptr<FApp> CreateApp()
{
	return std::make_shared<Sandbox::Sandbox>();
}
