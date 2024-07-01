//
// Created by Vasile George on 29.03.2024.
//

#include "Service.h"
#include "vector.h"
#include "Errors.h"
#include <algorithm>
#include <fstream>
#include <unordered_map>
#include "ClasaNoua.h"
#include <memory>
using std::unordered_map;
using std::copy_if;
using std::sort;
using std::unique_ptr;

Service::Service(Rep& repo, Validator& validator, Cos& cos) : repo{repo}, validator{validator}, cos{cos}{}

void Service::store(const std::string& titlu, const std::string& gen, const int an, const std::string& actor) {
        this->validator.validateFilm(titlu, actor, gen, an);
        Film p{titlu, gen, an, actor};
        this->repo.store(p);
        this->undoActions.push_back(make_unique<UndoAdauga>(this->repo, p));
}

void Service::modifica(const std::string& titlu, const std::string& gen, const int an, const std::string& actor) {
        this->validator.validateFilm(titlu, actor, gen, an);
        vector<Film> f=this->repo.get_all();
        Film cautat;
        for(auto &film : f)
            if(film.getTitlu() == titlu)
            {
                cautat=film;
                break;
            }
        this->undoActions.push_back(make_unique<UndoModifica>(this->repo, cautat, Film{titlu, gen, an, actor}));
        this->repo.modifica(titlu, gen, an, actor);
}

void Service::sterge(const int nr) {
    this->undoActions.push_back(make_unique<UndoSterge>(this->repo, this->repo.get_all()[nr]));
    this->repo.sterge(nr);
}

void Service::sterge_titlu(string s)
{
    vector<Film> v = repo.get_all();
    for(auto i: v)
        if(i.getTitlu() == s)
            this->undoActions.push_back(make_unique<UndoSterge>(this->repo, i));
    this->repo.stergeFilm(s);
}

vector<Film> Service::get_all() const {
    return this->repo.get_all();
}

vector<Film> Service::cautare(std::string& titlu) const{
    vector<Film> f = this->repo.get_all();
    vector<Film> rez;
    auto g = std::find_if(f.begin(), f.end(), [=](const Film &a) {
        return a.getTitlu()==titlu;
    });
    if(g != f.end())
        rez.push_back(*g);
    return rez;
}

vector<Film> Service::filtrare_titlu(basic_string<char, char_traits<char>, allocator<char>> titlu) const {
    vector<Film> f = this->repo.get_all();
    vector<Film> rez;
    copy_if(f.begin(), f.end(), back_inserter(rez), [titlu](const Film &a) {
        return a.getTitlu() == titlu;
    });
    return rez;
}

vector<Film> Service::filtrare_an(const int an) const{
    vector<Film> f = this->repo.get_all();
    vector<Film> rez;
    for(int i = 0; i < f.size(); i++)
        if (f[i].getAn() == an)
            rez.push_back(f[i]);
    return rez;
}

vector<Film> Service::filtrare_gen(const string& gen) const {
    vector<Film> v = this->repo.get_all();
    vector<Film> rez;
    for(auto f: v)
        if(f.getGen() == gen)
            rez.push_back(f);
    return rez;
}

vector<Film> Service::sortare_dupa_titlu() const{
    vector<Film> f = this->repo.get_all();
    sort(f.begin(), f.end(), [](const Film& a, const Film& b) {
        return a.getTitlu() < b.getTitlu();
    });
    return f;
}

vector<Film> Service::sortare_dupa_actor() const{
    vector<Film> f = this->repo.get_all();
    sort(f.begin(), f.end(), [](const Film& a, const Film& b) {
        return a.getActor() < b.getActor();
    });
    return f;
}

vector<Film> Service::sortare_dupa_an_si_gen() const{
    vector<Film> f = this->repo.get_all();
    sort(f.begin(), f.end(), [](const Film& a, const Film& b) {
        return a.getAn() < b.getAn() || (a.getAn() == b.getAn() && a.getGen() < b.getGen());
    });
    return f;
}

void Service::adauga_in_cos(const std::string& titlu) {
    vector<Film> f = this->repo.get_all();
    for(auto film : f)
        if(film.getTitlu() == titlu)
        {
            this->cos.add(f, titlu);
            break;
        }
}

void Service::sterge_titlu_cos(std::string s) {
    cos.sterge_titlu(s);
}

void Service::goleste_cos() {
    this->cos.goleste();
}

void Service::genereaza_aleatoriu(const int nr) {
    vector<Film> f = this->repo.get_all();
    this->cos.genereaza_aleatoriu(f, nr);
}

vector<Film> Service::get_cos() const {
    //vector <Film> v{Film{"Titanic", "Drama", 1997, "Leonardo DiCaprio"}};
    return this->cos.get_all();
}

unordered_map<string, FilmCount> Service::genereaza_raport() const{
    vector<Film> f = this->repo.get_all();
    unordered_map<string, FilmCount> rez;
    for(auto i: f)
        rez[i.getGen()].increment();
    return rez;
}

void Service::undo()
{
    if(!this->undoActions.empty()) {
        this->undoActions.back()->doUndo();
        this->undoActions.pop_back();
    }
}
