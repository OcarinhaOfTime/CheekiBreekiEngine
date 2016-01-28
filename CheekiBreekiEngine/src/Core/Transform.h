#pragma once
#include <glm\gtc\quaternion.hpp>
#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>

namespace CheekiBreekiEngine {
	class Transform {
	public:
		glm::tquat<double, glm::highp> rotation;
		glm::tvec3<double, glm::highp> position;
		glm::tvec3<double, glm::highp> scale;
		

		void rotate(const glm::tvec3<double, glm::highp> &axis, const double &angle) {
			rotation = glm::rotate(rotation, angle, axis);
		}

		void translate(const glm::vec3 &diplacement) {
			position += diplacement;
		}

		void scale(const glm::vec3 &factor) {
			scale *= factor;
		}

		glm::mat4 getTransformMatrix() {
			glm::tmat4x4<double, glm::highp> mtx = glm::scale(glm::mat4_cast(rotation), scale);
			return glm::translate(mtx, position);

		}
	};
}