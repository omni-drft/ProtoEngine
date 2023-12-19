#include <engine/ProtoWindow.h>

namespace ProtoEngine 
{
  Window::Window()
  {
    windowWidth = 800;
    windowHeight = 600;
  }

  Window::Window(int width, int height, const char* title) 
  {
    windowWidth = width;
    windowHeight = height;
    windowTitle = title;
  }

  int Window::Initialize()
  {
    if (!glfwInit())
    {
      std::cerr << "Failed to initialize GLFW!\n";
      glfwTerminate();
      return -1;
		}

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);

    window = glfwCreateWindow(windowWidth, windowHeight, windowTitle, nullptr, nullptr);
    if (!window)
    {
			std::cerr << "Failed to create GLFW window!\n";
			glfwTerminate();
			return -1;
		}

    glfwGetFramebufferSize(window, &windowWidth, &windowHeight);
    glfwMakeContextCurrent(window);

    glewExperimental = GL_TRUE; 
    if (glewInit() != GLEW_OK)
    {
      std::cerr << "Failed to initialize GLEW!\n";
      glfwDestroyWindow(window);
      glfwTerminate();
      return -1;
    }

    glEnable(GL_DEPTH_TEST);

    glViewport(0, 0, windowWidth, windowHeight);
    glfwSetWindowUserPointer(window, this);
  }

  bool Window::ShouldClose()
  {
    if (glfwWindowShouldClose(window))
    {
			return true;
		}
    return false;
  }

  void Window::SwapBuffers()
  {
		glfwSwapBuffers(window);
  }

  void Window::PollEvents()
  {
    glfwPollEvents();
  }

  void Window::SetClearColor(int r, int g, int b, int a)
  {
    glClearColor(
      static_cast<float>(r) / 255.0f, 
      static_cast<float>(g) / 255.0f, 
      static_cast<float>(b) / 255.0f, 
      static_cast<float>(a) / 255.0f
    );
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  }

  Window::~Window() 
  {
    glfwDestroyWindow(window);
    glfwTerminate();
  }

  GLFWwindow* Window::getWindow() const 
  {
    return window;
  }

}
