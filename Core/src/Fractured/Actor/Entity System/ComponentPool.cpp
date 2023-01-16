#include "frpch.h"
#include "ComponentPool.h"

#include "Fractured/Core/FLogger.h"

namespace FracturedInternal::EntitySystem
{
	ComponentPool::ComponentPool(size_t elementSize)
	{
		mElementSize = elementSize;
		if(elementSize > MAX_ENTITIES)
		{
			FR_LOG_ERROR("Entities has reached it max. Can only have: ", MAX_ENTITIES + " Entities");
		}
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
