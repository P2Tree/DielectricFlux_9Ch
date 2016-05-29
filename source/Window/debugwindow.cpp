/**
 *  \file   debugwindow
 *  \brief  This is debug window, with its class and function
 *  \author Yang Liuming <dicksonliuming@gmail.com>
 *  \version    v1.0
 *  \date   2016-05
 *
 **************************************************************/
#include "debugwindow.h"

#include "Bottomwindow.h"
#include "windowinterface.h"
#include "types.h"
#include "timerservice.h"
#include "serviceinterface.h"

#include <QMessageBox>
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QApplication>
#include <QStackedWidget>
#include <QDialog>
#include <QFormLayout>
#include <QTimer>
#include <QVariant>

DebugWindow::DebugWindow() : BottomWindow() , currentWindowFlag(DebugFlag)
{
    debugWindowTitle = "Debug Window";
    mainTitle->setText(debugWindowTitle);
    setupMainLayout();
    setupButtonLayout();
}


void DebugWindow::setupMainLayout () {
    debugMainDeclare = new QLabel(tr("This is Debug Window"));
    //mainLayout->addWidget(debugMainDeclare);
}

void DebugWindow::setupButtonLayout () {
    debugButton = new QPushButton(tr("debug"));
    returnButton = new QPushButton(tr("return"));
    buttonLayout->addWidget(debugButton);
    buttonLayout->addWidget(returnButton);
    connect(debugButton, SIGNAL(clicked()), this, SLOT(debugButtonClicked()));
    connect(returnButton, SIGNAL(clicked()), this, SLOT(returnButtonClicked()));
}

WindowFlag_t DebugWindow::getCurrentWindowFlag() {
    return currentWindowFlag;
}

void DebugWindow::retranslateUi(DebugWindow* const debugWindow) {
    debugWindow->setWindowTitle(QApplication::translate("DebugWindow",
                               "DebugWindow", 0, QApplication::UnicodeUTF8));
}

void DebugWindow::debugMessageBox(BottomWindow *const debugWindow, QString const debugcontent) {
    QMessageBox::warning(debugWindow, "Debug Window", debugcontent,
                                QMessageBox::Ok, QMessageBox::Ok);
}

void DebugWindow::setupDebugDialog(BottomWindow *const debugWindow) {
    debugDialog = new QDialog(debugWindow);
    debugDialog->setAttribute(Qt::WA_DeleteOnClose);
    debugDialog->setWindowTitle(tr("Debug Dialog"));
    debugDialog->setFixedSize(300, 200);

    ServiceInterface serviceInterface;
    QLabel *timerCountShow = new QLabel;
    //timerCountShow->setFrameShape(QFrame::Box);
    timerCountShow->setFrameShadow(QFrame::Raised);
    timerCountShow->setLineWidth(1);
    timerCountShow->setAlignment(Qt::AlignCenter);
    QVariant v(serviceInterface.getSystemTimerRegisterCount());
    timerCountShow->setText(v.toString());
    QLabel *timerCountLabel = new QLabel(tr("DebugCount"));
    //timerCountLabel->setFrameShape(QFrame::Box);
    timerCountLabel->setFrameShadow(QFrame::Raised);
    timerCountLabel->setLineWidth(1);
    timerCountLabel->setAlignment(Qt::AlignCenter);

    debugDialogLayout = new QFormLayout(debugDialog);
    debugDialogLayout->addRow(timerCountLabel, timerCountShow);

    debugDialogLayout->setSpacing(10);
    debugDialog->setLayout(debugDialogLayout);
    debugDialog->show();
}
/* slot functions in debugWindow class */

/// This is the only key in debug module, you can change this function
/// to show any paraments or contents in its clicked slots function.
void DebugWindow::debugButtonClicked() {
    WindowInterface windowInterface;
    WindowFlag_t currentWindowFlag = windowInterface.getWindowFlag();
    if (currentWindowFlag == DebugFlag)
        //debugMessageBox(this, "currentWindowFlag == DebugFlag");
        setupDebugDialog(this);
}


void DebugWindow::returnButtonClicked() {
    WindowInterface windowInterface;
    WindowFlag_t currentWindowFlag = windowInterface.getWindowFlag();
    if (currentWindowFlag == DebugFlag) {
        windowInterface.changeWindow(StandbyFlag, this, Close);
    }

}

