#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    isFirstNumberActive(true),
    isNewCalculation(false)
{
    ui->setupUi(this);

    QList<QPushButton*> numberButtons = {
        ui->N0, ui->N1, ui->N2, ui->N3, ui->N4,
        ui->N5, ui->N6, ui->N7, ui->N8, ui->N9
    };

    for (QPushButton* button : numberButtons) {
        connect(button, &QPushButton::clicked, this, &MainWindow::on_numberButton_clicked);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_numberButton_clicked()
{
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    if (!button) return;

    if (isNewCalculation) {
        clearAllFields();
        isNewCalculation = false;
    }

    QString currentText = isFirstNumberActive ? ui->num1->text() : ui->num2->text();
    currentText += button->text();

    if (isFirstNumberActive) {
        ui->num1->setText(currentText);
    } else {
        ui->num2->setText(currentText);
    }
}

void MainWindow::on_enter_clicked()
{
    if (isNewCalculation) {
        clearAllFields();
        isNewCalculation = false;
    } else if (!ui->num1->text().isEmpty()) {
        isFirstNumberActive = false;
    }
}

void MainWindow::on_clear_clicked()
{
    if (isNewCalculation) {
        clearAllFields();
        isNewCalculation = false;
    } else {
        if (isFirstNumberActive) {
            ui->num1->clear();
        } else {
            ui->num2->clear();
        }
    }
}

void MainWindow::on_add_clicked()
{
    if (ui->num1->text().isEmpty() || ui->num2->text().isEmpty()) return;

    int num1 = ui->num1->text().toInt();
    int num2 = ui->num2->text().toInt();
    ui->result->setText(QString::number(num1 + num2));

    isFirstNumberActive = true;
    isNewCalculation = true;
}

void MainWindow::on_sub_clicked()
{
    if (ui->num1->text().isEmpty() || ui->num2->text().isEmpty()) return;

    int num1 = ui->num1->text().toInt();
    int num2 = ui->num2->text().toInt();
    ui->result->setText(QString::number(num1 - num2));

    isFirstNumberActive = true;
    isNewCalculation = true;
}

void MainWindow::on_mul_clicked()
{
    if (ui->num1->text().isEmpty() || ui->num2->text().isEmpty()) return;

    int num1 = ui->num1->text().toInt();
    int num2 = ui->num2->text().toInt();
    ui->result->setText(QString::number(num1 * num2));

    isFirstNumberActive = true;
    isNewCalculation = true;
}

void MainWindow::on_div_clicked()
{
    if (ui->num1->text().isEmpty() || ui->num2->text().isEmpty()) return;

    int num1 = ui->num1->text().toInt();
    int num2 = ui->num2->text().toInt();

    if (num2 == 0) {
        ui->result->setText("Error, can't divide by zero");
        return;
    }

    ui->result->setText(QString::number(static_cast<double>(num1) / num2));

    isFirstNumberActive = true;
    isNewCalculation = true;
}

void MainWindow::clearAllFields()
{
    ui->num1->clear();
    ui->num2->clear();
    ui->result->clear();
    isFirstNumberActive = true;
}
