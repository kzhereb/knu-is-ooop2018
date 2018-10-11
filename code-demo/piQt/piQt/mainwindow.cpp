#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "picalculator.h"
#include <QDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_rbAtan_clicked()
{
    int steps = ui->leSteps->text().toInt();
    AtanCalculator calc;
    qDebug()<<"Atan"<<calc.calculate(steps);
}

void MainWindow::on_rbIntegrate_clicked()
{
    int steps = ui->leSteps->text().toInt();
    IntegrateCalculator calc;
    qDebug()<<"Integrate"<<calc.calculate(steps);
}
