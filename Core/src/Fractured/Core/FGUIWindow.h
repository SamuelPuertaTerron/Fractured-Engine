#pragma once

#ifdef FR_DEBUG

namespace FracturedInternal::Core
{
	class FGUIWindow
	{
	public:

		FGUIWindow() = default;
		~FGUIWindow() = default;

		void Init();

		void DisplayWindow();

	private:
	};
}

#endif


