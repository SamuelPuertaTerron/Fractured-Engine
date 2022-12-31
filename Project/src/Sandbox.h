#pragma once
#include "Fractured.h"

using namespace Fractured;

namespace Sandbox
{
	class Sandbox : public Application
	{
	public:
		Sandbox() = default;
		virtual ~Sandbox() = default;

	protected:
		WindowSettings GetWindowSettings() override;
		void OnAppCreate() override;
		void OnAppUpdate(float DeltaTime) override;
		void OnAppRender() override;
	private:
	};
}

std::shared_ptr<FApp> CreateApp()
{
	return std::make_shared<Sandbox::Sandbox>();
}
