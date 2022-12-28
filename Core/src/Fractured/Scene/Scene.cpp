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


	void Scene::Update()
	{
		
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
}
