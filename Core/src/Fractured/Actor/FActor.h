#pragma once

#include "Component.h"
#include "frpch.h"

#include "Fractured/Math/FRandom.h"
#include "Entity System/Entity.h"
#include "Fractured/Core/FEngine.h"
#include "Fractured/Core/FLogger.h"

namespace FracturedInternal
{
	class FEngine;
}

namespace FracturedInternal::Actor
{

	class FActor
	{
	public:
		FActor() = default;

		[[nodiscard]] int32 GetId() const { return mId; }

		template<typename T>
		T* GetComponent()
		{
			T* component = FracturedInternal::FEngine::GetInstance()->GetScene()->GetEntityManager()->Get<T>(id);
			return component;
		}

		template<typename T>
		T* AddComponent()
		{
			T* component = FracturedInternal::FEngine::GetInstance()->GetScene()->GetEntityManager()->Assign<T>(id);
			return component;
		}

		template<typename T>
		bool HasComponent() const
		{
			T* component = FracturedInternal::FEngine::GetInstance()->GetScene()->GetEntityManager()->Get<T>(id);
			if (component)
				return true;

			FR_LOG_ERROR("Null: Component does not exist");
			return false;
		}

		TransformComponent* GetTransform() { return GetComponent<TransformComponent>(); }

	public:
		std::string name = "";

		EntitySystem::EntityId id;
	private:
		fint32 mId = FRandom::RandomNumber(1000);
	};
}
