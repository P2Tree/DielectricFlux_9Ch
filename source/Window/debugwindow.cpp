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
#include <QApplication>

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
    QMessageBox::warning(debugWindow, "Debug Window", "debug content",
                                QMessageBox::Ok, QMessageBox::Ok);
}

void DebugWindow::debugMessageBox(DebugWindow *const debugWindow, QString const debugcontent) {
    QMessageBox::warning(debugWindow, "Debug Window", debugcontent,
                                QMessageBox::Ok, QMessageBox::Ok);
}

void DebugWindow::setupMainLayout () {
    debugMainDeclare = new QLabel(tr("This is Debug Window"));
    mainLayout->addWidget(debugMainDeclare);
}

void DebugWindow::setupButtonLayout () {
    debugButton = new QPushButton(tr("debug"));
    buttonLayout->addWidget(debugButton);
}

void retranslateUi(DebugWindow* const debugWindow) {
    debugWindow->setWindowTitle(QApplication::translate("DebugWindow",
                               "DebugWindow", 0, QApplication::UnicodeUTF8));
}
/* slot functions in debugWindow class */

/// This is the only key in debug module, you can change this function
/// to show any paraments or contents in its clicked slots function.
void DebugWindow::debugButtonClicked() {
    WindowInterface windowInterface;
    WindowFlag currentWindowFlag = windowInterface.getCurrentWindow();
    if (currentWindowFlag == DebugFlag)
        debugMessageBox(this, "currentWindowFlag == DebugFlag");
}
