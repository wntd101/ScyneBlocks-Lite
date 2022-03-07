#pragma once

#include <main.h>

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
void mousePosCallback(GLFWwindow* window, double xPos, double yPos);

bool isKeyDown(int key);
double getMouseDx();
double getMouseDy();

void endInputs();