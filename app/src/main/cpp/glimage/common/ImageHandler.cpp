//
// Created by Eric Rao on 01/07/2018.
//

#include "../include/ImageHandler.h"

namespace glimage {

    ImageHandler::ImageHandler()
    : m_bRevertEnabled(false), m_drawer(nullptr), m_resultDrawer(nullptr)
    {}

    ImageHandler::~ImageHandler() {
        //ENABLE_GLOBAL_GLCONTEXT();
        clearImageFilters();
        delete m_drawer;
        delete m_resultDrawer;
    }

    bool ImageHandler::initWithRawBufferData(const void* data, GLint w, GLint h, BufferFormat format, bool bEnableReversion) {
        //ENABLE_GLOBAL_GLCONTEXT();
        int channel;
        GLenum dataFmt, channelFmt;
        getDataAndChannelByFormat(format, &dataFmt, &channelFmt, &channel);
        if(channel == 0)
            return false;
        char* tmpBuffer = getScaledBufferInSize(data, w, h, channel, getMaxTextureSize(), getMaxTextureSize());
        const char* bufferData = (tmpBuffer == nullptr) ? (const char*)data : tmpBuffer;

        m_dstImageSize.set(w, h);
        ALOGE("Image Handler Init With RawBufferData %d x %d, %d channel\n", w, h, channel);

        glDeleteTextures(1, &m_srcTexture);
        m_bRevertEnabled = bEnableReversion;
        if (m_bRevertEnabled) {
            m_srcTexture = genTextureWithBuffer(bufferData, w, h, channelFmt, dataFmt, channel);
            ALOGE("Input Image Texture id %d\n", m_srcTexture);
        }
        else {
            m_srcTexture = 0;
        }

        bool status = initImageFBO(bufferData, w, h, channelFmt, dataFmt, channel);

        delete[] tmpBuffer;

        checkGLError("ImageHandler::initWithRawBufferData");
        return status;
    }
}