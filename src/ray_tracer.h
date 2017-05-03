//
// Created by Jinglei Yang on 4/26/17.
//

#ifndef RENDR_RAY_TRACER_H
#define RENDR_RAY_TRACER_H

#include "renderer.h"

namespace Rendr {

    class RayTracer : public Renderer {
    public:

        ~RayTracer();
        void init();
        void render();
        void resize(int w, int h);
    };
}


#endif //RENDR_RAY_TRACER_H
