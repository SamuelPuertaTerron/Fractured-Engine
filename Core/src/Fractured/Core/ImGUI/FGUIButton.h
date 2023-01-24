#pragma once

namespace FracturedInternal
{
	namespace Math
	{
		struct FVector2;
	}
}

namespace FracturedInternal::GUI
{
	class FGUIButton
	{
	public:
		static bool Button(const std::string& title);
		static bool Button(const std::string& title, Math::FVector2 position);
	};
}


