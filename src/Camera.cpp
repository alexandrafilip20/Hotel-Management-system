#include "Camera.h"
#include<iostream>
#include<fstream>
using namespace std;

Camera::Camera()
{
    nrCamera=0;
    ocupat=false;
}

/*Camera Camera::operator=(Camera aux)
{
    nrCamera=aux.nrCamera;
    ocupat=aux.ocupat;
    return *this;
}*/

Camera::Camera(int nrCamera, bool ocupat)
{
    this->nrCamera=nrCamera;
    this->ocupat=ocupat;
}

Camera::~Camera()
{
    ocupat=false;
}

istream &operator>> (istream &i, Camera &c)
{
    i>>c.nrCamera;
    return i;
}

ostream &operator<< (ostream &o, const Camera &c)
{
    o<<c.nrCamera;
    return o;
}

bool Camera::get_ocupat()
{
    return ocupat;
}

int Camera::get_nrCamera()
{
    return nrCamera;
}

int Camera::capacitate=2;
