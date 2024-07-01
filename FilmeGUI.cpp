//
// Created by Vasile George on 30.04.2024.
//

#include "FilmeGUI.h"
#include <QWidget>
#include <QHBoxLayout>
#include <QListWidget>
#include <QFormLayout>
#include <QLineEdit>
#include <QPushButton>
#include <vector>
#include <cstring>
#include <QLabel>
#include "Service.h"
#include "Errors.h"
#include "CosGUI.h"
#include <QDebug>
#include <QMessageBox>
#include <QDesktopServices>
#include <QUrl>
#include "CosReadOnly.h"
#include "ClasaProprieLista.h"

void FilmeGUI::clearFields() {
    editTitlu->clear();
    editGen->clear();
    editAn->clear();
    editActor->clear();
}

void FilmeGUI::loadData() {
    //lst->clear();
    table->clear();
    std::vector<Film> Filme = s.get_all();
    table->setRowCount(Filme.size());
    table->setColumnCount(4);
    table->setHorizontalHeaderLabels(QStringList() << "Titlu" << "Gen" << "An" << "Actor");
    int row = 0;
    for (const auto& film : Filme) {
        table->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(film.getTitlu())));
        table->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(film.getGen())));
        table->setItem(row, 2, new QTableWidgetItem(QString::number(film.getAn())));
        table->setItem(row, 3, new QTableWidgetItem(QString::fromStdString(film.getActor())));
        row++;
    }
}

void FilmeGUI::initGUI() {
    setWindowTitle("Filme");
    // Layout-ul principal
    QHBoxLayout *lyMain = new QHBoxLayout{};
    setLayout(lyMain);

    auto newMine = new QListView;
    auto cevaNou = new ClasaProprieLista(this);
    newMine->setModel(cevaNou);
    lyMain->addWidget(newMine);
    tblView->setModel(tblModel);
    lyMain->addWidget(tblView);
    // Secțiunea din stânga
    QVBoxLayout* leftLayout = new QVBoxLayout{};
    leftLayout->addWidget(table);
    leftLayout->addWidget(btnArataDetalii);
    leftLayout->addWidget(btnStrg);
    leftLayout->addWidget(btnUndo);
    leftLayout->addWidget(btnCos);
    leftLayout->addWidget(btnAdaugaCos);
    leftLayout->addWidget(btnOpenTrailer);
    leftLayout->addWidget(btnCantitateGen);

    // Widget pentru secțiunea din stânga
    QWidget* leftWidget = new QWidget;
    leftWidget->setLayout(leftLayout);
    lyMain->addWidget(leftWidget);

    // Secțiunea din dreapta
    QWidget* rightWidget = new QWidget;
    QVBoxLayout* rightLayout = new QVBoxLayout{};
    rightWidget->setLayout(rightLayout);

    // Formularul pentru introducerea datelor
    QWidget* form = new QWidget;
    QFormLayout* lyForm = new QFormLayout;
    form->setLayout(lyForm);
    lyForm->addRow("Titlu", editTitlu);
    lyForm->addRow("Gen", editGen);
    lyForm->addRow("An", editAn);
    lyForm->addRow("Actor", editActor);

    // Layout pentru butoanele de adăugare și modificare
    QHBoxLayout* btnLayout = new QHBoxLayout;
    btnLayout->addWidget(btnAdaugaFilm);
    btnLayout->addWidget(btnModificaFilm);

    // Layout pentru butoanele de filtrare și reîmprospătare
    QHBoxLayout* filterLayout = new QHBoxLayout;
    filterLayout->addWidget(btnFiltrareTitlu);
    filterLayout->addWidget(btnFiltrareAn);
    filterLayout->addWidget(btnFiltrareGen);

    //Pentru refresh
    QHBoxLayout* refreshLy = new QHBoxLayout;
    refreshLy->addWidget(btnRefresh);

    //Sortari
    QHBoxLayout* sortsLy = new QHBoxLayout;
    sortsLy->addWidget(btnSortTitlu);
    sortsLy->addWidget(btnSortActor);
    sortsLy->addWidget(btnSortAnGen);

    // Layout pentru butonul de ieșire
    QVBoxLayout* exitLayout = new QVBoxLayout;
    exitLayout->addWidget(btnExit);
    exitLayout->addWidget(btnCosReadOnly);

    // Adăugarea widget-urilor în secțiunea din dreapta
    rightLayout->addWidget(form);
    rightLayout->addLayout(btnLayout);
    rightLayout->addLayout(filterLayout);
    rightLayout->addLayout(refreshLy);
    rightLayout->addLayout(sortsLy);
    rightLayout->addLayout(exitLayout);

    lyMain->addWidget(rightWidget);

}

