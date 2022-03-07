#include <util/input.h>

bool keyPressedData[GLFW_KEY_LAST] = {};

double posX  = 0,
	   posY  = 0,
	   lastX = 1920 / 2,
	   lastY = 1080 / 2;

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	keyPressedData[key] = action == GLFW_PRESS;
}

void mousePosCallback(GLFWwindow* window, double xPos, double yPos)
{
	lastX = posX;
	lastY = posY;

	posX = xPos;
	posY = yPos;
}

void endInputs()
{
	lastX = posX;
	lastY = posY;
}

double getMouseDx()
{
	return posX - lastX;
}

double getMouseDy()
{
	return lastY - posY;
}

bool isKeyDown(int key)
{
	return keyPressedData[key];
}