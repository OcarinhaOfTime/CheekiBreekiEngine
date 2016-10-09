#pragma once
#include <glm\glm.hpp>

namespace CheekiBreekiEngine {
	class Camera {
	protected:
		glm::vec3 position;
		glm::vec3 look;
		glm::vec3 up;
		glm::vec3 right;

		glm::mat4 identity = glm::mat4(1.0f);

	public:
		Camera() : up(glm::vec3(0, 1, 0)), look(glm::vec3(0, 0, -1)), right(look * up), position(glm::vec3(0, 0, -5)) {}
		void move(float x, float y, float z);
		void lookAt(float x, float y, float z);
		glm::mat4 viewMtx();
		glm::mat4 VPMtx();
		virtual glm::mat4 projectionMtx() = 0;
	};
}