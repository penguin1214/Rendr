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

        // rasterize a point
        void rasterize_point( float x, float y, Color color );

        // rasterize a line
        void rasterize_line( float x0, float y0,
                             float x1, float y1,
                             Color color);

        // rasterize a triangle
        void rasterize_triangle( float x0, float y0,
                                 float x1, float y1,
                                 float x2, float y2,
                                 Color color, Triangle *tri = NULL );

    private:
        SVG* svg;
        int sample_rate;
        Matrix3x3 svg_to_ndc;
        std::vector<unsigned char> framebuffer;
        size_t framebuffer_width_, framebuffer_height_;
    };
}


#endif //RENDR_RAY_TRACER_H
