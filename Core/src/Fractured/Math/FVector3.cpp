#include "frpch.h"
#include "FVector3.h"

namespace FracturedInternal::Math
{

	FVector3::FVector3()
	{
		this->x = 0;
		this->y = 0;
		this->z = 0;
	}

	FVector3::FVector3(float x, float y, float z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}
}