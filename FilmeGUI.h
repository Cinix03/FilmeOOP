// Created by Vasile George on 30.04.2024.

#ifndef LAB6OOP_FILMEGUI_H
#define LAB6OOP_FILMEGUI_H

#include <QWidget>
#include <QHBoxLayout>
#include <QTableWidget>  // Include QTableWidget instead of QListWidget
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
#include "TableModel.h"

using std::string;

class FilmeGUI: public QWidget{
public:
    FilmeGUI(Service& s, CosGUI& cos):s{s}, cos{cos}{
        initGUI();
        loadData();
        initConnect();
    }
private:
    CosGUI& cos;
    Service& s;
    TableModel* tblModel = new TableModel{s.get_all()};
    QTableView *tblView = new QTableView;
    // QListWidget* lst = new QListWidget;  // Comment out the QListWidget
    QTableWidget* table = new QTableWidget;  // Add a QTableWidget
    QPushButton* btnExit = new QPushButton("&Exit");
    QPushButton* btnFiltrareTitlu = new QPushButton("&Filtrarea titlu");
    QPushButton* btnRefresh = new QPushButton("&Refresh");
    QPushButton* btnFiltrareAn = new QPushButton("&Filtrare an");
    QPushButton* btnFiltrareGen = new QPushButton("&Filtrare gen");
    QPushButton* btnArataDetalii = new QPushButton("&Arata/Ascunde detalii");
    QPushButton* btnCos = new QPushButton("&Cos");
    QPushButton* btnAdaugaCos = new QPushButton("&Adauga in cos");
    QPushButton* btnSortTitlu = new QPushButton("&Sortare Titlu");
    QPushButton* btnSortActor = new QPushButton("&Sortare Actor");
    QPushButton* btnSortAnGen = new QPushButton("&Sortare AnGen");
    QPushButton* btnOpenTrailer = new QPushButton("&Open Trailer");
    QPushButton* btnCantitateGen = new QPushButton("&Cantitate gen");
    QPushButton* btnCosReadOnly = new QPushButton("&Cos read only");

    QLineEdit* editTitlu = new QLineEdit;
    QLineEdit* editGen = new QLineEdit;
    QLineEdit* editAn = new QLineEdit;
    QLineEdit* editActor = new QLineEdit;

    void clearFields();

    void loadData();

    void initGUI();

    void initConnect();

    void reloadTable(vector<Film> filme);


protected:
    QPushButton* btnAdaugaFilm = new QPushButton("&Adauga");
    QPushButton *btnStrg = new QPushButton{"&Sterge"};
    QPushButton* btnModificaFilm = new QPushButton("&Modifica");
    QPushButton* btnUndo = new QPushButton("&Undo");
};

#endif //LAB6OOP_FILMEGUI_H