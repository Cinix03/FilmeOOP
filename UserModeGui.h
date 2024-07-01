//
// Created by Vasile George on 11.05.2024.
//

#ifndef LAB6OOP_USERMODEGUI_H
#define LAB6OOP_USERMODEGUI_H


#include "FilmeGUI.h"

class UserModeGui: public FilmeGUI{
public:
    UserModeGui(Service& service, CosGUI& cos): FilmeGUI(service, cos) {
        btnAdaugaFilm->setVisible(false);
        btnStrg->setVisible(false);
        btnModificaFilm->setVisible(false);
        btnUndo->setVisible(false);
    }
};


#endif //LAB6OOP_USERMODEGUI_H
