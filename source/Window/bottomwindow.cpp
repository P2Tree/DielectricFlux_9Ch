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
    bottomWindow->setCentralWidget(centralWidget);


}

void BottomWindow::retranslateUi(BottomWindow *bottomWindow) {
    bottomWindow->setWindowTitle(QApplication::translate("bottomWindow",
                               "bottomWindow", 0, QApplication::UnicodeUTF8));
}


