#include "mainwindow.h"
#include "ui_mainwindow.h"



#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
        addCalculators();
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

void MainWindow::calculate(QString name)
{
    int steps = ui->leSteps->text().toInt();
    double result = calc->calculate(steps);
    qDebug()<<name<<":" << result;
    ui->lblResult->setText(QString("%1: %2").arg(name).arg(result));
}

void MainWindow::addCalculators()
{
    mapCalc["Atan"] = std::make_shared<AtanCalculator>();
    mapCalc["Integrate"] = std::make_shared<IntegrateCalculator>();
    mapCalc["Monte Carlo"] = std::make_shared<MonteCarloCalculator>();
    mapCalc["Euler 2,3"] = std::make_shared<TwoAtanCalculator>(1,2,1,1,3,1);
    mapCalc["Machin 5,239"] = std::make_shared<TwoAtanCalculator>(1,5,4,1,239,-1);


    foreach(const QString &key, mapCalc.keys()) {
        ui->lswCalculators->addItem(key);
    }
}

void MainWindow::on_rbIntegrate_clicked()
{
    calc = std::make_shared<IntegrateCalculator>();
    calculate("Integrate");
}
