#pragma once

#define GLEW_STATIC

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

namespace ProtoEngine {

    class Window {
    public:
        Window();
        Window(int width, int height, const char* title);
        int Initialize();
        bool ShouldClose();
        void SwapBuffers();
        void PollEvents();
        void SetClearColor(int r, int g, int b, int a);
        ~Window();

        GLFWwindow* getWindow() const;
    private:

        GLFWwindow* window;

        int windowWidth;
        int windowHeight;
        const char* windowTitle;
    };

};
