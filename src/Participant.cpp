#include "Participant.h"

Participant::Participant()
{

}

Participant::Participant(string nume, int camera)
{
    this->nume=nume;
    this->camera=camera;
    this->id=nrParticipanti;
    nrParticipanti++;
}

Participant::Participant(string nume)
{
    this->nume=nume;
    this->id=nrParticipanti;
    nrParticipanti++;
}

Participant::~Participant()
{

}

istream &operator>>(istream &i, Participant &p)
{
    //cout<<"Introdu numele participantului: ";
    i>>p.nume;
   // cout<<"Participantul doreste sa serveasca micul dejun la restaurant ? ";
    string x;
    i>>x;
    if(x=="da" || x=="Da" || x=="DA" )
        p.micDejun=true;
    else if(x=="nu" || x=="NU" || x=="Nu" )
        p.micDejun=false;
   // else  throw invalid_argument("Error! Must specifiy if the person wants breakfast or not");
    // de facut exceptie aici
}

ostream &operator<<(ostream &o, const Participant &p)
{
    o<<"Numele participantului este "<<p.nume<<'\n';
    if(p.micDejun == true)
          o<< "Participantul doreste mic dejun la restaurant" << '\n';
    else o<< "Participantul doreste mic dejun in camera" << '\n';
    return o;
}

int Participant::nrParticipanti=1;
