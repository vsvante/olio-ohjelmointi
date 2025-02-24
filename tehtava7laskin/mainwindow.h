#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_numberButton_clicked();
    void on_enter_clicked();
    void on_clear_clicked();
    void on_add_clicked();
    void on_sub_clicked();
    void on_mul_clicked();
    void on_div_clicked();
    void clearAllFields();

private:
    Ui::MainWindow *ui;
    bool isFirstNumberActive;
    bool isNewCalculation;
};
#endif // MAINWINDOW_H
