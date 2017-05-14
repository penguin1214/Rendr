//
// Created by Jinglei Yang on 5/3/17.
//

#ifndef RENDR_VECTOR2D_H
#define RENDR_VECTOR2D_H

#include <cmath>
#include <iostream>

namespace Rendr {
    class Vector2D {
    public:

        double x, y;
        /*
         * Constructor.
         * Initialize vector to (0,0).
         */
        Vector2D() : x(0.0), y(0.0) {}

        /*
         * Constructor.
         * Initialize vector to (x, y) as given.
         */
        Vector2D(double x, double y) : x(x), y(y) {}

        /*
         * Constructor.
         * Copy constructor.
         */
        Vector2D(const Vector2D &v) : x(v.x), y(v.y) {}

        // operator overload

        // reverse
        inline Vector2D operator-(void) const {
            return Vector2D(-x, -y);
        }

        // add
        inline Vector2D operator+(const Vector2D& v) const {
            return Vector2D(this->x+v.x, this->y+v.y);
        }

        // subtract
        inline Vector2D operator-(const Vector2D& v) const {
            return Vector2D(this->x-v.x, this->y-v.y);
        }

        // right scalar multiplication
        inline Vector2D operator*(double r) const {
            return Vector2D(this->x*r, this->y*r);
        }

        // scalar division
        inline Vector2D operator/(double r) const {
            return Vector2D(this->x/r, this->y/r);
        }

        // add v
        inline void operator+=(const Vector2D& v) {
            x += v.x; y += v.y;
        }

        // subtract
        inline void operator-=(const Vector2D& v) {
            x -= v.x; y-= v.y;
        }

        // scalar multiply by r
        inline void operator*=(double r) {
            x *= r; y *= r;
        }

        // scalar divide by r
        inline void operator/=(double r) {
            x /= r; y /= r;
        }



        // inner product
        inline double dot(const Vector2D& v1, const Vector2D& v2) {
            return (v1.x*v2.x + v1.y*v2.y);
        }

        // cross product
        inline double cross(const Vector2D& v1, const Vector2D& v2) {
            return (v1.x*v2.y - v1.y*v2.x);
        }


        /*
         * return norm
         */
        inline double norm() const {
            return sqrt(x*x + y*y);
        }

        /*
         * return unit vector
         */
        inline Vector2D unit() const {
            return *this / this->norm();
        }
    };
    inline std::ostream&operator<<(std::ostream& os, const Vector2D& v) {
        os << "(" << v.x << ", " << v.y << ")";
        return os;
    }

    // multiplication
    inline Vector2D operator*(double r, const Vector2D& v) {
        return Vector2D(r*v.x, r*v.y);
    }
}
#endif //RENDR_VECTOR2D_H
