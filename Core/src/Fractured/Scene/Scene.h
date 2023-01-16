#pragma once

#include "Fractured/Actor/Entity System/EntityManager.h"

namespace FracturedInternal
{
	namespace Actor
	{
		class FActor;
	}
}

namespace FracturedInternal::Scene
{
	class Scene
	{
	public:
		Scene();
		~Scene();

		void Start();
		void Update();
		void Render();

		EntitySystem::EntityId CreateEntity() const;
		void DestroyEntity(Actor::FActor actor) const;

		EntitySystem::EntityManager* GetEntityManager() const { return mEntityManager; }
	private:
		EntitySystem::EntityManager* mEntityManager;
	};
}


