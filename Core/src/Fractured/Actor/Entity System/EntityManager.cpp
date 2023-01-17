#include "frpch.h"
#include "EntityManager.h"
#include <Fractured/Actor/Component.h>

using namespace FracturedInternal::Actor;


namespace FracturedInternal::EntitySystem
{
	EntityManager::~EntityManager()
	{
		mComponentPools.clear();
		mFreeEntities.clear();
		mEntities.clear();
	}

	EntityId EntityManager::CreateEntity()
	{
		//Reuse old entity if deleted
		if(!mFreeEntities.empty())
		{
			const EntityIndex newIndex = mFreeEntities.back();
			mFreeEntities.pop_back();
			EntityId newId = CreateEntityId(newIndex, GetEntityVersion(mEntities[newIndex].id));
			mEntities[newIndex].id = newId;
			return mEntities[newIndex].id;
		}

		mEntities.push_back({ mEntities.size(), ComponentMask() });
		Assign<TransformComponent>(mEntities.back().id);
		return mEntities.back().id;
	}

	void EntityManager::DestroyEntity(EntityId id)
	{
		const EntityId newId = CreateEntityId(static_cast<EntityIndex>(-1), GetEntityVersion(id) + 1);
		mEntities[GetEntityIndex(id)].id = newId;

		mEntities[GetEntityIndex(id)].mask.reset();
		mFreeEntities.push_back(GetEntityIndex(id));
	}
}