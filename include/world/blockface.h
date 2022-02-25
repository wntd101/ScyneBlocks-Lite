#pragma once

#include <main.h>
#define VERTEXARRAYLEN 28
#define INDICESARRAYLEN 6

class BlockFace
{
private:

	unsigned int vbo = 0, vao = 0, ebo = 0;
	float vertices[VERTEXARRAYLEN];
	int indices[INDICESARRAYLEN];

public:

	void init(float verts[VERTEXARRAYLEN], unsigned int tris[INDICESARRAYLEN]);

	void render();

	void remove();
};