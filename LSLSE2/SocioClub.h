#ifndef SOCIOCLUB_H_INCLUDED
#define SOCIOCLUB_H_INCLUDED

#include "iostream"
#include <string>

class SocioClub{
private:
    std::string nombre, domicilio;
    int numero, anio;
public:
    SocioClub();

    std::string& getNombre();
    std::string& getDomicilio();

    bool operator == (int);
    bool operator < (SocioClub&);

    friend std::istream& operator>>(std::istream&, SocioClub&);
    friend std::ostream& operator<<(std::ostream&, const SocioClub&);
};

#endif // SOCIOCLUB_H_INCLUDED
