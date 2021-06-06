cmake_minimum_required(VERSION 3.19)
project(HelpGL)

set(CMAKE_CXX_STANDARD 20)

add_executable(HelpGL test/main.cpp Mesh.cpp Mesh.h ShaderProgram.cpp ShaderProgram.h GLFunctions.cpp GLFunctions.h)
target_link_libraries(HelpGL GL GLEW glfw)
