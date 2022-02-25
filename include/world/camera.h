#pragma once

#include <main.h>
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>

struct Camera
{
	glm::mat4 projMat;
	glm::mat4 viewMat;

	void init(float fov, float aspect);
};