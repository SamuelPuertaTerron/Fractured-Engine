#pragma once

namespace FracturedInternal::EntitySystem
{
	typedef unsigned long long EntityId;

	constexpr int MAX_COMPONENTS = 32;
	typedef std::bitset<MAX_COMPONENTS> ComponentMask;

	inline int mComponentCounter = 0;

	template<class T>
	int GetId()
	{
		static int sComponentId = mComponentCounter++;
		return sComponentId;
	}
}


