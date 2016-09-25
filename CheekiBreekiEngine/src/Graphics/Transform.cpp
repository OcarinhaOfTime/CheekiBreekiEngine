#include "Transform.h"
#include <GL\glew.h>
#include <glm\gtx\transform.hpp>

namespace CheekiBreekiEngine {
	void Transform::updateMatrix() {
		matrix = translationMatrix * scaleMatrix * rotationMatrix;
	}

	void Transform::setPosition(glm::vec3 position) {
		translationMatrix = glm::translate(identityMatrix, position);
	}

	void Transform::setScale(glm::vec3 scale) {
		scaleMatrix = glm::scale(identityMatrix, scale);
	}

	void Transform::setRotation(glm::vec3 rotation) {
		rotationMatrix = glm::rotate(identityMatrix, rotation.x, glm::vec3(1, 0, 0));
		rotationMatrix *= glm::rotate(identityMatrix, rotation.y, glm::vec3(0, 1, 0));
		rotationMatrix *= glm::rotate(identityMatrix, rotation.z, glm::vec3(0, 0, 1));
	}

	void Transform::setRotation(float angle, glm::vec3 dir) {
		rotationMatrix = glm::rotate(identityMatrix, angle, dir);
	}

	glm::mat4 Transform::modelMtx() {
		return translationMatrix * scaleMatrix * rotationMatrix;
	}
}