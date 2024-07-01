#include "Tests/teste.h"
#include "Ui.h"
#include <iostream>
#include <QApplication>
#include "FilmeGUI.h"
#include "UserModeGui.h"
#include "Login.h"

void run_all_tests()
{
    test_service_store();
    test_service_modifica();
    test_service_sterge();
    test_service_sortare_dupa_titlu();
    test_service_sortare_dupa_actor();
    test_service_sortare_dupa_an_si_gen();
    test_service_filtrare_an();
    test_service_filtrare_titlu();
    test_getters();
    test_setters();
    test_cautare();

    test_cos_add();
    test_cos_goleste();
    test_cos_genereaza_aleatoriu();
    test_cos_sterge();
    service_genereaza_aleatoriu();
    service_goleste_cos();
    service_get_cos();

    //test_genereaza_raport();

    test_MyVector();
    test_MyVector_add();
    test_undo();
    test_scrieFisier();
    test_citesteFisier();

    test_RepoDictionar();
}
int main(int argc, char *argv[]){
    run_all_tests();
    std::cout<<"Congrats!";
    RepoFisiere r{"/Users/vasilegeorge/CLionProjects/Lab6OOP/stocare.txt"};
    QApplication a(argc, argv);
    Validator v;
    Cos c;
    Service s{r, v, c};
    CosGUI cos{s};
    FilmeGUI admin{s, cos};
    UserModeGui user{s, cos};
    Login guii{admin, user};
    guii.show();
    //Ui ui{s};
    //ui.run();
    return a.exec();
}
