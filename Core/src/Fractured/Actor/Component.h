#pragma once
#include "Fractured/Math/FVector2.h"
#include "Fractured/Rendering/SpriteRenderer.h"

namespace FracturedInternal::Actor
{
	using namespace Math;
	using namespace Render;

	struct TransformComponent
	{
		FVector2 Position = FVector2(0.0f, 0.0f);
		FVector3 Rotation = FVector3(0.0f, 0.0f, 0.0f);;
		FVector2 Scale = FVector2(1.0f, 1.0f);

		TransformComponent() = default;
		TransformComponent(FVector2 position, FVector3 rotation, FVector2 scale) : Position(position), Rotation(rotation), Scale(scale) {};
	};

	struct RenderComponent
	{
		Texture Sprite;

		RenderComponent() = default;
		RenderComponent(Texture sprite) : Sprite(sprite) {}
	};
}

