/* ======================== PURPOSE OF FILE ========================
* 
* This file is the header for the HandleInput class. 
* HandleInput class processes all necessary kinds of input
* that a user can provide to the application.
* 
==================================================================*/

#pragma once

// Library Includes
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "Window.h"
#include "Log.h"

/// <summary>
/// General purpose namespace for the engine
/// </summary>
namespace ProtoEngine
{
	/// <summary>
	/// Class to handle input from the user
	/// </summary>
	class HandleInput
	{
	public:
		/// <summary>
		/// Constructor for the input handler
		/// </summary>
		/// <param name="window">- pointer to window that currently takes input</param>
		HandleInput(Window* window);

	private:
		/// <summary>
		/// Current window that is taking input
		/// </summary>
		Window* inputWindow;

		/// <summary>
		/// Static callback function for handling all key presses
		/// </summary>
		static void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

		/// <summary>
		/// Static callback function for handling the cursor position
		/// </summary>
		static void CursorPositionCallback(GLFWwindow* window, double xpos, double ypos);

		/// <summary>
		/// Static callback function for handling mouse button presses
		/// </summary>
		static void MouseButtonCallback(GLFWwindow* window, int button, int action, int mods);

		/// <summary>
		/// Static callback function for handling mouse scrolling
		/// </summary>
		static void ScrollCallback(GLFWwindow* window, double xoffset, double yoffset);

		/// <summary>
		/// Static callback function for handling character input
		/// </summary>
		static void CharacterCallback(GLFWwindow* window, unsigned int codepoint);
	};
}