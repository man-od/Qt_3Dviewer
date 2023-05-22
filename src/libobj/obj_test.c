#include <check.h>
#include <math.h>

#include "affine_transform.h"
#include "obj_data.h"

int eq_matrix(float *a, float *b) {
  int ans = 0;
  for (int i = 0; i < 16; i++) {
    if (fabs(a[i] - b[i]) > 1e-5f) {
      ans = 1;
    }
  }
  return ans;
}

START_TEST(test_parser_1) {
  ObjData *A;
  A = obj_data_get("../../obj/Pyramid.obj");
  ck_assert_int_eq(A->exception, NO_EXC);
  obj_data_destroy(A);
}
END_TEST

START_TEST(test_rotationX) {
  float angle = toRadian(40);
  float mat[16];
  mat[0] = 1.0f, mat[1] = 0.0f, mat[2] = 0.0f, mat[3] = 0.0f;
  mat[4] = 0.0f, mat[5] = 0.766044f, mat[6] = -0.642787f, mat[7] = 0.0f;
  mat[8] = 0.0f, mat[9] = 0.642787f, mat[10] = 0.766044f, mat[11] = 0.0f;
  mat[12] = 0.0f, mat[13] = 0.0f, mat[14] = 0.0f, mat[15] = 1.0f;
  float res[16] = {0};
  rotateX(angle, res);
  int error = eq_matrix(res, mat);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(test_rotationY) {
  float angle = toRadian(75);
  float mat[16];
  mat[0] = 0.258819, mat[1] = 0.0f, mat[2] = 0.965925, mat[3] = 0.0f;
  mat[4] = 0.0f, mat[5] = 1.0f, mat[6] = 0.0f, mat[7] = 0.0f;
  mat[8] = -0.965925, mat[9] = 0.0f, mat[10] = 0.258819, mat[11] = 0.0f;
  mat[12] = 0.0f, mat[13] = 0.0f, mat[14] = 0.0f, mat[15] = 1.0f;
  float res[16] = {0};
  rotateY(angle, res);
  int error = eq_matrix(res, mat);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(test_rotationZ) {
  float angle = toRadian(157);
  float mat[16];
  mat[0] = -0.920504, mat[1] = -0.390731, mat[2] = 0.0f, mat[3] = 0.0f;
  mat[4] = 0.390731, mat[5] = -0.920504, mat[6] = 0.0f, mat[7] = 0.0f;
  mat[8] = 0.0f, mat[9] = 0.0f, mat[10] = 1.0f, mat[11] = 0.0f;
  mat[12] = 0.0f, mat[13] = 0.0f, mat[14] = 0.0f, mat[15] = 1.0f;

  float res[16] = {0};
  rotateZ(angle, res);
  int error = eq_matrix(res, mat);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(test_zoom) {
  float coef = 0.5;
  float mat[16];
  mat[0] = coef, mat[1] = 0.0f, mat[2] = 0.0f, mat[3] = 0.0f;
  mat[4] = 0.0f, mat[5] = coef, mat[6] = 0.0f, mat[7] = 0.0f;
  mat[8] = 0.0f, mat[9] = 0.0f, mat[10] = coef, mat[11] = 0.0f;
  mat[12] = 0.0f, mat[13] = 0.0f, mat[14] = 0.0f, mat[15] = 1.0f;
  float res[16] = {0};
  zoom(0.5, res);
  int error = eq_matrix(res, mat);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(test_offsetX) {
  float dist = 5;
  float mat[16];
  mat[0] = 1.0f, mat[1] = 0.0f, mat[2] = 0.0f, mat[3] = 0.0f;
  mat[4] = 0.0f, mat[5] = 1.0f, mat[6] = 0.0f, mat[7] = 0.0f;
  mat[8] = 0.0f, mat[9] = 0.0f, mat[10] = 1.0f, mat[11] = 0.0f;
  mat[12] = dist, mat[13] = 0.0f, mat[14] = 0.0f, mat[15] = 1.0f;
  float res[16] = {0};
  offsetX(dist, res);
  int error = eq_matrix(res, mat);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(test_offsetY) {
  float dist = 8;
  float mat[16];
  mat[0] = 1.0f, mat[1] = 0.0f, mat[2] = 0.0f, mat[3] = 0.0f;
  mat[4] = 0.0f, mat[5] = 1.0f, mat[6] = 0.0f, mat[7] = 0.0f;
  mat[8] = 0.0f, mat[9] = 0.0f, mat[10] = 1.0f, mat[11] = 0.0f;
  mat[12] = 0.0f, mat[13] = dist, mat[14] = 0.0f, mat[15] = 1.0f;
  float res[16] = {0};
  offsetY(dist, res);
  int error = eq_matrix(res, mat);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(test_offsetZ) {
  float dist = 3;
  float mat[16];
  mat[0] = 1.0f, mat[1] = 0.0f, mat[2] = 0.0f, mat[3] = 0.0f;
  mat[4] = 0.0f, mat[5] = 1.0f, mat[6] = 0.0f, mat[7] = 0.0f;
  mat[8] = 0.0f, mat[9] = 0.0f, mat[10] = 1.0f, mat[11] = 0.0f;
  mat[12] = 0.0f, mat[13] = 0.0f, mat[14] = dist, mat[15] = 1.0f;
  float res[16] = {0};
  offsetZ(dist, res);
  int error = eq_matrix(res, mat);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(test_mult) {
  float matA[16];
  float matB[16];
  float res[16];
  matA[0] = 1.0f, matA[1] = 7.5f, matA[2] = 3.0f, matA[3] = 9.0f;
  matA[4] = 23.0f, matA[5] = 87.0f, matA[6] = 45.0f, matA[7] = 9.0f;
  matA[8] = 5.0f, matA[9] = 3.0f, matA[10] = 32.0f, matA[11] = 6.0f;
  matA[12] = 2.0f, matA[13] = 1.0f, matA[14] = 12.0f, matA[15] = 8.0f;

  matB[0] = 6.0f, matB[1] = 8.0f, matB[2] = 13.0f, matB[3] = 9.0f;
  matB[4] = 43.0f, matB[5] = 17.0f, matB[6] = 6.0f, matB[7] = 1.0f;
  matB[8] = 9.0f, matB[9] = 3.0f, matB[10] = 7.0f, matB[11] = 11.3f;
  matB[12] = 20.4f, matB[13] = 2.0f, matB[14] = 0.0f, matB[15] = 3.0f;

  res[0] = 539.1f, res[1] = 162.5f, res[2] = 79.0f, res[3] = 77.4f;
  res[4] = 4467.6f, res[5] = 1816.0f, res[6] = 1136.0f, res[7] = 829.5f;
  res[8] = 569.4f, res[9] = 199.0f, res[10] = 307.0f, res[11] = 427.6f;
  res[12] = 326.2f, res[13] = 85.0f, res[14] = 116.0f, res[15] = 178.6f;

  float ans[16] = {0};
  multMatrix(matA, matB, ans);
  int error = eq_matrix(res, ans);
  ck_assert_int_eq(error, 0);
}

int main(void) {
  Suite *s1 = suite_create("Core");
  TCase *tc = tcase_create("Core");
  SRunner *sr = srunner_create(s1);
  int failed_count;
  suite_add_tcase(s1, tc);

  tcase_add_test(tc, test_rotationX);
  tcase_add_test(tc, test_rotationY);
  tcase_add_test(tc, test_rotationZ);
  tcase_add_test(tc, test_parser_1);
  tcase_add_test(tc, test_zoom);
  tcase_add_test(tc, test_offsetX);
  tcase_add_test(tc, test_offsetY);
  tcase_add_test(tc, test_offsetZ);
  tcase_add_test(tc, test_mult);

  srunner_run_all(sr, CK_ENV);
  failed_count = srunner_ntests_failed(sr);
  srunner_free(sr);
  return failed_count == 0 ? 0 : 1;
}
