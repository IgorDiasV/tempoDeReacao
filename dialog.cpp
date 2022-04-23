#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::carregarValores(int score, float media_reacao, float tempoTotal)
{
    ui->labelScore->setText(QString::number(score));
    ui->labelMedia->setText(QString::number(media_reacao));
    ui->labelTempoTotal->setText(QString::number(tempoTotal/1000));
}
