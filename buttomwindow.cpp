/**
  * \file   ButtomWindow
  * \brief  window in buttom, include all class and function of it
  * \author PWE(Yang Liuming) <dicksonliuming@gmail.com>
  * \version    v1.0
  * \date   2016-5
  *
  ********************************************************/

#include "buttomwindow.h"


ButtomWindow::ButtomWindow(QWidget *parent) :
    QMainWindow(parent)
{

    setupUi(this);
    retranslateUi(this);

    QMetaObject::connectSlotsByName(this);
    
}

ButtomWindow::~ButtomWindow() {

}

void ButtomWindow::setupUi(ButtomWindow *buttomWindow) {
    if (buttomWindow->objectName().isEmpty())
        buttomWindow->setObjectName(QString::fromUtf8("ButtomWindow"));
    buttomWindow->resize(WindowLengtH, WindowWidtH);

    centralWidget = new QWidget(buttomWindow);
    centralWidget->setObjectName(QString::fromUtf8("centralWidget"));

    centralLayout = new QGridLayout;
    mainLayout = new QGridLayout;
    mainTitle = new QLabel(tr("DielectricFlux 9 Channel"));
    ///TODO:Yang Liuming <dicksonliuming@gmail.com>
    // mainLogo
    mainLogoTitle = new QLabel(tr("CABR"));
    buttonLayout = new QVBoxLayout;


    centralLayout->addWidget(mainTitle, 0, 0);
    //mainLayout->addWidget(mainLogo, 0, 1);
    centralLayout->addWidget(mainLogoTitle, 0, 1);
    centralLayout->addLayout(mainLayout, 1, 0);
    centralLayout->addLayout(buttonLayout, 1, 1);

    centralWidget->setLayout(centralLayout);
    buttomWindow->setCentralWidget(centralWidget);


}

void ButtomWindow::retranslateUi(QMainWindow *buttomWindow) {
    buttomWindow->setWindowTitle(QApplication::translate("ButtomWindow",
                               "ButtomWindow", 0, QApplication::UnicodeUTF8));
}
