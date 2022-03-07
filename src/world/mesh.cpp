#include <world/mesh.h>
void Mesh::init(float verts[], int tris[], int vertCount, int triCount)
{
	//Assign arrays to members
	for (int i = 0; i < vertCount; i++)
	{
		vertices.push_back(verts[i]);
	}
	for (int i = 0; i < triCount; i++)
	{
		indices.push_back(tris[i]);
	}

	this->triCount = triCount;

	//==== Generate VAO, VBO, EBO ====//

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	vbo.bind(GL_ARRAY_BUFFER, vertCount * sizeof(float), vertices.data(), GL_STATIC_DRAW);
	vbo.bind(GL_ELEMENT_ARRAY_BUFFER, triCount * sizeof(int), indices.data(), GL_STATIC_DRAW);

	//==== Vertex Attributes ====//

	int vertPosSize = 3, vertColorSize = 4;
	int vertexSizeInBytes = (vertPosSize + vertColorSize) * sizeof(float);

	glVertexAttribPointer(0, vertPosSize, GL_FLOAT, GL_FALSE, vertexSizeInBytes, 0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, vertColorSize, GL_FLOAT, GL_FALSE, vertexSizeInBytes, (const void*)(sizeof(float) * vertPosSize));
	glEnableVertexAttribArray(1);
}

void Mesh::render()
{
	glBindVertexArray(vao);
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);

	glDrawElements(GL_TRIANGLES, triCount, GL_UNSIGNED_INT, 0);
}

void Mesh::remove()
{
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);

	glBindVertexArray(0);
}