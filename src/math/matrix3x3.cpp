//
// Created by Jinglei Yang on 5/5/17.
//

#include "matrix3x3.h"

#include <cmath>

namespace Rendr {
    Matrix3x3::Matrix3x3() {
        for (int i = 0; i < 3; ++i) {
            entries[i] = Vector3D();
        }
    }

    Matrix3x3::Matrix3x3(double *data) {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                entries[i][j] = data[i*3+j];
            }
        }
    }

    Matrix3x3::Matrix3x3(double m11, double m12, double m13, double m21, double m22, double m23, double m31, double m32,
                         double m33) {
        entries[0][0] = m11; entries[0][1] = m12; entries[0][2] = m13;
        entries[1][0] = m21; entries[1][1] = m22; entries[1][2] = m23;
        entries[2][0] = m31; entries[2][1] = m32; entries[2][2] = m33;
    }

    double Matrix3x3::det() const {
        return -(*this)[0][2]*(*this)[1][1]*(*this)[2][0] + (*this)[0][1]*(*this)[1][2]*(*this)[2][0] +
                (*this)[0][2]*(*this)[1][0]*(*this)[2][1] - (*this)[0][0]*(*this)[1][2]*(*this)[2][1] -
                (*this)[0][1]*(*this)[1][0]*(*this)[2][2] + (*this)[0][0]*(*this)[1][1]*(*this)[2][2] ;
    }

    Matrix3x3 Matrix3x3::identity() {
        return Matrix3x3(1.,0.,0.,0.,1.,0.,0.,0.,1.);
    }

    Matrix3x3 Matrix3x3::transpose() const {
        return Matrix3x3((*this)[0][0], (*this)[1][0], (*this)[2][0],
                         (*this)[0][1], (*this)[1][1], (*this)[2][1],
                         (*this)[0][2], (*this)[1][2], (*this)[2][2]);
    }

    Matrix3x3 Matrix3x3::inverse() const {

    }

    Vector3D& Matrix3x3::operator[](int i) {
        return entries[i];
    }

    const Vector3D& Matrix3x3::operator[](int i) const {
        return entries[i];
    }

    Matrix3x3 Matrix3x3::operator-() const {
        return Matrix3x3(-(*this)[0][0], -(*this)[0][1], -(*this)[0][2],
                         -(*this)[1][0], -(*this)[1][1], -(*this)[1][2],
                         -(*this)[2][0], -(*this)[2][1], -(*this)[2][2]);
    }

    Matrix3x3 Matrix3x3::operator+(const Matrix3x3 &M) {
        Matrix3x3 mat = Matrix3x3();
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                mat[i][j] = (*this)[i][j] + M[i][j];
            }
        }
        return mat;
    }

    void Matrix3x3::operator+(double d) {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                (*this)[i][j] += d;
            }
        }
    }

    Matrix3x3 Matrix3x3::operator-(const Matrix3x3 &M) {
        Matrix3x3 mat = Matrix3x3();
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                mat[i][j] = (*this)[i][j] - M[i][j];
            }
        }
        return mat;
    }

    void Matrix3x3::operator-(double d) {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                (*this)[i][j] -= d;
            }
        }
    }

    void Matrix3x3::operator+=(const Matrix3x3 &M) {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                (*this)[i][j] += M[i][j];
            }
        }
    }

    void Matrix3x3::operator-=(const Matrix3x3 &M) {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                (*this)[i][j] -= M[i][j];
            }
        }
    }

    Matrix3x3 Matrix3x3::operator*(const Matrix3x3 &M) const {
        Matrix3x3 mat = Matrix3x3();
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                for (int k = 0; k < 3; ++k) {
                    mat[i][j] += (*this)[i][k]*M[j][k];
                }
            }
        }
        return mat;
    }

    Matrix3x3 Matrix3x3::operator*(double d) const {
        Matrix3x3 mat = Matrix3x3();
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                mat[i][j] = (*this)[i][j] * d;
            }
        }
        return mat;
    }

    Vector3D Matrix3x3::operator*( const Vector3D &v) const {
        return entries[0]*v[0] + entries[1]*v[1] + entries[2]*v[2];
    }

    Matrix3x3 Matrix3x3::operator/(double d) {
        Matrix3x3 mat = Matrix3x3();
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                mat[i][j] = (*this)[i][j] / d;
            }
        }
        return mat;
    }

    void Matrix3x3::operator/=(double d) {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                (*this)[i][j] /= d;
            }
        }
    }
}