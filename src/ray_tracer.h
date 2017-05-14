//
// Created by Jinglei Yang on 4/26/17.
//

#ifndef RENDR_RAY_TRACER_H
#define RENDR_RAY_TRACER_H

#include <vector>
#include "renderer.h"
#include "CGL/svg.h"
#include "math/matrix3x3.h"
#include "GLFW/glfw3.h"

namespace Rendr {

    class RayTracer : public Renderer {
    public:

        RayTracer(SVG* svg): svg(svg) {}

        ~RayTracer();
        void init();
        void render();
        void resize(int w, int h);

        // drawing functions
        void redraw();
        void draw_pixels();
        void draw_zoom();

    private:
        SVG* svg;
        Matrix3x3 svg_to_ndc;
        std::vector<unsigned char> framebuffer;
        size_t framebuffer_width_, framebuffer_height_;
    };
}


#endif //RENDR_RAY_TRACER_H
