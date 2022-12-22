#pragma once
#include "FColour.h"

namespace FracturedInternal
{
	struct FColour;
}

namespace FracturedInternal::Render
{
	class FRenderingManager
	{
	public:
		FRenderingManager() = default;
		~FRenderingManager() = default;

		void BeginRender(FColour clearColour = FracturedInternal::FColour(0.1f, 0.1f, 0.1f));
		void EndRender();
	private:

	};
}

