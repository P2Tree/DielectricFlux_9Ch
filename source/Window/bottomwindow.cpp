/**
  * \file   bottomWindow
  * \brief  window in bottom, include all class and function of it
  * \brief  you can change window scale in bottomwindow.h with WIDTH and LENGTH
  * \author PWE(Yang Liuming) <dicksonliuming@gmail.com>
  * \version    v1.0
  * \date   2016-5
  *
  ********************************************************/


#include "bottomwindow.h"

#include "System_main.h"
#include "windowinterface.h"
#include "types.h"
#include <QMainWindow>
#include <QtGui/QGridLayout>
#include <QtGui/QLineEdit>
#include <QtGui/QApplication>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QMessageBox>
#include <QSpacerItem>
#include <QPalette>
#include <QStatusBar>
#include <QFormLayout>

BottomWindow::BottomWindow(QWidget *parent) :
    QMainWindow(parent)
{
    setupUi(this);
    retranslateUi(this);
}

BottomWindow::~BottomWindow() {

}

void BottomWindow::setupUi(BottomWindow *bottomWindow) {
    if (bottomWindow->objectName().isEmpty())
        bottomWindow->setObjectName(QString::fromUtf8("bottomWindow"));
    Qt::WindowFlags flags = 0;  // not WindowFlag_t, it is used to set window types
    flags |= Qt::WindowMinimizeButtonHint;
    bottomWindow->setWindowFlags(flags);
    bottomWindow->setFixedSize(WindowLengtH, WindowWidtH);

    centralWidget = new QWidget(bottomWindow);
    centralWidget->setObjectName(QString::fromUtf8("centralWidget"));


    QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
    centralWidget->setSizePolicy(sizePolicy);

    centralLayout = new QGridLayout();
    centralLayout->setSpacing(0);
    centralLayout->setContentsMargins(0, 0, 0, 0);
    centralLayout->setObjectName(QString::fromUtf8("centralLayout"));

    QFont font;
    font.setFamily(QString::fromUtf8("Consolas"));
    font.setPointSize(11);
    font.setBold(true);
    font.setWeight(75);

    mainTitle = new QLabel();
    mainTitle->setText(tr("DielectricFlux 9 Channel"));
    mainTitle->setObjectName(QString::fromUtf8("mainTitle"));
    mainTitle->setFont(font);
    mainTitle->setFrameShape(QFrame::Box);
    mainTitle->setFrameShadow(QFrame::Raised);
    mainTitle->setLineWidth(1);
    mainTitle->setAlignment(Qt::AlignCenter);
    //mainTitle->setStyleSheet("border:2px solid red;");

    centralLayout->addWidget(mainTitle, 0, 0, 1, 1);

    ///TODO:Yang Liuming <dicksonliuming@gmail.com>
    // mainLogo
    mainLogoTitle = new QLabel();
    mainLogoTitle->setText(tr("CABR"));
    mainLogoTitle->setFont(font);
    mainLogoTitle->setFrameShape(QFrame::Box);
    mainLogoTitle->setFrameShadow(QFrame::Raised);
    mainLogoTitle->setLineWidth(1);
    mainLogoTitle->setAlignment(Qt::AlignCenter);
    //mainLogoTitle->setStyleSheet("border:2px solid red;");

    centralLayout->addWidget(mainLogoTitle, 0, 1, 1, 1);

    mainWidget = new QWidget();
    mainWidget->setObjectName(QString::fromUtf8("mainWidget"));

    mainLine = new QFrame(mainWidget);
    mainLine->setObjectName(QString::fromUtf8("mainLine"));
    mainLine->setGeometry(QRect(590, 0, 20, 540));
    mainLine->setLineWidth(1);
    mainLine->setFrameShape(QFrame::VLine);
    mainLine->setFrameShadow(QFrame::Sunken);

    mainHLine = new QFrame(mainWidget);
    mainHLine->setObjectName(QString::fromUtf8("mainHLine"));
    mainHLine->setGeometry(QRect(0, 540, 20, 500));
    mainHLine->setLineWidth(1);
    mainHLine->setFrameShape(QFrame::HLine);
    mainHLine->setFrameShadow(QFrame::Sunken);

    centralLayout->addWidget(mainWidget, 1, 0, 1, 1);

    rightLayout = new QVBoxLayout();
    rightLayout->setSpacing(6);
    rightLayout->setObjectName(QString::fromUtf8("rightLayout"));

    buttonUpSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);
    rightLayout->addItem(buttonUpSpacer);

    buttonLayout = new QVBoxLayout();
    buttonLayout->setSpacing(6);
    buttonLayout->setObjectName(QString::fromUtf8("buttonLayout"));

    rightLayout->addLayout(buttonLayout);

    buttonDownSpacer = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Minimum);
    rightLayout->addItem(buttonDownSpacer);

    centralLayout->addLayout(rightLayout, 1, 1, 1, 1);

    centralLayout->setRowStretch(0, 1);
    centralLayout->setRowStretch(1, 16);
    centralLayout->setColumnStretch(0, 3);
    centralLayout->setColumnStretch(1, 1);

    centralWidget->setLayout(centralLayout);

    bottomWindow->setCentralWidget(centralWidget);

    statusBar = new QStatusBar(bottomWindow);
    statusBar->setObjectName(QString::fromUtf8("statusBar"));
    bottomWindow->setStatusBar(statusBar);

}

void BottomWindow::retranslateUi(BottomWindow *bottomWindow) {
    bottomWindow->setWindowTitle(QApplication::translate("bottomWindow",
                               "bottomWindow", 0, QApplication::UnicodeUTF8));
    mainTitle->setText(QApplication::translate("bottomWindow", "DielectricFlux 9 Channel", 0, QApplication::UnicodeUTF8));
    mainLogoTitle->setText(QApplication::translate("bottomWindow", "CABR", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
    mainWidget->setStatusTip(QApplication::translate("bottomWindow", "WorkSpace", 0, QApplication::UnicodeUTF8));
#endif

}

u32_t BottomWindow::getMainWidgetWidth() {
    return mainWidget->geometry().width();
}

u32_t BottomWindow::getMainWidgetHeight() {
    return mainWidget->geometry().height();
}

