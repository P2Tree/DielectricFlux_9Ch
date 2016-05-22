#ifndef STANDBYWINDOW_H
#define STANDBYWINDOW_H

#include <buttomwindow.h>

class QLabel;
class QPushButton;
class QString;

class StandbyWindow : public ButtomWindow
{
public:
    StandbyWindow();

private:
    QString standbyWindowTitle;
    QLabel *standbyMainDeclare;
    QPushButton *standbyButtonStart;
    QPushButton *standbyButtonFile;
    QPushButton *standbyButtonSetup;
    QPushButton *standbyButtonAbout;

    void setupMainLayout(void);
    void setupButtonLayout(void);

    void retranslateUi(StandbyWindow *const);
};

#endif // STANDBYWINDOW_H
