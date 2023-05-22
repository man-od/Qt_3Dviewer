#include "obj_loader.h"

#include <QDir>
#include <QFileDialog>
#include <QMessageBox>
#include <cmath>

#include "../libgif/gif.h"

ObjLoader::ObjLoader(QWidget* parent)
    : QOpenGLWidget(parent),
      m_line_type(false),
      m_proj_type(PARALLEL),
      m_point_size(1.0f),
      m_line_size(1.0f),
      m_obj_data(obj_data_get("0")),
      m_vbo(QOpenGLBuffer::VertexBuffer),
      m_ibo(QOpenGLBuffer::IndexBuffer),
      m_color_line(0.7f, 0.7f, 0.7f),
      m_color_point(0.7f, 0.7f, 0.7f),
      m_color_bg(Qt::black),
      m_zMat{IDENTITY_MAT},
      m_rMatX{IDENTITY_MAT},
      m_rMatY{IDENTITY_MAT},
      m_rMatZ{IDENTITY_MAT},
      m_mMatX{IDENTITY_MAT},
      m_mMatY{IDENTITY_MAT},
      m_mMatZ{IDENTITY_MAT} {}

ObjLoader::~ObjLoader() { objDestroy(); }

exc_t ObjLoader::objOpen(const QString& path) {
  objDestroy();
  QByteArray bytes = path.toLocal8Bit().data();
  m_obj_data = obj_data_get(bytes.constData());
  exc_t exc = (!m_obj_data) ? ALLOC_FAIL : m_obj_data->exception;
  if (exc != ALLOC_FAIL) {
    if (exc) {
      obj_data_destroy(m_obj_data);
      m_obj_data = obj_data_get("0");
    }
    objCreate();
    resizeGL(width(), height());
    update();
  }
  return exc;
}

void ObjLoader::objDestroy() {
  makeCurrent();
  m_vao.destroy();
  m_vbo.destroy();
  m_ibo.destroy();
  m_program->removeAllShaders();
  m_program->deleteLater();
  obj_data_destroy(m_obj_data);
}

void ObjLoader::objRotate(float angle, int axis) {
  float rad_angle = toRadian(angle);
  if (axis == X) {
    rotateX(rad_angle, m_rMatX);
  } else if (axis == Y) {
    rotateY(rad_angle, m_rMatY);
  } else {
    rotateZ(rad_angle, m_rMatZ);
  }

  update();
}

void ObjLoader::objZoom(float coef) {
  zoom(coef, m_zMat);
  update();
}

void ObjLoader::objMove(float dist, int axis) {
  if (axis == X) {
    offsetX(dist, m_mMatX);
  } else if (axis == Y) {
    offsetY(dist, m_mMatY);
  } else {
    offsetZ(dist, m_mMatZ);
  }
  update();
}

void ObjLoader::objCreate() {
  m_vao.create();
  m_vao.bind();

  m_vbo.create();
  m_vbo.bind();
  m_vbo.setUsagePattern(QOpenGLBuffer::StaticDraw);
  m_vbo.allocate(m_obj_data->vertices.position,
                 m_obj_data->vertices.size * sizeof(float));

  m_ibo.create();
  m_ibo.bind();
  m_ibo.setUsagePattern(QOpenGLBuffer::StaticDraw);
  m_ibo.allocate(m_obj_data->facets.index,
                 m_obj_data->facets.size * sizeof(unsigned int));

  m_program = new QOpenGLShaderProgram(this);

  m_program->addShaderFromSourceCode(
      QOpenGLShader::Vertex,
      "attribute vec3 position;\n"
      "uniform mat4 projMat;\n"
      "uniform mat4 rotateMat;\n"
      "uniform mat4 zoomMat;\n"
      "uniform mat4 moveMat;\n"
      "void main()\n"
      "{\n"
      "gl_Position =  projMat * rotateMat * moveMat * zoomMat * vec4(position, "
      "1.0);\n"
      "}\0");
  m_program->addShaderFromSourceCode(QOpenGLShader::Fragment,
                                     "uniform vec3 color;\n"
                                     "void main()\n"
                                     "{\n"
                                     "gl_FragColor = vec4(color, 1.0);\n"
                                     "}\0");

  if (!m_program->link()) {
    close();
  }

  m_program->enableAttributeArray(0);
  m_program->setAttributeBuffer(0, GL_FLOAT, 0, 3, 0);

  m_program->bind();

  m_matrixUniform = m_program->uniformLocation("projMat");
  m_rotateUniform = m_program->uniformLocation("rotateMat");
  m_zoomUniform = m_program->uniformLocation("zoomMat");
  m_moveUniform = m_program->uniformLocation("moveMat");
  m_colorUniform = m_program->uniformLocation("color");

  m_vao.release();
  m_vbo.release();
  m_ibo.release();
  m_program->release();
}

void ObjLoader::setLineSize(float size) {
  m_line_size = size;
  update();
}

void ObjLoader::setPointSize(float size) {
  m_point_size = size;
  update();
}

unsigned int ObjLoader::getFacetCount() { return m_obj_data->facet_count; }

QColor ObjLoader::getColorLine() {
  return QColor::fromRgbF(m_color_line.x(), m_color_line.y(), m_color_line.z());
}

QColor ObjLoader::getColorPoint() {
  return QColor::fromRgbF(m_color_point.x(), m_color_point.y(),
                          m_color_point.z());
}

QColor ObjLoader::getColorBg() { return m_color_bg; }

