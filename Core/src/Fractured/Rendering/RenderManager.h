#pragma once
#include "FColour.h"
#include "Shader.h"
#include "Texture.h"
#include "SpriteRenderer.h"

namespace FracturedInternal
{
	struct FColour;
}

namespace FracturedInternal::Render
{
	class SpriteRenderer;

	class FRenderingManager
	{
	public:
		FRenderingManager() = default;
		~FRenderingManager() = default;

		void BeginRender(FColour clearColour);
		void EndRender();

		void GetAllTexturesFromFolder();

		FColour GetClearColour() { return mClearColour; }
		void SetClearColour(const FColour colour) { mClearColour = colour; }

		void CreateShader();

		[[nodiscard]] Texture GetTexture(int index) const { return mTextures[index]; }
		[[nodiscard]] Shader GetSpriteShader() const { return mSpriteShader; }
	private:
		Shader mSpriteShader;
		std::vector<Texture> mTextures;
		FColour mClearColour = FColour(0.1f, 0.1f, 0.1f);
	};
}

