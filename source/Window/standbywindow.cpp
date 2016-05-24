#include "standbywindow.h"

#include "Bottomwindow.h"
#include "windowinterface.h"

#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QLayout>
#include <QApplication>
#include <QMessageBox>

StandbyWindow::StandbyWindow() : BottomWindow(), currentWindowFlag(StandbyFlag)
{
    standbyWindowTitle = "Standby Window";
    mainTitle->setText(standbyWindowTitle);
    setupMainLayout();
    setupButtonLayout();


}

void StandbyWindow::setupMainLayout () {
    standbyMainDeclare = new QLabel(tr("This is Standby Window"));
    mainLayout->addWidget(standbyMainDeclare);
}

void StandbyWindow::setupButtonLayout () {
    if (DebugModE == OpenDebug) {
        debugButton = new QPushButton(tr("Debug"));
        buttonLayout->addWidget(debugButton);
        connect(debugButton, SIGNAL(clicked()), this, SLOT(debugButtonClicked()));
    }
    standbyButtonStart = new QPushButton(tr("Start"));
    standbyButtonFile = new QPushButton(tr("File"));
    standbyButtonSetup = new QPushButton(tr("Setup"));
    standbyButtonAbout = new QPushButton(tr("About"));
    buttonLayout->addWidget(standbyButtonStart);
    buttonLayout->addWidget(standbyButtonFile);
    buttonLayout->addWidget(standbyButtonSetup);
    buttonLayout->addWidget(standbyButtonAbout);

}

void StandbyWindow::retranslateUi(StandbyWindow * const standbyWindow) {
    standbyWindow->setWindowTitle(QApplication::translate("StandbyWindow",
                               "StandbyWindow", 0, QApplication::UnicodeUTF8));
}

WindowFlag StandbyWindow::getCurrentWindowFlag() {
    return currentWindowFlag;
}

void StandbyWindow::debugMessageBox(StandbyWindow *const debugWindow) {
    QMessageBox::warning(debugWindow, "Debug Window", "debug content",
                                QMessageBox::Ok, QMessageBox::Ok);
}

void StandbyWindow::debugMessageBox(StandbyWindow *const debugWindow, QString const debugcontent) {
    QMessageBox::warning(debugWindow, "Debug Window", debugcontent,
                                QMessageBox::Ok, QMessageBox::Ok);
}

/* slot functions in standbywindow class */

/// This is the only key in debug module, you can change this function
/// to show any paraments or contents in its clicked slots function.
void StandbyWindow::debugButtonClicked() {
    WindowInterface windowInterface;
    WindowFlag currentWindowFlag = windowInterface.getWindowFlag();
    if (currentWindowFlag == StandbyFlag)
        debugMessageBox(this, "currentWindowFlag == StandbyFlag");
}
