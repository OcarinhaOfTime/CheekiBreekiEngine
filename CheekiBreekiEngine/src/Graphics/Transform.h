#pragma once
#include <glm\glm.hpp>

namespace CheekiBreekiEngine {
	class Transform {
		glm::vec3 position;
		glm::vec3 scale;
		glm::vec3 rotation;

		glm::mat4 identityMatrix = glm::mat4(1.0f);
		glm::mat4 translationMatrix = glm::mat4(1.0f);
		glm::mat4 scaleMatrix = glm::mat4(1.0f);
		glm::mat4 rotationMatrix = glm::mat4(1.0f);
		glm::mat4 matrix = glm::mat4(1.0f);

		void updateMatrix();

	public:
		void setPosition(glm::vec3 position);
		void setScale(glm::vec3 scale);
		void setRotation(glm::vec3 rotation);
		void setRotation(float angle, glm::vec3 dir);
		void bind();
		glm::mat4 modelMtx();
	};
}
