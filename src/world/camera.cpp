#include <world/camera.h>

Camera::Camera()
{

}

Camera::Camera(glm::vec3 pos, glm::vec3 rot, float fov)
{
	position = pos;
	this->fov = fov;
	projMat = glm::perspective(glm::radians(fov), (float)1920.0f / (float)1080.0f, 0.1f, 1000.0f);
}

glm::mat4 Camera::getProjectionMatrix()
{
	return projMat;
}

glm::mat4 Camera::getViewMatrix()
{
	viewMat = glm::lookAt(position, position + target, up);
	return viewMat;
}

void Camera::translate(glm::vec3 offset)
{
	position += offset;
}