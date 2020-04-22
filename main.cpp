#include <iostream>
#include "Incapere.h"
#include "Camera.h"
#include "Apartament.h"
#include "SalaConferinta.h"
#include "Hotel.h"
#include "Participant.h"
#include "Grup.h"
#include<conio.h>
using namespace std;

int zi=1;

void adauga_cerere(ostream &o)
{
    Grup g;
    cin >> g;
    o<< g;
}

void anulare_cerere()
{
    ifstream in1("detalii_hotel");
    Hotel h;
    in1>> h;
    int x, nr = 0;
    Grup g;
    vector<Grup> gr;

    ifstream in("cereri_cazare");

    cout << "Cererile de cazare sunt:" << '\n';

    while(in >> g)
    {
        nr++;
        gr.push_back(g);
        cout << "Cererea cu numarul " << nr << " :" << '\n';
        cout << g << '\n';
        g = Grup();
    }

    in.close();

    cout << "Alegeti cererea pe care doriti sa o anulati:" << '\n';

    cin >> x;

    gr.erase(gr.begin() + (x - 1));
    nr--;
    h.set_nrCamere(h.get_nrCamere()+gr[x].get_nrCamere());
    h.set_nrApartamente(h.get_nrApartamente()+gr[x].get_nrApartamente());

    ofstream out("show_cereri_cazare");
    cout << "Cererile ramase sunt:" << '\n';

    for(int i = 1; i <=gr.size(); i++)
    {
        out << gr[i];
        cout << "Cererea cu numarul "<< i << ":" << '\n';
        cout << gr[i];
    }

    out.close();
}
void verificare_cazare(ostream &out)
{
    ifstream in1("detalii_hotel");
    Hotel h;
    in1>> h;
    ifstream in2("cereri_cazare");


    Grup g;
    int nr = 0;
    vector<Grup> gr;
    vector<Grup> cazari;
    //vector<Camera> C;
    //vector<Apartament> A;
    //vector<SalaConferinte> SC;
    int x;
    int cazariConfirmate = 0;


    while(in2 >> g)
    {
        nr++;
        gr.push_back(g);
        g= Grup();
    }

    cout << "Cererile de cazare sunt:" << '\n';

    for(int i = 0; i <gr.size(); i++)
    {
        cout << "Cererea cu numarul " << i << '\n';
        cout << gr[i];
        g=gr[i];
        cout<<endl;
        int ok=1;
       for(int j = i; j <= i + g.get_perioada() && ok == 1; j++)
            {
                int z=g.get_perioada();
                int a=g.get_nrParticipanti();
                int b=a/4, c=a%4;
                if(h.get_nrApartamente() >=b)
                {
                    h.set_nrApartamente(h.get_nrApartamente()-b);

                    if(h.get_nrCamere() >= (c+1)/2)
                        {h.set_nrCamere(h.get_nrCamere()-c);
                        cout<<"Participantii vor ocupa "<< b << " apartamente si "<< (c+1)/2 <<" camere"<<endl; ok=0;
                        cout<<"Perioada de cazare incepe la ziua "<< zi<< " si se incheie la ziua " << zi+z;

                        zi=zi+z;
                        gr[i].set_nrApartamente(b);
                        gr[i].set_nrCamere((c+1)/2);}
                    else
                        j++;
                }
                else if(h.get_nrCamere() >= (a+1)/2)
                {
                    h.set_nrCamere(h.get_nrCamere()-(a+1)/2);
                    cout<<"Participantii vor ocupa "<< (a+1)/2<< " camere";
                     cout<<"Perioada de cazare incepe la ziua "<< zi<< " si se incheie la ziua " << zi+z;
                     zi=zi+z;
                    ok=0;
                    gr[i].set_nrApartamente(0);
                    gr[i].set_nrCamere((a+1)/2);
                }
                else
                    j++;

            }
            cout<<endl;
        }
        cout<<endl;


}
int main()
    {
        ifstream in1("detalii_hotel");
        Hotel h;
        in1>> h;
        int rol;

        cout << "Pentru a efectua o cerere de cazare, introduceti 1." << '\n';

        cout << "Pentru a administra hotelul, introduceti 2." << '\n';
        cout<<endl;

        cin >> rol;

        switch(rol)
        {
        case 1:
        {
            ofstream out("cereri_cazare");
            adauga_cerere(out);
            out.close();
        }
        break;

        case 2:
        {
            int y;
            cout << "Pentru a vizualiza cererile, introduceti 1." << '\n';
            cout << "Pentru a anula o cerere, introduceti 2." << '\n';
            cout << "Pentru a opera o cerere si a o confirma, introduceti 3." << '\n';
            cout<<endl;

            cin >> y;
            cout<<endl;
            switch(y)
            {
            case 1:
            {
                ifstream in("cereri_cazare",ofstream::app);
                Grup g;
                while((in >> g).good())
                {
                    //in >> G;
                    cout << g ;
                    cout<<endl;
                    g = Grup();
                }

            }
            break;
            case 2:
                anulare_cerere();
                break;

            case 3:
            {
                cout << "Hotelul are capacitatea de "<< h.get_capacitateMaxima() << " persoane\n";
                cout << "Hotelul are " << h.get_nrIncaperi() << " incaperi: camere de 2 persoane, 4 persoane si sali de conferinta\n";
                cout << "Hotelul are " << h.get_nrCamere() << " camere de persoane\n";
                cout << "Hotelul are " << h.get_nrApartamente() << " apartamente de 4 persoane\n";
                cout << "Hotelul are " << h.get_nrSaliConferinta()  << " sali de cdonferinta\n";
                cout << "Restaurantul are capacitatea de " << h.get_capacitateRestaurant() <<  " persoane\n";
                cout << '\n';

                ofstream out3("cazari_confirmate", ofstream::app);
                verificare_cazare(out3);
                out3.close();
                break;
            }

            default:
                cout << "Optiunea introdusa nu este valida" << '\n';
            }
        }

        break;
        default:
            cout << "Optiunea introdusa nu este valida" << '\n';
            break;

        }
        return 0;
    }
