#pragma once

//maths
#include <GLM\vec2.hpp>

//STL
#include <iostream>

namespace Advent3D {

#define MAX_KEYS 1024
#define MAX_MOUSE_BUTTONS 32

enum class KeyCode : unsigned int
{
	A = 65,
	B = 66,
	C = 67,
	D = 68,
	E = 69,
	F = 70,
	G = 71,
	H = 72,
	I = 73,
	J = 74,
	K = 75,
	L = 76,
	M = 77,
	N = 78,
	O = 79,
	P = 80,
	Q = 81,
	R = 82,
	S = 83,
	T = 84,
	U = 85,
	V = 86,
	W = 87,
	X = 88,
	Y = 89,
	Z = 90,

	G0 = 48,
	G1 = 49,
	G2 = 50,
	G3 = 51,
	G4 = 52,
	G5 = 53,
	G6 = 54,
	G7 = 55,
	G8 = 56,
	G9 = 57,

	KP0 = 320,
	KP1 = 321,
	KP2 = 322,
	KP3 = 323,
	KP4 = 324,
	KP5 = 325,
	KP6 = 326,
	KP7 = 327,
	KP8 = 328,
	KP9 = 329,

	Escape = 256,
	Enter = 257,
	Tab = 258,
	BackSpace = 259,
	Space = 32
};

enum class Button : unsigned int
{
	Left = 0,
	Right = 1,
	Middle = 2,

	B1 = 0,
	B2 = 1,
	B3 = 2,
	B4 = 3,
	B5 = 4,
	B6 = 5,
	B7 = 6,
	B8 = 7
};

enum class GamePad : unsigned int
{
	B1 = 0,
	B2 = 1,
	B3 = 2,
	B4 = 3,
	B5 = 4,
	B6 = 5,
	B7 = 6,
	B8 = 7,
	B9 = 8,
	B10 = 9,
	B11 = 10,
	B12 = 11,
	B13 = 12,
	B14 = 13,
	B15 = 14,
	B16 = 15
};

struct Input
{
	static bool Keys[MAX_KEYS];
	static bool MouseButtons[MAX_MOUSE_BUTTONS];

	static double mx, my;

	Input()
	{
		for (int i = 0; i < MAX_KEYS; i++)
		{
			Keys[i] = 0;
		}

		for (int i = 0; i < MAX_MOUSE_BUTTONS; i++)
		{
			MouseButtons[i] = 0;
		}
	}

	static bool GetKey(KeyCode key);
	static bool GetButton(Button button);
	static glm::vec2 GetMousePosition();
};

}