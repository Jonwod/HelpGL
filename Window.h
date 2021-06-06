//
// Created by jon on 05/06/2021.
//

#ifndef HELPGL_WINDOW_H
#define HELPGL_WINDOW_H
#include <string>

class GLFWwindow;

namespace HelpGL {
    /**
     * Presently just one active window is supported
     */
    class Window {
    public:
        Window(int x, int y, const std::string &title);
        ~Window();
        void setClearColor(float r, float g, float b);
        void swapBuffers();
        inline GLFWwindow * getGLFLWindow() { return glfw_window; }
    private:
        GLFWwindow *glfw_window;
    };
}

#endif //HELPGL_WINDOW_H
