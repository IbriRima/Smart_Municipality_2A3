#include "customtablemodel.h"
#include <QtCore/QVector>
#include <QtCore/QTime>
#include <QtCore/QRect>
#include <QtGui/QColor>
#include <QSqlQueryModel>
CustomTableModel::CustomTableModel(QObject *parent) :
    QAbstractTableModel(parent)
{    QSqlQueryModel *model= new QSqlQueryModel();
     model->setQuery("SELECT DUREE,DATE_RAMASSAGE FROM RAMASSAGE ");

    m_columnCount = model->columnCount();
    m_rowCount = model->rowCount();

    // m_data
    for (int i = 0; i < m_rowCount; i++) {
        QVector<qreal>* dataVec = new QVector<qreal>(m_columnCount);

        for (int k = 0; k < dataVec->size(); k++) {
            if (k % 2 == 0)
                dataVec->replace(k, i * 50 + qrand() % 20);
            else
                dataVec->replace(k, qrand() % 100);

        }
        m_data.append(dataVec);

    }
}

int CustomTableModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return m_data.count();
}

int CustomTableModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return m_columnCount;
}

QVariant CustomTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal) {
        if (section % 2 == 0)
            return "Date";
        else
            return "Duree";
    } else {
        return QString("%1").arg(section + 1);
    }
}

QVariant CustomTableModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole) {
        return m_data[index.row()]->at(index.column());
    } else if (role == Qt::EditRole) {
        return m_data[index.row()]->at(index.column());
    } else if (role == Qt::BackgroundRole) {
        for (const QRect &rect : m_mapping) {
            if (rect.contains(index.column(), index.row()))
                return QColor(m_mapping.key(rect));
        }
        // cell not mapped return white color
        return QColor(Qt::white);
    }
    return QVariant();
}

Qt::ItemFlags CustomTableModel::flags(const QModelIndex &index) const
{
    return QAbstractItemModel::flags(index) | Qt::ItemIsEditable;
}

void CustomTableModel::addMapping(QString color, QRect area)
{
    m_mapping.insertMulti(color, area);
}
