//
// Created by jon on 05/06/2021.
//

#include "Mesh.h"

HelpGL::Mesh::Mesh(const std::vector<float>& vertices,
                   const std::vector<GLuint>& elements,
                   const std::vector<VertexAttributeSettings>& vs,
                   GLuint shader)
                   :shader_program(shader),
                   num_indices(elements.size())
{
    // The VAO specifies how the data is encoded
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    // The VBO is our handle to the array holding the actual vertices
    // on the GPU
    glGenBuffers(1, &vbo);

    // Makes the buffer active
    glBindBuffer(GL_ARRAY_BUFFER, vbo);

    // Uploads the data to the active buffer
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * vertices.size(), vertices.data(), GL_STATIC_DRAW);

    for(int i = 0; i < vs.size(); ++i) {
        // Affects the currently bound buffer, which is still vbo
        // Part of the VAO state, so does not have to be called again
        glVertexAttribPointer(i, vs[i].size, vs[i].type, vs[i].normalized, vs[i].stride, vs[i].pointer);
        glEnableVertexAttribArray(i);
    }

    glGenBuffers(1, &ebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint) * elements.size(), elements.data(), GL_STATIC_DRAW);

    // Cleanup
    glBindVertexArray(0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}


void HelpGL::Mesh::draw() {
    glUseProgram(shader_program);
    glBindVertexArray(vao);
    glDrawElements(GL_TRIANGLES, num_indices, GL_UNSIGNED_INT, nullptr);
}


HelpGL::Mesh::~Mesh() {
    glDeleteVertexArrays(1, &vao);
    glDeleteBuffers(1, &vbo);
}

