#include <world/block.h>
#include <world/camera.h>

void Block::init()
{
	shader.init("default");
	frontFace.init(frontFaceVerts, frontFaceTris);
	transform = glm::rotate(transform, glm::radians(40.0f), glm::vec3(0.0, 1.0, 0.0));
}

void Block::update(Camera cam)
{
	shader.use();
	shader.uploadMat4("uTransform", transform);
	shader.uploadMat4("uProjection", cam.projMat);
	shader.uploadMat4("uView", cam.viewMat);

	frontFace.render();
	frontFace.remove();

	shader.detach();
}