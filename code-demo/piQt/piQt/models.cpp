#include "models.h"
#include <QDateTime>
#include <QStringList>

Models::Models()
{

}

Models::~Models()
{

}

StandardModels::StandardModels(): Models(), model(new QStandardItemModel)
{
    model->setColumnCount(4);
    model->setHorizontalHeaderLabels(QStringList{
                                                   "Time",
                                                   "Name",
                                                   "Steps",
                                                   "Result"
                                     });
}

StandardModels::~StandardModels()
{

}

QAbstractItemModel *StandardModels::getModel()
{
    return model;
}

void StandardModels::addResult(QString name, int steps, double result)
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
}



CustomModels::CustomModels(): Models(), model(new PiCalculatorResultModel)
{

}

CustomModels::~CustomModels()
{

}

QAbstractItemModel *CustomModels::getModel()
{
    return model;
}

void CustomModels::addResult(QString name, int steps, double result)
{
    PiCalculatorResult res;
    res.timestamp = QDateTime::currentDateTime();
    res.name = name;
    res.steps = steps;
    res.result = result;
    model->addResult(res);
}
