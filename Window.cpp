//
// Created by jon on 05/06/2021.
//

#include "Window.h"
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdexcept>


namespace HelpGL{
    void onGlfwError(int code, const char* error) {
        std::cerr<<"GLFW ERROR, code: "<<code<<std::endl;
        std::cerr<<error<<std::endl;
    }

    void framebuffer_size_callback(GLFWwindow* window, int width, int height)
    {
        // make sure the viewport matches the new window dimensions; note that width and
        // height will be significantly larger than specified on retina displays.
        glViewport(0, 0, width, height);
    }


    Window::Window(int x, int y, const std::string& title) {
        glfwInit();
        glfwSetErrorCallback(onGlfwError);
        glfwWindowHint(GLFW_SAMPLES, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfw_window = glfwCreateWindow(x, y, title.c_str(), nullptr, nullptr);
        if(glfw_window == nullptr ){
            glfwTerminate();
            throw std::runtime_error("Failed to open GLFW window");
        }
        glfwMakeContextCurrent(glfw_window);
        glfwSetFramebufferSizeCallback(glfw_window, framebuffer_size_callback);

        glewExperimental = true;
        if(glewInit() != GLEW_OK) {
            glfwTerminate();
            throw std::runtime_error("Failed to initialize GLEW");
        }

        glClearColor(0.0f, 0.0f, 0.4f, 0.0f);
        glEnable(GL_DEPTH_TEST);
        glDepthFunc(GL_LESS);

        glfwSetInputMode(glfw_window, GLFW_STICKY_KEYS, GL_TRUE);
    }


    void Window::setClearColor(float r, float g, float b) {
        glClearColor(r, g, b, 0.0f);
    }


    void Window::swapBuffers() {
        glfwSwapBuffers(glfw_window);
    }

    Window::~Window() {
        glfwTerminate();
    }
}