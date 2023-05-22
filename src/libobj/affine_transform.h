#ifndef AFFINE_TRANSFORM_H
#define AFFINE_TRANSFORM_H

enum Axis { X, Y, Z };

#define IDENTITY_MAT 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1

#ifdef __cplusplus
extern "C" {
#endif

void rotateX(float angle, float *mat);
void rotateY(float angle, float *mat);
void rotateZ(float angle, float *mat);

void offsetX(float dist, float *mat);
void offsetY(float dist, float *mat);
void offsetZ(float dist, float *mat);

void zoom(float coef, float *mat);

void multMatrix(const float *mat1, const float *mat2, float *res);

float toRadian(float angle);

#ifdef __cplusplus
}
#endif

#endif  // AFFINE_TRANSFORM_H
