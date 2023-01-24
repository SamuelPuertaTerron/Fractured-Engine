#pragma once

#include "FRenderManager.h"
#include "FTexture.h"
#include "Fractured/Math/FVector2.h"
#include "Fractured/Math/FVector3.h"

namespace FracturedInternal::Render
{
	//Uses Batch Rendering for sprites
	class FSpriteRenderer
	{
	public:
		FSpriteRenderer() = default;
		~FSpriteRenderer();

		void BuildShape();
		void RenderShape(Math::FVector2 position, Math::FVector3 rotation, Math::FVector2 scale, FTexture texture);
	public:
		fint32 mVBO, mVAO;
	private:
	};
}


