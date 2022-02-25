#include <world/camera.h>

void Camera::init(float fov, float aspect)
{
	projMat = glm::perspective(glm::radians(fov), aspect, 0.1f, 1000.0f);
	viewMat = glm::mat4(1.0f);
}