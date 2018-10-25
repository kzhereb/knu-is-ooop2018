#include "models.h"
#include <QDateTime>
#include <QStringList>

Models::Models(): model(new QStandardItemModel)
{
    model->setColumnCount(4);
    model->setHorizontalHeaderLabels(QStringList{
                                                   "Time",
                                                   "Name",
                                                   "Steps",
                                                   "Result"
                                     });
}

QAbstractItemModel *Models::getModel()
{
    return model;
}

void Models::addResult(QString name, int steps, double result)
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
