//
// Created by Vasile George on 03.05.2024.
//

#include <QFormLayout>
#include <fstream>
#include <iostream>
#include <QDesktopServices>
#include <QUrl>

#include "CosGUI.h"

CosGUI::CosGUI(Service& service) : s{service} {
    this->initGUI();
    this->loadCos();
    this->initConnect();
}

void CosGUI::loadCos() {
    vector<Film>v = s.get_cos();
    lst->clear();
    for(auto i: v)
        lst->addItem(QString::fromStdString(i.getTitlu()));
}

void CosGUI::initGUI() {
    setWindowTitle("Coș");
    //Layout ul principat
    QHBoxLayout* lyMain = new QHBoxLayout;
    setLayout(lyMain);

    //sectiunea stanga
    QVBoxLayout* leftLy = new QVBoxLayout;
    leftLy->addWidget(lst);
    leftLy->addWidget(btnGolire);
    leftLy->addWidget(btnElimina);
    leftLy->addWidget(btnExit);

    //Widget
    QWidget* leftWidget = new QWidget;
    QWidget* form = new QWidget;
    QFormLayout* formLy = new QFormLayout;
    formLy->addRow("Nume Fisier", editNumeFis);
    formLy->addWidget(btnExport);
    formLy->addRow("Cate numere sa fie generate", editCate);
    formLy->addWidget(btnGenereazaRandom);
    form->setLayout(formLy);
    leftWidget->setLayout(leftLy);
    lyMain->addWidget(leftWidget);
    lyMain->addWidget(form);
}
void CosGUI::initConnect() {
    s.cos.addObserver(this);
    QObject::connect(btnGolire, &QPushButton::clicked, [&](){
        s.goleste_cos();
        lst->clear();
    });
    QObject::connect(btnExit, &QPushButton::clicked, [&](){
        close();
    });

    QObject::connect(btnElimina, &QPushButton::clicked, [&](){
        if(lst->count() != 0) {
            QListWidgetItem *selected = lst->currentItem();
            string titlu = selected->text().toStdString();
            s.sterge_titlu_cos(titlu);
            lst->clear();
            loadCos();
        }
    });

    QObject::connect(btnExport, &QPushButton::clicked, [&](){
        QString numeFis = editNumeFis->text();
        string filename = numeFis.toStdString();
        filename=filename+".csv";
        printf("%s", filename.c_str());
        std::ofstream fout(filename);
        if (!fout.is_open()) {
            std::cout << "Error: Unable to open file";
            return; // Exit the function if the file couldn't be opened
        }
        fout<<"Titlu,Gen,An,Actor\n";
        for(auto &film : this->s.get_cos())
            fout<<film.getTitlu()<<","<<film.getGen()<<","<<film.getAn()<<","<<film.getActor()<<"\n";
        editNumeFis->clear();
        QDesktopServices::openUrl(QUrl::fromLocalFile(QString::fromStdString(filename)));
    });

    QObject::connect(btnGenereazaRandom, &QPushButton::clicked, [&](){
       s.genereaza_aleatoriu(editCate->text().toInt());
       loadCos();
       editCate->clear();
    });
}
