#ifndef HOTEL_H
#define HOTEL_H
#include "Incapere.h"
#include "Camera.h"
#include "Apartament.h"
#include "SalaConferinta.h"

class Hotel
{
    int capacitateMaxima;
    int capacitateRestaurant;
    int nrIncaperi;
    vector<Incapere> incaperi;
    int nrCamere;
    vector<Camera> camere;
    int nrApartamente;
    vector<Apartament> apartamente;
    int nrSaliConferinta;
    vector<SalaConferinta> saliConferinta;
    public:
        Hotel();
        Hotel(int nrIncaperi, vector<Incapere> incaperi, int capacitateRestaurant, int capacitateMaxima);
        ~Hotel();
        //Hotel(const Hotel&);
        //virtual int operator=(const Incapere&){return 0;}
        friend istream &operator>> (istream &i, Hotel &h);
        friend ostream &operator<< (ostream &o, const Hotel &h);

        int get_nrIncaperi();
        int get_capacitateMaxima();
        int get_capacitateRestaurant();
        int get_nrCamere();
        void set_nrCamere(int x);
        void set_nrApartamente(int x);
        vector<Camera> get_camere();
        int get_nrApartamente();
        vector<Apartament> getApartamente();
        int get_nrSaliConferinta();
        vector<SalaConferinta> getSaliConferinta();

};

#endif // HOTEL_H
