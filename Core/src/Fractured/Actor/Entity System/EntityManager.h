#pragma once
#include "ComponentPool.h"
#include "Entity.h"
#include "Fractured/Core/FLogger.h"

namespace FracturedInternal::EntitySystem
{
	struct EntityDesc
	{
		EntityId id;
		ComponentMask mask;
	};

	class EntityManager
	{
	public:
		EntityManager() = default;
		~EntityManager();

		EntityId CreateEntity();
		void DestroyEntity(EntityId id);

		template<typename T>
		T* Assign(EntityId id)
		{
			int componentId = GetId<T>();

			if (mComponentPools.size() <= componentId) //Not Enough component pool
			{
				mComponentPools.resize(componentId + 1);
			}
			if (mComponentPools[componentId] == nullptr)
			{
				mComponentPools[componentId] = new ComponentPool(sizeof(T));
			}

			T* component = new (mComponentPools[componentId]->Get(id)) T();

			mEntities[id].mask.set(componentId);
			return component;
		}
		
		template<typename T>
		T* Get(EntityId id)
		{
			int componentId = GetId<T>();
			if (!mEntities[id].mask.test(componentId))
				return nullptr;

			T* component = static_cast<T*>(mComponentPools[componentId]->Get(id));
			return component;
		}

		template<typename T>
		void Remove(EntityId id)
		{
			// ensures you're not accessing an entity that has been deleted
			if (mEntities[GetEntityIndex(id)].id != id)
			{
				return;
			}

			int componentId = GetId<T>();
			mEntities[GetEntityIndex(id)].mask.reset(componentId);
		}

		std::vector<EntityDesc> GetEntities() const { return mEntities; }

	private:
		std::vector<EntityDesc> mEntities = std::vector<EntityDesc>();
		std::vector<ComponentPool*> mComponentPools = std::vector<ComponentPool*>();

		std::vector<EntityIndex> mFreeEntities;
	};
}

