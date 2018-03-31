#include "input.h"

namespace advent {

bool Input::Keys[MAX_KEYS];
bool Input::MouseButtons[MAX_MOUSE_BUTTONS];

double Input::mx = 0;
double Input::my = 0;

bool Input::getKey(KeyCode key)
{
	unsigned int value = static_cast<unsigned int>(key);

	if (value >= MAX_KEYS)
	{
		std::cout << "The keycode specified is greater than the array can hold" << std::endl;
		return false;
	}

	return Input::Keys[value];
}

bool Input::getMouseButton(MouseButton button)
{
	unsigned int value = static_cast<unsigned int>(button);

	if (value >= MAX_MOUSE_BUTTONS)
	{
		std::cout << "the button specified is greater than the array can hold" << std::endl;
		return false;
	}

	return Input::MouseButtons[value];
}

maths::vec2 Input::getMousePosition()
{
	return maths::vec2(Input::mx, Input::my);
}

}