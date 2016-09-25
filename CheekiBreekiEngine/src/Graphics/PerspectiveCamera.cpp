#include "PerspectiveCamera.h"
#include <glm\gtx\transform.hpp>

namespace CheekiBreekiEngine {
	glm::mat4 PerspectiveCamera::projectionMtx() {
		return glm::perspective(fov, aspectRatio, nearClippingPlane, farClippingPlane);
	}
}
