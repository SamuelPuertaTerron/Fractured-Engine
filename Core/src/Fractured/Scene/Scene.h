#pragma once

#include "Fractured/Actor/Entity System/EntityManager.h"

namespace FracturedInternal::Scene
{
	class Scene
	{
	public:
		Scene();
		~Scene();

		void Update();
		void Render();

		EntitySystem::EntityManager* GetEntityManager() const { return mEntityManager; }
	private:
		EntitySystem::EntityManager* mEntityManager;
	};
}


