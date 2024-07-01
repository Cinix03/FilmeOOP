//
// Created by Vasile George on 20.04.2024.
//

#ifndef LAB6OOP_ACTIUNEUNDO_H
#define LAB6OOP_ACTIUNEUNDO_H


#include "Repo.h"

// Clasa abstracta ActiuneUndo
class ActiuneUndo {
public:
    virtual void doUndo() = 0; // metoda pur virtuala
    virtual ~ActiuneUndo() = default; // destructor virtual
};

// Clasa derivata UndoAdauga
class UndoAdauga : public ActiuneUndo {
private:
    Film film;
    Rep& repo;
public:
    UndoAdauga(Rep& repo, const Film& film) : repo{repo}, film{film} {}
    void doUndo() override;
};

// Clasa derivata UndoSterge
class UndoSterge : public ActiuneUndo {
private:
    Film film;
    Rep& repo;
public:
    UndoSterge(Rep& repo, const Film& film) : repo{repo}, film{film} {}
    void doUndo() override;
};

// Clasa derivata UndoModifica
class UndoModifica : public ActiuneUndo {
private:
    Film filmVechi;
    Film filmNou;
    Rep& repo;
public:
    UndoModifica(Rep& repo, const Film& filmVechi, const Film& filmNou) : repo{repo}, filmVechi{filmVechi}, filmNou{filmNou} {}
    void doUndo() override;
};


#endif //LAB6OOP_ACTIUNEUNDO_H
