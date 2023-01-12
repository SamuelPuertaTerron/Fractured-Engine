#pragma once

#include "Fractured/Core/FEngine.h"

using namespace FracturedInternal;
/**
 * \brief How the application is Created Internally.
 * \return The Created Application as a FApp object which is loaded into the engine. 
 */
inline std::shared_ptr<FApp> CreateApp();

namespace FracturedInternal
{
	int Main(int argc, char* argv[])
	{
		const auto app = CreateApp();
		FracturedInternal::FEngine::GetInstance()->Run(app);
		return 0;
	}
}


#ifdef FR_RELEASE

#include <Windows.h>

int APIENTRY WinMain(HINSTANCE hInst, HINSTANCE hInstPrev, PSTR cmdline, int cmdshow)
{
	return FracturedInternal::Main(__argc, __argv);
}

#endif

#ifdef FR_DEBUG

int main(int argc, char** argv)
{
	return FracturedInternal::Main(argc, argv);
}

#endif




