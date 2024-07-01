//
// Created by Vasile George on 11.04.2024.
//

#include "Cos.h"
#include "Film.h"
#include <random>
#include <algorithm>
#include <chrono>
#include <iostream>
#include <fstream>

using std::shuffle;


void Cos::add(vector<Film> filme, string titlu) {
    for(auto &film : filme)
        if(film.getTitlu() == titlu)
            cos.push_back(film);
    notify();
}

void Cos::goleste() {
    cos.clear();
    notify();
}

void Cos::genereaza_aleatoriu(vector<Film> filme, int nr){
    this->cos.clear();
    auto seed = std::chrono::system_clock::now().time_since_epoch().count();
    shuffle(filme.begin(), filme.end(), std::default_random_engine(seed));
    if(nr<=filme.size())
        for(int i=0; i<nr; i++)
            this->cos.push_back(filme[i]);
    notify();
}

void Cos::sterge(const int nr) {
    cos.erase(cos.begin() + nr);
    notify();
}

void Cos::sterge_titlu(string s){
    int nr=-1;
    for(auto film: cos) {
        nr++;
        if (film.getTitlu() == s)
        {
            cos.erase(cos.begin()+nr);
            break;
        }
    }
    notify();
}

vector<Film> Cos::get_all() const {
    return cos;
}
