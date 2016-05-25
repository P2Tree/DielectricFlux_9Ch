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
    bottomWindow->resize(WindowLengtH, WindowWidtH);

    centralWidget = new QWidget(bottomWindow);
    centralWidget->setObjectName(QString::fromUtf8("centralWidget"));

    centralLayout = new QGridLayout;

    mainTitle = new QLabel(tr("DielectricFlux 9 Channel"));
    mainTitle->setStyleSheet("border:2px solid red;");
    //mainTitle-> setPalette(palette);
    ///TODO:Yang Liuming <dicksonliuming@gmail.com>
    // mainLogo
    mainLogoTitle = new QLabel(tr("CABR"));
    mainLogoTitle->setStyleSheet("border:2px solid red;");

    mainLayout = new QGridLayout;
    rightLayout = new QVBoxLayout;

    buttonLayout = new QVBoxLayout;
    buttonSpace = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

    rightLayout->addSpacerItem(buttonSpace);
    rightLayout->addLayout(buttonLayout);


    centralLayout->addWidget(mainTitle, 0, 0);
    //mainLayout->addWidget(mainLogo, 0, 1);
    centralLayout->addWidget(mainLogoTitle, 0, 1);
    centralLayout->addLayout(mainLayout, 1, 0, 13, 0);
    centralLayout->addLayout(rightLayout, 1, 1, 13, 1);

    centralLayout->setSpacing(10);
    centralLayout->setVerticalSpacing(100);
    centralLayout->setColumnStretch(0, 10);
    centralLayout->setColumnStretch(1, 4);
    //centralLayout->setRowStretch(0, 1);
    //centralLayout->setRowStretch(1, 1);

    centralWidget->setLayout(centralLayout);
    bottomWindow->setCentralWidget(centralWidget);


}

void BottomWindow::retranslateUi(BottomWindow *bottomWindow) {
    bottomWindow->setWindowTitle(QApplication::translate("bottomWindow",
                               "bottomWindow", 0, QApplication::UnicodeUTF8));
}


