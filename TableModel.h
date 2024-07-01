//
// Created by Vasile George on 27.05.2024.
//

#ifndef LAB6OOP_TABLEMODEL_H
#define LAB6OOP_TABLEMODEL_H


#pragma once
#include <QAbstractTableModel>
#include "Film.h"
#include <vector>
#include <qdebug.h>

using namespace std;

class TableModel : public QAbstractTableModel {
    std::vector<Film> filme;
public:
    TableModel(const std::vector<Film>& oferte) : filme{oferte } {
    }

    int rowCount(const QModelIndex& parent = QModelIndex()) const override {
        return filme.size();
    }
    int columnCount(const QModelIndex& parent = QModelIndex()) const override {
        return 4;
    }

    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override {
        //qDebug() << "row:" << index.row() << " col:" << index.column() << " role" << role;
        if (role == Qt::DisplayRole) {
            Film p = filme[index.row()];
            printf("index.row() = %d\n", index.row());
            if (index.column() == 0) {
                return QString::fromStdString(p.getTitlu());
            }
            else if (index.column() == 1) {
                return QString::fromStdString(p.getGen());
            }
            else if (index.column() == 2) {
                return QString::fromStdString(p.getActor());
            }
            else if (index.column() == 3) {
                return QString::number(p.getAn());
            }
        }

        return QVariant{};
    }

    void setFilme(const vector<Film>& filme) {
        this->filme = filme;
        auto topLeft = createIndex(0, 0);
        auto bottomR = createIndex(rowCount(), columnCount());
        emit dataChanged(topLeft, bottomR);
        emit layoutChanged();
    }
};


#endif //LAB6OOP_TABLEMODEL_H
