#include <engine/ProtoWindow.h>
#include <engine/ProtoShader.h>

int main()
{
    ProtoEngine::Window* myWindow = new ProtoEngine::Window(1000, 700, "My OpenGL Window");

    myWindow->Initialize();

    ProtoEngine::ProtoShader shader("../engine/src/engine/shaders/VertexShader.glsl", "../engine/src/engine/shaders/FragmentShader.glsl");

    // Vertex data for a simple triangle
    GLfloat vertices[] = {
        -0.5f, -0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
         0.0f,  0.5f, 0.0f
    };

    GLuint VAO, VBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // Link the vertex attributes
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    while (!myWindow->ShouldClose())
    {
      myWindow->SetClearColor(255, 120, 0, 255);

      // Use the shader
      shader.Use();

      // Draw the triangle
      glBindVertexArray(VAO);
      glDrawArrays(GL_TRIANGLES, 0, 3);
      glBindVertexArray(0);
      myWindow->SwapBuffers();
      myWindow->PollEvents();
		}

    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);

    delete myWindow;

    return 0;
}