#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QDateTime>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->tblResults->setColumnWidth(0,150);

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

void MainWindow::on_rbIntegrate_clicked()
{
    calc = std::make_shared<IntegrateCalculator>();
    calculate("Integ");
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

void MainWindow::calculate(QString name)
{
    calc = mapCalc[name];
    int steps = ui->leSteps->text().toInt();
    double result = calc->calculate(steps);
    qDebug()<<name<<": " << result;
    ui->lblResult->setText(QString("%1: %2").arg(name).arg(result));

    addResultToTable(name, steps, result);
}

void MainWindow::addResultToTable(QString name, int steps, double result)
{
    QString time = QDateTime::currentDateTime().toString();
    int rowCount = ui->tblResults->rowCount();
    ui->tblResults->setRowCount(rowCount+1);

    QTableWidgetItem* itemDT = new QTableWidgetItem(time);
    ui->tblResults->setItem(rowCount,0,itemDT);

    QTableWidgetItem* itemName = new QTableWidgetItem(name);
    ui->tblResults->setItem(rowCount,1,itemName);

    QTableWidgetItem* itemSteps = new QTableWidgetItem(QString::number(steps));
    ui->tblResults->setItem(rowCount,2,itemSteps);

    QTableWidgetItem* itemResult = new QTableWidgetItem(QString::number(result));
    ui->tblResults->setItem(rowCount,3,itemResult);
}

void MainWindow::on_lswCalculators_currentTextChanged(const QString &currentText)
{
    calculate(currentText);
}
