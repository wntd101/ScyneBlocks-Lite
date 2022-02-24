#pragma once

#include <main.h>
#include <world/mesh.h>

static GLFWwindow* window;

int init();
int createWindow(int width, int height, const char* title);

void loop();

int startWindow(int width, int height, const char* title, void(*func)(Mesh), Mesh block);