#pragma once

#include <main.h>
#include <world/mesh.h>
#include <gfx/shader.h>
#include <world/camera.h>

class Block
{
private:

	float frontFaceVerts[28] =
	{
		//Position				//Color
		-0.5f,  0.5f, -0.5f,	0.0f, 1.0f, 0.0f, 1.0f,		//Top Left
		 0.5f,  0.5f, -0.5f,	0.0f, 1.0f, 0.0f, 1.0f,		//Top Right
		 0.5f, -0.5f, -0.5f,	0.0f, 1.0f, 0.0f, 1.0f,		//Bottom Right
		-0.5f, -0.5f, -0.5f,	0.0f, 1.0f, 0.0f, 1.0f		//Bottom Left
	};

	int frontFaceTris[6] =
	{
		2, 1, 0,
		2, 0, 3
	};

	Shader shader;
	Mesh frontFace;

	glm::mat4 transform = glm::mat4(1.0f);

public:

	void init();
	void update(Camera cam);
};