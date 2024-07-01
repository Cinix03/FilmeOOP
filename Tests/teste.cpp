//
// Created by Vasile George on 27.03.2024.
//

#include "../Film.h"
#include "teste.h"
#include "../Repo.h"
#include "../Service.h"
#include "../Cos.h"
#include <fstream>

#include <fstream>

void clearFileContent(const std::string& filename) {
    std::ofstream file;
    file.open(filename, std::ios::out | std::ios::trunc);
    file.close();
}

void test_getters()
{
    Film f{"Titanic", "Drama", 1997, "Leonardo DiCaprio"};
    assert(f.getTitlu() == "Titanic");
    assert(f.getGen() == "Drama");
    assert(f.getAn() == 1997);
    assert(f.getActor() == "Leonardo DiCaprio");
}
void test_setters()
{
    Film f{"Titanic", "Drama", 1997, "Leonardo DiCaprio"};
    f.setTitlu("Inception");
    f.setGen("SF");
    f.setAn(2010);
    f.setActor("Leonardo DiCaprio");
    assert(f.getTitlu() == "Inception");
    assert(f.getGen() == "SF");
    assert(f.getAn() == 2010);
    assert(f.getActor() == "Leonardo DiCaprio");
}

void test_service_store() {
    clearFileContent("test.txt");
    RepoFisiere r{"test.txt"};
    Validator v;
    Cos c;
    Service s{r, v, c};
    s.store("Titanic", "Drama", 1997, "LeonardoDiCaprio");
    assert(s.get_all().size() == 1);
}

void test_service_modifica() {
    clearFileContent("test.txt");
    RepoFisiere r{"test.txt"};
    Validator v;
    Cos c;
    Service s{r, v, c};
    s.store("Titanic", "Drama", 1997, "LeonardoDiCaprio");
    s.modifica("Titanic", "Action", 1998, "ArnoldSchwarzenegger");
    Film f = s.get_all()[0];
    assert(f.getTitlu() == "Titanic");
    assert(f.getGen() == "Action");
    assert(f.getAn() == 1998);
    assert(f.getActor() == "ArnoldSchwarzenegger");
}

void test_service_sterge() {
    clearFileContent("test.txt");
    RepoFisiere r{"test.txt"};
    Validator v;
    Cos c;
    Film t = Film();
    assert(t.getTitlu() == "");
    assert(t.getGen() == "");
    assert(t.getAn() == 0);
    assert(t.getActor() == "");
    Service s{r, v, c};
    s.store("Titanic", "Drama", 1997, "LeonardoDiCaprio");
    s.sterge(0);
    assert(s.get_all().size() == 0);
}

void test_service_sortare_dupa_titlu() {
    clearFileContent("test.txt");
    RepoFisiere r{"test.txt"};
    Validator v;
    Cos c;
    Service s{r, v, c};
    s.store("Titanic", "Drama", 1997, "LeonardoDiCaprio");
    s.store("Inception", "SF", 2010, "LeonardoDiCaprio");
    vector<Film> sorted = s.sortare_dupa_titlu();
    assert(sorted[0].getTitlu() == "Inception");
    assert(sorted[1].getTitlu() == "Titanic");
}

void test_service_sortare_dupa_actor() {
    clearFileContent("test.txt");
    RepoFisiere r{"test.txt"};
    Validator v;
    Cos c;
    Service s{r, v, c};
    s.store("Inception", "SF", 2010, "LeonardoDiCaprio");
    s.store("Terminator", "Action", 1984, "ArnoldSchwarzenegger");
    vector<Film> sorted = s.sortare_dupa_actor();
    assert(sorted[0].getActor() == "ArnoldSchwarzenegger");
    assert(sorted[1].getActor() == "LeonardoDiCaprio");
}

void test_service_sortare_dupa_an_si_gen() {
    clearFileContent("test.txt");
    RepoFisiere r{"test.txt"};
    Validator v;
    Cos c;
    Service s{r, v, c};
    s.store("Inception", "SF", 2010, "LeonardoDiCaprio");
    s.store("Titanic", "Drama", 1997, "LeonardoDiCaprio");
    vector<Film> sorted = s.sortare_dupa_an_si_gen();
    assert(sorted[0].getAn() == 1997);
    assert(sorted[1].getAn() == 2010);
}

void test_service_filtrare_titlu() {
    clearFileContent("test.txt");
    RepoFisiere r{"test.txt"};
    Validator v;
    Cos c;
    Service s{r, v, c};
    s.store("Inception", "SF", 2010, "LeonardoDiCaprio");
    s.store("Titanic", "Drama", 1997, "LeonardoDiCaprio");
    std::string ex = "Titanic";
    vector<Film> filtered = s.filtrare_titlu(ex);
    assert(filtered.size() == 1);
    assert(filtered[0].getTitlu() == "Titanic");
}

void test_service_filtrare_an() {
    clearFileContent("test.txt");
    RepoFisiere r{"test.txt"};
    Validator v;
    Cos c;
    Service s{r, v, c};
    s.store("Inception", "SF", 2010, "LeonardoDiCaprio");
    s.store("Titanic", "Drama", 1997, "LeonardoDiCaprio");
    vector<Film> filtered = s.filtrare_an(1997);
    assert(filtered.size() == 1);
    assert(filtered[0].getAn() == 1997);
}
void test_MyVector()
{
    vector<Film>v;
    assert(v.size() == 0);
}

