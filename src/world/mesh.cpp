#include <gfx/shader.h>

class Mesh 
{
private:
	Shader shader;

	unsigned int vao, vbo;

public:
	Mesh(std::string shaderName, float a_positions[], float a_colors[], int a_indices[])
	{
		shader.init(shaderName);
		shader.compile();

		//==== Generate VAO, VBO And EBO ====//
		glGenVertexArrays(1, &vao);
		glBindVertexArray(vao);

		glGenBuffers(1, &vbo);
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glBufferData(GL_ARRAY_BUFFER, sizeof(a_positions), a_positions, GL_STATIC_DRAW);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);
	}

	void update()
	{
		shader.use();

		glBindVertexArray(vao);

		shader.detach();
	}
};