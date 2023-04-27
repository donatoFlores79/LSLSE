#include "socio_club.h"

int SocioClub::getNumeroSocio() const{
    return numeroSocio;
}

std::string SocioClub::getNombreSocio() const{
    return nombreSocio;
}

std::string SocioClub::getDomicilio() const{
    return domicilio;
}

int SocioClub::getAnioIngreso() const{
    return anioIngreso;
}

void SocioClub::setNumeroSocio(const int i){
    numeroSocio = i;
}

void SocioClub::setNombreSocio(const std::string s){
    nombreSocio = s;
}

void SocioClub::setDomicilio(const std::string s){
    domicilio = s;
}

void SocioClub::setAnioIngreso(const int i){
    anioIngreso = i;
}

std::ostream& operator << (std::ostream& o, const SocioClub& s){
    o << s.nombreSocio << "|" << s.anioIngreso << "|" << s.domicilio << "|" << s.numeroSocio;
    return o;
}

std::istream& operator >> (std::istream& I, SocioClub& x){
    std::cout<< "Nombre: ";
    I>> x.nombreSocio;
    std::cout<< "Anio de ingreso: ";
    I>> x.anioIngreso;
    std::cout<< "Domicilio: ";
    I>> x.domicilio;
    std::cout<< "Numero de socio: ";
    I>> x.numeroSocio;
    return I;
}

SocioClub& SocioClub::operator = (const SocioClub& s){
    numeroSocio = s.numeroSocio;
    nombreSocio = s.nombreSocio;
    anioIngreso = s.anioIngreso;
    domicilio = s.domicilio;

    return *this;
}

bool SocioClub::operator == (const SocioClub& s){
    if(nombreSocio != s.nombreSocio){
        return false;
    }
    else if(domicilio != s.domicilio){
        return false;
    }
    return true;
}

bool SocioClub::operator > (const SocioClub& s){
    if(numeroSocio > s.numeroSocio){
        return true;
    }
    return false;
}
