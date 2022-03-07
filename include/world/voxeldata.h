#pragma once

#include <main.h>
#include <glm.hpp>

static const int chunkSize = 16;

static glm::vec3 vertexPositions[24] =
{
	 glm::vec3(0.0f, 0.0f, 1.0f),
	 glm::vec3(1.0f, 0.0f, 1.0f),
	 glm::vec3(1.0f, 1.0f, 1.0f),
	 glm::vec3(0.0f, 1.0f, 1.0f),
	 glm::vec3(0.0f, 0.0f, 0.0f),
	 glm::vec3(1.0f, 0.0f, 0.0f),
	 glm::vec3(1.0f, 1.0f, 0.0f),
	 glm::vec3(0.0f, 1.0f, 0.0f)
};

static glm::vec4 vertexColors[32] =
{
	glm::vec4(1.0f, 1.0f, 0.0f, 1.0f),
	glm::vec4(0.0f, 1.0f, 0.0f, 1.0f),
	glm::vec4(0.0f, 1.0f, 1.0f, 1.0f),
	glm::vec4(1.0f, 1.0f, 1.0f, 1.0f),
	glm::vec4(0.0f, 0.0f, 1.0f, 1.0f),
	glm::vec4(1.0f, 0.0f, 0.0f, 1.0f),
	glm::vec4(0.0f, 0.0f, 0.0f, 1.0f),
	glm::vec4(0.0f, 1.0f, 0.0f, 1.0f)
};

static int triangles[6][6] =
{
	//Back Face
	{ 0, 3, 1, 2 },

	//Front Face
	{ 5, 6, 4, 7 },

	//Top Face
	{ 3, 7, 2, 6 },

	//Bottom Face
	{ 1, 5, 0, 4 },

	//Left Face
	{ 4, 7, 0, 3 },

	//Right Face
	{ 1, 2, 5, 6 }
};

static glm::vec3 faceChecks[] =
{
	glm::vec3( 0.0f,  0.0f, -1.0f),
	glm::vec3( 0.0f,  0.0f,  1.0f),
	glm::vec3( 0.0f,  1.0f,  0.0f),
	glm::vec3( 0.0f, -1.0f,  0.0f),
	glm::vec3(-1.0f,  0.0f,  0.0f),
	glm::vec3( 1.0f,  0.0f,  0.0f),
};