#include "frpch.h"
#include "FGUIButton.h"

#include "imgui.h"

#include "Fractured/Math/FVector2.h"

namespace FracturedInternal::GUI
{
	bool FGUIButton::Button(const std::string& title)
	{
		return ImGui::Button(title.c_str());
	}
	bool FGUIButton::Button(const std::string& title, Math::FVector2 position)
	{
		return ImGui::Button(title.c_str(), ImVec2(position.x, position.y));
	}
}
