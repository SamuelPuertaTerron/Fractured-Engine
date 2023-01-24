#pragma once

#include "Fractured/Actor/Entity System/EntityManager.h"

namespace FracturedInternal
{
	namespace Math
	{
		struct FVector2;
	}
}

namespace FracturedInternal
{
	namespace Actor
	{
		class FActor;
	}
}

namespace FracturedInternal::Scene
{
	class FScene
	{
	public:
		FScene();
		~FScene();

		void Start();
		void Update();
		void Render();

		EntitySystem::EntityId CreateEntity() const;
		void DestroyEntity(Actor::FActor actor) const;

		void SpawnEntity(Actor::FActor actor) const;
		void SpawnEntity(Actor::FActor actor, Math::FVector2 position) const;

		EntitySystem::EntityManager* GetEntityManager() const { return mEntityManager; }
	private:
		EntitySystem::EntityManager* mEntityManager;
	};
}


