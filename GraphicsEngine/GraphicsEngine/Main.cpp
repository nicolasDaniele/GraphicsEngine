#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "ShaderLoader.h"
#include "Camera.h"
#include "LightRenderer.h"
#include "MeshRenderer.h"
#include "TextureLoader.h"
#include "Utils.h"

const int WIDTH = 800;
const int HEIGHT = 600;

Camera* camera;
LightRenderer* light;
MeshRenderer* mesh;
ShaderLoader shader;

float lastMouseXPos = WIDTH / 2.0f;
float lastMouseYPos = HEIGHT / 2.0f;
bool firstMouse = true;
float deltaTime = 0.0f;
float lastFrame = 0.0f;

void InitGame();
void RenderScene();
void HandleInput(GLFWwindow* window);
void MouseMoveCallback(GLFWwindow* window, double xposIn, double yposIn);

static void glfwError(int id, const char* description)
{
	std::cout << description << std::endl;
}

int main(int argc, char** argv)
{
	glfwSetErrorCallback(&glfwError);
	glfwInit();

	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Graphics Engine", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}

	glfwSetCursorPosCallback(window, MouseMoveCallback);

	glfwMakeContextCurrent(window);
	glewInit();
	InitGame();

	while (!glfwWindowShouldClose(window)) 
	{
		float currentFrame = static_cast<float>(glfwGetTime());
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;

		glm::mat4 projection = glm::perspective(glm::radians(camera->GetZoomAmount()), (float)WIDTH / (float)HEIGHT, 0.1f, 100.0f);
		//shader.setMat4("projection", projection);

		glm::mat4 view = camera->GetViewMatrix();
		//shader.setMat4("view", view);

		RenderScene();
		glfwSwapBuffers(window);
		glfwPollEvents();
		HandleInput(window);
	}

	glfwTerminate();

	delete camera;
	delete light;

	return 0;
}

void InitGame()
{
	glEnable(GL_DEPTH_TEST);
 
	GLuint flatShaderProgram = shader.CreateProgram("Assets/Shaders/FlatModel.vs",
			"Assets/Shaders/FlatModel.fs");

	GLuint texturedShaderProgram =
		shader.CreateProgram("Assets/Shaders/TexturedModel.vs",
			"Assets/Shaders/TexturedModel.fs");

	camera = new Camera(45.0f, WIDTH, HEIGHT, 0.1f, 100.0f, glm::vec3(0.0f, 0.0f, 6.0f));

	light = new LightRenderer(MeshType::MT_Triangle, camera);
	light->SetProgram(flatShaderProgram);
	light->SetPosition(glm::vec3(0.0f, 0.0f, 0.0f));

	TextureLoader tLoader;
	GLuint texture = tLoader.GetTextureID("Assets/Textures/arcade.png");

	mesh = new MeshRenderer(MeshType::MT_Cube, camera);
	mesh->SetProgram(texturedShaderProgram);
	mesh->SetTexture(texture);
	mesh->SetPosition(glm::vec3(0.0f, 0.0f, 0.0f));
	mesh->SetScale(glm::vec3(1.0f));
}

void RenderScene() 
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(1.0, 1.0, 0.0, 1.0);

	if(mesh)
		mesh->Draw();
}

void HandleInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
	
	if (camera)
	{
		if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS || glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
			camera->MoveCamera(Utils::Direction::FORWARD, deltaTime);
		if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS || glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
			camera->MoveCamera(Utils::Direction::BACKWARD, deltaTime);
		if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS || glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
			camera->MoveCamera(Utils::Direction::LEFT, deltaTime);
		if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS || glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
			camera->MoveCamera(Utils::Direction::RIGHT, deltaTime);
	}
}

void MouseMoveCallback(GLFWwindow* window, double xposIn, double yposIn)
{
	float xpos = static_cast<float>(xposIn);
	float ypos = static_cast<float>(yposIn);

	if (firstMouse)
	{
		lastMouseXPos = xpos;
		lastMouseYPos = ypos;
		firstMouse = false;
	}

	float xoffset = xpos - lastMouseXPos;
	float yoffset = lastMouseYPos - ypos;

	lastMouseXPos = xpos;
	lastMouseYPos = ypos;

	camera->RotateCamera(xoffset, yoffset);
}