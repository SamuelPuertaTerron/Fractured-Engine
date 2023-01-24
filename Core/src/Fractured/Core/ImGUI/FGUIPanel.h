#pragma once

namespace FracturedInternal::GUI
{
	enum PanelFlags_
	{
		None			= 0,
		NoTitleBar		= 1 << 0,
		NoResize		= 1 << 1,
		NoMove			= 1 << 2,
		NoScrollBar		= 1 << 3,
		NoCollapse		= 1 << 5,
		AlwaysAutoSize	= 1 << 6,
		NoBackground	= 1 << 7,
		MenuBar			= 1 << 10,
		NoDecoration = NoBackground | NoScrollBar | NoTitleBar | NoResize | AlwaysAutoSize,
	};

	typedef int PanelFlags;

	class FGUIPanel
	{
	public:
		static bool StartPanel(PanelFlags flags = 64);
		static bool StartPanel(const std::string& title, PanelFlags flags = None | AlwaysAutoSize);
		static void EndPanel();
	};
}


