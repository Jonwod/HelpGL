//
// Created by jon on 05/06/2021.
//

#ifndef HELPGL_SHADERPROGRAM_H
#define HELPGL_SHADERPROGRAM_H
#include <GL/glew.h>

namespace HelpGL {
    class ShaderProgram {
    public:
        ShaderProgram(const char * vertex_file_path, const char* fragment_file_path);
    private:
        GLuint program_id;
    };
}


#endif //HELPGL_SHADERPROGRAM_H
