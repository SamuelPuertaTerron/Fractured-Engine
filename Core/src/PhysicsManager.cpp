#include "frpch.h"
#include "PhysicsManager.h"
#include "Fractured/Actor/Entity System/EntityManager.h"

#include "box2d/b2_world.h"
#include "box2d/b2_body.h"
#include "box2d/b2_fixture.h"
#include "box2d/b2_polygon_shape.h"
#include "box2d/b2_circle_shape.h"

namespace FracturedInternal::Physics
{
	PhysicsManager::~PhysicsManager()
	{
		delete mPhysicsWorld;
	}

	void PhysicsManager::Init()
	{

	}

	void PhysicsManager::PhysicsStart()
	{
		
	}
}


