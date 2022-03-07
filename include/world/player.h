#pragma once

#include <main.h>
#include <world/camera.h>
#include <util/input.h>

#include <glm.hpp>

class Player
{
public:

	Camera cam;
	glm::vec3 direction;

	Player();
	Player(glm::vec3 position);
	void update();

};