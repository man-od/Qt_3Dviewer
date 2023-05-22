#ifndef VIEWER_H
#define VIEWER_H

#include <QColorDialog>
#include <QFileDialog>
#include <QMainWindow>
#include <QSettings>

QT_BEGIN_NAMESPACE
namespace Ui {
class Viewer;
}
QT_END_NAMESPACE

class Viewer : public QMainWindow {
  Q_OBJECT

 public:
  explicit Viewer(QWidget *parent = nullptr);
  ~Viewer() override;

 protected:
  void init_viewer();
  void set_viewer_colors();
  void save_settings();
  void load_settings();
 private slots:
  void on_pushButton_openObj_clicked();
  void on_switch_line_type_currentIndexChanged(int);
  void on_switch_projection_currentIndexChanged(int);
  void on_LineWidth_SpinBox_valueChanged(int);
  void on_switch_type_vertex_currentIndexChanged(int);
  void on_vertexSize_SpinBox_valueChanged(int);
  void on_bg_color_clicked();
  void on_line_color_clicked();
  void on_vertex_color_clicked();
  void on_zoom_SpinBox_valueChanged(double);
  void on_moveSpinBox_X_valueChanged(int);
  void on_moveSpinBox_Y_valueChanged(int);
  void on_moveSpinBox_Z_valueChanged(int);
  void on_rotate_spinBox_X_valueChanged(int);
  void on_rotate_spinBox_Y_valueChanged(int);
  void on_rotate_spinBox_Z_valueChanged(int);

  void on_screen_button_clicked();

  void on_reset_clicked();

  void on_gif_button_clicked();

 private:
  Ui::Viewer *ui;
  QSettings settings;
};
#endif  // VIEWER_H
