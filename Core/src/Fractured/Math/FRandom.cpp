#include "frpch.h"
#include "FRandom.h"

namespace FracturedInternal::Math
{
	int FRandom::RandomNumber(int range)
	{
		return (int)GenerateRandomNumber(range);
	}
	int FRandom::RandomNumberInRange(int low, int high)
	{
		return (int)GenerateRandomNumberRange(low, high);
	}
	float FRandom::RandomNumber(float range)
	{
		return (float)GenerateRandomNumber(range);
	}
	float FRandom::RandomNumberInRange(float low, float high)
	{
		return (float)GenerateRandomNumberRange(low, high);
	}

	//Private

	double FRandom::GenerateRandomNumber(double range)
	{
		static std::random_device rd;
		static std::mt19937 value(rd());
		static std::uniform_int_distribution<int> uniform_dist(0, static_cast<int>(range));
		return uniform_dist(value);
	}
	double FRandom::GenerateRandomNumberRange(double low, double high)
	{
		static std::random_device rd;
		static std::mt19937 value(rd());
		static std::uniform_int_distribution<int> uniform_dist(static_cast<int>(low), static_cast<int>(high));
		return uniform_dist(value);
	}
}