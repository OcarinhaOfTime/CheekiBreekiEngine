#pragma once
#include <glm\glm.hpp>

namespace CheekiBreekiEngine {
	class Camera {
		glm::vec3 position;
		glm::vec3 look;
		glm::vec3 up;
		glm::vec3 right;

	public:
		Camera() : up(glm::vec3(0, 1, 0)) {}
	};
}