//
// Created by jon on 13/09/2020.
//

#ifndef HELPGL_TEXTURE2D_H
#define HELPGL_TEXTURE2D_H
#include <string>
#include <GL/glew.h>

namespace HelpGL {
    class Texture2D {
    public:
        explicit Texture2D(const std::string &file_path);

        inline int getWidth() const { return width; }

        inline int getHeight() const { return height; }

        inline int getNrChannels() const { return nrChannels; }

        void bind(GLenum texture_unit) const;

    private:
        int width = 0;
        int height = 0;
        int nrChannels = 0;
        unsigned int gl_texture_id = -1;
    };
}

#endif //HELPGL_TEXTURE2D_H
