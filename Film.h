//
// Created by Vasile George on 27.03.2024.
//

#ifndef LAB6OOP_FILM_H
#define LAB6OOP_FILM_H


#include <string>
using std::string;
using std::vector;
class Film {
private:
    string titlu;
    int an;
    string gen;
    string actor;
public:
    Film();
    Film(const string& titlu, const string& gen, const int an, const string& actor);
    Film(const Film& p);
    ~Film();
    string getActor() const;
    string getTitlu() const;
    int getAn() const;
    string getGen() const;
    void setActor(const string& nume);
    void setTitlu(const string& tip);
    void setAn(const int an);
    void setGen(const string& gen);
};

std::ostream& operator<<(std::ostream& os,const Film& p);

#endif //LAB6OOP_FILM_H

