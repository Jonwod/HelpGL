//
// Created by jon on 05/06/2021.
//

#ifndef JONNYGRAPHICS_MESH_H
#define JONNYGRAPHICS_MESH_H
#include <vector>
#include <GL/glew.h>

namespace HelpGL {
    /**
     * Specifies the layout and format of a vertex attribute
     * within a buffer. Buffers
     */
    struct VertexAttributeSettings {
        // This is the number of components per vertex for this attribute
        // (e.g. 3 for a 3d vector)
        GLint size;

        // The type of vertex components
        GLenum type;

        // ??
        GLboolean normalized;

        // Byte offset between consecutive generic vertex attributes
        // stride 0 is a tightly packed array
        GLsizei stride;

        // Offset of the start of the data from the beginning
        // of the data buffer
        const void * pointer;
    };


    class Mesh {
    public:
        // Will move the input data
        Mesh(const std::vector<float>& vertices,
             const std::vector<GLuint>& elements,
             const std::vector<VertexAttributeSettings>& vertex_format,
             GLuint shader_program);

        ~Mesh();
        void draw();
    private:
        // These are created and 'owned' by the mesh
        GLuint vao;
        GLuint vbo;
        GLuint ebo;
        GLsizei num_indices;

        // This is not owned by the mesh and must be created externally
        // and kept alive as long as the mesh is
        GLuint shader_program;
    };
}

#endif //JONNYGRAPHICS_MESH_H
