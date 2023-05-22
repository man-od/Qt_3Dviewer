#include <QApplication>

#include "viewer/viewer.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  Viewer w;
  w.setWindowTitle("3DViewer_v1.0");
  w.setWindowIcon(QIcon(":/images/3DViewer_icon.png"));
  w.show();
  return a.exec();
}
