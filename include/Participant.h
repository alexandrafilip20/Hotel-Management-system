#ifndef PARTICIPANT_H
#define PARTICIPANT_H
#include<string>
#include<iostream>
using namespace std;

class Participant
{
    static int nrParticipanti;
    int id;
    string nume;
    int camera;
    bool micDejun;
    public:
        Participant();
        Participant(string nume, int camera);
        Participant(string nume);
        ~Participant();
        friend istream &operator>>(istream &i, Participant &p);
        friend ostream &operator<<(ostream &o, const Participant &p);

};

#endif // PARTICIPANT_H
