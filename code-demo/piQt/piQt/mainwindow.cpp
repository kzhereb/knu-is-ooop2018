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
    double result = calc.calculate(steps);
    qDebug()<<"Atan"<< result;
    ui->lblResult->setText(QString("Atan: %1").arg(result));
}

void MainWindow::on_rbIntegrate_clicked()
{
    int steps = ui->leSteps->text().toInt();
    IntegrateCalculator calc;
    double result = calc.calculate(steps);
    qDebug()<<"Integrate"<< result;
    ui->lblResult->setText(QString("Integ: %1").arg(result));
}
