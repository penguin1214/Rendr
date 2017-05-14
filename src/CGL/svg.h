// Original file Copyright CMU462 Fall 2015:
// Kayvon Fatahalian, Keenan Crane,
// Sky Gao, Bryce Summers, Michael Choquette.
#ifndef RENDR_SVG_H
#define RENDR_SVG_H

#include <map>
#include <vector>
#include <string>

#include "color.h"
#include "../math/vector2D.h"
#include "../math/matrix3x3.h"
#include "../math/transform.h"
#include "tinyxml2.h"
#include "../texture.h"

using namespace tinyxml2;
using namespace CGL;

namespace Rendr {

    class RayTracer;

    typedef enum e_SVGElementType {
        NONE = 0,
        POINT,
        LINE,
        POLYLINE,
        RECT,
        POLYGON,
        ELLIPSE,
        IMAGE,
        GROUP,
        TRIANGLE
    } SVGElementType;

    struct Style {
        Color strokeColor;
        Color fillColor;
        float strokeWidth;
        float miterLimit;
    };

    struct SVGElement {

        SVGElement( SVGElementType _type )
                : type( _type ), transform( Matrix3x3::identity() ) { }

        virtual ~SVGElement() { }

        virtual void draw(RayTracer *dr, Matrix3x3 global_transform) = 0;

        // primitive type
        SVGElementType type;

        // styling
        Style style;

        // transformation list
        Matrix3x3 transform;

    };

    struct Triangle : SVGElement {

        Triangle(): SVGElement (TRIANGLE ) { }
        Vector2D p0_svg, p1_svg, p2_svg;

        void draw(RayTracer *dr, Matrix3x3 global_transform);
        virtual Color color(Vector3D p_bary, Vector3D p_dx_bary = Vector3D(), Vector3D p_dy_bary = Vector3D(),
                            SampleParams sp = SampleParams()) = 0;
    };

    struct ColorTri : Triangle {

        // Should return appropriate color given barycentric
        // coordinates x and y corresponding to vertices 'a' and 'b'.
        // Ignore the dx and dy arguments -- they are for TexTri to
        // do trilinear filtering.
        Color color(Vector3D p_bary, Vector3D p_dx_bary = Vector3D(), Vector3D p_dy_bary = Vector3D(),
                    SampleParams sp = SampleParams());

        // Per-vertex colors. Should be interpolated between using
        // barycentric coordinates.
        Color p0_col, p1_col, p2_col;
    };

    struct TexTri : Triangle {

        // Should return appropriate color given barycentric
        // coordinates x and y corresponding to vertices 'a' and 'b'.
        // Use the dx and dy arguments for mipmap
        // level selection in trilinear filtering.
        Color color(Vector3D p_bary, Vector3D p_dx_bary = Vector3D(), Vector3D p_dy_bary = Vector3D(),
                    SampleParams sp = SampleParams());

        // Per-vertex uv coordinates.
        // Should be interpolated between using barycentric coordinates.
        Vector2D p0_uv, p1_uv, p2_uv;
        Texture *tex;
    };

    struct Group : SVGElement {

        Group() : SVGElement  ( GROUP ) { }
        std::vector<SVGElement*> elements;

        void draw(RayTracer *dr, Matrix3x3 global_transform);

        ~Group();

    };

    struct Point : SVGElement {

        Point() : SVGElement ( POINT ) { }
        Vector2D position;

        void draw(RayTracer *dr, Matrix3x3 global_transform);

    };

    struct Line : SVGElement {

        Line() : SVGElement ( LINE ) { }
        Vector2D from;
        Vector2D to;

        void draw(RayTracer *dr, Matrix3x3 global_transform);

    };

    struct Polyline : SVGElement {

        Polyline() : SVGElement  ( POLYLINE ) { }
        std::vector<Vector2D> points;

        void draw(RayTracer *dr, Matrix3x3 global_transform);

    };

    struct Rect : SVGElement {

        Rect() : SVGElement ( RECT ) { }
        Vector2D position;
        Vector2D dimension;

        void draw(RayTracer *dr, Matrix3x3 global_transform);

    };

    struct Polygon : SVGElement {

        Polygon() : SVGElement  ( POLYGON ) { }
        std::vector<Vector2D> points;

        void draw(RayTracer *dr, Matrix3x3 global_transform);

    };

    struct Image : SVGElement {

        Image() : SVGElement  ( IMAGE ) { }
        Vector2D position;
        Vector2D dimension;
        Texture tex;

        void draw(RayTracer *dr, Matrix3x3 global_transform);

    };

    struct SVG {

        ~SVG();
        float width, height;
        std::vector<SVGElement*> elements;
        std::map<std::string, Texture*> textures;

        void draw(RayTracer *dr, Matrix3x3 global_transform) {
            for (int i = 0; i < elements.size(); ++i)
                elements[i]->draw(dr, global_transform);
        }

    };

}

#endif
