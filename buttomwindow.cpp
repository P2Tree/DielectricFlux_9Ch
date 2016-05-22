/**
  * \file   ButtomWindow
  * \brief  window in buttom, include all class and function of it
  * \author PWE(Yang Liuming) <dicksonliuming@gmail.com>
  * \version    v1.0
  * \date   2016-5
  *
  ********************************************************/


#include "buttomwindow.h"

#include "System_main.h"
#include "types.h"
#include <QMainWindow>
#include <QtGui/QGridLayout>
#include <QtGui/QLineEdit>
#include <QtGui/QApplication>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QMessageBox>

ButtomWindow::ButtomWindow(QWidget *parent) :
    QMainWindow(parent)
{

    setupUi(this);
    retranslateUi(this);
    connect(debugButton, SIGNAL(clicked()), this, SLOT(debugButtonClicked()));
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

    if (DebugModE == OpenDebug) {
        debugButton = new QPushButton(tr("Debug Window"));
        buttonLayout->addWidget(debugButton);
    }

    centralLayout->addWidget(mainTitle, 0, 0);
    //mainLayout->addWidget(mainLogo, 0, 1);
    centralLayout->addWidget(mainLogoTitle, 0, 1);
    centralLayout->addLayout(mainLayout, 1, 0);
    centralLayout->addLayout(buttonLayout, 1, 1);

    centralWidget->setLayout(centralLayout);
    buttomWindow->setCentralWidget(centralWidget);


}

void ButtomWindow::retranslateUi(ButtomWindow *buttomWindow) {
    buttomWindow->setWindowTitle(QApplication::translate("ButtomWindow",
                               "ButtomWindow", 0, QApplication::UnicodeUTF8));
}

void ButtomWindow::debugMessageBox(ButtomWindow *const buttomWindow) {
    switch(QMessageBox::warning(buttomWindow, "Debug Window", "debug content",
                                QMessageBox::Ok, QMessageBox::Ok))
    {
    case QMessageBox::Ok:
           break;
    default:
           break;
    }
}

void ButtomWindow::debugLayout(ButtomWindow *const buttomWindow) {

}

/// slot functions in buttomwindow
void ButtomWindow::debugButtonClicked() {
    WindowInterface windowInterface;
    WindowFlag currentWindowFlag = windowInterface.getCurrentWindow();
    if (currentWindowFlag == StandbyFlag)
        debugMessageBox(this);
}
