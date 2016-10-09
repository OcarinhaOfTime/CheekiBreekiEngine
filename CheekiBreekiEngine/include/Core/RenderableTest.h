#pragma once
#include <Graphics\Renderable.h>
#include <Graphics\Mesh.h>
#include <Graphics\Shader.h>
#include <Graphics\Texture.h>
#include <Graphics\Material.h>
#include <Graphics\Transform.h>
#include <Graphics\Camera.h>

namespace CheekiBreekiEngine {
	class RenderableTest : public Renderable{		
	public:
		Mesh* mesh;
		Shader* shader;
		Material* material;
		Texture* texture;
		Camera* cam;
		Transform* transform;

		RenderableTest();

		// Inherited via Renderable
		virtual void start() override;
		virtual void update() override;
		virtual void terminate() override;
	};
}