#pragma once

namespace FracturedInternal::EntitySystem
{
	constexpr int MAX_ENTITIES = 500;

	class ComponentPool
	{
	public:
		ComponentPool() = default;
		ComponentPool(size_t elementSize);

		~ComponentPool();

		void* Get(size_t index) const;
	private:
		char* mData = nullptr;
		size_t mElementSize = 0;
	};
}


