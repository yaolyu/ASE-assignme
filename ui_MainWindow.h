/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *m_centralwidget;
    QGridLayout *s_mainGridLayout;
    QGroupBox *s_translateGroupBox;
    QGridLayout *gridLayout_3;
    QDoubleSpinBox *m_tx;
    QDoubleSpinBox *m_ty;
    QLabel *s_txLabel;
    QDoubleSpinBox *m_tz;
    QLabel *s_tyLabel;
    QLabel *s_tzLabel;
    QWidget *widget;
    QFormLayout *formLayout_2;
    QFormLayout *s_FormLayoutMatrixOrder;
    QComboBox *m_matrixOrder;
    QLabel *s_matrixOrderLabel;
    QGroupBox *s_scaleGroupBox;
    QGridLayout *gridLayout_4;
    QDoubleSpinBox *m_sz;
    QLabel *s_txLabel_2;
    QLabel *s_tzLabel_2;
    QDoubleSpinBox *m_sy;
    QDoubleSpinBox *m_sx;
    QLabel *s_tyLabel_2;
    QFrame *frame_2;
    QSlider *m_normalSize;
    QCheckBox *m_normals;
    QRadioButton *radioButton;
    QTabWidget *s_rotateTabWidget;
    QWidget *s_rotateTabWidgetPage1;
    QGridLayout *gridLayout_2;
    QDoubleSpinBox *m_rx;
    QDoubleSpinBox *m_ry;
    QDoubleSpinBox *m_rz;
    QLabel *s_rotZLabel;
    QLabel *s_rotXLabel;
    QLabel *s_rotYLabel;
    QWidget *tab;
    QGridLayout *gridLayout_5;
    QDoubleSpinBox *m_eulerAngle;
    QDoubleSpinBox *m_eulerXAxis;
    QDoubleSpinBox *m_eulerYAxis;
    QDoubleSpinBox *m_eulerZAxis;
    QLabel *s_eulerAxisLabel;
    QLabel *s_eulerAngleLabel;
    QFrame *frame;
    QPushButton *m_colour;
    QGroupBox *groupBox;
    QLabel *label;
    QLabel *label_3;
    QDoubleSpinBox *m_p1;
    QDoubleSpinBox *m_p2;
    QDoubleSpinBox *m_p3;
    QCheckBox *m_show_bone;
    QLabel *label_2;
    QTextEdit *textEdit;
    QCheckBox *m_resetani;
    QCheckBox *m_elimination;
    QCheckBox *m_wireframe;
    QCheckBox *m_wireframe1;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1321, 798);
        MainWindow->setBaseSize(QSize(0, 0));
        m_centralwidget = new QWidget(MainWindow);
        m_centralwidget->setObjectName(QStringLiteral("m_centralwidget"));
        s_mainGridLayout = new QGridLayout(m_centralwidget);
        s_mainGridLayout->setObjectName(QStringLiteral("s_mainGridLayout"));
        s_translateGroupBox = new QGroupBox(m_centralwidget);
        s_translateGroupBox->setObjectName(QStringLiteral("s_translateGroupBox"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(s_translateGroupBox->sizePolicy().hasHeightForWidth());
        s_translateGroupBox->setSizePolicy(sizePolicy);
        gridLayout_3 = new QGridLayout(s_translateGroupBox);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        m_tx = new QDoubleSpinBox(s_translateGroupBox);
        m_tx->setObjectName(QStringLiteral("m_tx"));
        m_tx->setMinimum(-20);
        m_tx->setMaximum(20);
        m_tx->setSingleStep(0.1);

        gridLayout_3->addWidget(m_tx, 1, 0, 1, 1);

        m_ty = new QDoubleSpinBox(s_translateGroupBox);
        m_ty->setObjectName(QStringLiteral("m_ty"));
        m_ty->setMinimum(-20);
        m_ty->setMaximum(20);
        m_ty->setSingleStep(0.1);

        gridLayout_3->addWidget(m_ty, 1, 1, 1, 1);

        s_txLabel = new QLabel(s_translateGroupBox);
        s_txLabel->setObjectName(QStringLiteral("s_txLabel"));
        s_txLabel->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(s_txLabel, 0, 0, 1, 1);

        m_tz = new QDoubleSpinBox(s_translateGroupBox);
        m_tz->setObjectName(QStringLiteral("m_tz"));
        m_tz->setMinimum(-20);
        m_tz->setMaximum(20);
        m_tz->setSingleStep(0.1);

        gridLayout_3->addWidget(m_tz, 1, 2, 1, 1);

        s_tyLabel = new QLabel(s_translateGroupBox);
        s_tyLabel->setObjectName(QStringLiteral("s_tyLabel"));
        s_tyLabel->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(s_tyLabel, 0, 1, 1, 1);

        s_tzLabel = new QLabel(s_translateGroupBox);
        s_tzLabel->setObjectName(QStringLiteral("s_tzLabel"));
        s_tzLabel->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(s_tzLabel, 0, 2, 1, 1);


        s_mainGridLayout->addWidget(s_translateGroupBox, 2, 6, 1, 2);

        widget = new QWidget(m_centralwidget);
        widget->setObjectName(QStringLiteral("widget"));
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        formLayout_2 = new QFormLayout(widget);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        s_FormLayoutMatrixOrder = new QFormLayout();
        s_FormLayoutMatrixOrder->setObjectName(QStringLiteral("s_FormLayoutMatrixOrder"));
        m_matrixOrder = new QComboBox(widget);
        m_matrixOrder->setObjectName(QStringLiteral("m_matrixOrder"));

        s_FormLayoutMatrixOrder->setWidget(0, QFormLayout::FieldRole, m_matrixOrder);

        s_matrixOrderLabel = new QLabel(widget);
        s_matrixOrderLabel->setObjectName(QStringLiteral("s_matrixOrderLabel"));

        s_FormLayoutMatrixOrder->setWidget(0, QFormLayout::LabelRole, s_matrixOrderLabel);


        formLayout_2->setLayout(0, QFormLayout::LabelRole, s_FormLayoutMatrixOrder);


        s_mainGridLayout->addWidget(widget, 0, 6, 1, 2);

        s_scaleGroupBox = new QGroupBox(m_centralwidget);
        s_scaleGroupBox->setObjectName(QStringLiteral("s_scaleGroupBox"));
        sizePolicy.setHeightForWidth(s_scaleGroupBox->sizePolicy().hasHeightForWidth());
        s_scaleGroupBox->setSizePolicy(sizePolicy);
        gridLayout_4 = new QGridLayout(s_scaleGroupBox);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        m_sz = new QDoubleSpinBox(s_scaleGroupBox);
        m_sz->setObjectName(QStringLiteral("m_sz"));
        m_sz->setMinimum(-20);
        m_sz->setMaximum(20);
        m_sz->setSingleStep(0.1);
        m_sz->setValue(1);

        gridLayout_4->addWidget(m_sz, 1, 2, 1, 1);

        s_txLabel_2 = new QLabel(s_scaleGroupBox);
        s_txLabel_2->setObjectName(QStringLiteral("s_txLabel_2"));
        s_txLabel_2->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(s_txLabel_2, 0, 0, 1, 1);

        s_tzLabel_2 = new QLabel(s_scaleGroupBox);
        s_tzLabel_2->setObjectName(QStringLiteral("s_tzLabel_2"));
        s_tzLabel_2->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(s_tzLabel_2, 0, 2, 1, 1);

        m_sy = new QDoubleSpinBox(s_scaleGroupBox);
        m_sy->setObjectName(QStringLiteral("m_sy"));
        m_sy->setMinimum(-20);
        m_sy->setMaximum(20);
        m_sy->setSingleStep(0.1);
        m_sy->setValue(1);

        gridLayout_4->addWidget(m_sy, 1, 1, 1, 1);

        m_sx = new QDoubleSpinBox(s_scaleGroupBox);
        m_sx->setObjectName(QStringLiteral("m_sx"));
        m_sx->setMinimum(-20);
        m_sx->setMaximum(20);
        m_sx->setSingleStep(0.1);
        m_sx->setValue(1);

        gridLayout_4->addWidget(m_sx, 1, 0, 1, 1);

        s_tyLabel_2 = new QLabel(s_scaleGroupBox);
        s_tyLabel_2->setObjectName(QStringLiteral("s_tyLabel_2"));
        s_tyLabel_2->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(s_tyLabel_2, 0, 1, 1, 1);


        s_mainGridLayout->addWidget(s_scaleGroupBox, 3, 6, 1, 1);

        frame_2 = new QFrame(m_centralwidget);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);

        s_mainGridLayout->addWidget(frame_2, 2, 8, 1, 1);

        m_normalSize = new QSlider(m_centralwidget);
        m_normalSize->setObjectName(QStringLiteral("m_normalSize"));
        m_normalSize->setMinimumSize(QSize(445, 27));
        m_normalSize->setLayoutDirection(Qt::RightToLeft);
        m_normalSize->setMinimum(1);
        m_normalSize->setMaximum(20);
        m_normalSize->setPageStep(1);
        m_normalSize->setValue(6);
        m_normalSize->setSliderPosition(6);
        m_normalSize->setOrientation(Qt::Horizontal);
        m_normalSize->setInvertedAppearance(true);
        m_normalSize->setTickPosition(QSlider::TicksBothSides);

        s_mainGridLayout->addWidget(m_normalSize, 5, 4, 1, 1);

        m_normals = new QCheckBox(m_centralwidget);
        m_normals->setObjectName(QStringLiteral("m_normals"));

        s_mainGridLayout->addWidget(m_normals, 5, 3, 1, 1);

        radioButton = new QRadioButton(m_centralwidget);
        radioButton->setObjectName(QStringLiteral("radioButton"));

        s_mainGridLayout->addWidget(radioButton, 2, 4, 1, 1);

        s_rotateTabWidget = new QTabWidget(m_centralwidget);
        s_rotateTabWidget->setObjectName(QStringLiteral("s_rotateTabWidget"));
        sizePolicy.setHeightForWidth(s_rotateTabWidget->sizePolicy().hasHeightForWidth());
        s_rotateTabWidget->setSizePolicy(sizePolicy);
        s_rotateTabWidgetPage1 = new QWidget();
        s_rotateTabWidgetPage1->setObjectName(QStringLiteral("s_rotateTabWidgetPage1"));
        gridLayout_2 = new QGridLayout(s_rotateTabWidgetPage1);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        m_rx = new QDoubleSpinBox(s_rotateTabWidgetPage1);
        m_rx->setObjectName(QStringLiteral("m_rx"));
        m_rx->setMinimum(-180);
        m_rx->setMaximum(180);

        gridLayout_2->addWidget(m_rx, 1, 0, 1, 1);

        m_ry = new QDoubleSpinBox(s_rotateTabWidgetPage1);
        m_ry->setObjectName(QStringLiteral("m_ry"));
        m_ry->setMinimum(-180);
        m_ry->setMaximum(180);

        gridLayout_2->addWidget(m_ry, 1, 1, 1, 1);

        m_rz = new QDoubleSpinBox(s_rotateTabWidgetPage1);
        m_rz->setObjectName(QStringLiteral("m_rz"));
        m_rz->setMinimum(-180);
        m_rz->setMaximum(180);

        gridLayout_2->addWidget(m_rz, 1, 2, 1, 1);

        s_rotZLabel = new QLabel(s_rotateTabWidgetPage1);
        s_rotZLabel->setObjectName(QStringLiteral("s_rotZLabel"));
        s_rotZLabel->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(s_rotZLabel, 0, 2, 1, 1);

        s_rotXLabel = new QLabel(s_rotateTabWidgetPage1);
        s_rotXLabel->setObjectName(QStringLiteral("s_rotXLabel"));
        s_rotXLabel->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(s_rotXLabel, 0, 0, 1, 1);

        s_rotYLabel = new QLabel(s_rotateTabWidgetPage1);
        s_rotYLabel->setObjectName(QStringLiteral("s_rotYLabel"));
        s_rotYLabel->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(s_rotYLabel, 0, 1, 1, 1);

        s_rotateTabWidget->addTab(s_rotateTabWidgetPage1, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        gridLayout_5 = new QGridLayout(tab);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        m_eulerAngle = new QDoubleSpinBox(tab);
        m_eulerAngle->setObjectName(QStringLiteral("m_eulerAngle"));
        m_eulerAngle->setMaximum(360);

        gridLayout_5->addWidget(m_eulerAngle, 1, 0, 1, 1);

        m_eulerXAxis = new QDoubleSpinBox(tab);
        m_eulerXAxis->setObjectName(QStringLiteral("m_eulerXAxis"));
        m_eulerXAxis->setMinimum(-1);
        m_eulerXAxis->setMaximum(1);
        m_eulerXAxis->setSingleStep(0.01);
        m_eulerXAxis->setValue(1);

        gridLayout_5->addWidget(m_eulerXAxis, 1, 1, 1, 1);

        m_eulerYAxis = new QDoubleSpinBox(tab);
        m_eulerYAxis->setObjectName(QStringLiteral("m_eulerYAxis"));
        m_eulerYAxis->setMinimum(-1);
        m_eulerYAxis->setMaximum(1);
        m_eulerYAxis->setSingleStep(0.01);

        gridLayout_5->addWidget(m_eulerYAxis, 1, 2, 1, 1);

        m_eulerZAxis = new QDoubleSpinBox(tab);
        m_eulerZAxis->setObjectName(QStringLiteral("m_eulerZAxis"));
        m_eulerZAxis->setMinimum(-1);
        m_eulerZAxis->setMaximum(1);
        m_eulerZAxis->setSingleStep(0.01);

        gridLayout_5->addWidget(m_eulerZAxis, 1, 3, 1, 1);

        s_eulerAxisLabel = new QLabel(tab);
        s_eulerAxisLabel->setObjectName(QStringLiteral("s_eulerAxisLabel"));

        gridLayout_5->addWidget(s_eulerAxisLabel, 0, 1, 1, 2);

        s_eulerAngleLabel = new QLabel(tab);
        s_eulerAngleLabel->setObjectName(QStringLiteral("s_eulerAngleLabel"));

        gridLayout_5->addWidget(s_eulerAngleLabel, 0, 0, 1, 1);

        s_rotateTabWidget->addTab(tab, QString());

        s_mainGridLayout->addWidget(s_rotateTabWidget, 1, 6, 1, 2);

        frame = new QFrame(m_centralwidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Plain);
        m_colour = new QPushButton(frame);
        m_colour->setObjectName(QStringLiteral("m_colour"));
        m_colour->setGeometry(QRect(-10, 0, 281, 32));

        s_mainGridLayout->addWidget(frame, 5, 6, 1, 2);

        groupBox = new QGroupBox(m_centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setMaximumSize(QSize(16777215, 339));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(110, 60, 121, 16));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 60, 91, 16));
        m_p1 = new QDoubleSpinBox(groupBox);
        m_p1->setObjectName(QStringLiteral("m_p1"));
        m_p1->setGeometry(QRect(20, 90, 68, 24));
        m_p1->setMaximum(20);
        m_p1->setSingleStep(0.1);
        m_p2 = new QDoubleSpinBox(groupBox);
        m_p2->setObjectName(QStringLiteral("m_p2"));
        m_p2->setGeometry(QRect(130, 90, 68, 24));
        m_p2->setMaximum(20);
        m_p2->setSingleStep(0.1);
        m_p3 = new QDoubleSpinBox(groupBox);
        m_p3->setObjectName(QStringLiteral("m_p3"));
        m_p3->setGeometry(QRect(250, 90, 68, 24));
        m_p3->setMaximum(20);
        m_p3->setSingleStep(0.1);
        m_show_bone = new QCheckBox(groupBox);
        m_show_bone->setObjectName(QStringLiteral("m_show_bone"));
        m_show_bone->setGeometry(QRect(20, 140, 115, 20));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(230, 60, 89, 21));
        textEdit = new QTextEdit(groupBox);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(100, 20, 111, 31));
        m_resetani = new QCheckBox(groupBox);
        m_resetani->setObjectName(QStringLiteral("m_resetani"));
        m_resetani->setGeometry(QRect(20, 170, 283, 20));
        m_elimination = new QCheckBox(groupBox);
        m_elimination->setObjectName(QStringLiteral("m_elimination"));
        m_elimination->setGeometry(QRect(20, 200, 131, 20));
        m_wireframe = new QCheckBox(groupBox);
        m_wireframe->setObjectName(QStringLiteral("m_wireframe"));
        m_wireframe->setGeometry(QRect(170, 140, 87, 20));
        label->raise();
        label_3->raise();
        m_p1->raise();
        m_p2->raise();
        m_p3->raise();
        m_show_bone->raise();
        label_2->raise();
        textEdit->raise();
        m_resetani->raise();
        m_elimination->raise();
        m_colour->raise();
        m_wireframe->raise();

        s_mainGridLayout->addWidget(groupBox, 4, 6, 1, 2);

        m_wireframe1 = new QCheckBox(m_centralwidget);
        m_wireframe1->setObjectName(QStringLiteral("m_wireframe1"));

        s_mainGridLayout->addWidget(m_wireframe1, 5, 2, 1, 1);

        MainWindow->setCentralWidget(m_centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1321, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);
        QWidget::setTabOrder(m_wireframe1, m_normals);

        retranslateUi(MainWindow);

        m_matrixOrder->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Affine Transform Demo using ngl::Matrix", 0));
        s_translateGroupBox->setTitle(QApplication::translate("MainWindow", "Translate", 0));
        s_txLabel->setText(QApplication::translate("MainWindow", "x", 0));
        s_tyLabel->setText(QApplication::translate("MainWindow", "y", 0));
        s_tzLabel->setText(QApplication::translate("MainWindow", "z", 0));
        m_matrixOrder->clear();
        m_matrixOrder->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Rotate Translate Scale", 0)
         << QApplication::translate("MainWindow", "Translate Rotate Scale", 0)
         << QApplication::translate("MainWindow", "Gimbal Lock", 0)
         << QApplication::translate("MainWindow", "Euler Translate Scale", 0)
         << QApplication::translate("MainWindow", "Translate Euler Scale", 0)
        );
        s_matrixOrderLabel->setText(QApplication::translate("MainWindow", "Matrix Order", 0));
        s_scaleGroupBox->setTitle(QApplication::translate("MainWindow", "Scale", 0));
        s_txLabel_2->setText(QApplication::translate("MainWindow", "x", 0));
        s_tzLabel_2->setText(QApplication::translate("MainWindow", "z", 0));
        s_tyLabel_2->setText(QApplication::translate("MainWindow", "y", 0));
        m_normals->setText(QApplication::translate("MainWindow", "normals   size", 0));
        radioButton->setText(QApplication::translate("MainWindow", "RadioButton", 0));
        s_rotZLabel->setText(QApplication::translate("MainWindow", "z", 0));
        s_rotXLabel->setText(QApplication::translate("MainWindow", "x", 0));
        s_rotYLabel->setText(QApplication::translate("MainWindow", "y", 0));
        s_rotateTabWidget->setTabText(s_rotateTabWidget->indexOf(s_rotateTabWidgetPage1), QApplication::translate("MainWindow", "Rotation", 0));
        s_eulerAxisLabel->setText(QApplication::translate("MainWindow", "Axis", 0));
        s_eulerAngleLabel->setText(QApplication::translate("MainWindow", "Angle", 0));
        s_rotateTabWidget->setTabText(s_rotateTabWidget->indexOf(tab), QApplication::translate("MainWindow", "Euler", 0));
        m_colour->setText(QApplication::translate("MainWindow", "Set Colour", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "Skeleton Control", 0));
        label->setText(QApplication::translate("MainWindow", "Second Skeleton", 0));
        label_3->setText(QApplication::translate("MainWindow", "First Skeleton", 0));
        m_show_bone->setText(QApplication::translate("MainWindow", "Show Skeleton", 0));
        label_2->setText(QApplication::translate("MainWindow", "Third Skeleton", 0));
        textEdit->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'.SF NS Text'; font-size:13pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Pace Control</p></body></html>", 0));
        m_resetani->setText(QApplication::translate("MainWindow", "Reset Animation", 0));
        m_elimination->setText(QApplication::translate("MainWindow", "Eliminate Bulges", 0));
        m_wireframe->setText(QApplication::translate("MainWindow", "wireframe", 0));
        m_wireframe1->setText(QApplication::translate("MainWindow", "wireframe", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
