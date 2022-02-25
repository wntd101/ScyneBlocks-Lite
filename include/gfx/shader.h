#pragma once

#include <main.h>

#include <glm.hpp>
#include <gtc/type_ptr.hpp>

#include <fstream>
#include <sstream>

class Shader
{
private:

	enum class ShaderType
	{
		NONE = 0, VERTEX = 1, FRAGMENT = 2
	};

	unsigned int vShader = 0, fShader = 0;
	unsigned int program = 0;

	std::string vSrc;
	std::string fSrc;

	void getFromFile(std::string path);

	void compile();

public:

	void init(std::string name);
	void use();
	void detach();

	void uploadFloat(const char* varName, float value);
	void uploadMat4(const char* varName, glm::mat4& value);
};