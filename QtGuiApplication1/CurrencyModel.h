#pragma once

#include <QAbstractTableModel>
#include <QMap>
#include <QDebug>

class CurrencyModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    CurrencyModel(QObject *parent = 0);
    ~CurrencyModel();

    void setCurrencyMap(const QMap<QString, double> &map);
    int rowCount(const QModelIndex &parent /* = QModelIndex() */) const;
    int columnCount(const QModelIndex &parent /* = QModelIndex() */) const;
    QVariant data(const QModelIndex &index, int role /* = Qt::DisplayRole */) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role /* = Qt::DisplayRole */) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role /* = Qt::EditRole */);

private:
    QString currenyAt(int offset) const;
    QMap<QString, double> currencyMap;
};
