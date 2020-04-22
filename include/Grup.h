#ifndef GRUP_H
#define GRUP_H
#include "Participant.h"
#include<vector>
#include<string>
#include <exception>
class Grup
{
    static int nrGrup;
    int id;
    int nrParticipanti;
    int nrApartamente;
    int nrCamere;
    vector<Participant> participanti;
    int perioada;
    int sosire;
    int nrSala;
    string tipSala;
    public:
        Grup();
        Grup(int nrParticipanti, int perioada, vector<Participant> participanti );

        ~Grup();
        friend istream &operator >> (istream &i, Grup &g);
        friend ostream &operator <<(ostream &o, const Grup &g);

        int get_id();
        int get_nrParticipanti();
        vector<Participant> get_participanti();
        string get_tipSala();
        void set_sosire(int val);
        int get_nrCamere();
        int get_nrApartamente();
        void set_nrCamere(int x);
        void set_nrApartamente(int x);
        int get_perioada();
        int get_sosire();
        void citire_CazariConfirmate(istream &i, Grup &g);
        void afisare_CazariConfirmate(ostream &o, Grup &g);

};

#endif // GRUP_H
