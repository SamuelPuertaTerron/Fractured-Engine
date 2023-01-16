#pragma once
#include "Fractured.h"

using namespace Fractured;

namespace Sandbox
{
	class Sandbox : public Application
	{
	public:
		Sandbox()  = default;
		virtual ~Sandbox() = default;

	protected:
		/**
		 * \brief Return the WindowSettings used to Created the Window.
		 */
		WindowSettings GetWindowSettings() override;
		/**
		 * \brief Is Performed before at the start of the application.
		 */
		void OnAppCreate()				   override;
		/**
		 * \brief Runs every frame, where the main logic is handled.
		 * \param DeltaTime the time between frames.
		 */
		void OnAppUpdate(float DeltaTime)  override;
		/**
		 * \brief Runs every frame, where rendering Text can be handled.
		 */
		void OnAppRender()				   override;
		/**
		 * \brief Runs before the application is Closed. 
		 */
		void OnAppQuit()				   override;
	private:
		GameObject object;
		GameObject object2;
		GameObject object3;
	};
}

std::shared_ptr<FApp> CreateApp()
{
	return std::make_shared<Sandbox::Sandbox>();
}
