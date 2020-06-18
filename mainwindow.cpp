#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <string>
#include <QApplication>
#include <QtDebug>

int minuty = 1; // normalnie 60
int godz = 23;//normalnie 23
int sek = 12;//normalnie 60
QString qStrMin = QString::number(minuty);
QString qStrGodz = QString::number(godz);
QString qStrSek = QString::number(sek);

QString mojaGodzina = "00:00:00";

//AnsiString godzinowa;
using namespace std;
//QLabel lblZegar = new QLabel();

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    QLabel lblZegar;
    ui->setupUi(this);

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(myfunction()));
    timer->start(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::myfunction()
{
    qDebug() << " up date...";
    cout << sek << endl;
    qStrSek =  QString::number(sek);
    qStrMin =  QString::number(minuty);
    qStrGodz =  QString::number(godz);

    if (sek < 10)
        qStrSek = "0" + QString::number(sek);
    if (minuty < 10)
        qStrMin = "0" + QString::number(minuty);
    if (godz < 10)
        qStrGodz = "0" + QString::number(godz);

    //QString strIntMoja = QString::number(sek);

    if (sek <= 0) {
        minuty = minuty - 1;
        sek = 60;
    }
    if (minuty<=0)
    {
        minuty = 59;
        godz = godz -1;
    }
    mojaGodzina = qStrGodz+":"+qStrMin+":"+qStrSek;
//    //mojaGodzina = QString::number(godz) + ":" + QString::number(minuty) + ":"
//                  + QString::number(sek);


ui->lblZegar->setText(mojaGodzina);


sek--;
}

void MainWindow::on_lblZegar_windowTitleChanged(const QString &title) {}

void MainWindow::on_pushButton_clicked()
{
    ui->lblZegar->setText("Zmiana");
    godz=0;
    minuty = 1;
    sek = 15;
}
