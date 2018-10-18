#include "mainwindow.h"
#include "ui_mainwindow.h"

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
    calc = std::make_shared<AtanCalculator>();
    calculate("Atan");
}

void MainWindow::on_rbIntegrate_clicked()
{
    calc = std::make_shared<IntegrateCalculator>();
    calculate("Integ");
}

void MainWindow::calculate(QString name)
{
    int steps = ui->leSteps->text().toInt();
    double result = calc->calculate(steps);
    qDebug()<<name<<": " << result;
    ui->lblResult->setText(QString("%1: %2").arg(name).arg(result));
}
