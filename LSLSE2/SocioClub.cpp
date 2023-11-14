#include "SocioClub.h"

using namespace std;

SocioClub::SocioClub(){};

string& SocioClub::getNombre(){
    return nombre;
}

string& SocioClub::getDomicilio(){
    return domicilio;
}
bool SocioClub::operator == (int num){
    return numero == num;
}
bool SocioClub::operator < (SocioClub& s){
    return numero < s.numero;
}

ostream& operator << (ostream& o, const SocioClub& s){
    o<< s.nombre << "|" << s.domicilio << "|" << s.numero << "|" << s.anio;
    return o;
}

istream& operator >> (istream& i, SocioClub& s){
    cout<< "Nombre:";
    i>> s.nombre;
    cout<< "Domicilio:";
    i>> s.domicilio;
    cout<< "Numero de socio:";
    i>> s.numero;
    cout<< "Anio de ingreso:";
    i>> s.anio;

    return i;
}
