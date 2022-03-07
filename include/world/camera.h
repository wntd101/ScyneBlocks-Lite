#pragma once

#include <main.h>
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>

class Camera
{
public:
	glm::mat4 projMat;
	glm::mat4 viewMat;

	glm::vec3 target = glm::vec3(0.0, 0.0, -1.0);
	glm::vec3 up = glm::vec3(0.0, 1.0, 0.0);
	glm::vec3 right = glm::vec3(1.0 , 0.0, 0.0);

	float fov;
	
	double yaw = 0.0f, pitch = 1.0f;

	glm::vec3 position;
	glm::vec3 rotation;

	Camera();
	Camera(glm::vec3 pos, glm::vec3 rot, float fov);
	glm::mat4 getProjectionMatrix();
	glm::mat4 getViewMatrix();
	
	void translate(glm::vec3 offset);
};