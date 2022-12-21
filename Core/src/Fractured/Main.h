#pragma once

#include "Core/FEngine.h"

using namespace FracturedInternal;

std::shared_ptr<FApp> CreateApp();

int main(int argc, char* argv[])
{
	const auto app = CreateApp();
	FracturedInternal::FEngine::GetInstance()->Run(app);
	return 0;
}