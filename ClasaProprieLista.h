//
// Created by Vasile George on 25.05.2024.
//

#ifndef LAB6OOP_CLASAPROPRIELISTA_H
#define LAB6OOP_CLASAPROPRIELISTA_H


#include <QAbstractListModel>

class ClasaProprieLista: public QAbstractListModel{
    //TODO: implementare
public:
    ClasaProprieLista(QObject* parent);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
private:
    std::vector<QString> lista;
};


#endif //LAB6OOP_CLASAPROPRIELISTA_H
