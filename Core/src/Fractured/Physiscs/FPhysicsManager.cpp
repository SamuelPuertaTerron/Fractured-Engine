#include "frpch.h"
#include "FPhysicsManager.h"
#include "Fractured/Actor/Entity System/EntityManager.h"

#include "box2d/b2_world.h"
#include "box2d/b2_body.h"
#include "box2d/b2_fixture.h"
#include "box2d/b2_polygon_shape.h"
#include "box2d/b2_circle_shape.h"

namespace FracturedInternal::Physics
{
	FPhysicsManager::~FPhysicsManager()
	{
		delete mPhysicsWorld;
	}

	void FPhysicsManager::Init()
	{
		mPhysicsWorld = new b2World({ 0.0f, -9.8f });
	}
}


