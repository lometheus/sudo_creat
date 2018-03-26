#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QPainter>
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();
    const int SIZE=9;
    const int WIDTH=40;
    const int x=20,y=20;

private:
    Ui::MainWindow *ui;
      QPainter *paint;
void MainWindow::paintEvent( QPaintEvent* ) ;
};

#endif // MAINWINDOW_H
