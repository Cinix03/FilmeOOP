//
// Created by Vasile George on 29.03.2024.
//

#ifndef LAB6OOP_REPO_H
#define LAB6OOP_REPO_H


#include "Film.h"
#include "vector.h"
//clasa abstracta
class Rep{
public:
    virtual ~Rep() = default;
    virtual void store(const Film& p) = 0;
    virtual void modifica(const string& titlu, const string& gen, const int an, const string& actor) = 0;
    virtual void sterge(const int nr) = 0;
    virtual void stergeFilm(const string& titlu) = 0;
    virtual vector<Film> get_all() = 0;
};

class Repo : public Rep{
protected:
    vector<Film> listaProduse;
public:
    /*
     * se adauga un film in lista de filme
     * pre: p - Film
     * post: listaProduse += p
     */
    virtual void store(const Film& p) override;
    /*
     * se modifica un film din lista de filme
     * pre: titlu, gen, an, actor - string
     * post: listaProduse[i] = Film(titlu, gen, an, actor)
     */
    virtual void modifica(const string& titlu, const string& gen, const int an, const string& actor);
    /*
     * se sterge un film din lista de filme
     * pre: nr - int
     * post: listaProduse -= listaProduse[nr]
     */
    virtual void sterge(const int nr);
    /*
     * se returneaza toate filmele
     */
    virtual void stergeFilm(const string& titlu);
    virtual vector<Film> get_all();
};

class RepoFisiere : public Repo {
private:
    string fisier;
public:
    RepoFisiere(const string& fisier) : fisier{fisier} {citesteFisier();}
    void store(const Film& p) override;
    void modifica(const string& titlu, const string& gen, const int an, const string& actor) override;
    void sterge(const int nr) override;
    void stergeFilm(const string& titlu) override;
    vector<Film> get_all() override;
    void citesteFisier();
    void scrieFisier();
};

class RepoDictionar : public Rep{
private:
    std::unordered_map<string, Film> dictionar;
public:
    void store(const Film& p) override;
    void modifica(const string& titlu, const string& gen, const int an, const string& actor) override;
    void sterge(const int nr) override;
    void stergeFilm(const string& titlu) override;
    vector<Film> get_all() override;

};

#endif
