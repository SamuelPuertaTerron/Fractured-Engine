#pragma once

namespace FracturedInternal::EntitySystem
{
	typedef unsigned int EntityIndex;
	typedef unsigned int EntityVersion;
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

	inline EntityId CreateEntityId(EntityIndex index, EntityVersion version)
	{
		// Shift the index up 32, and put the version in the bottom
		return (static_cast<EntityId>(index) << 32) | (static_cast<EntityId>(version));
	}
	inline EntityIndex GetEntityIndex(EntityId id)
	{
		// Shift down 32 so we lose the version and get our index
		return id >> 32;
	}
	inline EntityVersion GetEntityVersion(EntityId id)
	{
		// Cast to a 32 bit int to get our version number (loosing the top 32 bits)
		return static_cast<EntityVersion>(id);
	}
	inline bool IsEntityValid(EntityId id)
	{
		// Check if the index is our invalid index
		return (id >> 32) != static_cast<EntityIndex>(-1);
	}

	#define INVALID_ENTITY CreateEntityId(EntityIndex(-1), 0)
}


