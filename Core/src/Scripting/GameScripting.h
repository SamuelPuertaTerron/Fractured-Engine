#pragma once

#include "Fractured/Core/FEngine.h"
#include "Fractured/Core/FApp.h"
#include "Fractured/Core/FLogger.h"

// ----- Entry Point ----- //
#include "Main.h"
// ----------------------- //

#include "Fractured/Input/FInputManager.h"
#include "Fractured/Actor/FActor.h"
#include "Fractured/Actor/Component.h"

namespace Fractured
{
	using namespace FracturedInternal::Actor;
	using namespace FracturedInternal::Input;
	using namespace FracturedInternal::Math;

	using Engine = FracturedInternal::FEngine;
	using Application = FracturedInternal::FApp;
	using Input = FracturedInternal::Input::FInputManager;
	using GameObject = FracturedInternal::Actor::FActor;
}
