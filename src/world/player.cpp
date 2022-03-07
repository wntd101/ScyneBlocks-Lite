#include <world/player.h>

Player::Player()
{
	cam = Camera(glm::vec3(0.0, 0.0, 0.0), glm::vec3(0.0, 0.0, 0.0), 70.0f);
}

Player::Player(glm::vec3 position)
{
	cam = Camera(position, glm::vec3(0.0, 0.0, 0.0), 70.0f);
}

void Player::update()
{
	double mouseX = getMouseDx();
	double mouseY = getMouseDy();

	mouseX *= 0.1f;
	mouseY *= 0.1f;

	cam.yaw += mouseX;
	cam.pitch += mouseY;

	if (cam.pitch > 89.0f) cam.pitch = 89.0f;
	if (cam.pitch < -89.0f) cam.pitch = -89.0f;

	direction.x = glm::cos(glm::radians(cam.yaw)) * glm::cos(glm::radians(cam.pitch));
	direction.y = glm::sin(glm::radians(cam.pitch));
	direction.z = glm::sin(glm::radians(cam.yaw)) * glm::cos(glm::radians(cam.pitch));

	cam.target = glm::normalize(direction);
	cam.right = glm::normalize(glm::cross(cam.target, glm::vec3(0.0, 1.0, 0.0)));
	cam.up = glm::normalize(glm::cross(cam.right, cam.target));

	if (isKeyDown(GLFW_KEY_W))
	{
		cam.translate(0.1f * cam.target);
	}
	else if (isKeyDown(GLFW_KEY_S))
	{
		cam.translate(-(0.1f * cam.target));
	}
	else if (isKeyDown(GLFW_KEY_A))
	{
		cam.translate(-glm::normalize(glm::cross(cam.target, glm::vec3(0.0, 1.0, 0.0))) * 0.1f);
	}
	else if (isKeyDown(GLFW_KEY_D))
	{
		cam.translate(glm::normalize(glm::cross(cam.target, glm::vec3(0.0, 1.0, 0.0))) * 0.1f);
	}
	else if (isKeyDown(GLFW_KEY_SPACE))
	{
		cam.translate(glm::vec3(0, 0.1f, 0));
	}
	else if (isKeyDown(GLFW_KEY_LEFT_SHIFT))
	{
		cam.translate(glm::vec3(0, -0.1f, 0));
	}
}