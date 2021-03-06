#pragma once
#include <glm\glm.hpp>
#include <string>
using std::string;

namespace CheekiBreekiEngine {
	class Shader {
		friend class Material;
		unsigned int vertexShaderID;
		unsigned int fragmentShaderID;
	public:
		unsigned int programID;
		void loadFromFile(const char* vertexShaderPath, const char* fragmentShaderPath);
		void loadFromFile(string vertexShaderPath, string fragmentShaderPath);
		void loadFromFile(string shaderPath);
		~Shader();

		void bind();
		void unbind();
	};
}
