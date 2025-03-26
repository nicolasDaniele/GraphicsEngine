#pragma once

#include <GL/glew.h>
#include "Libraries/glm/glm/glm.hpp"
#include "Libraries/glm/glm/gtc/type_ptr.hpp"
#include "Mesh.h"

class Camera;

class LightRenderer
{
public:
	LightRenderer(MeshType meshType, Camera* camera);
	~LightRenderer() {}

	void Draw();

	glm::vec3 GetPosition() const;
	glm::vec3 GetColor() const;
	void SetPosition(glm::vec3 _position);
	void SetColor(glm::vec3 _color);
	void SetProgram(GLuint _program);

private:
	Camera* camera;
	std::vector<Vertex>vertices;
	std::vector<GLuint>indices;
	glm::vec3 position, color;
	GLuint vbo, ebo, vao, program;
};

