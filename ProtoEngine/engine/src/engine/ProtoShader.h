#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace ProtoEngine {

	class ProtoShader
	{
		public:
			ProtoShader(const char* vertexLocation, const char* fragmentLocation);
			~ProtoShader();

			void Use();

			void SetUniform(const std::string& name, float value);
			void SetUniform(const std::string& name, int value);

		private:
			GLuint programID;
			
			GLuint CompileShader(const char* source, GLenum type);
			void checkCompileErrors(GLuint shader, std::string type);
			//std::string LoadShader(const char* location);

			const char* vertexShaderSource = "#version 330 core\n"
				"layout (location = 0) in vec3 aPos;\n"
				"void main()\n"
				"{\n"
				"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
				"}\0";
			const char* fragmentShaderSource = "#version 330 core\n"
				"out vec4 FragColor;\n"
				"void main()\n"
				"{\n"
				"   FragColor = vec4(0.0f, 0.0f, 0.0f, 1.0f);\n"
				"}\n\0";

	};

}
