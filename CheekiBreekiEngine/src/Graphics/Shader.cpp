#include <GL\glew.h>

#include <Graphics\Shader.h>
#include <Core\IOUtils.h>

#include <iostream>
#include <fstream>

using std::cout;
using std::endl;

namespace CheekiBreekiEngine {
	bool checkStatus(
		GLuint objID,
		PFNGLGETSHADERIVPROC objPropertyGetterFunc,
		PFNGLGETSHADERINFOLOGPROC getInfoLogFunc,
		GLenum statusType
		) {
		GLint status;
		objPropertyGetterFunc(objID, statusType, &status);
		if (status != GL_TRUE) {
			GLint infoLogLength;
			objPropertyGetterFunc(objID, GL_INFO_LOG_LENGTH, &infoLogLength);
			GLchar* buffer = new GLchar[infoLogLength];

			GLsizei bufferSizeUseless;
			getInfoLogFunc(objID, infoLogLength, &bufferSizeUseless, buffer);

			std::cout << buffer << std::endl;
			delete[] buffer;

			return false;
		}

		return true;
	}

	bool checkShaderStatus(GLuint shaderID) {
		return checkStatus(shaderID, glGetShaderiv, glGetShaderInfoLog, GL_COMPILE_STATUS);
	}

	bool checkProgramStatus(GLuint programID) {
		return checkStatus(programID, glGetProgramiv, glGetProgramInfoLog, GL_LINK_STATUS);
	}

	void Shader::loadFromFile(const char * vertexShaderPath, const char * fragmentShaderPath) {
		string temp, temp2;
		temp = IOUtils::readFile(vertexShaderPath);
		temp2 = IOUtils::readFile(fragmentShaderPath);

		const char * vCode = temp.c_str();
		const char * fCode = temp2.c_str();

		vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
		fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
		const char* adapter[1];
		adapter[0] = vCode;
		glShaderSource(vertexShaderID, 1, adapter, 0);
		adapter[0] = fCode;
		glShaderSource(fragmentShaderID, 1, adapter, 0);

		glCompileShader(vertexShaderID);
		if (!checkShaderStatus(vertexShaderID)) {
			cout << "Shader " << vertexShaderPath << " not compiled";
		}

		glCompileShader(fragmentShaderID);
		if (!checkShaderStatus(fragmentShaderID)) {
			cout << "Shader " << fragmentShaderPath << " not compiled";
		}

		programID = glCreateProgram();
		glAttachShader(programID, vertexShaderID);
		glAttachShader(programID, fragmentShaderID);

		glLinkProgram(programID);
		checkProgramStatus(programID);
	}

	void Shader::loadFromFile(string vertexShaderPath, string fragmentShaderPath) {
		loadFromFile(vertexShaderPath.c_str(), fragmentShaderPath.c_str());
	}

	Shader::~Shader() {
		glDeleteShader(vertexShaderID);
		glDeleteShader(fragmentShaderID);
		glDeleteProgram(programID);
	}

	void Shader::bind() {
		glUseProgram(programID);
	}

	void Shader::unbind() {
		glUseProgram(0);
	}
}