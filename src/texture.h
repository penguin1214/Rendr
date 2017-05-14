//
// Created by Jinglei Yang on 5/7/17.
//

#ifndef RENDR_TEXTURE_H
#define RENDR_TEXTURE_H

#include <vector>
#include "CGL/color.h"
#include "math/vector2D.h"

#include <iostream>
using namespace std;
using namespace CGL;

namespace Rendr {

    typedef enum PixelSampleMethod { P_NEAREST = 0, P_LINEAR = 1 } PixelSampleMethod;
    typedef enum LevelSampleMethod { L_ZERO = 0, L_NEAREST = 1, L_LINEAR = 2 } LevelSampleMethod;

    struct SampleParams {
        Vector2D p_uv;
        Vector2D p_dx_uv, p_dy_uv;
        PixelSampleMethod psm;
        LevelSampleMethod lsm;
    };

    static const int kMaxMipLevels = 14;

    struct MipLevel {
        size_t width;
        size_t height;
        std::vector<unsigned char> texels;
    };

    struct Texture {
        size_t width;
        size_t height;
        std::vector<MipLevel> mipmap;

        void init(const vector<unsigned char>& pixels, const size_t& w, const size_t& h) {
            width = w; height = h;

            // A fancy C++11 feature. emplace_back constructs the element in place,
            // and in this case it uses the new {} list constructor syntax.
            mipmap.emplace_back(MipLevel{width, height, pixels});

            generate_mips();
        }

        // Generates up to kMaxMipLevels of mip maps. Level 0 contains
        // the unfiltered original pixels.
        void generate_mips(int startLevel = 0);

        Color sample(const SampleParams &sp);
        float get_level(const SampleParams &sp);

        Color sample_nearest(Vector2D uv, int level = 0);

        Color sample_bilinear(Vector2D uv, int level = 0);

        Color sample_trilinear(Vector2D uv, Vector2D du, Vector2D dv);
    };

}
#endif //RENDR_TEXTURE_H
