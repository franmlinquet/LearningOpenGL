#include "libs.h"
#include "Shader.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

const GLint WIDTH = 1600, HEIGHT = 1200;


int main() {

	/* GLFW Init */
	glfwInit();

	/* Setting OpenGL Context config */
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	/* Create Window & Context */
	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "OpenGL v3.3 Project", NULL, NULL);
	if (!window) {
		std::cout << "Failed to create GLFW window" << std::endl;
		return -1;
	}

	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	/* GLAD Init */

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}


	Shader myShader("vertexShaderSource.glsl", "fragmentShaderSource.glsl");


	/* Vertex data[] */
	/*float vertices[] = {
		-0.5f, -0.5f, 0.0f, // Bottom left
		0.5f, -0.5f, 0.0f,  // Bottom right
		0.0f, 0.5f, 0.0f    // Top mid
	};*/

	float vertices[] = {
		 0.5f,  0.5f, 0.0f, 1.0f, 0.0f, 0.0f, // top right
		 0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, // bottom right
		-0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, // bottom left
		-0.5f,  0.5f, 0.0f, 1.0f, 1.0f, 1.0f  // top left 
	};
	unsigned int indices[] = {  // note that we start from 0!
		0, 1, 3,   // first triangle
		1, 2, 3    // second triangle
	};

	/* Generate Vertex Buffer & Array */
	unsigned int VBO, VAO, EBO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	/* Bind VAO First, Then bind & set buffer(s), and then configure attributes */
	/* First generate/configure all the VAOs */
	glBindVertexArray(VAO);


	/* Bind Vertex Buffer */
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW); 


	/* Bind Element Buffer */
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);


	/* Linking Vertex Attributes */
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*) 0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	/* Unbinding VAO in case of re-writing accidentally */
	glBindVertexArray(0);

	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	/* Render Loop */
	while (!glfwWindowShouldClose(window)) {
		/* Input */
		processInput(window);

		/* Render */
		glClearColor(0.7f, 0.7f, 0.8f, 0.5f);
		glClear(GL_COLOR_BUFFER_BIT);

		/* Drawing Triangle */
		myShader.use();
		glBindVertexArray(VAO);
		//glDrawArrays(GL_TRIANGLES, 0, 3);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

		/* Swap Buffer */
		glfwSwapBuffers(window);

		/* Poll Events*/
		glfwPollEvents();
	}

	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
	

	glfwTerminate();

	return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window) {
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, GL_TRUE);
	}
}