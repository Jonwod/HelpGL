//
// Created by jon on 06/09/2020.
//

#ifndef HELPGL_FUNCTIONS_H
#define HELPGL_FUNCTIONS_H
#include <GL/glew.h>
#include <string>
#include <vector>

namespace HelpGL {
    // Creates shader compiled from specified source file and returns the id for the GL shader object
    // Will throw runtime_error if something goes wrong.
    GLuint loadShader(GLenum shader_type, const std::string &file_path);

    // Creates a new openGL program from the specified shaders
    // Does not glUseProgram internally
    // Returns the id.
    // Throws runtime_error in the event of a problem
    GLuint makeProgram(const std::vector<GLuint> &shaders);
}

#endif //HELPGL_FUNCTIONS_H
