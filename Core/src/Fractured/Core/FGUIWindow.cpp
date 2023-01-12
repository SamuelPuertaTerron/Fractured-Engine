#include "frpch.h"

#ifdef FR_DEBUG
#include "FGUIWindow.h"

#include "FEngine.h"
#include "imgui.h"


namespace FracturedInternal::Core
{
	void FGUIWindow::DisplayWindow()
	{
		ImGui::Begin("Debug");
		ImGui::Text("Debug Screen");
		ImGui::Spacing();
		ImGui::End();
	}
}

#endif
