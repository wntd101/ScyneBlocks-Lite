#pragma once

#include <main.h>
#include <util/buffer.h>
#include <vector>

class Mesh
{
private:
	unsigned int vao = 0;

	Buffer vbo;
	Buffer ebo;

	std::vector<float> vertices;
	std::vector<int> indices;

public:

	void init(float verts[], int tris[], int vertCount, int triCount);

	void render();

	void remove();
};