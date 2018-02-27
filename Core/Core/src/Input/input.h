#pragma once

#include <GLFW\glfw3.h>
#include <GLM\vec2.hpp>
#include <iostream>

#define MAX_KEYS 1024
#define MAX_MOUSE_BUTTONS 32

struct KeyCode
{
	//main keyboard keys//

	const static unsigned int A = GLFW_KEY_A;
	const static unsigned int B = GLFW_KEY_B;
	const static unsigned int C = GLFW_KEY_C;
	const static unsigned int D = GLFW_KEY_D;
	const static unsigned int E = GLFW_KEY_E;
	const static unsigned int F = GLFW_KEY_F;
	const static unsigned int G = GLFW_KEY_G;
	const static unsigned int H = GLFW_KEY_H;
	const static unsigned int I = GLFW_KEY_I;
	const static unsigned int K = GLFW_KEY_K;
	const static unsigned int L = GLFW_KEY_L;
	const static unsigned int M = GLFW_KEY_M;
	const static unsigned int N = GLFW_KEY_N;
	const static unsigned int O = GLFW_KEY_O;
	const static unsigned int P = GLFW_KEY_P;
	const static unsigned int Q = GLFW_KEY_Q;
	const static unsigned int R = GLFW_KEY_R;
	const static unsigned int S = GLFW_KEY_S;
	const static unsigned int T = GLFW_KEY_T;
	const static unsigned int U = GLFW_KEY_U;
	const static unsigned int V = GLFW_KEY_V;
	const static unsigned int Z = GLFW_KEY_Z;

	//numbers//
	const static unsigned int G0 = GLFW_KEY_0;
	const static unsigned int G1 = GLFW_KEY_1;
	const static unsigned int G2 = GLFW_KEY_2;
	const static unsigned int G3 = GLFW_KEY_3;
	const static unsigned int G4 = GLFW_KEY_4;
	const static unsigned int G5 = GLFW_KEY_5;
	const static unsigned int G6 = GLFW_KEY_6;
	const static unsigned int G7 = GLFW_KEY_7;
	const static unsigned int G8 = GLFW_KEY_8;
	const static unsigned int G9 = GLFW_KEY_9;

	//keypad numbers//
	const static unsigned int KP0 = GLFW_KEY_KP_0;
	const static unsigned int KP1 = GLFW_KEY_KP_1;
	const static unsigned int KP2 = GLFW_KEY_KP_2;
	const static unsigned int KP3 = GLFW_KEY_KP_3;
	const static unsigned int KP4 = GLFW_KEY_KP_4;
	const static unsigned int KP5 = GLFW_KEY_KP_5;
	const static unsigned int KP6 = GLFW_KEY_KP_6;
	const static unsigned int KP7 = GLFW_KEY_KP_7;
	const static unsigned int KP8 = GLFW_KEY_KP_8;
	const static unsigned int KP9 = GLFW_KEY_KP_9;

	//other useful keys
	const static unsigned int Escape = GLFW_KEY_ESCAPE;
	const static unsigned int Enter = GLFW_KEY_ENTER;
	const static unsigned int Tab = GLFW_KEY_TAB;
	const static unsigned int BackSpace = GLFW_KEY_BACKSPACE;
};

//working but messy

/*
struct Button
{
	//main buttons//
	const static unsigned int Left = GLFW_MOUSE_BUTTON_LEFT;
	const static unsigned int Right = GLFW_MOUSE_BUTTON_RIGHT;
	const static unsigned int Middle = GLFW_MOUSE_BUTTON_3;
	
	//other mouse buttons//
	const static unsigned int B1 = GLFW_MOUSE_BUTTON_1;
	const static unsigned int B2 = GLFW_MOUSE_BUTTON_2;
	const static unsigned int B3 = GLFW_MOUSE_BUTTON_3;
	const static unsigned int B4 = GLFW_MOUSE_BUTTON_4;
	const static unsigned int B5 = GLFW_MOUSE_BUTTON_5;
	const static unsigned int B6 = GLFW_MOUSE_BUTTON_6;
	const static unsigned int B7 = GLFW_MOUSE_BUTTON_7;
	const static unsigned int B8 = GLFW_MOUSE_BUTTON_8;
};*/

//test
enum class Button : unsigned int
{
	Left = GLFW_MOUSE_BUTTON_LEFT
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

	static bool GetKey(unsigned int key);
	static bool GetButton(unsigned int button);
	static glm::vec2 GetMousePosition();
};
