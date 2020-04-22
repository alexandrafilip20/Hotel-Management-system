#include "Hotel.h"

Hotel::Hotel()
{
    nrIncaperi=0;
    capacitateRestaurant=0;
    capacitateMaxima=0;
    nrCamere=0;
    nrApartamente=0;
    nrSaliConferinta=0;
}

Hotel::Hotel(int nrIncaperi, vector<Incapere> incaperi, int capacitateRestaurant, int capacitateMaxima)
{
    this->nrIncaperi=nrIncaperi;
    this->incaperi=incaperi;
    this->capacitateRestaurant=capacitateRestaurant;
    this->capacitateMaxima=capacitateMaxima;
}

//Hotel::Hotel(const Hotel &aux):Incapere(aux), Camera(aux), Apartament(aux)




Hotel::~Hotel()
{
    nrIncaperi=0;
    capacitateRestaurant=0;
    capacitateMaxima=0;
    nrCamere=0;
    nrApartamente=0;
    nrSaliConferinta=0;
}

istream &operator>> (istream &i, Hotel &h)
{
    //cout<<"Introdu numarul de incaperi al hotelului: ";
    i>>h.nrIncaperi;
    //cout<<"Introdu numarul de camere al hotelului: ";
    i>>h.nrCamere;
    int x;
    for(int j=1;j<=h.nrCamere;j++)
    {

        h.camere.push_back(Camera(j,false));
    }
  //  cout<<"Introdu numarul de apartamente al hotelului: ";
    i>>h.nrApartamente;
    for(int j=1;j<=h.nrApartamente;j++)
    {

        h.apartamente.push_back(Apartament(j,false));
    }
   // cout<<"Introdu numarul salilor de conferinta: ";
    i>>h.nrSaliConferinta;
    //cout<<"Introdu capacitatea restaurantului: "
    i>>h.capacitateRestaurant;
    h.capacitateMaxima= h.nrCamere*2 + h.nrApartamente*4;
    return i;
}

ostream &operator<< (ostream &o, const Hotel &h)
{

    o<< "Nr de incaperi ale hotelului este de: " << h.nrIncaperi << '\n';
    o<< "Capacitatea maxima a hotelului este de: " << h.capacitateMaxima << '\n';
    o<< "Restaurantul are capacitatea de " << h.capacitateRestaurant << " persoane" << '\n';
    o<< "Hotelul are "<<h.nrCamere<< " camere" << '\n';
    o<< "Hotelul are "<<h.nrApartamente<< " apartamente"<< '\n';
    o<< "Hotelul are "<<h.nrSaliConferinta << " sali de conferinta"<< '\n';
    return o;
}

void Hotel::set_nrCamere(int x)
 {
     nrCamere=x;
 }

void Hotel::set_nrApartamente(int x)
{
    nrApartamente=x;
}

int Hotel::get_nrIncaperi()
    {
        return nrIncaperi;
    }
int Hotel::get_capacitateMaxima()
    {
        return capacitateMaxima;
    }
int Hotel::get_capacitateRestaurant()
    {
        return capacitateRestaurant;
    }
int Hotel::get_nrCamere()
    {
        return nrCamere;
    }
vector<Camera> Hotel::get_camere()
    {
        return camere;
    }
int Hotel::get_nrApartamente()
    {
        return nrApartamente;
    }
vector<Apartament> Hotel::getApartamente()
    {
        return apartamente;
    }
int Hotel::get_nrSaliConferinta()
    {
        return nrSaliConferinta;
    }
vector<SalaConferinta> Hotel::getSaliConferinta()
    {
        return saliConferinta;
    }
