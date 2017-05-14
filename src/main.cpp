//
// Created by Jinglei Yang on 4/24/17.
//

#include <iostream>
#include "CGL/svg.h"
#include "CGL/svgparser.h"
#include "window.h"
#include "ray_tracer.h"

const int width = 800;
const int height = 800;

using namespace Rendr;
#define msg(s) cerr << "[Drawer] " << s << endl;

SVG* loadFile(const char* path) {
    SVG* svg = new SVG();
    if( SVGParser::load( path, svg ) < 0) {
        delete svg;
        return NULL;
    }

    return svg;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        msg("Not enough arguments. Pass in an .svg file");
        return 0;
    }

    SVG* svg = loadFile(argv[1]);
    if (svg == NULL) {
        msg("No svg files successfully loaded. Exiting.");
        return 0;
    }

    RayTracer rayTracer = RayTracer(svg);

    Window window = Window(width, height);
    window.set_renderer(&rayTracer);
    window.init();
    window.start();
    exit(EXIT_SUCCESS);

    return 0;
}
