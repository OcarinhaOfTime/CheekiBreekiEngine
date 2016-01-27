#pragma once
#include <glm\glm.hpp>
#include <string>
using std::string;

namespace CheekiBreekiEngine {
	class Shader {
		friend class Material;
		unsigned int vertexShaderID;
		unsigned int fragmentShaderID;
		unsigned int programID;
	public:
		void loadFromFile(const char* vertexShaderPath, const char* fragmentShaderPath);
		void loadFromFile(string vertexShaderPath, string fragmentShaderPath);
		~Shader();

		void bind();
		void unbind();
	};
}
