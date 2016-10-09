#include <Graphics\Camera.h>
#include <glm\gtx\transform.hpp>
void CheekiBreekiEngine::Camera::move(float x, float y, float z) {
	this->position += this->right * x + this->up * y + this->look * z;
}

void CheekiBreekiEngine::Camera::lookAt(float x, float y, float z) {
	this->position = glm::vec3(x, y, z);
}

glm::mat4 CheekiBreekiEngine::Camera::viewMtx() {
	return glm::lookAt(position, look, up);
}

glm::mat4 CheekiBreekiEngine::Camera::VPMtx() {
	return projectionMtx() * viewMtx();
}
