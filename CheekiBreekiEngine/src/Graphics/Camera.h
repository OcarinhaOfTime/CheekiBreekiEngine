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
		Camera() : up(glm::vec3(0, 1, 0)) {}
		void setPosition(glm::vec3 position);
		void setLook(glm::vec3 look);
		void setUp(glm::vec3 up);
		glm::mat4 viewMtx();
		glm::mat4 VPMtx();
		virtual glm::mat4 projectionMtx() = 0;
	};
}