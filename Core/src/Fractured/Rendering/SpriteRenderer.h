#pragma once

#include "RenderManager.h"
#include "Texture.h"
#include "Fractured/Math/FVector2.h"
#include "Fractured/Math/FVector3.h"

namespace FracturedInternal::Render
{
	//Uses Batch Rendering for sprites
	class SpriteRenderer
	{
	public:
		SpriteRenderer() = default;
		~SpriteRenderer();

		void BuildShape();
		void RenderShape(Math::FVector2 position, Math::FVector3 rotation, Math::FVector2 scale, Texture texture);
	public:
		int32 mVBO, mVAO;
	private:
	};
}


