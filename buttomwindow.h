/**
  *     ButtomWindow:
  *     centralWidget: centralLayout:
  *     |----------------------------------------|
  *     |       mainTitle       | mainLogo(Title)|
  *     |-----------------------|----------------|
  *     |                       |                |
  *     |                       |                |
  *     |                       |                |
  *     |       mainLayout      |  buttonLayout  |
  *     |      (redefined by    | (redefined by  |
  *     |       other window)   |  other window) |
  *     |                       |                |
  *     |                       |                |
  *     |-----------------------|----------------|
  *
  *     centralWidget is central widget of ButtomWindow,
  *     and it is also the central widget of other window
  *
  **************************************************/

#ifndef BUTTOMWINDOW_H
#define BUTTOMWINDOW_H

#include <QMainWindow>
#include <types.h>

//contrl panel
#define LENGTH  800
#define WIDTH   600
#define DEBUG   OpenDebug   //CloseDebug

class QMainWindow;
class QGridLayout;
class QLabel;
class QVBoxLayout;
class QWidget;
class QPushButton;

/// window length and width is compatible with the Display Screen
class ButtomWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit ButtomWindow(QWidget *parent = 0);
    ~ButtomWindow();

private:
    QGridLayout *centralLayout;
    QWidget *centralWidget;
    QPushButton *debugButton;
    static const u32_t WindowLengtH=800;
    static const u32_t WindowWidtH=600;

    void setupUi(ButtomWindow *const);
    void retranslateUi(ButtomWindow *const);

    static const debug_t DebugModE = DEBUG;

protected:
    QGridLayout *mainLayout;
    QLabel *mainTitle;
    QVBoxLayout *buttonLayout;
    //QPicture *mainLogo;
    QLabel *mainLogoTitle;	// will be replaced by interfaceLogo later

    virtual void setupMainLayout(void) = 0;
    virtual void setupButtonLayout(void) = 0;

    void debugMessageBox(ButtomWindow *const);
    void debugLayout(ButtomWindow *const);

signals:

public slots:
    void debugButtonClicked();
};

#endif // BUTTOMWINDOW_H
