
#include "Repo.h"
#include <fstream>

void Repo::store(const Film& p) {
    listaProduse.push_back(p);
}

vector<Film> Repo::get_all(){
    return listaProduse;
}

void Repo::modifica(const string& titlu, const string& gen, const int an, const string& actor)
{
    for(auto &f : listaProduse)
    {
        if(f.getTitlu() == titlu)
            f =  Film{titlu, gen, an, actor};
    }
}

void Repo::sterge(const int nr)
{
    listaProduse.erase(listaProduse.begin() + nr);
}

void Repo::stergeFilm(const string &titlu)
{
    listaProduse.erase(std::remove_if(listaProduse.begin(), listaProduse.end(), [&titlu](const Film& f) {
        return f.getTitlu() == titlu;
    }), listaProduse.end());
}

void RepoFisiere::citesteFisier()
{
    std::ifstream f(fisier);
    if(!f.is_open())
        return;
    listaProduse.clear();
    string titlu, gen, actor;
    int an;
    while(f >> titlu >> gen >> an >> actor)
    {
        Film p{titlu, gen, an, actor};
        store(p);
    }
    f.close();
}


void RepoFisiere::scrieFisier() {
    std::ofstream f(fisier);
    if(!f.is_open())
        return;
    for(auto &film : listaProduse)
    {
        f << film.getTitlu() << " " << film.getGen() << " " << film.getAn() << " " << film.getActor() << "\n";
    }
    f.close();
}


void RepoFisiere::store(const Film& p) {
    Repo::store(p);
    scrieFisier();
}

void RepoFisiere::modifica(const string& titlu, const string& gen, const int an, const string& actor)
{
    Repo::modifica(titlu, gen, an, actor);
    scrieFisier();
}

void RepoFisiere::sterge(const int nr)
{
    Repo::sterge(nr);
    scrieFisier();
}

void RepoFisiere::stergeFilm(const string &titlu)
{
    Repo::stergeFilm(titlu);
    scrieFisier();
}

vector<Film> RepoFisiere::get_all()
{
    citesteFisier();
    return Repo::get_all();
}


void RepoDictionar::store(const Film& p) {
    dictionar[p.getTitlu()] = p;
}

vector<Film> RepoDictionar::get_all() {
    vector<Film> f;
    for(auto &p : dictionar)
        f.push_back(p.second);
    return f;
}

void RepoDictionar::modifica(const string& titlu, const string& gen, const int an, const string& actor)
{
    dictionar[titlu] = Film{titlu, gen, an, actor};
}

void RepoDictionar::sterge(const int nr)
{
    auto it = dictionar.begin();
    for(int i = 0; i < nr; i++)
        it++;
    dictionar.erase(it);
}

void RepoDictionar::stergeFilm(const string &titlu) {
    dictionar.erase(titlu);
}


