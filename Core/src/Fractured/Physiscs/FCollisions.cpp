#include "frpch.h"
#include "FCollisions.h"

#include "Fractured/Actor/FActor.h"

namespace FracturedInternal::Physics
{
	bool FCollisions::HasCollided(Actor::FActor& one, Actor::FActor& two)
	{
		const bool colX = one.GetTransform()->Position.x + one.GetTransform()->Scale.x >= two.GetTransform()->Position.x &&
			two.GetTransform()->Position.x + two.GetTransform()->Scale.x >= one.GetTransform()->Position.x;
		const bool colY = one.GetTransform()->Position.y + one.GetTransform()->Scale.y >= two.GetTransform()->Position.y &&
			two.GetTransform()->Position.y + two.GetTransform()->Scale.y >= one.GetTransform()->Position.y;

		return colX && colY;
	}
}