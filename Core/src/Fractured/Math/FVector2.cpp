#include "frpch.h"
#include "FVector2.h"

namespace FracturedInternal::Math
{
	FVector2::FVector2()
	{
		this->x = 0;
		this->y = 0;
	}

	FVector2::FVector2(float x, float y)
	{
		this->x = x;
		this->y = y;
	}
}