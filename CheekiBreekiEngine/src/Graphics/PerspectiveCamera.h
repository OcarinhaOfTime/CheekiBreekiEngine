#pragma once
#include <Graphics\Camera.h>
namespace CheekiBreekiEngine {
	class PerspectiveCamera : public Camera {
		float fov;
		float aspectRatio;
		float nearClippingPlane;
		float farClippingPlane;
		// Inherited via Camera
		virtual glm::mat4 projectionMtx() override;
	public:
		PerspectiveCamera(float fov, float aspectRatio, float nearClippingPlane, float farClippingPlane) : fov(fov), aspectRatio(aspectRatio), nearClippingPlane(nearClippingPlane), farClippingPlane(farClippingPlane){}
	};
}