#ifndef BASEWINDOW_H
#define BASEWINDOW_H

#include <QMainWindow>

#include "common.h"

namespace Ui {
class BaseWindow;
}

class BaseWindow : public QMainWindow
{
    Q_OBJECT
    QTTEST_OBJECT

public:
    explicit BaseWindow(QWidget *parent = 0);
    ~BaseWindow();

    void init ();

public slots:
    void onClickOk();


private:
    Ui::BaseWindow *ui;
};

#endif // BASEWINDOW_H
