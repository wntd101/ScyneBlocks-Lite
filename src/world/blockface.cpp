#include <world/blockface.h>

void BlockFace::init(float verts[VERTEXARRAYLEN], unsigned int tris[INDICESARRAYLEN])
{
	//Assign arrays to members
	for (int i = 0; i < VERTEXARRAYLEN; i++)
	{
		vertices[i] = verts[i];
	}
	for (int i = 0; i < INDICESARRAYLEN; i++)
	{
		indices[i] = tris[i];
	}

	//==== Generate VAO, VBO, EBO ====//

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glGenBuffers(1, &ebo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	//==== Vertex Attributes ====//

	int vertPosSize = 3, vertColorSize = 4;
	int vertexSizeInBytes = (vertPosSize + vertColorSize) * sizeof(float);

	glVertexAttribPointer(0, vertPosSize, GL_FLOAT, GL_FALSE, vertexSizeInBytes, 0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, vertColorSize, GL_FLOAT, GL_FALSE, vertexSizeInBytes, (const void*)(sizeof(float) * vertPosSize));
	glEnableVertexAttribArray(1);
}

void BlockFace::render()
{
	glBindVertexArray(vao);
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);

	glDrawElements(GL_TRIANGLES, INDICESARRAYLEN, GL_UNSIGNED_INT, 0);
}

void BlockFace::remove()
{
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);

	glBindVertexArray(0);
}