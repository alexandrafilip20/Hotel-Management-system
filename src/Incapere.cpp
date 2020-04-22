#include "Incapere.h"

Incapere::Incapere ()
{
    this->id=idIncapereGenerator;
    idIncapereGenerator++;
}

/*Incapere::Incapere(const Incapere &aux):id(aux.id)
{

}*/

int Incapere::get_id()
{
    return id;
}

int Incapere::idIncapereGenerator=1;
