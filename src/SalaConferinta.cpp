#include "SalaConferinta.h"

SalaConferinta::SalaConferinta()
{
    proiector=false;
    ocupat=false;
    nrSala=0;
    nrMese=0;
    capacitate=0;
}

SalaConferinta::SalaConferinta(bool ocupat, string nume)
{
    this->ocupat=ocupat;
    this->nume=nume;
}

SalaConferinta::~SalaConferinta()
{
    proiector=false;
    ocupat=false;
    nrSala=0;
    nrMese=0;
    capacitate=0;
}

istream &operator>> (istream &i, SalaConferinta &s)
{
    cout<<"Introdu numele salii de conferinte: ";
    i>>s.nume;
    cout<<"Introdu tipul salii de conferinte: ";
    i>>s.tip;
    cout<<"Introdu capacitatea salii de conferinte: ";
    i>>s.capacitate;
    if(s.tip=="individual")
    {
        cout<<"Introdu numarul de mese: ";
        i>>s.nrMese;
        int x;
        for(int j=0;j<s.nrMese;j++)
        {
            cout<<"Introdu numarul de persoane de la o masa";
            i>>x;
            if(x<4 || x>8)
                throw invalid_argument("Masa trebuie sa aiba intre 4 si 8 locuri");
                //de facut alta exceptie
            else s.mese.push_back(x);
        }
    }
    else if(s.tip!="scena")
          throw invalid_argument("Nu exista o astfel de sala de conferinte");
    // de facut alta exceptie
    return i;


}
ostream &operator<<(ostream &o, const SalaConferinta &s)
{
    o<<"Numele salii de conferinte este: "<<s.nume<<'\n';
    o<<"Tipul salii de conferinte este: "<< s.tip<<'\n';
    o<<"Capacitatea salii este de "<<s.capacitate<<" de persoane" <<'\n';
    if(s.tip == "individual")
        {
            o<<"Sala are "<<s.nrMese <<" mese"<<'\n';
            o<<"Mesele au, in ordine, urmatoarele capacitati:" << '\n';
            for(int i = 0; i < s.nrMese; i++)
                o<<s.mese[i]<< " ";
        }
    return o;

}
int SalaConferinta::get_nrMese()
{
    return nrMese;
}
int SalaConferinta::get_capacitate()
{
    return capacitate;
}
bool SalaConferinta::get_ocupat()
{
    return ocupat;
}
int SalaConferinta::get_nrSala()
{
    return nrSala;
}
