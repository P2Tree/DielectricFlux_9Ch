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
#include "../types.h"

//contrl panel
#define LENGTH  800
#define WIDTH   600

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
    // belong with window directly
    QGridLayout *centralLayout;
    QWidget *centralWidget;

    static const u32_t WindowLengtH=LENGTH;
    static const u32_t WindowWidtH=WIDTH;

    /**
      * \brief  draw window
      */
    void setupUi(ButtomWindow *const);

    /**
      * \brief  translate window
      */
    void retranslateUi(ButtomWindow *const);

protected:
    QGridLayout *mainLayout;
    QLabel *mainTitle;
    QVBoxLayout *buttonLayout;
    //QPicture *mainLogo;
    QLabel *mainLogoTitle;	// will be replaced by interfaceLogo later

    /**
      * \brief  every window inherit bottomwindow should rewrite this two function\
      *         to draw mainlayout and buttonlayout.
      */
    virtual void setupMainLayout(void) = 0;
    virtual void setupButtonLayout(void) = 0;

signals:

public slots:

};

#endif // BUTTOMWINDOW_H
