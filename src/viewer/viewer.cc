#include "viewer.h"

#include <QImageWriter>
#include <QMessageBox>
#include <QStandardPaths>
#include <QStyleFactory>

#include "../libgif/gif.h"
#include "./ui_viewer.h"

Viewer::Viewer(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::Viewer),
      settings("3DViewer_v1.0") {
  ui->setupUi(this);
  set_viewer_colors();
  init_viewer();
  load_settings();
}

Viewer::~Viewer() {
  save_settings();
  delete ui;
}

void Viewer::init_viewer() {
  ui->zoom_SpinBox->setValue(1);
  connect(ui->rotate_x, &QSlider::valueChanged, ui->rotate_spinBox_X,
          &QSpinBox::setValue);
  connect(ui->rotate_spinBox_X, QOverload<int>::of(&QSpinBox::valueChanged),
          ui->rotate_x, &QSlider::setValue);
  ui->rotate_x->setRange(-360, 360);
  ui->moveSpinBox_X->setRange(-1000, 1000);
  ui->moveSpinBox_X->setValue(0);

  connect(ui->rotate_y, &QSlider::valueChanged, ui->rotate_spinBox_Y,
          &QSpinBox::setValue);
  connect(ui->rotate_spinBox_Y, QOverload<int>::of(&QSpinBox::valueChanged),
          ui->rotate_y, &QSlider::setValue);
  ui->rotate_y->setRange(-360, 360);
  ui->moveSpinBox_Y->setRange(-1000, 1000);
  ui->moveSpinBox_Y->setValue(0);

  connect(ui->rotate_z, &QSlider::valueChanged, ui->rotate_spinBox_Z,
          &QSpinBox::setValue);
  connect(ui->rotate_spinBox_Z, QOverload<int>::of(&QSpinBox::valueChanged),
          ui->rotate_z, &QSlider::setValue);
  ui->rotate_z->setRange(-360, 360);
  ui->moveSpinBox_Z->setRange(-1000, 1000);
  ui->moveSpinBox_Z->setValue(0);

  connect(ui->LineWidth_Slider, &QSlider::valueChanged, ui->LineWidth_SpinBox,
          &QSpinBox::setValue);
  connect(ui->LineWidth_SpinBox, QOverload<int>::of(&QSpinBox::valueChanged),
          ui->LineWidth_Slider, &QSlider::setValue);
  ui->LineWidth_Slider->setRange(1, 10);
  ui->LineWidth_SpinBox->setRange(1, 10);

  connect(ui->vertexSize_Slider, &QSlider::valueChanged, ui->vertexSize_SpinBox,
          &QSpinBox::setValue);
  connect(ui->vertexSize_SpinBox, QOverload<int>::of(&QSpinBox::valueChanged),
          ui->vertexSize_Slider, &QSlider::setValue);
  ui->vertexSize_Slider->setRange(1, 10);
  ui->vertexSize_SpinBox->setRange(1, 10);

  ui->rotate_spinBox_X->setRange(-360, 360);
  ui->rotate_spinBox_X->setValue(0);

  ui->rotate_spinBox_Y->setRange(-360, 360);
  ui->rotate_spinBox_Y->setValue(0);

  ui->rotate_spinBox_Z->setRange(-360, 360);
  ui->rotate_spinBox_Z->setValue(0);
}

void Viewer::set_viewer_colors() {
  QApplication::setStyle(QStyleFactory::create("Fusion"));
  QPalette darkPalette;
  darkPalette.setColor(QPalette::Window, QColor(53, 53, 53));
  darkPalette.setColor(QPalette::WindowText, Qt::white);
  darkPalette.setColor(QPalette::Base, QColor(25, 25, 25));
  darkPalette.setColor(QPalette::AlternateBase, QColor(53, 53, 53));
  darkPalette.setColor(QPalette::ToolTipBase, Qt::white);
  darkPalette.setColor(QPalette::ToolTipText, Qt::white);
  darkPalette.setColor(QPalette::Text, Qt::white);
  darkPalette.setColor(QPalette::Button, QColor(53, 53, 53));
  darkPalette.setColor(QPalette::ButtonText, Qt::white);
  darkPalette.setColor(QPalette::BrightText, Qt::red);
  darkPalette.setColor(QPalette::Link, QColor(42, 130, 218));
  darkPalette.setColor(QPalette::Highlight, QColor(42, 130, 218));
  darkPalette.setColor(QPalette::HighlightedText, Qt::black);
  QApplication::setPalette(darkPalette);
}

void Viewer::save_settings() {
  settings.setValue("projection", ui->switch_projection->currentIndex());
  settings.setValue("line type", ui->switch_line_type->currentIndex());
  settings.setValue("line color", ui->objWidget->getColorLine());
  settings.setValue("line width", ui->LineWidth_SpinBox->value());
  settings.setValue("point type", ui->switch_type_vertex->currentIndex());
  settings.setValue("point color", ui->objWidget->getColorPoint());
  settings.setValue("point width", ui->vertexSize_SpinBox->value());
  settings.setValue("background color", ui->objWidget->getColorBg());
}

void Viewer::load_settings() {
  QString settingsFilePath = settings.fileName();
  QFile file(settingsFilePath);
  if (file.exists()) {
    ui->switch_projection->setCurrentIndex(
        settings.value("projection").toInt());
    ui->switch_line_type->setCurrentIndex(settings.value("line type").toInt());
    ui->objWidget->setColorLine(settings.value("line color").value<QColor>());
    ui->LineWidth_SpinBox->setValue(settings.value("line width").toInt());
    ui->switch_type_vertex->setCurrentIndex(
        settings.value("point type").toInt());
    ui->objWidget->setColorPoint(settings.value("point color").value<QColor>());
    ui->vertexSize_SpinBox->setValue(settings.value("point width").toInt());
    ui->objWidget->setColorBg(
        settings.value("background color").value<QColor>());
  }
}

