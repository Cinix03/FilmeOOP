//
// Created by Vasile George on 11.05.2024.
//

#include "Login.h"
#include "UserModeGui.h"


Login::Login(FilmeGUI& adminMode, UserModeGui& user):adminMode{adminMode}, userMode{user}{
    this->initGUI();
    this->initConnect();
    editParola->setEchoMode(QLineEdit::Password);
}

void Login::initGUI() {
    QVBoxLayout* mainLy = new QVBoxLayout;
    setLayout(mainLy);
    QWidget* middle = new QWidget;
    QFormLayout* mid = new QFormLayout;
    mid->addRow("Parola(in caz de admin)", editParola);
    mid->addWidget(btnAdminMode);
    mid->addWidget(btnUserMode);
    middle->setLayout(mid);
    mainLy->addWidget(middle);
}

void Login::initConnect() {
    QObject::connect(btnAdminMode, &QPushButton::clicked, [&](){
       string parola = editParola->text().toStdString();
       if(cnt==3) {
           QMessageBox::critical(this, "Error", QString::fromStdString("ATI INCERCAT DE PREA MULTE ORI"));
           close();
       }
       else if(parola == "admin"){
           adminMode.show();
           close();
       }
       else{
           QMessageBox::critical(this, "Error", QString::fromStdString("PAROLA INCORECTA"));
           editParola->clear();
           cnt++;
       }
    });

    QObject::connect(btnUserMode, &QPushButton::clicked, [&](){
       userMode.show();
       close();
    });
}