
#ifndef BUTTOMWINDOW_H
#define BUTTOMWINDOW_H

#include "System_main.h"
#include "types.h"
#include <QMainWindow>
#include <QtGui/QGridLayout>
#include <QtGui/QLineEdit>
#include <QtGui/QApplication>
#include <QtGui/QLabel>

/// window length and width is compatible with the Display Screen
const u32_t WindowLengtH=800;
const u32_t WindowWidtH=600;

class ButtomWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit ButtomWindow(QWidget *parent = 0);
    ~ButtomWindow();

private:
    void setupUi(ButtomWindow *const);
    void retranslateUi(QMainWindow *const);

protected:
    QGridLayout *centralLayout;
    QGridLayout *mainLayout;
    QLabel *mainTitle;
    //QPicture *interfaceLogo;
    QLabel *mainLogoTitle;	// will be replaced by interfaceLogo later
    QVBoxLayout *buttonLayout;

    QWidget *centralWidget;

signals:

public slots:

};

#endif // BUTTOMWINDOW_H
