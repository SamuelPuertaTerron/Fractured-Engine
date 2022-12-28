#pragma once
#include "FVector2.h"

namespace FracturedInternal::Math
{
	class FRandom
	{
	public:
		static int RandomNumber(int range);
		static int RandomNumberInRange(int low, int high);

		static float RandomNumber(float range);
		static float RandomNumberInRange(float low, float high);
	private:
		static double GenerateRandomNumber(double range);
		static double GenerateRandomNumberRange(double low, double high);
	};
}


