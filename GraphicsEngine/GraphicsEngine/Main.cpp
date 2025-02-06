#include <GL/glew.h>
#include <GLFW/glfw3.h>

int main(int argc, char** argv)
{
		glfwInit();
	GLFWwindow* window = glfwCreateWindow(800,
		600,
		" Hello OpenGL ",
		NULL,
		NULL);
	return 0;
}