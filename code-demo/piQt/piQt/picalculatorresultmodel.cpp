#include "picalculatorresultmodel.h"

PiCalculatorResultModel::PiCalculatorResultModel(QObject *parent)
    : QAbstractTableModel(parent)
{
}

QVariant PiCalculatorResultModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole)
    {
        if (orientation == Qt::Horizontal) {
            QStringList headers{
                               "Time",
                               "Name",
                               "Steps",
                               "Result"
                                };
            return headers[section];
        }
    }
    return QVariant();
}

int PiCalculatorResultModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return static_cast<int>(results.size());
}

int PiCalculatorResultModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return 4;
}

QVariant PiCalculatorResultModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (role == Qt::DisplayRole) {

        int row = index.row();
        int column = index.column();
        const PiCalculatorResult& result = results[row];
        switch(column) {
            case 0:
                return result.timestamp.toString("yyyy-MM-dd hh:mm:ss");
            case 1:
                return result.name;
            case 2:
                return QString::number(result.steps);
            case 3:
                return QString::number(result.result);
        }
    }
    return QVariant();
}

void PiCalculatorResultModel::addResult(const PiCalculatorResult& result)
{
    this->insertRow(results.size());
    results.push_back(result);
}

bool PiCalculatorResultModel::insertRows(int row, int count, const QModelIndex &parent)
{
    beginInsertRows(parent, row, row + count - 1);
    // FIXME: Implement me!
    endInsertRows();
    return true;
}

void PiCalculatorResultModel::sort(int column, Qt::SortOrder order)
{
    switch(column) {
        case 0:
            if (order==Qt::AscendingOrder) {
                std::sort(results.begin(),results.end(), [](const PiCalculatorResult& a, const PiCalculatorResult& b) {
                return a.timestamp<b.timestamp;
                });
            } else {
                std::sort(results.begin(),results.end(), [](const PiCalculatorResult& a, const PiCalculatorResult& b) {
                return a.timestamp>b.timestamp;
                });
            }
            break;
        case 1:
        if (order==Qt::AscendingOrder) {
            std::sort(results.begin(),results.end(), [](const PiCalculatorResult& a, const PiCalculatorResult& b) {
            return a.name<b.name;
            });
        } else {
            std::sort(results.begin(),results.end(), [](const PiCalculatorResult& a, const PiCalculatorResult& b) {
            return a.name>b.name;
            });
        }
        break;

    }
    emit dataChanged(index(0,0),index(results.size(),4));
}

//bool PiCalculatorResultModel::insertColumns(int column, int count, const QModelIndex &parent)
//{
//    beginInsertColumns(parent, column, column + count - 1);
//    // FIXME: Implement me!
//    endInsertColumns();
//}
