#pragma once

#include "box2d/box2d.h"


namespace FracturedInternal
{
	namespace EntitySystem
	{
		class EntityManager;
	}
}

namespace FracturedInternal::Physics
{
	class PhysicsManager
	{
	public:
		PhysicsManager() = default;
		~PhysicsManager();

		void Init();

		b2World* GetPhysicsWorld() const { return mPhysicsWorld; }
	private:
		b2World* mPhysicsWorld = nullptr;
	};
}