void Viewer::on_pushButton_openObj_clicked() {
  QString filepath = QFileDialog::getOpenFileName(
      this, tr("Open File"), QDir::homePath(), tr("OBJ files (*.obj)"));
  if (!filepath.isEmpty()) {
    QFileInfo fileInfo(filepath);
    exc_t exc = ui->objWidget->objOpen(filepath);
    if (exc) {
      QStringList str = {"Нет ошибки", "no such file or directory",
                         "invalid file", "allocate failed"};
      QMessageBox::critical(this, "Error", str[exc]);
    }
    ui->label_file_name->setText("Название файла: " + fileInfo.fileName());
    ui->label_vertex_am->setText(
        "Количество вершин: " +
        QString::number(ui->objWidget->getVertexCount()));
    ui->label_facets_am->setText(
        "Количество ребер: " + QString::number(ui->objWidget->getFacetCount()));
  }
}

void Viewer::on_bg_color_clicked() {
  QColor color = QColorDialog::getColor(QColor(0.0, 0.0, 0.0, 0));
  if (color.isValid()) {
    ui->objWidget->setColorBg(color);
  }
}

void Viewer::on_switch_line_type_currentIndexChanged(int index) {
  ui->objWidget->setLineType(index);
}

void Viewer::on_switch_projection_currentIndexChanged(int index) {
  ui->objWidget->setProjectionType(index);
}

void Viewer::on_LineWidth_SpinBox_valueChanged(int arg1) {
  ui->objWidget->setLineSize(static_cast<float>(arg1));
}

void Viewer::on_switch_type_vertex_currentIndexChanged(int index) {
  ui->objWidget->setPointType(index);
}

void Viewer::on_vertexSize_SpinBox_valueChanged(int arg1) {
  ui->objWidget->setPointSize(static_cast<float>(arg1));
}

void Viewer::on_line_color_clicked() {
  QColor color = QColorDialog::getColor(QColor(0.0, 0.0, 0.0, 0));
  if (color.isValid()) {
    ui->objWidget->setColorLine(color);
  }
}

void Viewer::on_vertex_color_clicked() {
  QColor color = QColorDialog::getColor(QColor(0.0, 0.0, 0.0, 0));
  if (color.isValid()) {
    ui->objWidget->setColorPoint(color);
  }
}

void Viewer::on_zoom_SpinBox_valueChanged(double value) {
  ui->objWidget->objZoom(static_cast<float>(value));
}

void Viewer::on_moveSpinBox_X_valueChanged(int value) {
  ui->objWidget->objMove(static_cast<float>(value), X);
}

void Viewer::on_moveSpinBox_Y_valueChanged(int value) {
  ui->objWidget->objMove(static_cast<float>(value), Y);
}

void Viewer::on_moveSpinBox_Z_valueChanged(int value) {
  ui->objWidget->objMove(static_cast<float>(value), Z);
}

void Viewer::on_rotate_spinBox_X_valueChanged(int value) {
  ui->objWidget->objRotate(static_cast<float>(value), X);
}

void Viewer::on_rotate_spinBox_Y_valueChanged(int value) {
  ui->objWidget->objRotate(static_cast<float>(value), Y);
}

void Viewer::on_rotate_spinBox_Z_valueChanged(int value) {
  ui->objWidget->objRotate(static_cast<float>(value), Z);
}

void Viewer::on_screen_button_clicked() {
  const QRect rect(0, 0, ui->objWidget->width(), ui->objWidget->height());
  QPixmap pixmap = ui->objWidget->grab(rect);

  const QString format = "png";
  QString savePath =
      QStandardPaths::writableLocation(QStandardPaths::PicturesLocation);
  if (savePath.isEmpty()) {
    savePath = QDir::currentPath();
  }
  savePath += tr("/screenshot.") + format;
  QFileDialog fileDialog(this, tr("Save As"), savePath);
  fileDialog.setAcceptMode(QFileDialog::AcceptSave);
  fileDialog.setFileMode(QFileDialog::AnyFile);
  fileDialog.setDirectory(savePath);

  QStringList mimeTypes;
  const QList<QByteArray> baMimeTypes = QImageWriter::supportedMimeTypes();
  for (const QByteArray &bf : baMimeTypes) {
    mimeTypes.append(QLatin1String(bf));
  }
  fileDialog.setMimeTypeFilters(mimeTypes);
  fileDialog.selectMimeTypeFilter("image/" + format);
  fileDialog.setDefaultSuffix(format);
  if (fileDialog.exec() != QDialog::Accepted) {
    return;
  }
  const QString fileName = fileDialog.selectedFiles().first();
  if (!pixmap.save(fileName)) {
    QMessageBox::warning(this, tr("Save Error"),
                         tr("The image could not be saved to \"%1\".")
                             .arg(QDir::toNativeSeparators(fileName)));
  }
}

void Viewer::on_reset_clicked() {
  ui->switch_projection->setCurrentIndex(0);
  ui->switch_line_type->setCurrentIndex(0);
  ui->objWidget->setColorLine(QColor::fromRgbF(0.7f, 0.7f, 0.7f));
  ui->LineWidth_SpinBox->setValue(0);
  ui->switch_type_vertex->setCurrentIndex(0);
  ui->objWidget->setColorPoint(QColor::fromRgbF(0.7f, 0.7f, 0.7f));
  ui->vertexSize_SpinBox->setValue(0);
  ui->objWidget->setColorBg(QColor(Qt::black));
}

void Viewer::on_gif_button_clicked() {
  std::thread gif_thread(&ObjLoader::makeGif, ui->objWidget);
  gif_thread.detach();
}
