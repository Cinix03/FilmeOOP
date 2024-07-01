//
// Created by Vasile George on 25.05.2024.
//

#include "ClasaProprieLista.h"
#include <QAbstractListModel>
#include <QPainter>
#include <QBrush>


ClasaProprieLista::ClasaProprieLista(QObject *parent):
        QAbstractListModel(parent) {

}

int ClasaProprieLista::rowCount(const QModelIndex &parent) const {
    return lista.size();
}

QVariant ClasaProprieLista::data(const QModelIndex &index, int role) const {
    if (role == Qt::DisplayRole) {
        return QString("Row %1").arg(index.row()+1);
    }
    return QVariant();
}