void test_MyVector_add()
{
    vector<Film> v;
    v.push_back(Film{"Titanic", "Drama", 1997, "LeonardoDiCaprio"});
    v.push_back(Film{"Inception", "SF", 2010, "LeonardoDiCaprio"});
    v.push_back(Film{"TheDarkKnight", "Actiune", 2008, "ChristianBale"});
    assert(v.size() == 3);
    assert(v[0].getTitlu() == "Titanic");
    assert(v[1].getTitlu() == "Inception");
}

void test_cautare()
{
    clearFileContent("test.txt");
    RepoFisiere r{"test.txt"};
    Validator v;
    Cos c;
    Service s{r, v, c};
    s.store("Inception", "SF", 2010, "LeonardoDiCaprio");
    s.store("Titanic", "Drama", 1997, "LeonardoDiCaprio");
    std::string ex = "Titanic";
    vector<Film> filtered = s.cautare(ex);
    assert(filtered.size() == 1);
    assert(filtered[0].getTitlu() == "Titanic");
}

void test_cos_add()
{
    clearFileContent("test.txt");
    RepoFisiere r{"test.txt"};
    Validator v;
    Cos c;
    Service s{r, v, c};
    s.store("Inception", "SF", 2010, "LeonardoDiCaprio");
    s.store("Titanic", "Drama", 1997, "LeonardoDiCaprio");
    s.adauga_in_cos("Inception");
    s.adauga_in_cos("Titanic");
    assert(c.get_all().size() == 2);
}

void test_cos_goleste()
{
    clearFileContent("test.txt");
    RepoFisiere r{"test.txt"};
    Validator v;
    Cos a;
    Service s{r, v, a};
    Cos c;
    s.store("Inception", "SF", 2010, "LeonardoDiCaprio");
    s.store("Titanic", "Drama", 1997, "LeonardoDiCaprio");
    c.add(s.get_all(), "Inception");
    c.add(s.get_all(), "Titanic");
    c.goleste();
    assert(c.get_all().size() == 0);
}

void test_cos_genereaza_aleatoriu()
{
    clearFileContent("test.txt");
    RepoFisiere r{"test.txt"};
    Validator v;
    Cos a;
    Service s{r, v, a};
    Cos c;
    s.store("Inception", "SF", 2010, "LeonardoDiCaprio");
    s.store("Titanic", "Drama", 1997, "LeonardoDiCaprio");
    s.store("TheDarkKnight", "Actiune", 2008, "ChristianBale");
    s.store("TheMatrix", "SF", 1999, "KeanuReeves");
    s.store("TheGodfather", "Drama", 1972, "MarlonBrando");
    s.store("TheShawshankRedemption", "Drama", 1994, "TimRobbins");
    s.store("TheDarkKnightRises", "Actiune", 2012, "ChristianBale");
    c.genereaza_aleatoriu(s.get_all(), 5);
    assert(c.get_all().size() == 5);
}

void test_cos_sterge()
{
    clearFileContent("test.txt");
    RepoFisiere r{"test.txt"};
    Validator v;
    Cos a;
    Service s{r, v, a};
    Cos c;
    s.store("Inception", "SF", 2010, "LeonardoDiCaprio");
    s.store("Titanic", "Drama", 1997, "LeonardoDiCaprio");
    s.store("TheDarkKnight", "Actiune", 2008, "ChristianBale");
    c.add(s.get_all(), "Inception");
    c.add(s.get_all(), "Titanic");
    c.add(s.get_all(), "TheDarkKnight");
    c.sterge(1);
    assert(c.get_all().size() == 2);
}

void service_goleste_cos()
{
    clearFileContent("test.txt");
    RepoFisiere r{"test.txt"};
    Validator v;
    Cos a;
    Service s{r, v, a};
    Cos c;
    s.store("Inception", "SF", 2010, "LeonardoDiCaprio");
    s.store("Titanic", "Drama", 1997, "LeonardoDiCaprio");
    s.store("TheDarkKnight", "Actiune", 2008, "ChristianBale");
    c.add(s.get_all(), "Inception");
    c.add(s.get_all(), "Titanic");
    c.add(s.get_all(), "TheDarkKnight");
    s.goleste_cos();
    assert(a.get_all().size() == 0);
}

void service_genereaza_aleatoriu()
{
    clearFileContent("test.txt");
    RepoFisiere r{"test.txt"};
    Validator v;
    Cos a;
    Service s{r, v, a};
    Cos c;
    s.store("Inception", "SF", 2010, "LeonardoDiCaprio");
    s.store("Titanic", "Drama", 1997, "LeonardoDiCaprio");
    s.store("TheDarkKnight", "Actiune", 2008, "ChristianBale");
    s.store("TheMatrix", "SF", 1999, "KeanuReeves");
    s.store("TheGodfather", "Drama", 1972, "MarlonBrando");
    s.store("TheShawshank Redemption", "Drama", 1994, "TimRobbins");
    s.store("TheDarkKnightRises", "Actiune", 2012, "ChristianBale");
    s.genereaza_aleatoriu(5);
    assert(a.get_all().size() == 5);
}

