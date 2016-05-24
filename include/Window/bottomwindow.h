/**
  *     bottomWindow:
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
  *     centralWidget is central widget of bottomWindow,
  *     and it is also the central widget of other window
  *
  **************************************************/

#ifndef BOTTOMWINDOW_H
#define BOTTOMWINDOW_H

#include <QMainWindow>
#include "types.h"
//#include "windowinterface.h"

//contrl panel
#define LENGTH  800
#define WIDTH   600

class QMainWindow;
class QGridLayout;
class QLabel;
class QVBoxLayout;
class QWidget;
class QPushButton;
class QString;

/// window length and width is compatible with the Display Screen
class BottomWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit BottomWindow(QWidget *parent = 0);
    virtual ~BottomWindow();

    QPushButton *debugButton;

    virtual WindowFlag getCurrentWindowFlag(void) = 0;
private:
    // belong with window directly
    QGridLayout *centralLayout;
    QWidget *centralWidget;

    static const u32_t WindowLengtH=LENGTH;
    static const u32_t WindowWidtH=WIDTH;

    /// This argument: currentWindowFlag, not be used in BottomWindow
    /// class, but in every class inherit BottomWindow, currentWindowFlag
    /// must be set and initialize. Also, virtual function: getCurrentWindowFlag()
    /// should be realized in son classes, it can get the currentWindowFlag.
    //WindowFlag const currentWindowFlag;

    /**
      * \brief  draw window
      */
    void setupUi(BottomWindow *const);

    /**
      * \brief  translate window
      */
    void retranslateUi(BottomWindow *const);

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

#endif // BOTTOMWINDOW_H
