#ifndef CAMERA_H
#define CAMERA_H
#include "Incapere.h"
#include<iostream>
#include<fstream>
using namespace std;

class Camera : public Incapere
{
    int nrCamera;
    bool ocupat;
    static int capacitate;
    public:
        Camera();
        Camera(int nrCamera, bool ocupat);
        ~Camera();
        //Camera operator=(Camera aux);
        friend istream &operator>> (istream &i, Camera &c);
        friend ostream &operator<< (ostream &i, const Camera &c);
        bool get_ocupat();
        int get_nrCamera();
};

#endif // CAMERA_H
