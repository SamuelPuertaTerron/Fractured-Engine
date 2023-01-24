#include "frpch.h"
#include "FScene.h"

#include "Fractured/Core/FEngine.h"
#include "Fractured/Actor/Component.h"
#include "Fractured/Actor/FActor.h"
#include "Fractured/Rendering/FRenderManager.h"

namespace FracturedInternal::Scene
{
	FScene::FScene()
	{
		mEntityManager = new EntitySystem::EntityManager();
	}

	FScene::~FScene()
	{
		delete mEntityManager;
	}


	void FScene::Start()
	{
		//Physics
		{
			for (auto const& entity : mEntityManager->GetEntities())
			{
				if (EntitySystem::IsEntityValid(entity.id))
				{

				}
			}
		}
	}

	void FScene::Update()
	{
		//Physics
		{
			for (auto const& entity : mEntityManager->GetEntities())
			{
				if (EntitySystem::IsEntityValid(entity.id))
				{

				}
			}
		}
	}
	void FScene::Render()
	{
		for (auto const& entity : mEntityManager->GetEntities())
		{
			if(EntitySystem::IsEntityValid(entity.id))
			{
				auto const& render = mEntityManager->Get<Actor::RenderComponent>(entity.id);
				auto const& transform = mEntityManager->Get<Actor::TransformComponent>(entity.id);

				if (render)
					FEngine::GetInstance()->GetSpriteRenderer()->RenderShape(transform->Position, transform->Rotation, transform->Scale, render->Sprite);
			}
		}
	}
	EntitySystem::EntityId FScene::CreateEntity() const
	{
		return mEntityManager->CreateEntity();
	}
	void FScene::DestroyEntity(Actor::FActor actor) const
	{
		mEntityManager->DestroyEntity(actor.id);
	}

	void FScene::SpawnEntity(Actor::FActor actor) const
	{
		Actor::FActor newActor = actor;
		newActor.id = CreateEntity();

		if (actor.HasComponent<Actor::RenderComponent>())
		{
			newActor.AddComponent<Actor::RenderComponent>();
			newActor.GetComponent<Actor::RenderComponent>()->Sprite = actor.GetComponent<Actor::RenderComponent>()->Sprite;
		}
	}
	void FScene::SpawnEntity(Actor::FActor actor, Math::FVector2 position) const
	{
		Actor::FActor newActor = actor;
		newActor.id = CreateEntity();
		newActor.GetTransform()->Position = position;

		if (actor.HasComponent<Actor::RenderComponent>())
		{
			newActor.AddComponent<Actor::RenderComponent>();
			newActor.GetComponent<Actor::RenderComponent>()->Sprite = actor.GetComponent<Actor::RenderComponent>()->Sprite;
		}
	}
}
