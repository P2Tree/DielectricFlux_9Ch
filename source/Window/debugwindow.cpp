/**
 *  \file   debugwindow
 *  \brief  This is debug window, with its class and function
 *  \author Yang Liuming <dicksonliuming@gmail.com>
 *  \version    v1.0
 *  \date   2016-05
 *
 **************************************************************/
#include "debugwindow.h"

#include "buttomwindow.h"
#include "windowinterface.h"
#include <QMessageBox>
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>
#include <QVBoxLayout>

DebugWindow::DebugWindow() : ButtomWindow()
{
#if (DebugModE == OpenDebug)
    debugWindowTitle = "Debug Window";
    mainTitle->setText(debugWindowTitle);
    setupMainLayout();
    setupButtonLayout();
    connect(debugButton, SIGNAL(clicked()), this, SLOT(debugButtonClicked()));
#endif

}

void DebugWindow::debugMessageBox(DebugWindow *const debugWindow) {
    switch(QMessageBox::warning(debugWindow, "Debug Window", "debug content",
                                QMessageBox::Ok, QMessageBox::Ok))
    {
    case QMessageBox::Ok:
           break;
    default:
           break;
    }
}

void DebugWindow::setupMainLayout () {
    debugMainDeclare = new QLabel(tr("This is Debug Window"));
    mainLayout->addWidget(debugMainDeclare);
}

void DebugWindow::setupButtonLayout () {
    debugButton = new QPushButton(tr("debug"));
    buttonLayout->addWidget(debugButton);
}

/// slot functions in debugWindow class
void DebugWindow::debugButtonClicked() {
    WindowInterface windowInterface;
    WindowFlag currentWindowFlag = windowInterface.getCurrentWindow();
    if (currentWindowFlag == DebugFlag)
        debugMessageBox(this);
}
