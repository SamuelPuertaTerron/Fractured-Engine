#pragma once
namespace FracturedInternal::Input
{
	enum class FKeyCode
	{
		NONE = 0, //Null

		//Function Keys
		FK_TAB = 9,
		FK_ESCAPE = 256,
		FK_SPACE = 32,
		FK_LEFT_SHIFT = 340,

		//A-Z Keys
		FK_A = 65,
		FK_B = 66,
		FK_C = 67,
		FK_D = 68,
		FK_E = 69,
		FK_F = 70,
		FK_G = 71,
		FK_H = 72,
		FK_I = 73,
		FK_J = 74,
		FK_K = 75,
		FK_L = 76,
		FK_M = 77,
		FK_N = 78,
		FK_O = 79,
		FK_P = 80,
		FK_Q = 81,
		FK_R = 82,
		FK_S = 83,
		FK_T = 84,
		FK_U = 85,
		FK_V = 86,
		FK_W = 87,
		FK_X = 88,
		FK_Y = 89,
		FK_Z = 90,

		//Top Number Keys
		FK_0 = 48,
		FK_1 = 49,
		FK_2 = 50,
		FK_3 = 51,
		FK_4 = 52,
		FK_5 = 53,
		FK_6 = 54,
		FK_7 = 55,
		FK_8 = 56,
		FK_9 = 57,
	};

	enum class FMouseCode
	{
		//Mouse Codes
		FM_LEFTMOUSEBUTTON = 0,
		FM_RIGHTMOUSEBUTTON = 1,
	};
}
