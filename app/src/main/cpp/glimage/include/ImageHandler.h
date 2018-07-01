//
// Created by Eric Rao on 01/07/2018.
//

#ifndef GLIMAGE_IMAGEHANDLER_H
#define GLIMAGE_IMAGEHANDLER_H

#include <GLES2/gl2.h>
#include <vector>

#include "CommonDefine.h"

namespace glimage {
    class ImageHandlerInterface {

    };

    class ImageHandler : public ImageHandlerInterface {
    public:
        ImageHandler();
        virtual ~ImageHandler();

        bool initWithRawBufferData(const void* data, GLint w, GLint h, BufferFormat format, bool bEnableReversion = true);

    protected:
        bool m_bRevertEnabled;
        std::vector<ImageFilterInterfaceAbstract*> m_vecFilters;

        TextureDrawer* m_drawer, *m_resultDrawer;
    };
}

#endif //GLIMAGE_IMAGEHANDLER_H
