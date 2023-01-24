#include "frpch.h"
#include "FGUIText.h"

#include "imgui.h"
#include "Fractured/Math/FVector2.h"

namespace FracturedInternal::GUI
{
	void FGUIText::Text(const std::string& message)
	{
		ImGui::Text(message.c_str());
	}
}