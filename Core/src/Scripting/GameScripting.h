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
		enum class FMouseCode;
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

	namespace Physics
	{
		class FCollisions;
	}
}

namespace Fractured
{
	//Generic
	using Engine = FracturedInternal::FEngine;
	using Application = FracturedInternal::FApp;
	using InputManager = FracturedInternal::Input::FInputManager;
	using GameObject = FracturedInternal::Actor::FActor;
	using Collision = FracturedInternal::Physics::FCollisions;

	using KeyCode = FracturedInternal::Input::FKeyCode;
	using MouseCode = FracturedInternal::Input::FMouseCode;

	using Colour = FracturedInternal::FColour;

	//Math
	using Vector2 = FracturedInternal::Math::FVector2;
	using Vector3 = FracturedInternal::Math::FVector3;
	using Random = FracturedInternal::Math::FRandom;


	//Components
	using TransformComponent = FracturedInternal::Actor::TransformComponent;
	using RenderComponent = FracturedInternal::Actor::RenderComponent;
	using BoxColliderComponent = FracturedInternal::Actor::BoxColliderComponent;
	using RigidbodyComponent = FracturedInternal::Actor::RigidbodyComponent;
}
