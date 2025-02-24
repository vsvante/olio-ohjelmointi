#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_LisaaNappi_clicked()
{
    QString str = ui->NumeroNaytto->text();
    int num = str.toInt();
    qDebug() << "Numero=" << num;

    num++;

    qDebug() << "Kasvatettu numero=" << num;
    QString newStr = QString::number(num);
    ui->NumeroNaytto->setText(newStr);
}


void MainWindow::on_ResetNappi_clicked()
{
    ui->NumeroNaytto->setText("0");
    qDebug() << "Numerot nollattu";
}

