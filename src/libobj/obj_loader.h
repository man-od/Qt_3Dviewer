#ifndef OBJ_LOADER_H
#define OBJ_LOADER_H

#include <QOpenGLBuffer>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLWidget>
#include <thread>

#include "affine_transform.h"
#include "obj_data.h"

class ObjLoader : public QOpenGLWidget, protected QOpenGLFunctions {
  Q_OBJECT
 public:
  exc_t objOpen(const QString &);
  void objRotate(float, int);
  void objZoom(float);
  void objMove(float, int);
  void makeGif();
  void setLineSize(float);
  void setPointSize(float);
  void setColorPoint(const QColor &);
  void setColorLine(const QColor &);
  void setColorBg(const QColor &);
  void setPointType(int);
  void setLineType(bool);
  void setProjectionType(int);
  unsigned int getVertexCount();
  unsigned int getFacetCount();
  QColor getColorLine();
  QColor getColorPoint();
  QColor getColorBg();
  explicit ObjLoader(QWidget *parent = nullptr);
  ~ObjLoader() override;

 protected:
  void initializeGL() override;
  void resizeGL(int, int) override;
  void paintGL() override;
  void objCreate();
  void objDestroy();
  void UniformRotationMat();
  void UniformMoveMat();

 private:
  enum ProjType { PARALLEL, CENTRAL };
  bool m_line_type;
  int m_point_type{};
  int m_proj_type;
  GLint m_matrixUniform{};
  GLint m_colorUniform{};
  GLint m_rotateUniform{};
  GLint m_zoomUniform{};
  GLint m_moveUniform{};
  GLfloat m_point_size;
  GLfloat m_line_size;
  ObjData *m_obj_data;
  QOpenGLBuffer m_vbo;
  QOpenGLBuffer m_ibo;
  QVector3D m_color_line;
  QVector3D m_color_point;
  QColor m_color_bg;
  QOpenGLShaderProgram *m_program{};
  QOpenGLVertexArrayObject m_vao;
  float m_zMat[16];
  float m_rMatX[16];
  float m_rMatY[16];
  float m_rMatZ[16];
  float m_mMatX[16];
  float m_mMatY[16];
  float m_mMatZ[16];
  QMatrix4x4 m_pMat;
  QImage m_frame;
};
#endif  // OBJ_LOADER_H
