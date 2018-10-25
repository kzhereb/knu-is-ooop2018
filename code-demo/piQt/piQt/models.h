#ifndef MODELS_H
#define MODELS_H

#include "picalculatorresultmodel.h"
#include <QStandardItemModel>


class Models
{
public:
    Models();
    virtual ~Models();
    virtual QAbstractItemModel* getModel()=0;
    virtual void addResult(QString name, int steps, double result)=0;

};

class StandardModels: public Models
{
public:
    StandardModels();
    ~StandardModels() override;
    QAbstractItemModel* getModel() override;
    void addResult(QString name, int steps, double result) override;
private:
    QStandardItemModel * model;
};

class CustomModels: public Models
{
public:
    CustomModels();
    ~CustomModels() override;
    QAbstractItemModel* getModel() override;
    void addResult(QString name, int steps, double result) override;
private:
    PiCalculatorResultModel * model;
};

#endif // MODELS_H
