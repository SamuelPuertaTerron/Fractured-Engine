#pragma once
#include "Fractured/Math/FVector2.h"

namespace FracturedInternal::Actor
{
	//Base Component Class
	struct Component
	{
		Component() = default;
	};

	struct TransformComponent : Component
	{
		Math::FVector2 Position;
	};

	struct RenderComponent : Component
	{
		
	};
}

