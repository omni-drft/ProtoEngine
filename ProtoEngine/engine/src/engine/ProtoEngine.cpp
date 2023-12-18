#include "ProtoEngine.h"

namespace ProtoEngine {

	void display()
	{
		// make the window content purple
		glClearColor(1.0f, 0.2f, 0.5f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);


		// swap the front and back buffers
		glutSwapBuffers();
	}

	void PrintHelloWorld()
	{
		// initialize GLUT
		int argc = 0;
    char* argv[] = { nullptr };
		glutInit(&argc, argv);
		glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
		glutInitWindowSize(800, 600);
		glutCreateWindow("ProtoEngine");

		// initialize glad
		if (!gladLoadGL()) {
			std::cout << "Failed to initialize GLAD" << std::endl;
			return;
		}
		
		// print OpenGL version
		std::cout << "OpenGL version: " << glGetString(GL_VERSION) << std::endl;

		glutDisplayFunc(display);
		glutMainLoop();

		
		
	}

}