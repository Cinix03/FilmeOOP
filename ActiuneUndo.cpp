//
// Created by Vasile George on 20.04.2024.
//

#include "ActiuneUndo.h"

void UndoAdauga::doUndo() {
    repo.stergeFilm(film.getTitlu());
}

void UndoModifica::doUndo() {
    repo.modifica(filmNou.getTitlu(), filmVechi.getGen(), filmVechi.getAn(), filmVechi.getActor());
}

void UndoSterge::doUndo() {
    repo.store(film);
}