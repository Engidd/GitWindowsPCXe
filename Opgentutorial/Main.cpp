#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>

#include"shaderClass.h"
#include"VAO.h"
#include"VBO.h"
#include"EBO.h"

//Vertices coordinates
GLfloat vertices[] =
{
	-0.5f , -0.5f * float(sqrt(3)) / 3, 0.0f,
	0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f,
	0.0f, 0.5f * float(sqrt(3)) * 2 / 3, 0.0f,
	-0.25f, 0.5f * float(sqrt(3)) / 6, 0.0f,
	0.25f, 0.5f * float(sqrt(3)) / 6, 0.0f,
	0.0f, -0.5f * float(sqrt(3)) / 3, 0.0f,
};

//Indices for vertices order
GLuint indices[] =
{
0,3,5,
3,2,4,
5,4,1
};


int	main()
{
	//initialize glfw
	glfwInit();
	
	//tell glfw what version to use
	//this proj 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	//tell glfw we are using CORE Profile
	//only to have modern functions
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	
	//create window 800800
	GLFWwindow* window = glfwCreateWindow(800, 800, "somethingwindow", NULL, NULL);
	
	//of something bad happens quit
	if (window == NULL)
	{
		std::cout << "you did something wrong" << std::endl ;
		glfwTerminate();
		return -1;
	}

	//introduce window to the current context
	glfwMakeContextCurrent(window);

	//load glad
	gladLoadGL();

	//specify viewport of OpenGl in the window
	//goes from 0,0 to 800,800
	glViewport(0, 0, 800, 800);

	// Generates Shader object using shaders defualt.vert and default.frag
	Shader shaderProgram("default.vert", "default.frag");

	VAO VAO1;
	VAO1.Bind();

	// Generates Vertex Buffer Object and links it to vertices
	VBO VBO1(vertices, sizeof(vertices));
	// Generates Element Buffer Object and links it to indices
	EBO EBO1(indices, sizeof(indices));
	

	VAO1.LinkVBO(VBO1, 0);

	VAO1.Unbind();
	VBO1.Unbind();
	EBO1.Unbind();
	
	/*
	GLuint vertexshader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexshader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexshader);

	GLuint fragmentshader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentshader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentshader);

	GLuint shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexshader);
	glAttachShader(shaderProgram, fragmentshader);
	glLinkProgram(shaderProgram);

	glDeleteShader(vertexshader);
	glDeleteShader(fragmentshader);


	GLuint VAO, VBO, EBO;


	//care these orders might be false prone to error 90, 87
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	//specify color background
	glad_glClearColor(0.08f, 0.8f, 0.7f, 1.0f);
	
	//clear the backbuffer and add the new color to it.
	glClear(GL_COLOR_BUFFER_BIT);
	
	//swap buffers
	glfwSwapBuffers(window);
	*/

	//main while loop
	while (!glfwWindowShouldClose(window))
	{
		// Specify the color of the background
		glClearColor(0.08f, 0.13f, 0.17f, 1.0f);
		// Clean the back buffer and assign the new color to it
		glClear(GL_COLOR_BUFFER_BIT);
		// Tell OpenGL which Shader Program we want to use
		shaderProgram.Activate();
		//Bind the VAO so OpenGL knows to use it.
		VAO1.Bind();
		// Draw primitives, number of indices, datatype of indices, index of indices
		glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, 0);
		// Swap the back buffer with the front buffer
		glfwSwapBuffers(window);

		//take care of all glfw events
		glfwPollEvents();
		
		
	}

	//Delete things we created

	VAO1.Delete();
	VBO1.Delete();
	EBO1.Delete();
	shaderProgram.Delete();

	//delete window before termination
	glfwDestroyWindow(window);

	//terminate glfw before ending the program
	glfwTerminate();
	return 0;
}