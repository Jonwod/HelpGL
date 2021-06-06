cmake_minimum_required(VERSION 3.19)
project(HelpGL)

set(CMAKE_CXX_STANDARD 20)

add_executable(GreenPentagon test/GreenPentagonTest.cpp Mesh.cpp Mesh.h GLFunctions.cpp GLFunctions.h)
target_link_libraries(GreenPentagon GL GLEW glfw)
