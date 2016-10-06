#pragma once
#include <Graphics\Camera.h>

namespace CheekiBreekiEngine {
	class OrthographicCamera : public Camera{
		float left, right, botton, top;
		float zNear, zFar;
	public:
		OrthographicCamera(float left = 0, float right = 10, float botton = 0, float top = 10, float zNear = 0.01f, float zFar = 100.0f);
		// Inherited via Camera
		virtual glm::mat4 projectionMtx() override;
	};
}