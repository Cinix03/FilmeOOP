//
// Created by Vasile George on 27.03.2024.
//

#include "Film.h"
#include <iostream>

Film::Film()
{
    this->actor = "";
    this->titlu = "";
    this->an = 0;
    this->gen = "";
}

Film::Film(const std::string& titlu, const std::string& tip, const int an, const std::string& actor): actor{actor}, titlu{titlu}, an{an}, gen{tip} {};

Film::Film(const Film& p) {
    this->actor = p.actor;
    this->titlu = p.titlu;
    this->an = p.an;
    this->gen = p.gen;
}

Film::~Film() {
}

std::ostream& operator<<(std::ostream& os, const Film& p) {
    os << p.getTitlu() << " " << p.getGen() << " " << p.getAn() << " " << p.getActor()<<'\n';
    return os;
}

string Film::getActor() const {
    return this->actor;
}

string Film::getTitlu() const {
    return this->titlu;
}

int Film::getAn() const {
    return this->an;
}

string Film::getGen() const {
    return this->gen;
}

void Film::setActor(const string& nume) {
    this->actor = nume;
}

void Film::setTitlu(const string& tip) {
    this->titlu = tip;
}

void Film::setAn(const int an) {
    this->an = an;
}

void Film::setGen(const string& gen) {
    this->gen = gen;
}
