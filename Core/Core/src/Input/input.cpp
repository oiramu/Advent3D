#include "input.h"

bool Input::Keys[MAX_KEYS];
bool Input::MouseButtons[MAX_MOUSE_BUTTONS];

double Input::mx = 0;
double Input::my = 0;

bool Input::GetKey(unsigned int  key)
{

	if (key >= MAX_KEYS)
	{
		std::cout << "The keycode specified is greater than the array can hold" << std::endl;
		return false;
	}

	return Input::Keys[key];
}

bool Input::GetButton(unsigned int button)
{
	if (button >= MAX_MOUSE_BUTTONS)
	{
		std::cout << "the button specified is greater than the array can hold" << std::endl;
		return false;
	}

	return Input::MouseButtons[button];
}

glm::vec2 Input::GetMousePosition()
{
	return glm::vec2(Input::mx, Input::my);
}