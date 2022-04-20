#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <sys/time.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    int x;
    int y;
    int corEscolhida;
    int r,g,b;
    int largura, altura;
    int acertos=0, erros=0;
    float tempoReacao=0;
    struct timeval tempo_inicial, tempo_final;

public:
    MainWindow(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    void escolherCor();
    void escolherPosicao();
    ~MainWindow();
public slots:
    void reniciar();
private:
    Ui::MainWindow *ui;
    void keyPressEvent( QKeyEvent *k );
};
#endif // MAINWINDOW_H
