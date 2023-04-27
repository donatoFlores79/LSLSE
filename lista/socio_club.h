#ifndef SOCIO_CLUB_H_INCLUDED
#define SOCIO_CLUB_H_INCLUDED

#include <iostream>
#include <string>

class SocioClub{
private:
    int numeroSocio;
    std::string nombreSocio;
    std::string domicilio;
    int anioIngreso;
public:
    int getNumeroSocio() const;
    std::string getNombreSocio() const;
    std::string getDomicilio() const;
    int getAnioIngreso() const;

    void setNumeroSocio(const int);
    void setNombreSocio(const std::string);
    void setDomicilio(const std::string);
    void setAnioIngreso(const int);

    SocioClub& operator = (const SocioClub&);
    bool operator == (const SocioClub&);
    bool operator > (const SocioClub&);

    friend std::ostream& operator << (std::ostream&, const SocioClub&);
    friend std::istream& operator >> (std::istream&, SocioClub&);
};

#endif // SOCIO_CLUB_H_INCLUDED
