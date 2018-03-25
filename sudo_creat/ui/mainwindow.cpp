#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //this->setWindowFlags(Qt::FramelessWindowHint);//去掉标题栏
    this->setWindowOpacity(0.9);
    this->setFixedSize( this->width (),this->height ());
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::paintEvent( QPaintEvent* )
{
    paint=new QPainter;
      paint->begin(this);//主窗口
      QPainter painter(this);
      painter.setBrush(QColor(255, 246, 143));
          painter.drawRect(20, 20, 120, 120);
          painter.drawRect(260, 20, 120, 120);
          painter.drawRect(20, 260, 120, 120);
          painter.drawRect(140, 140, 120, 120);
         painter.drawRect(260, 260, 120, 120);
     painter.setBrush(QColor(255, 106, 106));
             painter.drawRect(20, 20, 40, 40);
      paint->setPen(QPen(Qt::black,2,Qt::SolidLine));//钢笔工具：颜色，线号，实线
      //画SIZE+1条横线
      for(int i=0;i<SIZE+1;i++)
        {
          paint->drawLine(x,y+WIDTH*i,x+WIDTH*(SIZE),y+WIDTH*i);//画线函数：x1,y1,x2,y2:画从(x1,y1)到(x2,y2)的线
        }
      //画SIZE+1条竖线
      for(int i=0;i<SIZE+1;i++)
        {
          paint->drawLine(x+WIDTH*i,y,x+WIDTH*i,y+WIDTH*(SIZE));
        }

      //在棋盘正中做一个黑棋子

      painter.setPen(QColor(238, 173, 14));
      QFont font;
      font.setFamily("Microsoft YaHei");
      font.setPointSize(26);
      painter.setFont(font);
      painter.drawText(25,53, "1  2  3  4  5  6  7  8  9");
      painter.drawText(25,93, "9  1  1  2  3  4  6  7  1");
      /*paint->setBrush(QBrush(Qt::black,Qt::SolidPattern));//毛刷：颜色，实图案
      paint->drawEllipse((SIZE+0.5)*WIDTH/2,(SIZE+0.5)*WIDTH/2,WIDTH/2,WIDTH/2);//画椭圆：中心点X,Y,宽度，高度
      */paint->end();
}


