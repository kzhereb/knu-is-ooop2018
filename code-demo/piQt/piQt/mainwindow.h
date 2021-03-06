#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "picalculator.h"
#include "models.h"

#include <QMainWindow>
#include <QHash>


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

    void on_lswCalculators_currentTextChanged(const QString &currentText);

private:
    Ui::MainWindow *ui;
    shared_ptr<PiCalculator> calc;
    QHash<QString, shared_ptr<PiCalculator>> mapCalc;

    shared_ptr<Models> models;



    void addCalculators();
    void calculate(QString name);
    void addResultToTable(QString name, int steps, double result);
};

#endif // MAINWINDOW_H
