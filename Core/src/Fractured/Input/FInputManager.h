#pragma once
#include "FKeyCodes.h"

namespace FracturedInternal::Input
{
	class FInputManager
	{
	public:
		static bool IsKeyPressed(const FKeyCode key);
		static bool IsMouseButtonPressed(const FMouseCode mouse);
		static void SetShowMouseCursor(const bool value);
	private:
		static bool KeyPress(FKeyCode key);
		static bool MousePress(FMouseCode mouse);
	};
}


