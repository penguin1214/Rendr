//
// Created by Jinglei Yang on 4/26/17.
//

#include "ray_tracer.h"

namespace Rendr {

    RayTracer::~RayTracer() {}

    void RayTracer::init() {}

    /**
     * Draw content.
     * Repost framebuffer and zoom window, if applicable.
     */
    void RayTracer::render() {
        draw_pixels();
    }

    void RayTracer::resize(int w, int h) {
        framebuffer_width_ = w; framebuffer_height_ = h;
        framebuffer.resize(4 * w * h);
    }

    // drawing functions
    void RayTracer::redraw() {}

    void RayTracer::draw_pixels() {
        const unsigned char *pixels = &framebuffer[0];
        glDrawPixels(framebuffer_width_, framebuffer_height_, GL_RGBA, GL_UNSIGNED_BYTE, pixels);
    }
}