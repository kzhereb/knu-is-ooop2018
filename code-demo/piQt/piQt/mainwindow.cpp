#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QDateTime>
#include <QStringList>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    model(new QStandardItemModel)
{
    ui->setupUi(this);



    model->setColumnCount(4);
    model->setHorizontalHeaderLabels(QStringList{
                                                   "Time",
                                                   "Name",
                                                   "Steps",
                                                   "Result"
                                               });

    ui->tblResults->setModel(model);

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
    QString time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    int rowCount = model->rowCount();
    model->setRowCount(rowCount+1);

    QStandardItem* itemDT = new QStandardItem(time);
    model->setItem(rowCount,0,itemDT);

    QStandardItem* itemName = new QStandardItem(name);
    model->setItem(rowCount,1,itemName);

    QStandardItem* itemSteps = new QStandardItem(QString::number(steps));
    model->setItem(rowCount,2,itemSteps);

    QStandardItem* itemResult = new QStandardItem(QString::number(result));
    model->setItem(rowCount,3,itemResult);

    ui->tblResults->setSortingEnabled(true);

}

void MainWindow::on_lswCalculators_currentTextChanged(const QString &currentText)
{
    calculate(currentText);
}
