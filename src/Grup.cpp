#include "Grup.h"
#include "NonPerioada.h";
Grup::Grup()
{

}

Grup::Grup(int nrParticipanti, int perioada, vector<Participant> participanti)
{
    this->id = nrGrup;
    nrGrup++;
    this->nrParticipanti = nrParticipanti;
    this->perioada = perioada;
    this->participanti = participanti;
}

Grup::~Grup()
{

}

istream &operator >> (istream &i, Grup &g)
{
    Participant p;
   //cout<<"Introdu numarul de participanti :";
    i>>g.nrParticipanti;
    for(int j = 0; j< g.nrParticipanti; j++)
    {
        i>>p;
        g.participanti.push_back(p);
    }
    //cout<<"Introdu tipul de sala cerut : ";
    i>> g.tipSala;
    try {
         //cout<<"Introdu perioada de sedere: ";
         i>> g.perioada;
         if(g.perioada < 1 || g.perioada > 10)
            throw(NonPerioada());
     }
        catch(exception e) { cout<<"Perioada de sedere trebuie sa fie de minim o noapte, respectiv maxim 10 nopti"<<endl;;

        }
    return i;
}

ostream &operator <<(ostream &o, const Grup &g)
{
    o<< g.nrParticipanti;
    o<<'\n';
    for(int i = 0; i < g.nrParticipanti; i++)
        o<< g.participanti[i];
    o<< "Perioada de sedere este de " << g.perioada << "zile" <<'\n';
    o<< "Tipul de sala este :" << g.tipSala << '\n';
   return o;
}

int Grup::get_nrCamere()
{
    return nrCamere;
}
int Grup::get_nrApartamente()
{
    return nrApartamente;
}

void Grup::set_nrCamere(int x)
{
    nrCamere=x;
}
void Grup::set_nrApartamente(int x)
{
    nrApartamente=x;
}
void Grup::set_sosire(int val)
{
    sosire=val;
}

int Grup::get_id()
{
    return id;
}
int Grup::get_nrParticipanti()
{
    return nrParticipanti;
}
vector<Participant> Grup::get_participanti()
{
    return participanti;
}
string Grup::get_tipSala()
{
    return tipSala;
}
int Grup::get_perioada()
{
    return perioada;
}
int Grup::get_sosire()
{
    return sosire;
}

void Grup::citire_CazariConfirmate(istream &i, Grup &g)
{
    Participant p;
    i>> g.nrParticipanti;
    for(int j= 0; j<g.nrParticipanti;j++)
        {
            i>>p;
            g.participanti.push_back(p);
        }
    i>> g.perioada;
    if(g.perioada < 1 || g.perioada > 10)
            throw invalid_argument("Perioada de sedere trebuie sa fie de minim o noapte, respectiv maxim 10 nopti");
    i>> g.sosire;
    i>> g.tipSala;

}

void Grup::afisare_CazariConfirmate(ostream &o, Grup &g)
{
    o<<"Numarul de participanti din grupe este de "<<g.nrParticipanti << " persoane"<<'\n';
    for(int i=0; i<g.nrParticipanti; i++)
        o<< g.participanti[i];
    o<< "Perioada de sedere este de " << g.perioada << " zile" <<'\n';
    o<< g.sosire << '\n';
    o<< "Tipul de sala este : "<<g.tipSala <<'\n';
}

int Grup:: nrGrup = 1;
