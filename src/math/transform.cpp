//
// Created by Jinglei Yang on 5/9/17.
//

#include "transform.h"
#include "../CGL/misc.h"

namespace Rendr {
    Vector2D operator*(const Matrix3x3 &m, const Vector2D &v) {
        Vector3D mv = m * Vector3D(v.x, v.y, 1);
        return Vector2D(mv.x / mv.z, mv.y / mv.z);
    }

    Matrix3x3 translate(float dx, float dy) {
        // Part 3: Fill this in.
        return Matrix3x3(1,0,dx,
                         0,1,dy,
                         0,0,1);
    }

    Matrix3x3 scale(float sx, float sy) {
        // Part 3: Fill this in.
        return Matrix3x3(sx,0,0,0,sy,0,0,0,1);
    }

// The input argument is in degrees counterclockwise
    Matrix3x3 rotate(float deg) {
        // Part 3: Fill this in.
        deg = deg*2*PI/360;
        Matrix3x3 mat = Matrix3x3(cos(deg),-sin(deg),0,sin(deg),cos(deg),0,0,0,1);
        return mat;
    }
}