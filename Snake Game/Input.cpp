#include "Input.h"

bool Input::GetKeyState(int keyIndex)
{
	return isKeyPressed[keyIndex];
}

void Input::UpdateInput()
{
	for (int i = 0; i < 6; i++)
	{
		isKeyPressed[i] = false;

		if (sf::Keyboard::isKeyPressed(Keys[i]))
		{
			if (!pressedLastFrame[i])
			{
				isKeyPressed[i] = true;
			}
			pressedLastFrame[i] = true;
		}
		else
		{
			pressedLastFrame[i] = false;
		}
	}
}