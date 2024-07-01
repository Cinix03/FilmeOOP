//
// Created by Vasile George on 03.05.2024.
//

#ifndef LAB6OOP_COSGUI_H
#define LAB6OOP_COSGUI_H


#include <QWidget>
#include <QPushButton>
#include <QListWidget>
#include <QHBoxLayout>
#include <QLineEdit>
#include "Service.h"
#include "Observer.h"

class CosGUI: public QWidget, public Observer{
public:
    CosGUI(Service& s);
    void loadCos();
private:
    Service& s;

    QListWidget* lst = new QListWidget;
    QLineEdit* editNumeFis = new QLineEdit;
    QLineEdit* editCate = new QLineEdit;

    QPushButton* btnGolire = new QPushButton{"&Goleste"};
    QPushButton* btnElimina = new QPushButton{"&Elimina"};
    QPushButton* btnExport = new QPushButton{"&Export CSV"};
    QPushButton* btnGenereazaRandom = new QPushButton{"&Genereaza random"};
    QPushButton* btnExit = new QPushButton("&Exit");

    void initGUI();
    void initConnect();
    void update() override{
        this->loadCos();
    };
};


#endif //LAB6OOP_COSGUI_H
