#include <iostream>
//#include "../Window.h"
#include "../Mesh.h"
#include "../GLFunctions.h"
#include <cmath>
#include <GL/glew.h>
#include <GLFW/glfw3.h>


void regularNGon(int n, float center_x, float center_y, float r, std::vector<float>& verts, std::vector<GLuint>& elements) {
    verts.clear(); elements.clear();
    constexpr double pi = 3.14159265359;
    float theta = 2.0 * pi / double(n);
    verts.push_back(center_x); verts.push_back(center_y), verts.push_back(0.f);
    for(int i = 1; i <= n; ++i) {
        verts.push_back(std::sin((i - 1) * theta));
        verts.push_back(std::cos((i - 1) * theta));
        verts.push_back(0.f);
        elements.push_back(0);
        elements.push_back(i);
        elements.push_back(i == n ? 1 : i + 1);
    }
}


void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    // make sure the viewport matches the new window dimensions; note that width and
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}



int main() {
    using namespace HelpGL;

    // TUT
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // glfw window creation
    // --------------------
    GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    glewExperimental = true;
    if(glewInit() != GLEW_OK) {
        glfwTerminate();
        throw std::runtime_error("Failed to initialize GLEW");
    }
    // ~~~~~~~~~~~~~~~~~~~~~~

    auto vert_shader = loadShader(GL_VERTEX_SHADER, "../test/shaders/shader.vert");
    auto frag_shader = loadShader(GL_FRAGMENT_SHADER, "../test/shaders/green.frag");
    auto program = makeProgram({vert_shader, frag_shader});
    glDeleteShader(vert_shader);
    glDeleteShader(frag_shader);

    std::vector<float> verts;
    std::vector<GLuint> elems;
    regularNGon(5, 0, 0, 0.4, verts, elems);
    VertexAttributeSettings vert_pos;
    vert_pos.type = GL_FLOAT;
    vert_pos.normalized = false;
    vert_pos.stride = 0;
    vert_pos.size = 3;
    vert_pos.pointer = nullptr;
    Mesh pent(verts, elems, {vert_pos}, program);

    do {
        glClear(GL_COLOR_BUFFER_BIT);
        pent.draw();

        glfwSwapBuffers(window);
        glfwPollEvents();
    } while ( glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
              !glfwWindowShouldClose(window));

    return 0;
}
