#pragma once

#include <GLFW\glfw3.h>
#include <GLM\vec2.hpp>
#include <iostream>

#define MAX_KEYS 1024
#define MAX_MOUSE_BUTTONS 32

enum class KeyCode : unsigned int
{
	//main keyboard keys//

	A = GLFW_KEY_A,
	B = GLFW_KEY_B,
	C = GLFW_KEY_C,
	D = GLFW_KEY_D,
	E = GLFW_KEY_E,
	F = GLFW_KEY_F,
	G = GLFW_KEY_G,
	H = GLFW_KEY_H,
	I = GLFW_KEY_I,
	K = GLFW_KEY_K,
	L = GLFW_KEY_L,
	M = GLFW_KEY_M,
	N = GLFW_KEY_N,
	O = GLFW_KEY_O,
	P = GLFW_KEY_P,
	Q = GLFW_KEY_Q,
	R = GLFW_KEY_R,
	S = GLFW_KEY_S,
	T = GLFW_KEY_T,
	U = GLFW_KEY_U,
	V = GLFW_KEY_V,
	Z = GLFW_KEY_Z,

	//numbers//
	G0 = GLFW_KEY_0,
	G1 = GLFW_KEY_1,
	G2 = GLFW_KEY_2,
	G3 = GLFW_KEY_3,
	G4 = GLFW_KEY_4,
	G5 = GLFW_KEY_5,
	G6 = GLFW_KEY_6,
	G7 = GLFW_KEY_7,
	G8 = GLFW_KEY_8,
	G9 = GLFW_KEY_9,

	//keypad numbers//
	KP0 = GLFW_KEY_KP_0,
	KP1 = GLFW_KEY_KP_1,
	KP2 = GLFW_KEY_KP_2,
	KP3 = GLFW_KEY_KP_3,
	KP4 = GLFW_KEY_KP_4,
	KP5 = GLFW_KEY_KP_5,
	KP6 = GLFW_KEY_KP_6,
	KP7 = GLFW_KEY_KP_7,
	KP8 = GLFW_KEY_KP_8,
	KP9 = GLFW_KEY_KP_9,

	//other useful keys
	Escape = GLFW_KEY_ESCAPE,
	Enter = GLFW_KEY_ENTER,
	Tab = GLFW_KEY_TAB,
	BackSpace = GLFW_KEY_BACKSPACE
};

enum class Button : unsigned int
{
	//main buttons//
	Left = GLFW_MOUSE_BUTTON_LEFT,
	Right = GLFW_MOUSE_BUTTON_RIGHT,
	Middle = GLFW_MOUSE_BUTTON_3,
	
	//other mouse buttons//
	B1 = GLFW_MOUSE_BUTTON_1,
	B2 = GLFW_MOUSE_BUTTON_2,
	B3 = GLFW_MOUSE_BUTTON_3,
	B4 = GLFW_MOUSE_BUTTON_4,
	B5 = GLFW_MOUSE_BUTTON_5,
	B6 = GLFW_MOUSE_BUTTON_6,
	B7 = GLFW_MOUSE_BUTTON_7,
	B8 = GLFW_MOUSE_BUTTON_8
};

namespace Input
{
        void Init()
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

	static bool GetKey(unsigned int key);
	static bool GetButton(unsigned int button);
	static glm::vec2 GetMousePosition();

	static bool Keys[MAX_KEYS];
	static bool MouseButtons[MAX_MOUSE_BUTTONS];

	static double mx, my;
};
