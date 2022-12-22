#pragma once

#include "Fractured/Core/FEngine.h"

using namespace FracturedInternal;

inline std::shared_ptr<FApp> CreateApp();

int main(int argc, char* argv[])
{
	const auto app = CreateApp();
	FracturedInternal::FEngine::GetInstance()->Run(app);
	return 0;
}