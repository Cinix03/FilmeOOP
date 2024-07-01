//
// Created by Vasile George on 11.05.2024.
//

#ifndef LAB6OOP_LOGIN_H
#define LAB6OOP_LOGIN_H
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
#include "FilmeGUI.h"
#include "UserModeGui.h"

class Login: public QWidget{
public:
    Login(FilmeGUI& adminMode, UserModeGui& userMode);
private:
    FilmeGUI& adminMode;
    UserModeGui& userMode;
    QPushButton* btnUserMode = new QPushButton("&Login as user");
    QPushButton* btnAdminMode = new QPushButton("&Login as admin");
    QLineEdit* editParola = new QLineEdit;
    int cnt;
    void initGUI();
    void initConnect();

};


#endif //LAB6OOP_LOGIN_H
