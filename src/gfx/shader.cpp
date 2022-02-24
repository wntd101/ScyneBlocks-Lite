#include <main.h>
#include <fstream>
#include <sstream>

enum class ShaderType
{
	VERTEX = 0, FRAGMENT = 1
};

class Shader
{
private:

	std::string filePath;

	unsigned int vertexID, fragmentID;
	unsigned int programID;

	std::string vertexSrc;
	std::string fragmentSrc;

	ShaderType type;

	int success;

public:

	void init(std::string name)
	{
		this->filePath = "res/shaders/" + name + ".glsl";

		std::ifstream stream(filePath);
		std::string line;
		std::stringstream ss[2];

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

		vertexSrc = ss[0].str();
		fragmentSrc = ss[1].str();

	}

	void compile()
	{
		const char* vs = vertexSrc.c_str();
		const char* fs = fragmentSrc.c_str();

		//==== Compile Vertex Shader ====//

		vertexID = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(vertexID, 1, &vs, nullptr);
		glCompileShader(vertexID);

		glGetShaderiv(vertexID, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			int infoLogLen;
			glGetShaderiv(vertexID, GL_INFO_LOG_LENGTH, &infoLogLen);
			char* infoLog = (char*)_malloca(infoLogLen * sizeof(char));
			glGetShaderInfoLog(vertexID, infoLogLen, &infoLogLen, infoLog);
			std::cout << "Error While Compiling Vertex Shader: " << infoLog << std::endl;
			return;
		}

		//==== Compile Fragment Shader ====//

		fragmentID = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragmentID, 1, &fs, nullptr);
		glCompileShader(fragmentID);

		glGetShaderiv(fragmentID, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			int infoLogLen;
			glGetShaderiv(fragmentID, GL_INFO_LOG_LENGTH, &infoLogLen);
			char* infoLog = (char*)_malloca(infoLogLen * sizeof(char));
			glGetShaderInfoLog(fragmentID, infoLogLen, &infoLogLen, infoLog);
			std::cout << "Error While Compiling Vertex Shader: " << infoLog << std::endl;
			return;
		}

		//==== Create Shader Program And Link Shaders ====//
		programID = glCreateProgram();
		glAttachShader(programID, vertexID);
		glAttachShader(programID, fragmentID);
		glLinkProgram(programID);
		glValidateProgram(programID);

		glDetachShader(programID, vertexID);
		glDetachShader(programID, fragmentID);
	}

	void use()
	{
		glUseProgram(programID);
	}

	void detach()
	{
		glUseProgram(0);
	}

};