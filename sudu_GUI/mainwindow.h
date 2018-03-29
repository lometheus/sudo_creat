#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QPainter>
#include <QMainWindow>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    QPainter *paint;
    const int SIZE=9;
    const int WIDTH=40;
    const int x=20,y=20;
    ~MainWindow();


private:
    Ui::MainWindow *ui;

    void paintEvent( QPaintEvent* ) ;
};

#endif // MAINWINDOW_H
