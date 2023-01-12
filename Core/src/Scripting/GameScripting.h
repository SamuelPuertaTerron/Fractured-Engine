#pragma once
#include "Fractured/Core/FEngine.h"
#include "Fractured/Core/FApp.h"

#include "Fractured/Input/FInputManager.h"
#include "Fractured/Actor/FActor.h"
#include "Fractured/Actor/Component.h"

#include "Fractured/Core/FLogger.h"

// ----- Entry Point ----- //
#include "Main.h"
// ----------------------- //

namespace FracturedInternal
{
	class FApp;
	class FEngine;

	struct FColour;

	namespace Input
	{
		enum class FKeyCode;
		class FInputManager;
	}

	namespace Actor
	{
		class FActor;

		//Components
		struct TransformComponent;
		struct RenderComponent;
		struct BoxColliderComponent;
		struct RigidbodyComponent;
	}

}

namespace Fractured
{
	//Generic
	using Engine = FracturedInternal::FEngine;
	using Application = FracturedInternal::FApp;
	using InputManager = FracturedInternal::Input::FInputManager;
	using GameObject = FracturedInternal::Actor::FActor;

	using KeyCode = FracturedInternal::Input::FKeyCode;

	using Colour = FracturedInternal::FColour;

	//Components
	using TransformComponent = FracturedInternal::Actor::TransformComponent;
	using RenderComponent = FracturedInternal::Actor::RenderComponent;
	using BoxColliderComponent = FracturedInternal::Actor::BoxColliderComponent;
	using RigidbodyComponent = FracturedInternal::Actor::RigidbodyComponent;
}