unsigned int ObjLoader::getVertexCount() { return m_obj_data->vertex_count; }

void ObjLoader::setColorLine(const QColor& color_line) {
  m_color_line =
      QVector3D(color_line.redF(), color_line.greenF(), color_line.blueF());
  update();
}

void ObjLoader::setColorPoint(const QColor& color_point) {
  m_color_point =
      QVector3D(color_point.redF(), color_point.greenF(), color_point.blueF());
  update();
}

void ObjLoader::setColorBg(const QColor& color_bg) {
  m_color_bg = color_bg;
  update();
}

void ObjLoader::setProjectionType(int proj_type) {
  m_proj_type = proj_type;
  resizeGL(width(), height());
  update();
}

void ObjLoader::setLineType(bool type) {
  m_line_type = type;
  update();
}
void ObjLoader::setPointType(int type) {
  m_point_type = type;
  update();
}

inline void ObjLoader::UniformRotationMat() {
  float rotateMat[16];
  multMatrix(m_rMatX, m_rMatY, rotateMat);
  multMatrix(rotateMat, m_rMatZ, rotateMat);
  glUniformMatrix4fv(m_rotateUniform, 1, GL_FALSE, rotateMat);
}

inline void ObjLoader::UniformMoveMat() {
  float moveMat[16];
  multMatrix(m_mMatX, m_mMatY, moveMat);
  multMatrix(moveMat, m_mMatZ, moveMat);
  glUniformMatrix4fv(m_moveUniform, 1, GL_FALSE, moveMat);
}

void ObjLoader::initializeGL() {
  initializeOpenGLFunctions();
  objCreate();
}

void ObjLoader::resizeGL(int width, int height) {
  m_pMat.setToIdentity();

  GLfloat size_x =
      std::abs(m_obj_data->vertices.min[0] - m_obj_data->vertices.max[0]);
  GLfloat size_y =
      std::abs(m_obj_data->vertices.min[1] - m_obj_data->vertices.max[1]);
  GLfloat size_z =
      std::abs(m_obj_data->vertices.min[2] - m_obj_data->vertices.max[2]);
  GLfloat mid_size_x =
      (m_obj_data->vertices.min[0] + m_obj_data->vertices.max[0]) / 2.0f;
  GLfloat mid_size_y =
      (m_obj_data->vertices.min[1] + m_obj_data->vertices.max[1]) / 2.0f;
  GLfloat mid_size_z =
      (m_obj_data->vertices.min[2] + m_obj_data->vertices.max[2]) / 2.0f;
  GLfloat max_size = std::max(std::max(size_x, size_y), size_z);
  GLfloat aspectratio = GLfloat(width) / GLfloat(height);
  if (m_proj_type == CENTRAL) {
    QVector3D center(mid_size_x, mid_size_y, mid_size_z);
    QMatrix4x4 viewMat;
    viewMat.lookAt(QVector3D(center.x(), center.y(), center.z() + max_size),
                   center, QVector3D(0.0f, 1.0f, 0.0f));
    m_pMat.perspective(100.0, aspectratio, 0.01f * max_size, 100.0f * max_size);
    m_pMat *= viewMat;
  } else {
    m_pMat.ortho(-max_size * aspectratio, max_size * aspectratio, -max_size,
                 max_size, -100.0f * max_size, 100.0f * max_size);
  }
}

void ObjLoader::makeGif() {
  QString file_name = QDir::homePath() + "/gif_image.gif";
  if (QFile::exists(file_name)) {
    QFile::remove(file_name);
  }
  int delay = 100;
  GifWriter gif_wr;
  GifBegin(&gif_wr, file_name.toStdString().c_str(), 640, 480, delay);
  for (int timer = 0; timer <= 5000; timer += delay) {
    GifWriteFrame(&gif_wr,
                  m_frame.convertToFormat(QImage::Format_Indexed8)
                      .convertToFormat(QImage::Format_RGBA8888)
                      .constBits(),
                  640, 480, 1);
    std::this_thread::sleep_for(std::chrono::milliseconds(delay));
  }
  GifEnd(&gif_wr);
}

void ObjLoader::paintGL() {
  glClearColor(m_color_bg.redF(), m_color_bg.greenF(), m_color_bg.blueF(),
               m_color_bg.alphaF());
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLineWidth(m_line_size);
  glPointSize(m_point_size);

  m_program->bind();
  m_vao.bind();

  glUniformMatrix4fv(m_matrixUniform, 1, GL_FALSE, m_pMat.constData());
  UniformRotationMat();
  UniformMoveMat();
  glUniformMatrix4fv(m_zoomUniform, 1, GL_FALSE, m_zMat);

  m_program->setUniformValue(m_colorUniform, m_color_line);
  if (m_line_type) {
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(2, 0x00F0);
  }
  glDrawElements(GL_LINES, m_obj_data->facets.size, GL_UNSIGNED_INT, nullptr);
  if (m_line_type) {
    glDisable(GL_LINE_STIPPLE);
  }
  if (m_point_type) {
    m_program->setUniformValue(m_colorUniform, m_color_point);
    if (m_point_type == 2) {
      glEnable(GL_POINT_SMOOTH);
    }
    glDrawElements(GL_POINTS, m_obj_data->facets.size, GL_UNSIGNED_INT,
                   nullptr);
    if (m_point_type == 2) {
      glDisable(GL_POINT_SMOOTH);
    }
  }
  m_frame = grabFramebuffer().scaled(640, 480, Qt::IgnoreAspectRatio);
  m_vao.release();
  m_program->release();
}
