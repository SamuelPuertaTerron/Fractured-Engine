#include "frpch.h"
#include "FGUIPanel.h"

#include "imgui.h"

namespace FracturedInternal::GUI
{
	bool FGUIPanel::StartPanel(PanelFlags flags)
	{
		return ImGui::Begin(" ", nullptr, (ImGuiWindowFlags)flags);
	}
	bool FGUIPanel::StartPanel(const std::string& title, PanelFlags flags)
	{
		return ImGui::Begin(title.c_str() , nullptr, (ImGuiWindowFlags)flags);
	}
	void FGUIPanel::EndPanel()
	{
		ImGui::End();
	}
}