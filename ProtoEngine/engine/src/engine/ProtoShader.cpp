#include "ProtoShader.h"

namespace ProtoEngine
{
	ProtoShader::ProtoShader(const char* vertexLocation, const char* fragmentLocation)
	{
		const char* vertexCode = vertexShaderSource;
    const char* fragmentCode = fragmentShaderSource;

    //std::cout << vertexCode << "\n\n\n\n";
    //std::cout << fragmentCode << "\n\n\n\n";

    GLuint vertexShader = CompileShader(vertexCode, GL_VERTEX_SHADER);
    GLuint fragmentShader = CompileShader(fragmentCode, GL_FRAGMENT_SHADER);

    programID = glCreateProgram();
    glAttachShader(programID, vertexShader);
    glAttachShader(programID, fragmentShader);
    glLinkProgram(programID);

    checkCompileErrors(programID, "PROGRAM");

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
	}

  ProtoShader::~ProtoShader()
  {
		glDeleteProgram(programID);
	}

  void ProtoShader::Use()
  {
    glUseProgram(programID);
  }

  void ProtoShader::SetUniform(const std::string& name, float value)
  {
    glUniform1f(glGetUniformLocation(programID, name.c_str()), value);
  }

  void ProtoShader::SetUniform(const std::string& name, int value)
  {
		glUniform1i(glGetUniformLocation(programID, name.c_str()), value);
	}

  GLuint ProtoShader::CompileShader(const char* source, GLenum type)
  {
    GLuint shader = glCreateShader(type);
    glShaderSource(shader, 1, &source, nullptr);
    glCompileShader(shader);
    checkCompileErrors(shader, (type == GL_VERTEX_SHADER) ? "VERTEX" : "FRAGMENT");
    return shader;
  }

  void ProtoShader::checkCompileErrors(GLuint shader, std::string type)
  {
    GLint success;
    GLchar infoLog[1024];
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

    if (!success) {
      glGetShaderInfoLog(shader, sizeof(infoLog), NULL, infoLog);
      std::cerr << "Shader compilation error (" << type << "): " << infoLog << "\n";
    }
  }

 // std::string ProtoShader::LoadShader(const char* location)
	//{
 //   // Open the file
 //   std::ifstream file(location);

 //   // Check if the file is open
 //   if (!file.is_open()) {
 //     std::cerr << "Error opening file: " << location << std::endl;
 //     // Return an empty string to indicate an error
 //     return std::string();
 //   }

 //   // Read the contents of the file into a string
 //   std::ostringstream contentStream;
 //   contentStream << file.rdbuf();
 //   std::string content = contentStream.str();

 //   // Close the file
 //   file.close();

 //   // Return the content
 //   return content;
	//}
}
