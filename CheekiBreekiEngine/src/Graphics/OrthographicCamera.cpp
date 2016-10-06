#include "OrthographicCamera.h"
#include <glm\gtx\transform.hpp>

namespace CheekiBreekiEngine {
	OrthographicCamera::OrthographicCamera(float left, float right, float botton, float top, float zNear, float zFar) 
		: left(left), right(right), botton(botton), top(top), zNear(zNear), zFar(zFar){
	}
	glm::mat4 OrthographicCamera::projectionMtx() {
		return glm::ortho(left, right, botton, top, zNear, zFar);
	}
}

