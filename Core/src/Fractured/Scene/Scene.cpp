#include "frpch.h"
#include "Scene.h"

#include "Fractured/Core/FEngine.h"
#include "Fractured/Actor/Component.h"
#include "Fractured/Rendering/RenderManager.h"

namespace FracturedInternal::Scene
{
	Scene::Scene()
	{
		mEntityManager = new EntitySystem::EntityManager();
	}

	Scene::~Scene()
	{
		delete mEntityManager;
	}


	void Scene::Start()
	{

	}

	void Scene::Update()
	{
		for (auto const& entity : mEntityManager->GetEntities())
		{
			auto const& rb = mEntityManager->Get<Actor::RigidbodyComponent>(entity.id);
			auto const& bc = mEntityManager->Get<Actor::BoxColliderComponent>(entity.id);
		}
	}
	void Scene::Render()
	{
		for (auto const& entity : mEntityManager->GetEntities())
		{
			auto const& render = mEntityManager->Get<Actor::RenderComponent>(entity.id);
			auto const& transform = mEntityManager->Get<Actor::TransformComponent>(entity.id);

			if(render)
				FEngine::GetInstance()->GetSpriteRenderer()->RenderShape(transform->Position, transform->Rotation, transform->Scale, render->Sprite);
		}
	}
	EntitySystem::EntityId Scene::CreateEntity()
	{
		return mEntityManager->CreateEntity();
	}
}
