#include "Camera.h"
#include <glm\gtx\transform.hpp>

void CheekiBreekiEngine::Camera::setPosition(glm::vec3 position) {
	this->position = position;
}

void CheekiBreekiEngine::Camera::setLook(glm::vec3 look) {
	this->look = look;
}

void CheekiBreekiEngine::Camera::setUp(glm::vec3 up) {
	this->up = up;
}

glm::mat4 CheekiBreekiEngine::Camera::viewMtx() {
	return glm::lookAt(position, look, up);
}

glm::mat4 CheekiBreekiEngine::Camera::VPMtx() {
	return projectionMtx() * viewMtx();
}
