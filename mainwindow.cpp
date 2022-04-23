#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include <stdlib.h>
#include <iostream>
#include <QKeyEvent>
#include <QBrush>
#include <QPen>
#include <QPainter>
#include <QDebug>
#include <sys/time.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{
    ui->setupUi(this);
    largura = width()-200;
    altura = height()-200;

    srand(time(0));

    escolherPosicao();
    escolherCor();
    gettimeofday(&tempo_inicial, NULL);
    connect(ui->retry_btn,SIGNAL(clicked(bool)),this,SLOT(reniciar()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::reniciar()
{
    acertos = 0;
    erros = 0;
    tentativas =0;
    tempoReacao = 0;
    score = 0;
    gettimeofday(&tempo_inicial, NULL);
    escolherPosicao();
    escolherCor();
    ui->teste->setText(QString::number(tempoReacao));
    repaint();
}

void MainWindow::escolherCor()
{
    srand(time(0));

    corEscolhida = rand()%4;

    switch (corEscolhida) {

    case 0:
        r=61;
        g=142;
        b=255;
        break;
   case 1:
        r=255;
        g=56;
        b=56;
        break;
   case 2:
        r=100;
        g=230;
        b=80;
        break;
   case 3:
        r=237;
        g=202;
        b=45;
        break;
    }
}

void MainWindow::escolherPosicao()
{
    x = 100+rand()%(largura -50);
    y=rand()%(altura -50);
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
    int valorTecla;

    if(acertos<10){
        if(tecla =='W'){
            valorTecla=0;
        }else if(tecla=='S'){
            valorTecla=1;
        }else if(tecla=='A'){
            valorTecla=2;
        }else if(tecla=='D'){
            valorTecla=3;
        }
        if(valorTecla==corEscolhida)
        {
            gettimeofday(&tempo_final, NULL);
            tempoReacao += (int) (1000 * (tempo_final.tv_sec - tempo_inicial.tv_sec) + (tempo_final.tv_usec - tempo_inicial.tv_usec) / 1000);
            ui->teste->setText(QString::number(tempoReacao));
            acertos+=1;
            escolherCor();
            escolherPosicao();
            repaint();
            gettimeofday(&tempo_inicial, NULL);
        }else{
            erros+=1;
        }
        tentativas++;
    }else{
        float media_reacao = tempoReacao/acertos;
        score = acertos-erros;

        Dialog tela;
        tela.carregarValores(score, media_reacao, tempoReacao);
        tela.exec();
    }
}
