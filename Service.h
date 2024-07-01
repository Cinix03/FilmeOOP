//
// Created by Vasile George on 29.03.2024.
//

#ifndef LAB6OOP_SERVICE_H
#define LAB6OOP_SERVICE_H


#include "Repo.h"
#include "Validator.h"
#include "Cos.h"
#include "ClasaNoua.h"
#include "ActiuneUndo.h"
#include <memory>
#include <unordered_map>
using std::unordered_map;
using std::unique_ptr;

class Service {
private:
    Rep& repo;
    Validator& validator;
    vector<unique_ptr<ActiuneUndo>> undoActions;

public:
    /* Constructor
     * se initializeaza un service
     * pre: repo - Repo
     * post: this->repo = repo
     */
    Service(Rep& repo, Validator& validator, Cos& cos);
    /*
     * se adauga un film in lista de filme
     * pre: titlu, gen, an, actor - string
     * post: repo.store(Film(titlu, gen, an, actor))
     */
    void store(const std::string& titlu, const std::string& gen, const int an, const std::string& actor);
    /*
     * se modifica un film din lista de filme
     * pre: titlu, gen, an, actor - string
        * post: repo.modifica(titlu, gen, an, actor)
     */
    void modifica(const std::string& titlu, const std::string& gen, const int an, const std::string& actor);
    /*
     * se sterge un film din lista de filme
     * pre: nr - int
     * post: repo.sterge(nr)
     */
    void sterge(const int nr);
    /*
     * se returneaza toate filmele
     */
    vector<Film> get_all() const;
    /*
     * se cauta un film dupa titlu
     * pre: titlu - string
     * post: se returneaza un vector de filme
     */
    vector<Film> cautare(std::string& titlu) const;
    /*
     * se filtreaza filmele dupa titlu
     * pre: titlu - string
     * post: se returneaza un vector de filme cu titlul titlu
     */
    vector<Film> filtrare_titlu(std::basic_string<char, std::char_traits<char>, std::allocator<char>> titlu) const;
    /*
     * se filtreaza filmele dupa an
     * pre: an - int
     * post: se returneaza un vector de filme cu anul an
     */
    vector<Film> filtrare_an(const int an) const;
    /*
     * se filtreaza filmele dupa gen
     * pre: gen - string
     * post: se returneaza un vector de filme cu genul gen
     */
    vector<Film> filtrare_gen(const string& gen) const;
    /*
     * se sorteaza filmele dupa titlu
     * post: se returneaza un vector de filme sortate dupa titlu
     */
    vector<Film> sortare_dupa_titlu() const;
    /*
     * se sorteaza filmele dupa actor
     * post: se returneaza un vector de filme sortate dupa actor
     */
    vector<Film> sortare_dupa_actor() const;
    /*
     * se sorteaza filmele dupa an si gen
     * post: se returneaza un vector de filme sortate dupa an si gen
     */
    vector<Film> sortare_dupa_an_si_gen() const;
    /*
     * se adauga un film in cos
     * pre: titlu - string
     * post: cos.store(titlu)
     */
    void adauga_in_cos(const std::string& titlu);
    /*
     * se goleste cosul
     * post: cos.goleste()
     */
    void goleste_cos();
    /*
     * se genereaza aleatoriu un numar de filme in cos
     * pre: n - int
     * post: cos.genereaza_aleatoriu(n)
     */
    void genereaza_aleatoriu(const int n);
    vector<Film> get_cos() const;

    void sterge_titlu_cos(string s);

    void export_csv(const string& filename) const;

    unordered_map<string, FilmCount>genereaza_raport() const;

    void undo();

    void sterge_titlu(string s);

    Cos& cos;
};


#endif //LAB6OOP_SERVICE_H
