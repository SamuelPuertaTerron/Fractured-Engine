#pragma once

namespace FracturedInternal
{
	struct FColour
	{
	public:
		float r;
		float g;
		float b;
		float a;

		FColour() = default;
		FColour(float r, float g, float b);
		FColour(float r, float g, float b, float a);
	};
}


