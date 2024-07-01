//
// Created by Vasile George on 11.04.2024.
//

#ifndef LAB6OOP_COS_H
#define LAB6OOP_COS_H
#include "Film.h"
#include "Observer.h"

class Cos: public Observable{
private:
    vector<Film> cos;
public:
    Cos() = default;
    void add(vector <Film> filme, string titlu);
    void goleste();
    void genereaza_aleatoriu(vector<Film> filme, int nr);
    void sterge(const int nr);
    void sterge_titlu(string s);
    vector<Film> get_all() const;
};


#endif //LAB6OOP_COS_H
