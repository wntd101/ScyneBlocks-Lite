#pragma once

#include <main.h>

static GLFWwindow* window;

int init();
void start();
int createWindow(int width, int height, const char* title);

void loop();
void update();

int startWindow(int width, int height, const char* title);