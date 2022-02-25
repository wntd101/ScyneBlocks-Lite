#include <gfx/shader.h>

void Shader::getFromFile(std::string path)
{
	std::ifstream stream(path);
	std::string line;
	std::stringstream ss[3];

	ShaderType type = ShaderType::NONE;

	while (getline(stream, line))
	{
		if (line.find("#type") != std::string::npos)
		{
			if (line.find("vertex") != std::string::npos)
				type = ShaderType::VERTEX;
			else if (line.find("fragment") != std::string::npos)
				type = ShaderType::FRAGMENT;
		}
		else
		{
			ss[(int)type] << line << "\n";
		}
	}

	vSrc = ss[1].str();
	fSrc = ss[2].str();
}

void Shader::compile()
{
	int success;
	char infoLog[512];

	const char* _vsrc = vSrc.c_str();
	const char* _fsrc = fSrc.c_str();

	vShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vShader, 1, &_vsrc, NULL);
	glCompileShader(vShader);

	glGetShaderiv(vShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vShader, 512, NULL, infoLog);
		std::cout << "Vertex Shader Compilation Error: " << infoLog << std::endl;
	}
	
	fShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fShader, 1, &_fsrc, NULL);
	glCompileShader(fShader);

	glGetShaderiv(fShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fShader, 512, NULL, infoLog);
		std::cout << "Fragment Shader Compilation Error: " << infoLog << std::endl;
	}

	program = glCreateProgram();
	glAttachShader(program, vShader);
	glAttachShader(program, fShader);
	glLinkProgram(program);

	glGetProgramiv(program, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetProgramInfoLog(program, 512, NULL, infoLog);
		std::cout << "Failed To Link Shader Program: " << infoLog << std::endl;
	}

	glDeleteShader(vShader);
	glDeleteShader(fShader);
}

void Shader::init(std::string name)
{
	getFromFile("res/shaders/" + name + ".glsl");
	compile();
}

void Shader::use()
{
	glUseProgram(program);
}

void Shader::detach()
{
	glUseProgram(0);
}

void Shader::uploadFloat(const char* varName, float value)
{
	int loc = glGetUniformLocation(program, varName);
	use();
	glUniform1f(loc, value);
}

void Shader::uploadMat4(const char* varName, glm::mat4& value)
{
	int loc = glGetUniformLocation(program, varName);
	use();
	glUniformMatrix4fv(loc, 1, GL_FALSE, glm::value_ptr(value));
}