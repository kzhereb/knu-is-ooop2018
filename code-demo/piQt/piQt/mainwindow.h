#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "picalculator.h"

#include <QMainWindow>

#include <memory>

using std::shared_ptr;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_rbAtan_clicked();

    void on_rbIntegrate_clicked();

private:
    Ui::MainWindow *ui;
    shared_ptr<PiCalculator> calc;

    void calculate(QString name);
};

#endif // MAINWINDOW_H
