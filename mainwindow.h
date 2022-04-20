#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    int x;
    int y;
    int corEscolhida;
    int r;
    int g;
    int b;
    int largura;
    int altura;
    int acertos=0;

public:
    MainWindow(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent *event);
    void escolherCor();
    void escolherPosicao();
    ~MainWindow();
public slots:
    void finalizador();


private:
    Ui::MainWindow *ui;
    void keyPressEvent( QKeyEvent *k );
};
#endif // MAINWINDOW_H
