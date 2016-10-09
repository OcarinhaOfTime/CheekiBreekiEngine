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
		PerspectiveCamera(float fov = 60, float aspectRatio = 4.0f / 3.0f, float nearClippingPlane = 0.01f, float farClippingPlane = 100) : fov(fov), aspectRatio(aspectRatio), nearClippingPlane(nearClippingPlane), farClippingPlane(farClippingPlane){}
	};
}