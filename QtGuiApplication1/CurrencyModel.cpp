#include "CurrencyModel.h"

CurrencyModel::CurrencyModel(QObject *parent)
    : QAbstractTableModel(parent)
{
}

CurrencyModel::~CurrencyModel()
{
}

void CurrencyModel::setCurrencyMap(const QMap<QString, double> &map)
{
    beginResetModel();
    currencyMap = map;
    endResetModel();
}

int CurrencyModel::rowCount(const QModelIndex &parent /* = QModelIndex() */) const
{
    return currencyMap.count();
}

int CurrencyModel::columnCount(const QModelIndex &parent /* = QModelIndex() */) const
{
    return currencyMap.count();
}

QVariant CurrencyModel::data(const QModelIndex &index, int role /* = Qt::DisplayRole */) const
{
    if (!index.isValid())
    {
        return QVariant();
    }
    if (role == Qt::TextAlignmentRole)
    {
        return int(Qt::AlignRight | Qt::AlignVCenter);
    }
    else if (role == Qt::DisplayRole || role == Qt::EditRole)
    {
        QString rowCurrency = currenyAt(index.row());
        qDebug() << index.row() << " rowCurrency:" << rowCurrency;
        QString columnCurrency = currenyAt(index.column());
        qDebug() << index.column() << " columnCurrency" << columnCurrency;
        if (currencyMap.value(rowCurrency) == 0.0)
        {
            return "####";
        }
        double amount = currencyMap.value(columnCurrency) / currencyMap.value(rowCurrency);
        return QString("%1").arg(amount, 0, 'f', 4);
    }
    return QVariant();
}

QVariant CurrencyModel::headerData(int section, Qt::Orientation orientation, int role /* = Qt::DisplayRole */) const
{
    if (role != Qt::DisplayRole)
    {
        return QVariant();
    }
    //return QString((currencyMap.begin() + section).key());
    return currenyAt(section);
}

Qt::ItemFlags CurrencyModel::flags(const QModelIndex &index) const
{
    Qt::ItemFlags flags = QAbstractItemModel::flags(index);
    if (index.row() != index.column())
    {
        flags |= Qt::ItemIsEditable;
    }
    return flags;
}

bool CurrencyModel::setData(const QModelIndex &index, const QVariant &value, int role /* = Qt::EditRole */)
{
    if (index.isValid()
        && index.row() != index.column()
        && role == Qt::EditRole)
    {
        QString columnCurrency = headerData(index.column(),
            Qt::Horizontal, Qt::DisplayRole).toString();
        QString rowCurrency = headerData(index.row(),
            Qt::Vertical, Qt::DisplayRole).toString();
        currencyMap.insert(columnCurrency, value.toDouble() * currencyMap.value(rowCurrency));
        emit dataChanged(index, index);
        return true;
    }
    return false;
}

QString CurrencyModel::currenyAt(int offset) const
{
    return (currencyMap.begin() + offset).key();
}
