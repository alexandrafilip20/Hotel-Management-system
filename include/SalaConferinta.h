#ifndef SALACONFERINTE_H
#define SALACONFERINTE_H
#include<iostream>
#include<string>
#include<vector>
using namespace std;

class SalaConferinta
{
    bool proiector;
    bool ocupat;
    int nrSala;
    int nrMese;
    int capacitate;
    vector<int> mese;
    string tip;
    string nume;
    public:
        SalaConferinta();
        SalaConferinta(bool ocupat, string nume);
        ~SalaConferinta();
        friend istream &operator>> (istream &i, SalaConferinta &s);
        friend ostream &operator<<(ostream &o, const SalaConferinta &s);
        int get_nrMese();
        int get_capacitate();
        bool get_ocupat();
        int get_nrSala();
};

#endif // SALACONFERINTE_H
