#pragma once

namespace FracturedInternal::GUI
{
	class ImGuiLoader
	{
	public:
		static bool Init();
		static void Destroy();

		static void BeginUIRender();
		static void EndUIRender();
	};
}


