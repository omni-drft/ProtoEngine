/* ======================== PURPOSE OF FILE ========================
* 
* This file is the entry point for the application. 
*	It creates a window using GLFW and GLEW, 
* and then enters a loop to render the window.
* 
================================================================== */

// Link OpenGL Extension Wrangler
#include <GL/glew.h>

// Link GLFW for window creation and input handling
#include <GLFW/glfw3.h>

// Link GLM for algebra
#include <glm/glm.hpp>

// Link standard libraries
#include <iostream>
#include <Windows.h>
#include <vector>

// Link custom classes
#include "HandleInput.h"
#include "Shader.h"
#include "Window.h"
#include "Object.h"

int main()
{


	// ======================== FIRST OBJECT DATA - ONLY TEMPORARY ========================
	// Define the vertices of a rectangle
	std::vector<float> vertices {
		100.0f, 100.0f,   // bottom-left
		200.0f, 100.0f,   // bottom-right
		200.0f, 200.0f,   // top-right
		100.0f, 200.0f    // top-left
	};

	// Define the indices to form two triangles (making a rectangle)
	std::vector<int> indices {
			0, 1, 2,  // first triangle
			2, 3, 0   // second triangle
	};
	// ====================================================================================



	// Close the console window if in release mode
	#ifdef NDEBUG
	FreeConsole();
	#endif // NDEBUG

	// Create a window
	ProtoEngine::Window window(2560, 1600, "ProtoEngine");

	// Initialise the input handler
	ProtoEngine::HandleInput inputHandler(window);

	// Create a shader
	ProtoEngine::Shader shader("Source/Shaders/vertexShader.glsl", "Source/Shaders/fragmentShader.glsl");
	shader.Use();	
	int currentWidth{}, currentHeight{};

	ProtoEngine::Object rectangle(vertices, indices);

	// Check for OpenGL errors
	#ifdef DEBUG
	GLenum error{ glGetError() };
	if (error != GL_NO_ERROR) {
		std::cerr << "OpenGL error: " << error << std::endl;
	}
	#endif // DEBUG

	// Loop until the user closes the window
	while (!glfwWindowShouldClose(window.GetWindow()))
	{
		// Clear the window
		window.ClearWindow();

		// Use the shader
		shader.Use();

		// Set the projection matrix
		window.GetDimensions(&currentWidth, &currentHeight);

		glViewport(0, 0, currentWidth, currentHeight);

		glm::mat4 projection{ glm::ortho(0.0f, static_cast<float>(currentWidth), 0.0f, static_cast<float>(currentHeight), -1.0f, 1.0f) };

		shader.SetMat4("projection", projection);
		shader.SetVec4("objectColor", 0.0f, 0.0f, 0.0f, 1.0f);

		// Draw the rectangle
		rectangle.Draw();

		// Swap front and back buffers
		window.SwapBuffers();

		// Poll for and process events
		window.PollEvents();

		// Check for OpenGL errors
		#ifdef DEBUG
		GLenum error{ glGetError() };
		if (error != GL_NO_ERROR) {
			std::cerr << "OpenGL error: " << error << std::endl;
		}
		#endif // DEBUG

	}

	return 0;
}