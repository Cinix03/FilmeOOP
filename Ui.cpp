//
// Created by Vasile George on 30.03.2024.
//

#include "Ui.h"
#include <iostream>
#include <fstream>
#include <unordered_map>
#include "ClasaNoua.h"
using std::string;
using std::cout;
using std::cin;
using std::unordered_map;


Ui::Ui(Service& service): service{service} {};

void Ui::run() {
    while (true) {
        cout << "1. Adauga film" << std::endl;
        cout << "2. Afiseaza filme" << std::endl;
        cout << "3. Sterge film" << std::endl;
        cout << "4. Modifica film" << std::endl;
        cout <<"5. Cauta film dupa titlu\n";
        cout<<"6. Filtrare dupa titlu\n";
        cout<<"7. Filtrare dupa an\n";
        cout<<"8. Sortare dupa titlu\n";
        cout<<"9. Sortare dupa actor\n";
        cout<<"10. Adauga film in cos\n";
        cout<<"11. Afiseaza cos\n";
        cout<<"12. Goleste cos\n";
        cout<<"13. Genereaza aleatoriu\n";
        cout<<"14. Genereaza raport\n";
        cout<<"15. Export in fisier csv\n";
        cout<<"16. Salvare filme in fisier\n";
        cout<<"17. Undo\n";
        cout << "0. Exit" << std::endl;
        int cmd;
        cin >> cmd;
        if (cmd == 0) {
            break;
        }
        if (cmd == 1) {
            string titlu, gen, actor;
            int an;
            cout << "Titlu: ";
            cin >> titlu;
            getchar();
            cout << "Gen: ";
            cin >> gen;
            getchar();
            cout << "An: ";
            cin >> an;
            getchar();
            cout << "Actor: ";
            cin >> actor;
            getchar();
            this->service.store(titlu, gen, an, actor);
        }
        if (cmd == 2) {
            cout<<"Titlu Gen An Actor\n";
            for (auto film: this->service.get_all())
                cout<<film;
        }
        if (cmd == 3) {
            int nr;
            cout << "Id: ";
            cin >> nr;
            getchar();
            this->service.sterge(nr);
        }
        if (cmd == 4) {
            string titlu, gen, actor;
            int an;
            cout << "Titlu: ";
            cin >> titlu;
            getchar();
            cout << "Gen: ";
            cin >> gen;
            getchar();
            cout << "An: ";
            cin >> an;
            getchar();
            cout << "Actor: ";
            cin >> actor;
            getchar();
            this->service.modifica(titlu, gen, an, actor);
        }
        if(cmd == 5){
            string titlu;
            cout<<"Titlu: ";
            cin>>titlu;
            getchar();
            cout<<"Titlu Gen An Actor\n";
            for(auto film: this->service.cautare(titlu))
                cout<<film;
        }
        if(cmd==6){
            string titlu;
            cout<<"Titlu: ";
            cin>>titlu;
            getchar();
            cout<<"Titlu Gen An Actor\n";
            for(auto film: this->service.filtrare_titlu(titlu))
                cout<<film;
        }
        if(cmd==7){
            int an;
            cout<<"An: ";
            cin>>an;
            getchar();
            cout<<"Titlu Gen An Actor\n";
            for(auto film: this->service.filtrare_an(an))
                cout<<film;
        }

        if(cmd==8){
            cout<<"Titlu Gen An Actor\n";
            for(auto film: this->service.sortare_dupa_titlu())
                cout<<film;
        }
        if(cmd==9){
            cout<<"Titlu Gen An Actor\n";
            for(auto film: this->service.sortare_dupa_actor())
                cout<<film;
        }
        if(cmd==10){
            string titlu;
            cout<<"Titlu: ";
            cin>>titlu;
            getchar();
            this->service.adauga_in_cos(titlu);
        }
        if(cmd==11){
            cout<<"Titlu Gen An Actor\n";
            for(auto film: this->service.get_cos())
                cout<<film;
        }
        if(cmd==12){
            this->service.goleste_cos();
        }
        if(cmd==13){
            int n;
            cout<<"Numar: ";
            cin>>n;
            getchar();
            this->service.genereaza_aleatoriu(n);
        }
        if(cmd==14)
        {
            //unordered_map<string, FilmCount> rez= this->service.genereaza_raport();
            //for(auto i: rez)
              //  cout<<i.first<<" "<<i.second.getCount()<<"\n";
        }
        if(cmd==15)
        {
            //export in fisier csv
            string filename;
            cout<<"Numele fisierului: ";
            cin>>filename;
            filename=filename+".csv";
            std::ofstream fout(filename);
            fout<<"Titlu,Gen,An,Actor\n";
            for(auto &film : this->service.get_all())
                fout<<film.getTitlu()<<","<<film.getGen()<<","<<film.getAn()<<","<<film.getActor()<<"\n";
        }
        if(cmd==16)
        {
            string filename;
            cout<<"Numele fisierului: ";
            cin>>filename;
            filename=filename+".csv";
            std::ofstream fout(filename);
            fout<<"Titlu,Gen,An,Actor\n";
            for(auto film : this->service.get_all())
                fout<<film.getTitlu()<<","<<film.getGen()<<","<<film.getAn()<<","<<film.getActor()<<"\n";

        }
        if(cmd==17)
            this->service.undo();
    }
}