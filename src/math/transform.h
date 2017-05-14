//
// Created by Jinglei Yang on 5/9/17.
//

#ifndef RENDR_TRANSFORM_H
#define RENDR_TRANSFORM_H

#include "vector2D.h"
#include "matrix3x3.h"

namespace Rendr{

Vector2D operator*(const Matrix3x3 &m, const Vector2D &v);

Matrix3x3 translate(float dx, float dy);
Matrix3x3 scale(float sx, float sy);
Matrix3x3 rotate(float deg);

}
#endif //RENDR_TRANSFORM_H
