#include "frpch.h"
#include "ComponentPool.h"

namespace FracturedInternal::EntitySystem
{
	ComponentPool::ComponentPool(size_t elementSize)
	{
		mElementSize = elementSize;
		mData = new char[elementSize * MAX_ENTITIES];
	}

	ComponentPool::~ComponentPool()
	{
		delete[] mData;
	}

	void* ComponentPool::Get(size_t index) const
	{
		return mData + index * mElementSize;
	}
}
