//
// Created by Vasile George on 15.04.2024.
//

#ifndef LAB6OOP_CLASANOUA_H
#define LAB6OOP_CLASANOUA_H

#include <string.h>
#include <iostream>
using std::string;

class FilmCount {
private:
        string gen;
        int count;
public:
        FilmCount(string gen="", int count=0) : gen{gen}, count{count}{}
        FilmCount(const FilmCount& other) : gen{other.gen}, count{other.count}{}
        string getGen() const {return this->gen;}
        int getCount() const {return this->count;}
        void increment() {this->count++;}
};


#endif //LAB6OOP_CLASANOUA_H
