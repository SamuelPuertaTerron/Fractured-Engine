#pragma once
#include "FColour.h"
#include "FShader.h"
#include "FTexture.h"
#include "FSpriteRenderer.h"

namespace FracturedInternal
{
	struct FColour;
}

namespace FracturedInternal::Render
{
	class FSpriteRenderer;

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

		[[nodiscard]] FTexture GetTexture(int index) const { return mTextures[index]; }
		[[nodiscard]] FShader GetSpriteShader() const { return mSpriteShader; }
	private:
		FShader mSpriteShader;
		std::vector<FTexture> mTextures;
		FColour mClearColour = FColour(0.1f, 0.1f, 0.1f);
	};
}

