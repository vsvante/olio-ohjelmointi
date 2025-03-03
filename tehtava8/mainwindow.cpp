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
    if (timer) {
        timer->stop();
        delete timer;
        timer = nullptr;
    }
    delete ui;
}

void MainWindow::on_sec120_clicked()
{
    gameTime = 120;
}

void MainWindow::on_sec300_clicked()
{
    gameTime = 300;
}

void MainWindow::on_start_clicked()
{
    if (gameTime == 0) return;

    p1Time = gameTime;
    p2Time = gameTime;
    currentPlayer = 1;

    ui->progressBar1->setRange(0, gameTime);
    ui->progressBar2->setRange(0, gameTime);
    ui->progressBar1->setValue(gameTime);
    ui->progressBar2->setValue(gameTime);

    if (!timer) {
        timer = new QTimer(this);
        connect(timer, &QTimer::timeout, this, &MainWindow::updateProgressBar);
    }
    timer->setInterval(1000);
    timer->start();
}

void MainWindow::updateProgressBar()
{
    if (currentPlayer == 1) {
        p1Time--;
        ui->progressBar1->setValue(p1Time);
        if (p1Time <= 0) {
            timer->stop();
            ui->progressBar1->setValue(0);
            QMessageBox::information(this, "Game Over", "Player 2 wins!");
        }
    } else {
        p2Time--;
        ui->progressBar2->setValue(p2Time);
        if (p2Time <= 0) {
            timer->stop();
            ui->progressBar2->setValue(0);
            QMessageBox::information(this, "Game Over", "Player 1 wins!");
        }
    }
}

void MainWindow::on_p1end_clicked()
{
    currentPlayer = 2;
}

void MainWindow::on_p2end_clicked()
{
    currentPlayer = 1;
}

void MainWindow::on_stop_clicked()
{
    if (timer) {
        timer->stop();
    }
    p1Time = 0;
    p2Time = 0;
    ui->progressBar1->setValue(0);
    ui->progressBar2->setValue(0);
}

