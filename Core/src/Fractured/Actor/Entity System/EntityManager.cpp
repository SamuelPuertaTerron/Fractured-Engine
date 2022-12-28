#include "frpch.h"
#include "EntityManager.h"
#include <Fractured/Actor/Component.h>

using namespace FracturedInternal::Actor;


namespace FracturedInternal::EntitySystem
{
	EntityId EntityManager::CreateEntity()
	{
		mEntities.push_back({ mEntities.size(), ComponentMask() });
		Assign<TransformComponent>(mEntities.back().id);
		return mEntities.back().id;
	}
}