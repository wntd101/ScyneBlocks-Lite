#include <world/chunk.h>
#include <util/input.h>

void Chunk::init()
{
	initializeVoxelMap();
	createMeshData();
	shader.init("default");
	mesh.init(vertices.data(), indices.data(), vertices.size(), indices.size());
}

void Chunk::update(Player p)
{
	shader.use();
	shader.uploadMat4("uProjection", p.cam.getProjectionMatrix());
	shader.uploadMat4("uView", p.cam.getViewMatrix());
	shader.uploadMat4("uTransform", glm::mat4(1.0));
	mesh.render();
	mesh.remove();
	shader.detach();
}

void Chunk::initializeVoxelMap()
{
	for (int x = 0; x < chunkSize; x++)
	{
		for (int y = 0; y < chunkSize; y++)
		{
			for (int z = 0; z < chunkSize; z++)
			{
				voxelMap[x][y][z] = true;
			}
		}
	}
}

void Chunk::createMeshData()
{
	for (int x = 0; x < chunkSize; x++)
	{
		for (int y = 0; y < chunkSize; y++)
		{
			for (int z = 0; z < chunkSize; z++)
			{
				addBlockData(glm::vec3(x, y, z));
			}
		}
	}
}

bool Chunk::checkVoxel(glm::vec3 pos)
{
	int x = glm::floor(pos.x);
	int y = glm::floor(pos.y);
	int z = glm::floor(pos.z);

	if (x < 0 || x > chunkSize - 1 || y < 0 || y > chunkSize - 1 || z < 0 || z > chunkSize - 1)
		return false;

	return voxelMap[x][y][z];
}

void Chunk::addBlockData(glm::vec3 pos)
{
	for (int i = 0; i < 6; i++)
	{
		if (!checkVoxel(pos + faceChecks[i]))
		{
			for (int p = 0; p < 4; p++)
			{
				int triangleIndex = triangles[i][p];
				vertices.push_back(pos.x + vertexPositions[triangleIndex].x);
				vertices.push_back(pos.y + vertexPositions[triangleIndex].y);
				vertices.push_back(pos.z + vertexPositions[triangleIndex].z);

				vertices.push_back(vertexColors[triangleIndex].x);
				vertices.push_back(vertexColors[triangleIndex].y);
				vertices.push_back(vertexColors[triangleIndex].z);
				vertices.push_back(vertexColors[triangleIndex].a);
			}

			indices.push_back(vertexIndex);
			indices.push_back(vertexIndex + 1);
			indices.push_back(vertexIndex + 2);
			indices.push_back(vertexIndex + 2);
			indices.push_back(vertexIndex + 1);
			indices.push_back(vertexIndex + 3);

			vertexIndex += 4;
		}
	}
}