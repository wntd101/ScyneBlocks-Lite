#pragma once

#include <main.h>
#include <world/voxeldata.h>
#include <world/mesh.h>
#include <gfx/shader.h>
#include <world/player.h>

#include <vector>

class Chunk
{
private:
	Mesh mesh;
	Shader shader;

	int vertexIndex = 0;
	std::vector<float> vertices;
	std::vector<int> indices;
	bool voxelMap[chunkSize][chunkSize][chunkSize];

public:
	void init();
	void update(Player p);
	void initializeVoxelMap();
	void createMeshData();
	bool checkVoxel(glm::vec3 pos);
	void addBlockData(glm::vec3 pos);
};