#include "frpch.h"

#include "imgui.h"
#include "ImGUI/FGUIText.h"
#include "ImGUI/ImGuiLoader.h"

#ifdef FR_DEBUG
#include "FGUIWindow.h"

#include "ImGUI/FGUIButton.h"
#include "ImGUI/FGUIPanel.h"
#include "FEngine.h"

namespace FracturedInternal::Core
{
	void FGUIWindow::Init()
	{
		if (!GUI::ImGuiLoader::Init())
		{
			FR_LOG_ERROR("ImGui has not been Initialized!");
		}
	}
	void FGUIWindow::DisplayWindow()
	{
		GUI::ImGuiLoader::BeginUIRender();

		FEngine::GetInstance()->GetApp()->OnAppRenderUI();

		if(GUI::FGUIPanel::StartPanel("Debug"))
		{
			GUI::FGUIText::Text("FPS: " + std::to_string(FEngine::GetInstance()->GetFPS()));

			GUI::FGUIPanel::EndPanel();
		}

		GUI::ImGuiLoader::EndUIRender();
	}
	void FGUIWindow::Destroy()
	{
		GUI::ImGuiLoader::Destroy();
	}
}

#endif
