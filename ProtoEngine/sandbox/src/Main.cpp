#include <engine/ProtoWindow.h>

int main()
{
    ProtoEngine::Window* myWindow = new ProtoEngine::Window(800, 600, "My OpenGL Window");

    myWindow->Initialize();

    while (!myWindow->ShouldClose())
    {
      myWindow->PollEvents();
      myWindow->SetClearColor(255, 0, 0, 255);
      myWindow->SwapBuffers();
		}

    return 0;
}