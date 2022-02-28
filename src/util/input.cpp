#include <util/input.h>

bool keyPressedData[GLFW_KEY_LAST] = {};

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	keyPressedData[key] = action == GLFW_PRESS;
}

bool isKeyDown(int key)
{
	return keyPressedData[key];
}