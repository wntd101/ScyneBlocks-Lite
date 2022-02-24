#include <main.h>
#include <gfx/window.h>
#include <gfx/shader.h>
#include <world/mesh.h>

void update(Mesh block)
{
	block.update();
}

int main()
{
	float positions[] =
	{
		-0.5f,  0.5f, 0.0f,
		 0.5f,  0.5f, 0.0f,
		 0.5f, -0.5f, 0.0f,
		-0.5f, -0.5f, 0.0f
	};

	float colors[] =
	{
		0.5f, 0.5f, 0.0f, 1.0f,
		0.5f, 0.5f, 0.0f, 1.0f,
		0.5f, 0.5f, 0.0f, 1.0f,
		0.5f, 0.5f, 0.0f, 1.0f
	};

	int indices[] =
	{
		0, 2, 1,
		0, 2, 3
	};

	Mesh block("default", positions, colors, indices);

	int windowCreated = startWindow(1920, 1080, "ScyneBlocks", &update, block);

	return windowCreated;
}