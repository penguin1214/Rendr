//
// Created by Jinglei Yang on 4/24/17.
//

#include <iostream>
#include "window.h"
#include "ray_tracer.h"

const int width = 800;
const int height = 800;

using namespace Rendr;

int main() {

    RayTracer rayTracer;
    Window window = Window(width, height);
    window.set_renderer(&rayTracer);
    window.init();
    window.start();
    exit(EXIT_SUCCESS);

    return 0;
}
