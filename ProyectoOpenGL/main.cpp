#include "libs.h"

int main() {

	/* GLFW Init */
	glfwInit();

	/* Setting OpenGL Context config */
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	/* Create Window & Context */
	GLFWwindow* window = glfwCreateWindow(620, 480, "OpenGL v3.3 Project", NULL, NULL);
	if (!window) {
		std::cout << "Failed to create GLFW window" << std::endl;
		return -1;
	}

	glfwMakeContextCurrent(window);

	/* GLAD Init */
	
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	/* Render Loop */
	while (!glfwWindowShouldClose(window)) {

		/* Render */
		glClearColor(0.7f, 0.2f, 0.2f, 0.7f);
		glClear(GL_COLOR_BUFFER_BIT);

		/* Swap Buffer */
		glfwSwapBuffers(window);

		/* Poll Events*/
		glfwPollEvents();
	}

	return 0;
}