void service_get_cos()
{
    clearFileContent("test.txt");
    RepoFisiere r{"test.txt"};
    Validator v;
    Cos a;
    Service s{r, v, a};
    Cos c;
    s.store("Inception", "SF", 2010, "LeonardoDiCaprio");
    s.store("Titanic", "Drama", 1997, "LeonardoDiCaprio");
    s.store("TheDarkKnight", "Actiune", 2008, "ChristianBale");
    s.adauga_in_cos("Inception");
    s.adauga_in_cos("Titanic");
    s.adauga_in_cos("TheDarkKnight");
    assert(s.get_cos().size() == 3);
}

void test_genereaza_raport()
{
//    Repo r;
//    Validator v;
//    Cos a;
//    Service s{r, v, a};
//    s.store("Inception", "SF", 2010, "Leonardo DiCaprio");
//    s.store("Titanic", "Drama", 1997, "Leonardo DiCaprio");
//    s.store("The Dark Knight", "Actiune", 2008, "Christian Bale");
//    //assert(s.genereaza_raport()["SF"] == 1);
//    //assert(s.genereaza_raport()["Drama"] == 1);
//    //assert(s.genereaza_raport()["Actiune"] == 1);
}

void test_undo()
{
    clearFileContent("test.txt");
    RepoFisiere r{"test.txt"};
    Validator v;
    Cos a;
    Service s{r, v, a};
    s.store("Inception", "SF", 2010, "LeonardoDiCaprio");
    s.store("Titanic", "Drama", 1997, "LeonardoDiCaprio");
    s.store("The Dark Knight", "Actiune", 2008, "ChristianBale");
    s.undo();
    assert(s.get_all().size() == 2);
    s.undo();
    assert(s.get_all().size() == 1);
    s.undo();
    assert(s.get_all().size() == 0);
    s.store("Inception", "SF", 2010, "LeonardoDiCaprio");
    s.sterge(0);
    assert(s.get_all().size() == 0);
    s.undo();
    assert(s.get_all().size() == 1);
    s.modifica("Inception", "SF", 2013, "LeonardoDiCaprio");
    assert(s.get_all()[0].getAn() == 2013);
    s.undo();
    assert(s.get_all()[0].getAn() == 2010);
}

void test_scrieFisier()
{
    clearFileContent("test.txt");
    RepoFisiere r{"test.txt"};
    Validator v;
    Cos a;
    Service s{r, v, a};
    s.store("Inception", "SF", 2010, "LeonardoDiCaprio");
    s.store("Titanic", "Drama", 1997, "LeonardoDiCaprio");
    s.store("TheDarkKnight", "Actiune", 2008, "ChristianBale");
    RepoFisiere r2{"test.txt"};
    vector<Film> f = r2.get_all();
    assert(f.size() == 3);
    assert(f[0].getTitlu() == "Inception");
    assert(f[1].getTitlu() == "Titanic");
    assert(f[2].getTitlu() == "TheDarkKnight");
}

void test_citesteFisier()
{
    clearFileContent("/Users/vasilegeorge/CLionProjects/Lab6OOP/Tests/test1.txt");
    std::ofstream f{"/Users/vasilegeorge/CLionProjects/Lab6OOP/Tests/test1.txt"};
    f << "Inception SF 2010 LeonardoDiCaprio\n";
    f << "Titanic Drama 1997 LeonardoDiCaprio\n";
    f << "TheDarkKnight Actiune 2008 ChristianBale\n";
    f.close();
    RepoFisiere r{"/Users/vasilegeorge/CLionProjects/Lab6OOP/Tests/test1.txt"};
    vector<Film> v = r.get_all();

    assert(v.size() == 3);
    assert(v[0].getTitlu() == "Inception");
    assert(v[1].getTitlu() == "Titanic");
    assert(v[2].getTitlu() == "TheDarkKnight");
}

void test_RepoDictionar()
{
    RepoDictionar r;
    r.store(Film{"Inception", "SF", 2010, "LeonardoDiCaprio"});
    r.store(Film{"Titanic", "Drama", 1997, "LeonardoDiCaprio"});
    r.store(Film{"TheDarkKnight", "Actiune", 2008, "ChristianBale"});
    vector<Film> v = r.get_all();
    assert(v.size() == 3);
    for(auto f: v)
        if(f.getTitlu()== "Inception")
        {
            assert(f.getGen() == "SF");
            assert(f.getAn() == 2010);
            assert(f.getActor() == "LeonardoDiCaprio");
        }
    r.modifica("Inception", "SF", 2013, "LeonardoDiCaprio");
    vector<Film> v2 = r.get_all();
    for(auto f: v2)
        if(f.getTitlu()== "Inception") {
            assert(f.getAn() == 2013);
        }
    r.sterge(0);
    assert(r.get_all().size() == 2);
    r.stergeFilm("Titanic");
    assert(r.get_all().size() == 1);
}