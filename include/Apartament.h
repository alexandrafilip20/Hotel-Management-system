#ifndef APARTAMENT_H
#define APARTAMENT_H
#include "Incapere.h"
#include<iostream>
#include<fstream>
using namespace std;

class Apartament:public Incapere
{
    static int capacitate;
    int nrApartament;
    bool ocupat;
    public:
        Apartament();
        Apartament(int nrApartament, bool ocupat);
        ~Apartament();
        //Apartament operator=(Apartament aux);
        friend istream &operator>> (istream &i, Apartament &a);
        friend ostream &operator<<(ostream &o, const Apartament &a);
        bool get_ocupat();
        int get_nrApartament();

};

#endif // APARTAMENT_H
