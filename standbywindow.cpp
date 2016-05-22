#include "standbywindow.h"

#include "buttomwindow.h"

#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QLayout>

StandbyWindow::StandbyWindow() : ButtomWindow()
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
    standbyButtonStart = new QPushButton(tr("Start"));
    standbyButtonFile = new QPushButton(tr("File"));
    standbyButtonSetup = new QPushButton(tr("Setup"));
    standbyButtonAbout = new QPushButton(tr("About"));
    buttonLayout->addWidget(standbyButtonStart);
    buttonLayout->addWidget(standbyButtonFile);
    buttonLayout->addWidget(standbyButtonSetup);
    buttonLayout->addWidget(standbyButtonAbout);
}

void retranslateUi(StandbyWindow * const standbyWindow) {

}
