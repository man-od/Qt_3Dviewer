/********************************************************************************
** Form generated from reading UI file 'viewer.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEWER_H
#define UI_VIEWER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>
#include "src/libobj/obj_loader.h"

QT_BEGIN_NAMESPACE

class Ui_Viewer
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    ObjLoader *objWidget;
    QGridLayout *grid_layout;
    QLabel *label_17;
    QPushButton *pushButton_openObj;
    QSlider *rotate_z;
    QSlider *LineWidth_Slider;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *bg_color;
    QPushButton *vertex_color;
    QPushButton *line_color;
    QPushButton *reset;
    QSpinBox *LineWidth_SpinBox;
    QFrame *line_4;
    QPushButton *gif_button;
    QLabel *label_6;
    QSpinBox *rotate_spinBox_X;
    QSpinBox *moveSpinBox_Z;
    QComboBox *switch_type_vertex;
    QSpinBox *rotate_spinBox_Y;
    QLabel *label_15;
    QLabel *label_8;
    QLabel *label_11;
    QFrame *line_3;
    QLabel *label_7;
    QLabel *label_13;
    QSpinBox *moveSpinBox_Y;
    QLabel *label_5;
    QSpinBox *vertexSize_SpinBox;
    QSlider *vertexSize_Slider;
    QLabel *label_facets_am;
    QLabel *label_16;
    QSpinBox *rotate_spinBox_Z;
    QLabel *label_4;
    QLabel *label_file_name;
    QLabel *label_12;
    QLabel *label_vertex_am;
    QLabel *label_2;
    QSlider *rotate_x;
    QComboBox *switch_projection;
    QLabel *label_10;
    QFrame *line_2;
    QLabel *label_14;
    QSlider *rotate_y;
    QComboBox *switch_line_type;
    QLabel *label_18;
    QPushButton *screen_button;
    QFrame *line;
    QLabel *label;
    QSpinBox *moveSpinBox_X;
    QDoubleSpinBox *zoom_SpinBox;

    void setupUi(QMainWindow *Viewer)
    {
        if (Viewer->objectName().isEmpty())
            Viewer->setObjectName(QString::fromUtf8("Viewer"));
        Viewer->resize(1299, 725);
        centralwidget = new QWidget(Viewer);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setStyleSheet(QString::fromUtf8(""));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        objWidget = new ObjLoader(centralwidget);
        objWidget->setObjectName(QString::fromUtf8("objWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(objWidget->sizePolicy().hasHeightForWidth());
        objWidget->setSizePolicy(sizePolicy);
        objWidget->setMinimumSize(QSize(774, 0));

        horizontalLayout->addWidget(objWidget);

        grid_layout = new QGridLayout();
        grid_layout->setObjectName(QString::fromUtf8("grid_layout"));
        label_17 = new QLabel(centralwidget);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        QFont font;
        font.setPointSize(15);
        label_17->setFont(font);

        grid_layout->addWidget(label_17, 1, 0, 3, 1);

        pushButton_openObj = new QPushButton(centralwidget);
        pushButton_openObj->setObjectName(QString::fromUtf8("pushButton_openObj"));

        grid_layout->addWidget(pushButton_openObj, 0, 0, 1, 5);

        rotate_z = new QSlider(centralwidget);
        rotate_z->setObjectName(QString::fromUtf8("rotate_z"));
        rotate_z->setOrientation(Qt::Horizontal);

        grid_layout->addWidget(rotate_z, 16, 1, 1, 2);

        LineWidth_Slider = new QSlider(centralwidget);
        LineWidth_Slider->setObjectName(QString::fromUtf8("LineWidth_Slider"));
        LineWidth_Slider->setOrientation(Qt::Horizontal);

        grid_layout->addWidget(LineWidth_Slider, 20, 1, 1, 2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        bg_color = new QPushButton(centralwidget);
        bg_color->setObjectName(QString::fromUtf8("bg_color"));

        horizontalLayout_2->addWidget(bg_color);

        vertex_color = new QPushButton(centralwidget);
        vertex_color->setObjectName(QString::fromUtf8("vertex_color"));
        vertex_color->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_2->addWidget(vertex_color);

        line_color = new QPushButton(centralwidget);
        line_color->setObjectName(QString::fromUtf8("line_color"));

        horizontalLayout_2->addWidget(line_color);

        reset = new QPushButton(centralwidget);
        reset->setObjectName(QString::fromUtf8("reset"));
        reset->setStyleSheet(QString::fromUtf8("background-color: rgb(20, 99, 224);\n"
"border-radius: 15%;\n"
"padding: 3px;\n"
""));

        horizontalLayout_2->addWidget(reset);


        grid_layout->addLayout(horizontalLayout_2, 25, 0, 1, 5);

        LineWidth_SpinBox = new QSpinBox(centralwidget);
        LineWidth_SpinBox->setObjectName(QString::fromUtf8("LineWidth_SpinBox"));
        sizePolicy.setHeightForWidth(LineWidth_SpinBox->sizePolicy().hasHeightForWidth());
        LineWidth_SpinBox->setSizePolicy(sizePolicy);

        grid_layout->addWidget(LineWidth_SpinBox, 20, 4, 1, 1);

        line_4 = new QFrame(centralwidget);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        grid_layout->addWidget(line_4, 23, 0, 1, 5);

        gif_button = new QPushButton(centralwidget);
        gif_button->setObjectName(QString::fromUtf8("gif_button"));
        gif_button->setMaximumSize(QSize(130, 16777215));
        QFont font1;
        font1.setPointSize(11);
        gif_button->setFont(font1);

        grid_layout->addWidget(gif_button, 5, 0, 1, 1);

        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMaximumSize(QSize(16777215, 21));
        label_6->setStyleSheet(QString::fromUtf8("text-align: center;"));

        grid_layout->addWidget(label_6, 13, 0, 1, 5, Qt::AlignHCenter);

        rotate_spinBox_X = new QSpinBox(centralwidget);
        rotate_spinBox_X->setObjectName(QString::fromUtf8("rotate_spinBox_X"));
        sizePolicy.setHeightForWidth(rotate_spinBox_X->sizePolicy().hasHeightForWidth());
        rotate_spinBox_X->setSizePolicy(sizePolicy);
        rotate_spinBox_X->setMinimumSize(QSize(100, 0));

        grid_layout->addWidget(rotate_spinBox_X, 14, 4, 1, 1);

        moveSpinBox_Z = new QSpinBox(centralwidget);
        moveSpinBox_Z->setObjectName(QString::fromUtf8("moveSpinBox_Z"));
        sizePolicy.setHeightForWidth(moveSpinBox_Z->sizePolicy().hasHeightForWidth());
        moveSpinBox_Z->setSizePolicy(sizePolicy);

        grid_layout->addWidget(moveSpinBox_Z, 10, 1, 1, 2);

        switch_type_vertex = new QComboBox(centralwidget);
        switch_type_vertex->addItem(QString());
        switch_type_vertex->addItem(QString());
        switch_type_vertex->addItem(QString());
        switch_type_vertex->setObjectName(QString::fromUtf8("switch_type_vertex"));

        grid_layout->addWidget(switch_type_vertex, 21, 1, 1, 4);

        rotate_spinBox_Y = new QSpinBox(centralwidget);
        rotate_spinBox_Y->setObjectName(QString::fromUtf8("rotate_spinBox_Y"));
        sizePolicy.setHeightForWidth(rotate_spinBox_Y->sizePolicy().hasHeightForWidth());
        rotate_spinBox_Y->setSizePolicy(sizePolicy);
        rotate_spinBox_Y->setMinimumSize(QSize(100, 0));

        grid_layout->addWidget(rotate_spinBox_Y, 15, 4, 1, 1);

        label_15 = new QLabel(centralwidget);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setMaximumSize(QSize(16777215, 21));
        label_15->setFont(font);

        grid_layout->addWidget(label_15, 9, 0, 1, 1, Qt::AlignRight);

        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        QFont font2;
        font2.setPointSize(13);
        label_8->setFont(font2);

        grid_layout->addWidget(label_8, 4, 0, 1, 1);

        label_11 = new QLabel(centralwidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setMaximumSize(QSize(16777215, 21));
        label_11->setStyleSheet(QString::fromUtf8("text-align: center;"));

        grid_layout->addWidget(label_11, 7, 0, 1, 5, Qt::AlignHCenter);

        line_3 = new QFrame(centralwidget);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        grid_layout->addWidget(line_3, 18, 0, 1, 5);

        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setMaximumSize(QSize(16777215, 21));
        label_7->setFont(font);

        grid_layout->addWidget(label_7, 8, 0, 1, 1, Qt::AlignRight);

        label_13 = new QLabel(centralwidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        grid_layout->addWidget(label_13, 21, 0, 1, 1);

        moveSpinBox_Y = new QSpinBox(centralwidget);
        moveSpinBox_Y->setObjectName(QString::fromUtf8("moveSpinBox_Y"));
        sizePolicy.setHeightForWidth(moveSpinBox_Y->sizePolicy().hasHeightForWidth());
        moveSpinBox_Y->setSizePolicy(sizePolicy);

        grid_layout->addWidget(moveSpinBox_Y, 9, 1, 1, 2);

        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMaximumSize(QSize(16777215, 21));
        label_5->setFont(font);

        grid_layout->addWidget(label_5, 16, 0, 1, 1, Qt::AlignRight);

        vertexSize_SpinBox = new QSpinBox(centralwidget);
        vertexSize_SpinBox->setObjectName(QString::fromUtf8("vertexSize_SpinBox"));
        sizePolicy.setHeightForWidth(vertexSize_SpinBox->sizePolicy().hasHeightForWidth());
        vertexSize_SpinBox->setSizePolicy(sizePolicy);

        grid_layout->addWidget(vertexSize_SpinBox, 22, 4, 1, 1);

        vertexSize_Slider = new QSlider(centralwidget);
        vertexSize_Slider->setObjectName(QString::fromUtf8("vertexSize_Slider"));
        vertexSize_Slider->setOrientation(Qt::Horizontal);

        grid_layout->addWidget(vertexSize_Slider, 22, 1, 1, 2);

        label_facets_am = new QLabel(centralwidget);
        label_facets_am->setObjectName(QString::fromUtf8("label_facets_am"));
        label_facets_am->setMaximumSize(QSize(16777215, 16));

        grid_layout->addWidget(label_facets_am, 3, 1, 1, 4);

        label_16 = new QLabel(centralwidget);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setMaximumSize(QSize(16777215, 21));
        label_16->setFont(font);

        grid_layout->addWidget(label_16, 10, 0, 1, 1, Qt::AlignRight);

        rotate_spinBox_Z = new QSpinBox(centralwidget);
        rotate_spinBox_Z->setObjectName(QString::fromUtf8("rotate_spinBox_Z"));
        sizePolicy.setHeightForWidth(rotate_spinBox_Z->sizePolicy().hasHeightForWidth());
        rotate_spinBox_Z->setSizePolicy(sizePolicy);
        rotate_spinBox_Z->setMinimumSize(QSize(100, 0));
        rotate_spinBox_Z->setMaximumSize(QSize(16777215, 25));

        grid_layout->addWidget(rotate_spinBox_Z, 16, 4, 1, 1);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMaximumSize(QSize(16777215, 21));
        label_4->setFont(font);

        grid_layout->addWidget(label_4, 15, 0, 1, 1, Qt::AlignRight);

        label_file_name = new QLabel(centralwidget);
        label_file_name->setObjectName(QString::fromUtf8("label_file_name"));
        label_file_name->setMaximumSize(QSize(16777215, 16));

        grid_layout->addWidget(label_file_name, 1, 1, 1, 4);

        label_12 = new QLabel(centralwidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setMaximumSize(QSize(16777215, 21));
        label_12->setFont(font);
        label_12->setStyleSheet(QString::fromUtf8("text-align: center;"));

        grid_layout->addWidget(label_12, 24, 0, 1, 5, Qt::AlignHCenter);

        label_vertex_am = new QLabel(centralwidget);
        label_vertex_am->setObjectName(QString::fromUtf8("label_vertex_am"));
        label_vertex_am->setMaximumSize(QSize(16777215, 16));

        grid_layout->addWidget(label_vertex_am, 2, 1, 1, 4);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        grid_layout->addWidget(label_2, 19, 0, 1, 1);

        rotate_x = new QSlider(centralwidget);
        rotate_x->setObjectName(QString::fromUtf8("rotate_x"));
        rotate_x->setOrientation(Qt::Horizontal);

        grid_layout->addWidget(rotate_x, 14, 1, 1, 2);

        switch_projection = new QComboBox(centralwidget);
        switch_projection->addItem(QString());
        switch_projection->addItem(QString());
        switch_projection->setObjectName(QString::fromUtf8("switch_projection"));
        switch_projection->setStyleSheet(QString::fromUtf8(""));

        grid_layout->addWidget(switch_projection, 4, 1, 1, 4);

        label_10 = new QLabel(centralwidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        grid_layout->addWidget(label_10, 20, 0, 1, 1);

        line_2 = new QFrame(centralwidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        grid_layout->addWidget(line_2, 6, 0, 1, 5);

        label_14 = new QLabel(centralwidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setMaximumSize(QSize(16777215, 21));
        label_14->setFont(font);

        grid_layout->addWidget(label_14, 14, 0, 1, 1, Qt::AlignRight);

        rotate_y = new QSlider(centralwidget);
        rotate_y->setObjectName(QString::fromUtf8("rotate_y"));
        rotate_y->setOrientation(Qt::Horizontal);

        grid_layout->addWidget(rotate_y, 15, 1, 1, 2);

        switch_line_type = new QComboBox(centralwidget);
        switch_line_type->addItem(QString());
        switch_line_type->addItem(QString());
        switch_line_type->setObjectName(QString::fromUtf8("switch_line_type"));

        grid_layout->addWidget(switch_line_type, 19, 1, 1, 4);

        label_18 = new QLabel(centralwidget);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        grid_layout->addWidget(label_18, 22, 0, 1, 1);

        screen_button = new QPushButton(centralwidget);
        screen_button->setObjectName(QString::fromUtf8("screen_button"));
        screen_button->setMaximumSize(QSize(130, 16777215));
        screen_button->setFont(font1);

        grid_layout->addWidget(screen_button, 5, 1, 1, 1);

        line = new QFrame(centralwidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        grid_layout->addWidget(line, 11, 0, 1, 5);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        grid_layout->addWidget(label, 5, 2, 1, 1, Qt::AlignRight);

        moveSpinBox_X = new QSpinBox(centralwidget);
        moveSpinBox_X->setObjectName(QString::fromUtf8("moveSpinBox_X"));
        sizePolicy.setHeightForWidth(moveSpinBox_X->sizePolicy().hasHeightForWidth());
        moveSpinBox_X->setSizePolicy(sizePolicy);

        grid_layout->addWidget(moveSpinBox_X, 8, 1, 1, 2);

        zoom_SpinBox = new QDoubleSpinBox(centralwidget);
        zoom_SpinBox->setObjectName(QString::fromUtf8("zoom_SpinBox"));

        grid_layout->addWidget(zoom_SpinBox, 5, 4, 1, 1);


        horizontalLayout->addLayout(grid_layout);

        horizontalLayout->setStretch(0, 7);
        horizontalLayout->setStretch(1, 3);
        Viewer->setCentralWidget(centralwidget);

        retranslateUi(Viewer);

        QMetaObject::connectSlotsByName(Viewer);
    } // setupUi

    void retranslateUi(QMainWindow *Viewer)
    {
        Viewer->setWindowTitle(QCoreApplication::translate("Viewer", "Viewer", nullptr));
        label_17->setText(QCoreApplication::translate("Viewer", "\320\230\320\275\321\204\320\276:", nullptr));
        pushButton_openObj->setText(QCoreApplication::translate("Viewer", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \321\204\320\260\320\271\320\273", nullptr));
        bg_color->setText(QCoreApplication::translate("Viewer", "\320\244\320\276\320\275", nullptr));
        vertex_color->setText(QCoreApplication::translate("Viewer", "\320\222\320\265\321\200\321\210\320\270\320\275\320\260", nullptr));
        line_color->setText(QCoreApplication::translate("Viewer", "  \320\240\320\265\320\261\321\200\320\276  ", nullptr));
        reset->setText(QCoreApplication::translate("Viewer", "\320\241\320\261\321\200\320\276\321\201", nullptr));
        gif_button->setText(QCoreApplication::translate("Viewer", "\320\241\320\276\320\267\320\264\320\260\320\275\320\270\320\265 GIF", nullptr));
        label_6->setText(QCoreApplication::translate("Viewer", "\320\222\320\240\320\220\320\251\320\225\320\235\320\230\320\225", nullptr));
        switch_type_vertex->setItemText(0, QCoreApplication::translate("Viewer", "\320\236\321\202\321\201\321\203\321\202\321\201\321\202\320\262\321\203\320\265\321\202", nullptr));
        switch_type_vertex->setItemText(1, QCoreApplication::translate("Viewer", "\320\232\320\262\320\260\320\264\321\200\320\260\321\202\320\275\320\260\321\217", nullptr));
        switch_type_vertex->setItemText(2, QCoreApplication::translate("Viewer", "\320\232\321\200\321\203\320\263\320\273\320\260\321\217", nullptr));

        label_15->setText(QCoreApplication::translate("Viewer", "Y", nullptr));
        label_8->setText(QCoreApplication::translate("Viewer", "\320\242\320\270\320\277 \320\277\321\200\320\276\320\265\320\272\321\206\320\270\320\270:", nullptr));
        label_11->setText(QCoreApplication::translate("Viewer", "\320\237\320\225\320\240\320\225\320\234\320\225\320\251\320\225\320\235\320\230\320\225", nullptr));
        label_7->setText(QCoreApplication::translate("Viewer", "X", nullptr));
        label_13->setText(QCoreApplication::translate("Viewer", "\320\242\320\270\320\277 \320\262\320\265\321\200\321\210\320\270\320\275\321\213", nullptr));
        label_5->setText(QCoreApplication::translate("Viewer", "Z", nullptr));
        label_facets_am->setText(QCoreApplication::translate("Viewer", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \321\200\320\265\320\261\320\265\321\200: ", nullptr));
        label_16->setText(QCoreApplication::translate("Viewer", "Z", nullptr));
        label_4->setText(QCoreApplication::translate("Viewer", " Y", nullptr));
        label_file_name->setText(QCoreApplication::translate("Viewer", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \321\204\320\260\320\271\320\273\320\260: ", nullptr));
        label_12->setText(QCoreApplication::translate("Viewer", "\320\246\320\262\320\265\321\202", nullptr));
        label_vertex_am->setText(QCoreApplication::translate("Viewer", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \320\262\320\265\321\200\321\210\320\270\320\275: ", nullptr));
        label_2->setText(QCoreApplication::translate("Viewer", "\320\242\320\270\320\277 \320\273\320\270\320\275\320\270\320\270", nullptr));
        switch_projection->setItemText(0, QCoreApplication::translate("Viewer", "\320\237\320\260\321\200\320\260\320\273\320\273\320\265\320\273\321\214\320\275\320\260\321\217", nullptr));
        switch_projection->setItemText(1, QCoreApplication::translate("Viewer", "\320\246\320\265\320\275\321\202\321\200\320\260\320\273\321\214\320\275\320\260\321\217 \320\277\321\200\320\276\320\265\320\272\321\206\320\270\321\217", nullptr));

        label_10->setText(QCoreApplication::translate("Viewer", "\320\240\320\260\320\267\320\274\320\265\321\200", nullptr));
        label_14->setText(QCoreApplication::translate("Viewer", "X", nullptr));
        switch_line_type->setItemText(0, QCoreApplication::translate("Viewer", "C\320\277\320\273\320\276\321\210\320\275\320\260\321\217", nullptr));
        switch_line_type->setItemText(1, QCoreApplication::translate("Viewer", "\320\237\321\203\320\275\320\272\321\202\320\270\321\200\320\275\320\260\321\217", nullptr));

        label_18->setText(QCoreApplication::translate("Viewer", "\320\240\320\260\320\267\320\274\320\265\321\200", nullptr));
        screen_button->setText(QCoreApplication::translate("Viewer", "\320\241\320\275\320\270\320\274\320\276\320\272 \321\215\320\272\321\200\320\260\320\275\320\260", nullptr));
        label->setText(QCoreApplication::translate("Viewer", "\320\234\320\260\321\201\321\210\321\202\320\260\320\261", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Viewer: public Ui_Viewer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEWER_H
