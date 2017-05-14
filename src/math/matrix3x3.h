//
// Created by Jinglei Yang on 5/5/17.
//

#ifndef RENDR_MATRIX3X3_H
#define RENDR_MATRIX3X3_H

#include "vector3D.h"

namespace Rendr {
    /**
     * Matrix 3x3 class.
     * - index access (overload [][])
     * - addition, subtraction, scalar multiplication, scalar division
     * - matrix multiplication with Vector3D
     */
    class Matrix3x3 {
    public:
        /**
         * Constructor.
         */
        Matrix3x3();

        Matrix3x3(double* data);

        Matrix3x3(double m11, double m12, double m13,
                  double m21, double m22, double m23,
                  double m31, double m32, double m33);

        ~Matrix3x3(){};

        // Return the determinant of matrix.
        double det() const;

        static Matrix3x3 identity();

        Matrix3x3 transpose() const;

        Matrix3x3 inverse() const;

        Vector3D& operator[](int i);

        const Vector3D& operator[](int i) const;

        Matrix3x3 operator-() const;

        // Matrix addition.
        Matrix3x3 operator+(const Matrix3x3& M);

        // Scalar addtion. Add value element wide.
        void operator+(double d);

        // Matrix subtraction.
        Matrix3x3 operator-(const Matrix3x3& M);

        // Scalar subtraction.
        void operator-(double d);

        // Addtion.
        void operator+=(const Matrix3x3& M);

        // Subtraction.
        void operator-=(const Matrix3x3& M);

        // Matrix multiplication
        Matrix3x3 operator*(const Matrix3x3& M) const;

        // Scalar multiplication
        Matrix3x3 operator*(double d) const;

        // Vector multiplication  3x3 * 3x1
        Vector3D operator*( const Vector3D& v) const;

        // Scalar division
        Matrix3x3 operator/(double d);

        void operator/=(double d);

    private:
        Vector3D entries[3];
    };
}

#endif //RENDR_MATRIX3X3_H
