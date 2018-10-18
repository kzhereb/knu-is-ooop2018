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

void MainWindow::on_rbIntegrate_clicked()
{
    calc = std::make_shared<IntegrateCalculator>();
    calculate("Integ");
}

void MainWindow::addCalculators()
{
    mapCalc["Atan"] = std::make_shared<AtanCalculator>();
    mapCalc["Integrate"] = std::make_shared<IntegrateCalculator>();
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
}

void MainWindow::on_lswCalculators_currentTextChanged(const QString &currentText)
{
    calculate(currentText);
}
