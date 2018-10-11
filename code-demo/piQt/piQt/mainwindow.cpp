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
    AtanCalculator calc;
    qDebug()<<"Atan"<<calc.calculate(10);
}

void MainWindow::on_rbIntegrate_clicked()
{
    IntegrateCalculator calc;
    qDebug()<<"Integrate"<<calc.calculate(10);
}
