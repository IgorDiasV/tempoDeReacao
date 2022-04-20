#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <stdlib.h>
#include <iostream>
#include <QKeyEvent>
#include <QBrush>
#include <QPen>
#include <QPainter>
#include <QDebug>
#include <time.h>



int r;
int g;
int b;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{

    ui->setupUi(this);
    largura = width()-200;
    altura = height()-200;

    srand(time(0));
    ui->teste->setText("funcionando ");

    escolherPosicao();
    escolherCor();
//    connect(ui->teste,SIGNAL(clicked(bool)),this,SLOT(finalizador()));




}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::escolherCor(){
     srand(time(0));

    corEscolhida = rand()%4;


    switch (corEscolhida) {

    case 0:
        r=0;
        g=0;
        b=255;
        break;
   case 1:
        r=255;
        g=0;
        b=0;
        break;
   case 2:
        r=0;
        g=255;
        b=0;
        break;
   case 3:
        r=255;
        g=255;
        b=0;
        break;



    }
}

void MainWindow::escolherPosicao()
{
    x = 100+rand()%(largura -50);
    y=rand()%(altura -50);
}
void MainWindow::finalizador()
{
    std::cout<<"seila qualquer coisa"<<std::endl;
    exit(0);
}
void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPen pen;
    QBrush brush;

    int larg =50;
    int alt = 50;
    largura = width()-200;
    altura = height()-200;

    pen.setColor(QColor(0,0,0));
    painter.setPen(pen);
    painter.drawRect(100,0,largura,altura);

    pen.setColor(QColor(r,g,b));
    painter.setPen(pen);

    brush.setStyle(Qt::SolidPattern);
    brush.setColor(QColor(r,g,b));
    painter.setBrush(brush);

    painter.drawEllipse(x,y,larg,alt);




}
void MainWindow::keyPressEvent( QKeyEvent *k )
{
    char tecla = char(k->key());
    std::cout<<tecla<<std::endl;
    int valorTecla;
    if(tecla =='W')
    {
        valorTecla=0;
    }else if(tecla=='S'){
        valorTecla=1;

    }else if(tecla=='A'){
        valorTecla=2;
    }else if(tecla=='D')
    {
        valorTecla=3;
    }
    if(valorTecla==corEscolhida)
    {
        std::cout<<"acertou"<<std::endl;
        acertos+=1;
        ui->teste->setText(QString::number(acertos));
        escolherCor();
        escolherPosicao();
        repaint();
    }else{
        std::cout<<"errou"<<std::endl;
    }
}
