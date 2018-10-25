#ifndef PICALCULATORRESULTMODEL_H
#define PICALCULATORRESULTMODEL_H

#include "picalculatorresult.h"

#include <QAbstractTableModel>
#include <vector>


class PiCalculatorResultModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit PiCalculatorResultModel(QObject *parent = nullptr);

    // Header:
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    void addResult(const PiCalculatorResult& result);

    // Add data:
   bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;
//    bool insertColumns(int column, int count, const QModelIndex &parent = QModelIndex()) override;

   void sort(int column, Qt::SortOrder order= Qt::AscendingOrder) override;

private:
    std::vector<PiCalculatorResult> results;
};

#endif // PICALCULATORRESULTMODEL_H
