//
// Created by Jinglei Yang on 4/26/17.
//

#include "ray_tracer.h"

namespace Rendr {

    RayTracer::~RayTracer() {}

    void RayTracer::init() {
        sample_rate = 1;
    }

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

    // Rasterize a point.
    void RayTracer::rasterize_point( float x, float y, Color color ) {
        // fill in the nearest pixel
        int sx = (int) floor(x);
        int sy = (int) floor(y);

        // check bounds
        if ( sx < 0 || sx >= framebuffer_width_ ) return;
        if ( sy < 0 || sy >= framebuffer_height_ ) return;

//        samplebuffer[sy][sx].fill_pixel(color);
        return;

    }

// Rasterize a line.
    void RayTracer::rasterize_line( float x0, float y0,
                                   float x1, float y1,
                                   Color color) {
        if (x0 > x1) {
            swap(x0,x1); swap(y0,y1);
        }

        float pt[] = {x0,y0};
        float m = (y1-y0)/(x1-x0);
        float dpt[] = {1,m};
        int steep = abs(m) > 1;
        if (steep) {
            dpt[0] = x1==x0 ? 0 : 1/abs(m);
            dpt[1] = x1==x0 ? (y1-y0)/abs(y1-y0) : m/abs(m);
        }

        while (floor(pt[0]) <= floor(x1) && abs(pt[1]-y0) <= abs(y1-y0)) {
            rasterize_point(pt[0],pt[1],color);
            pt[0]+=dpt[0]; pt[1]+=dpt[1];
        }
    }

// Rasterize a triangle.
    void RayTracer::rasterize_triangle( float x0, float y0,
                                       float x1, float y1,
                                       float x2, float y2,
                                       Color color, Triangle *tri) {
        // Part 1: Fill in this function with basic triangle rasterization code.
        //         Hint: Implement fill_color() function first so that you can see
        //         rasterized points and lines, then start rasterizing triangles.
        //         Use something like this:
        //             samplebuffer[row][column].fill_pixel(color);

        // Part 2: Add supersampling.
        //         You need to write color to each sub-pixel by yourself,
        //         instead of using the fill_pixel() function.
        //         Hint: Use the fill_color() function like this:
        //             samplebuffer[row][column].fill_color(sub_row, sub_column, color);
        //         You also need to implement get_pixel_color() function to support supersampling.
        // Part 4: Add barycentric coordinates and use tri->color for shading when available.
        // Part 5: Fill in the SampleParams struct and pass it to the tri->color function.
        // Part 6: Pass in correct barycentric differentials to tri->color for mipmapping.
        float min_x = x0, max_x = x0;
        if (x1<x0) min_x = x1;
        else max_x = x1;
        min_x = min(min_x, x2);
        max_x = max(max_x, x2);

        float min_y = y0, max_y = y0;
        if (y1<y0) min_y = y1;
        else max_y = y1;
        min_y = min(min_y, y2);
        max_y = max(max_y, y2);

        int x, y;
        int i, j;
        float point[] = {0, 0};
        float v0[] = {0,0};
        float v1[] = {0,0};
        float v2[] = {0,0};
        float sps = sqrt(sample_rate);
        Color c;

        Vector3D p_bary;

        for (y = floor(min_y); y < floor(max_y); y++) {
            for (x = floor(min_x); x < floor(max_x); x++) {
                for (j = 0; j < sps; ++j) {
                    point[1] = y+j/sps;
                    for (i = 0; i < sps; ++i) {
                        point[0] = x+i/sps;
                        // use barycentric coordinates
                        v0[0] = x0-x2; v0[1] = y0-y2;
                        v1[0] = x0-x1; v1[1] = y0-y1;
                        v2[0] = x2-x1; v2[1] = y2-y1;

                        // compute barycentric coordinates
                        p_bary[0] = ((point[1]-y1)*v2[0]-(point[0]-x1)*v2[1]) / (v1[1]*v2[0]-v1[0]*v2[1]);
                        p_bary[1] = ((point[1]-y2)*v0[0]-(point[0]-x2)*v0[1]) / (v2[0]*v0[1]-v2[1]*v0[0]);
                        p_bary[2] = 1-p_bary[0]-p_bary[1];

                        // get color
                        c = tri->color(p_bary);

                        if ((p_bary[0]>=0) && (p_bary[1]>=0) && (p_bary[2]>0)) {
//                            samplebuffer[y][x].fill_color(j,i,c);
//                            framebuffer[y][x].fill_color(j,i,c);
                        }
                    }
                }
            }
        }
    }
}