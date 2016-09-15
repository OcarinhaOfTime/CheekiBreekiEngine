#pragma once
#include <string>
#include <Graphics\Texture.h>
#include <Graphics\Sampler2D.h>
#include <Graphics\Shader.h>
#include <map>
#include <vector>
using std::string;
using std::map;
using std::vector;

namespace CheekiBreekiEngine {
	class Material {
		unsigned int programID;
		unsigned int mvpID;

		map<unsigned int, float> floatUniforms;
		map<unsigned int, glm::vec3> vec3Uniforms;
		map<unsigned int, glm::vec4> vec4Uniforms;
		map<unsigned int, glm::mat4> mat4Uniforms;

		vector<Sampler2D*> samplers;

		void bindUniforms();
		void bindSampler(Sampler2D* sampler);
	public:
		~Material();

		void initialise(Shader*);

		void setMatrixUniform(const char* uniformName, glm::mat4& MVP);
		void setMVP(glm::mat4& mtx);

		void setVec3Uniform(const char* uniformName, glm::vec3& vec);

		void addFloatUniform(const char* uniformName, float f);
		void addVec3Uniform(const char* uniformName, glm::vec3& vec);
		void addVec4Uniform(const char* uniformName, glm::vec4& vec);
		void addMat4Uniform(const char* uniformName, glm::mat4& mat);

		void addSample(string uniformName, Texture* texture);
		void addSample(string uniformName, Texture* texture, unsigned int textureWrapS, unsigned int textureWrapT);

		void bind();
		void unbind();
	};
}
