//
// Created by Jinglei Yang on 5/3/17.
//

#ifndef RENDR_VECTOR3D_H
#define RENDR_VECTOR3D_H

#include <iostream>
#include <cmath>

namespace Rendr {
    class Vector3D {
    public:

        double x, y, z;

        /*
         * Constructor.
         */
        Vector3D() : x(0.0), y(0.0), z(0.0) {}

        Vector3D(double x, double y, double z) : x(x), y(y), z(z) {}

        Vector3D(double c) : x(c), y(c), z(c) {}

        Vector3D(const Vector3D& v) : x(v.x), y(v.y), z(v.z) {}

        inline double& operator[] (const int index) {
            switch (index) {
                case 0:
                    return x;
                case 1:
                    return y;
                case 2:
                    return z;
            }
        }

        inline const double&operator[] (const int index) const {
            switch (index) {
                case 0:
                    return x;
                case 1:
                    return y;
                case 2:
                    return z;
            }
        }

        inline bool operator==(const Vector3D& v) {
            return v.x==x && v.y==y && v.z==z;
        }

        // reverse
        inline Vector3D operator-() const {
            return Vector3D(-x, -y, -z);
        }

        // add
        inline Vector3D operator+(const Vector3D& v) const {
            return Vector3D(x+v.x, y+v.y, z+v.z);
        }

        // subtract
        inline Vector3D operator-(const Vector3D& v) const {
            return Vector3D(x-v.x, y-v.y, z-v.z);
        }

        // right scalar multiplication
        inline Vector3D operator*(const double r) const {
            return Vector3D(x*r, y*r, z*r);
        }

        // right scalar division
        inline Vector3D operator/(const double r) const {
            return Vector3D(x/r, y/r, z/r);
        }

        inline Vector3D operator+=(const Vector3D& v) {
            return Vector3D(x+=v.x, y+=v.y, z+=v.z);
        }

        inline Vector3D operator-=(const Vector3D& v) {
            return Vector3D(x-=v.x, y-=v.y, z-=v.z);
        }

        inline Vector3D operator*=(const Vector3D& v) {
            return Vector3D(x*=v.x, y*=v.y, z*=v.z);
        }

        inline Vector3D operator/=(const Vector3D& v) {
            return Vector3D(x/=v.x, y/=v.y, z/=v.z);
        }

        inline double norm() {
            return sqrt(x*x+y*y+z*z);
        }

        inline Vector3D unit() {
            return *this / this->norm();
        }

    };
    inline Vector3D dot(const Vector3D& v1, const Vector3D& v2) {
        return Vector3D(v1.x*v2.x+v1.y*v2.y+v1.z*v2.z);
    }

    inline Vector3D cross(const Vector3D& v1, const Vector3D& v2) {
        return Vector3D(v1.y*v2.z - v1.z*v2.y,
                        v1.z*v2.x - v1.x*v2.z,
                        v1.x*v2.y - v1.y*v2.x);
    }

    inline std::ostream &operator<<(std::ostream &os, Vector3D &v) {
        os << "(" << v.x << ", " << v.y << ", " << v.z << ")";
        return os;
    }
}
#endif //RENDR_VECTOR3D_H
