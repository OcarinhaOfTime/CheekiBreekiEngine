#pragma once
#include <glm\glm.hpp>

namespace CheekiBreekiEngine {
	class Vector2 {
		glm::vec2 vec;

	public:
		double x, y;
		Vector2(double x, double y);
		Vector2 operator+ (const Vector2 &other) {

		}
	};
}
