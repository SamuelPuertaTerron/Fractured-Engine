#pragma once

namespace FracturedInternal
{
	namespace Actor
	{
		class FActor;
	}
}

namespace FracturedInternal::Physics
{
	class FCollisions
	{
	public:
		static bool HasCollided(Actor::FActor& one, Actor::FActor& two);
	};
}

