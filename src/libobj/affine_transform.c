#include "affine_transform.h"

#include <math.h>
#include <string.h>

#define S21_PI 3.14159265358979323846

void rotateX(float angle, float *mat) {
  mat[0] = 1.0f, mat[1] = 0.0f, mat[2] = 0.0f, mat[3] = 0.0f;
  mat[4] = 0.0f, mat[5] = cosf(angle), mat[6] = -sinf(angle), mat[7] = 0.0f;
  mat[8] = 0.0f, mat[9] = sinf(angle), mat[10] = cosf(angle), mat[11] = 0.0f;
  mat[12] = 0.0f, mat[13] = 0.0f, mat[14] = 0.0f, mat[15] = 1.0f;
}

void rotateY(float angle, float *mat) {
  mat[0] = cosf(angle), mat[1] = 0.0f, mat[2] = sinf(angle), mat[3] = 0.0f;
  mat[4] = 0.0f, mat[5] = 1.0f, mat[6] = 0.0f, mat[7] = 0.0f;
  mat[8] = -sinf(angle), mat[9] = 0.0f, mat[10] = cosf(angle), mat[11] = 0.0f;
  mat[12] = 0.0f, mat[13] = 0.0f, mat[14] = 0.0f, mat[15] = 1.0f;
}

void rotateZ(float angle, float *mat) {
  mat[0] = cosf(angle), mat[1] = -sinf(angle), mat[2] = 0.0f, mat[3] = 0.0f;
  mat[4] = sinf(angle), mat[5] = cosf(angle), mat[6] = 0.0f, mat[7] = 0.0f;
  mat[8] = 0.0f, mat[9] = 0.0f, mat[10] = 1.0f, mat[11] = 0.0f;
  mat[12] = 0.0f, mat[13] = 0.0f, mat[14] = 0.0f, mat[15] = 1.0f;
}

void multMatrix(const float *mat1, const float *mat2, float *res) {
  float tmp[16];
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      float f = 0;
      for (int k = 0; k < 4; k++) {
        f += mat1[i * 4 + k] * mat2[k * 4 + j];
      }
      tmp[i * 4 + j] = f;
    }
  }
  memcpy(res, tmp, 16 * sizeof(float));
}

float toRadian(float angle) { return angle * S21_PI / 180; }

void zoom(float coef, float *mat) {
  mat[0] = coef, mat[1] = 0.0f, mat[2] = 0.0f, mat[3] = 0.0f;
  mat[4] = 0.0f, mat[5] = coef, mat[6] = 0.0f, mat[7] = 0.0f;
  mat[8] = 0.0f, mat[9] = 0.0f, mat[10] = coef, mat[11] = 0.0f;
  mat[12] = 0.0f, mat[13] = 0.0f, mat[14] = 0.0f, mat[15] = 1.0f;
}

void offsetX(float dist, float *mat) {
  mat[0] = 1.0f, mat[1] = 0.0f, mat[2] = 0.0f, mat[3] = 0.0f;
  mat[4] = 0.0f, mat[5] = 1.0f, mat[6] = 0.0f, mat[7] = 0.0f;
  mat[8] = 0.0f, mat[9] = 0.0f, mat[10] = 1.0f, mat[11] = 0.0f;
  mat[12] = dist, mat[13] = 0.0f, mat[14] = 0.0f, mat[15] = 1.0f;
}

void offsetY(float dist, float *mat) {
  mat[0] = 1.0f, mat[1] = 0.0f, mat[2] = 0.0f, mat[3] = 0.0f;
  mat[4] = 0.0f, mat[5] = 1.0f, mat[6] = 0.0f, mat[7] = 0.0f;
  mat[8] = 0.0f, mat[9] = 0.0f, mat[10] = 1.0f, mat[11] = 0.0f;
  mat[12] = 0.0f, mat[13] = dist, mat[14] = 0.0f, mat[15] = 1.0f;
}

void offsetZ(float dist, float *mat) {
  mat[0] = 1.0f, mat[1] = 0.0f, mat[2] = 0.0f, mat[3] = 0.0f;
  mat[4] = 0.0f, mat[5] = 1.0f, mat[6] = 0.0f, mat[7] = 0.0f;
  mat[8] = 0.0f, mat[9] = 0.0f, mat[10] = 1.0f, mat[11] = 0.0f;
  mat[12] = 0.0f, mat[13] = 0.0f, mat[14] = dist, mat[15] = 1.0f;
}
