#include "LightRenderer.h"
#include "Camera.h"

LightRenderer::LightRenderer(MeshType meshType, Camera* camera)
{
	this->camera = camera;

	switch (meshType) {
	case MT_Triangle: Mesh::SetTriangleData(vertices, indices);
		break;
	case MT_Quad: Mesh::SetQuadData(vertices, indices); 
		break;
	case MT_Cube: Mesh::SetCubeData(vertices, indices); 
		break;
	case MT_Sphere: Mesh::SetSphereData(vertices, indices);
		break;
	}

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * vertices.size(),
		&vertices[0], GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex),	(GLvoid*)0);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex),
		(void*)(offsetof(Vertex, Vertex::color)));

	glGenBuffers(1, &ebo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint) * indices.size(), 
		&indices[0], GL_STATIC_DRAW);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void LightRenderer::Draw()
{
	glm::mat4 model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0), position);

	glUseProgram(this->program);
	GLint modelLoc = glGetUniformLocation(program, "model");
	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

	glm::mat4 view = camera->GetViewMatrix();
	GLint vLoc = glGetUniformLocation(program, "view");
	glUniformMatrix4fv(vLoc, 1, GL_FALSE, glm::value_ptr(view));
	glm::mat4 proj = camera->GetProjectionMatrix();
	GLint pLoc = glGetUniformLocation(program, "projection");
	glUniformMatrix4fv(pLoc, 1, GL_FALSE, glm::value_ptr(proj));

	glBindVertexArray(vao);
	glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);

	glBindVertexArray(0);
	glUseProgram(0);
}

glm::vec3 LightRenderer::GetPosition() const
{
	return position;
}

glm::vec3 LightRenderer::GetColor() const
{
	return color;
}

void LightRenderer::SetPosition(glm::vec3 _position)
{
	position = _position;
}

void LightRenderer::SetColor(glm::vec3 _color)
{
	this->color = _color;
}

void LightRenderer::SetProgram(GLuint _program)
{
	this->program = _program;
}

