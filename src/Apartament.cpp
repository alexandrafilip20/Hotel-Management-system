#include "Apartament.h"
#include<iostream>
#include<fstream>
using namespace std;

Apartament::Apartament()
{
    nrApartament=0;
    ocupat=false;
}

Apartament::Apartament(int nrApartament, bool ocupat)
{
    this->nrApartament=nrApartament;
    this->ocupat=ocupat;
}

/*Apartament Apartament::operator=(Apartament aux)
{
    nrApartament=aux.nrApartament;
    ocupat=aux.ocupat;
    return *this;
}*/

Apartament::~Apartament()
{
    ocupat=false;
}

istream &operator>> (istream &i, Apartament &a)
{
    i>>a.nrApartament;
    return i;
}

ostream &operator<< (ostream &o, const Apartament &a)
{
    o<<a.nrApartament;
    return o;
}

bool Apartament::get_ocupat()
{
    return ocupat;
}

int Apartament::get_nrApartament()
{
    return nrApartament;
}

int Apartament::capacitate=4;