void FilmeGUI::reloadTable(vector<Film> filme) {
    table->clear();
    table->setRowCount(filme.size());
    table->setColumnCount(4);
    table->setHorizontalHeaderLabels(QStringList() << "Titlu" << "Gen" << "An" << "Actor");
    int row = 0;
    for (const auto& film : filme) {
        table->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(film.getTitlu())));
        table->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(film.getGen())));
        table->setItem(row, 2, new QTableWidgetItem(QString::number(film.getAn())));
        table->setItem(row, 3, new QTableWidgetItem(QString::fromStdString(film.getActor())));
        row++;
    }

}

void FilmeGUI::initConnect()
{
    QObject::connect(btnExit, &QPushButton::clicked, [&](){
        close();});

    QObject::connect(btnAdaugaFilm, &QPushButton::clicked, [&]() {
        try {
            auto titlu = editTitlu->text();
            auto gen = editGen->text();
            auto an = editAn->text();
            auto actor = editActor->text();
            this->s.store(titlu.toStdString(), gen.toStdString(), an.toInt(), actor.toStdString());
            tblModel->setFilme(s.get_all());
            loadData();

            clearFields();
        } catch (Exception &e) {
            QMessageBox::critical(this, "Error", QString::fromStdString(e.getMsg()));
            clearFields();
        }
    });

    QObject::connect(btnStrg, &QPushButton::clicked, [&](){
        //QListWidgetItem* selected = lst->currentItem();
        QTableWidgetItem* selected = table->currentItem();
        this->s.sterge_titlu(selected->text().toStdString());
        tblModel->setFilme(s.get_all());
        loadData();
    });

    QObject::connect(btnModificaFilm, &QPushButton::clicked, [&]() {
        try{
            auto titlu = editTitlu->text();
            auto gen = editGen->text();
            auto an = editAn->text();
            auto actor = editActor->text();
            this->s.modifica(titlu.toStdString(), gen.toStdString(), an.toInt(), actor.toStdString());
            tblModel->setFilme(s.get_all());
            clearFields();}
        catch (Exception &e) {
            QMessageBox::critical(this, "Error", QString::fromStdString(e.getMsg()));
            clearFields();
        }
    });

    QObject::connect(btnFiltrareTitlu, &QPushButton::clicked, [&](){
        auto titlu = editTitlu->text();
        vector<Film> f = this->s.filtrare_titlu(titlu.toStdString());
        //lst->clear();
//        for(auto film: f)
//            lst->addItem(QString::fromStdString(film.getTitlu()));
        reloadTable(f);
        clearFields();
    });

    QObject::connect(btnFiltrareGen, &QPushButton::clicked, [&](){
        auto gen = editGen->text();
        vector<Film> f = this->s.filtrare_gen(gen.toStdString());
//        lst->clear();
//        for(auto film: f)
//            lst->addItem(QString::fromStdString(film.getTitlu()));
        reloadTable(f);
        clearFields();
    });

    QObject::connect(btnRefresh, &QPushButton::clicked, [&](){
        loadData();
    });

    QObject::connect(btnFiltrareAn, &QPushButton::clicked, [&](){
        auto an = editAn->text().toInt();
        vector<Film> v = s.filtrare_an(an);
//        lst->clear();
//        for(auto film: v)
//            lst->addItem(QString::fromStdString(film.getTitlu()));
        reloadTable(v);
        clearFields();
    });

    QObject::connect(table, &QTableWidget::itemSelectionChanged, [&]() {
        // Get the selected item
        QTableWidgetItem* selected = table->currentItem();
        if (selected) {
            // Get the row of the selected item
            int row = selected->row();
            // Update the QLineEdit widgets
            editTitlu->setText(table->item(row, 0)->text());
            editGen->setText(table->item(row, 1)->text());
            editAn->setText(table->item(row, 2)->text());
            editActor->setText(table->item(row, 3)->text());
        }
    });

    QObject::connect(btnUndo, &QPushButton::clicked, [&](){
        s.undo();
        loadData();
    });

    QObject::connect(btnArataDetalii, &QPushButton::clicked, [&](){
//        if(lst->item(0)->text().contains(" "))
//        {
//            for(int i=0; i<lst->count();i++){
//                this->lst->item(i)->setText(this->lst->item(i)->text().split(" ").at(0));
//            }
//        }
//        else
//            for(int i=0; i<lst->count();i++)
//            {
//                QListWidgetItem* item = lst->item(i);
//                string titlu = item->text().toStdString();
//                vector<Film> f = s.cautare(titlu);
//                for(auto film: f)
//                {
//                    string filmDetails = film.getTitlu() + " " + film.getGen() + " " + std::to_string(film.getAn()) + " " + film.getActor();
//                    lst->item(i)->setText(QString::fromStdString(filmDetails));
//                }
//            }
    });

    QObject::connect(btnCos, &QPushButton::clicked, [&](){
        auto newCos = new CosGUI(s);
        newCos->show();
    });

    QObject::connect(btnAdaugaCos, &QPushButton::clicked, [&](){
        //QListWidgetItem* selected = lst->currentItem();

        QTableWidgetItem* selected = table->currentItem();
        string titlu = selected->text().toStdString();
        s.adauga_in_cos(titlu);
    });

    QObject::connect(btnSortTitlu, &QPushButton::clicked, [&](){
        vector<Film> rez = s.sortare_dupa_titlu();
//        lst->clear();
//        for(auto f: rez)
//            lst->addItem(QString::fromStdString(f.getTitlu()));
        reloadTable(rez);
    });

    QObject::connect(btnSortActor, &QPushButton::clicked, [&](){
        vector<Film> rez = s.sortare_dupa_actor();
//        lst->clear();
//        for(auto f: rez)
//            lst->addItem(QString::fromStdString(f.getTitlu()));
        reloadTable(rez);
    });

    QObject::connect(btnSortAnGen, &QPushButton::clicked, [&](){
        vector<Film> rez = s.sortare_dupa_an_si_gen();
//        lst->clear();
//        for(auto f: rez)
//            lst->addItem(QString::fromStdString(f.getTitlu()));
        reloadTable(rez);
    });

    QObject::connect(btnOpenTrailer, &QPushButton::clicked, [&](){
        //QListWidgetItem* selected = lst->currentItem();
        QTableWidgetItem* selected = table->currentItem();
        string titlu = selected->text().toStdString();
        string link = "https://www.youtube.com/results?search_query=" + titlu + " trailer";
        QDesktopServices::openUrl(QUrl(QString::fromStdString(link)));
    });

    QObject::connect(btnCantitateGen, &QPushButton::clicked, [this](){
        QVBoxLayout* lyBig = new QVBoxLayout;
        QWidget* big = new QWidget;
        QWidget* cantitateGen = new QWidget;
        cantitateGen->setWindowTitle("Cantitate gen");
        QHBoxLayout* lyCantitateGen = new QHBoxLayout;
        cantitateGen->setLayout(lyCantitateGen);
        QLabel* label = new QLabel;
        label->setText("Cantitate gen");
        lyCantitateGen->addWidget(label);
        lyBig->addWidget(label, 0, Qt::AlignCenter);  // Set alignment to center
        lyBig->addWidget(cantitateGen);
        big->setLayout(lyBig);
        big->show();

        // Get all unique genres
        unordered_map<string, FilmCount> rez = this->s.genereaza_raport();
        for (const auto& pair : rez) {
            // For each unique genre, create a button
            QPushButton* btnGenre = new QPushButton(QString::fromStdString(pair.first));
            lyCantitateGen->addWidget(btnGenre);

            // Connect the button to a lambda function that updates the label text
            QObject::connect(btnGenre, &QPushButton::clicked, [this, label, pair](){
                label->setText(QString::fromStdString(pair.first + ": " + std::to_string(pair.second.getCount())));
            });
        }
    });

    QObject::connect(btnCosReadOnly, &QPushButton::clicked, [&](){
        CosReadOnly* cosReadOnly = new CosReadOnly(s);
        cosReadOnly->show();
    });

}