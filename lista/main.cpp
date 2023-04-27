#include <iostream>
#include "socio_club.h"

template<class T>
class LSLSE;

template<class T>
class node{
private:
    T data;
    node<T>* sig;
public:
    node():sig(nullptr){};
    friend class LSLSE<T>;
};

template<class T>
class LSLSE{
private:
    node<T>* lista;
public:
    LSLSE():lista(nullptr){};
    ~LSLSE();
    bool vacia()const;
    node<T>* ultimo()const;
    node<T>* primero()const;
    node<T>* anterior(node<T>* pos)const;
    node<T>* localiza(T elem);
    void insertar(node<T>* pos, T elem);
    bool eliminar(node<T>* pos);
    void imprimir()const;
    void imprime1(node<T>*) const;
    bool esRepetido(int num);
    void ordena();
};

template<class T>
LSLSE<T>::~LSLSE(){
    node<T>* aux = lista;
    while (aux != nullptr) {
            node<T>* sig = aux->sig;
            delete aux;
            aux = nullptr;
            aux = sig;
        }
}

template<class T>
void LSLSE<T>::imprimir()const{
    node<T>* aux=lista;
    while(aux!=nullptr){
        std::cout<< aux->data << "-> ";
        aux=aux->sig;
    }
}

template<class T>
bool LSLSE<T>::eliminar(node<T>* pos){
    if(vacia() || pos==nullptr){
        return false;
    }
    if(pos==lista){
        lista=lista->sig;
    }
    else{
        anterior(pos)->sig=pos->sig;
    }
    delete pos;
    return true;
}

template<class T>
void LSLSE<T>::insertar(node<T>* pos, T elem){
    node<T>* aux= new node<T>;
    aux->data=elem;
    if(pos==nullptr){
        aux->sig=lista;
        lista=aux;
    }
    else{
        aux->sig=pos->sig;
        pos->sig=aux;
    }
}

template<class T>
node<T>* LSLSE<T>::anterior(node<T>* pos)const{
    if(vacia() || pos==nullptr){
        return nullptr;
    }
    node<T>* aux=lista;
    while(aux!=nullptr && aux->sig!=pos){
        aux=aux->sig;
    }
    return aux;
}

template<class T>
node<T>* LSLSE<T>::localiza(T elem){
    node<T>* aux = lista;
    while(aux != nullptr){
        if(aux -> data == elem)
            return aux;
        aux = aux->sig;
    }
    return nullptr;
}

template<class T>
node<T>* LSLSE<T>::primero()const{
    if(vacia()){
        return nullptr;
    }
    return lista;
}


template<class T>
node<T>* LSLSE<T>::ultimo()const{
    if(vacia()){
        return nullptr;
    }
    node<T>* aux=lista;
    while(aux->sig!=nullptr){
        aux=aux->sig;
    }
    return aux;
}

template<class T>
bool LSLSE<T>::vacia()const{
    if(lista==nullptr)
        return true;
    return false;
}

template<class T>
bool LSLSE<T>::esRepetido(int num){
    node<T>* aux = lista;
    while(aux!=nullptr){
        if(aux-> data.getNumeroSocio() == num){
            return true;
        }
        aux=aux->sig;
    }
    return false;
}

template<class T>
void LSLSE<T>::ordena(){
    if (vacia() || (lista->sig) == nullptr) return;
    bool cambio = true;
    while (cambio) {
        cambio = false;
        node<T>* curr = lista;
        node<T>* prev = nullptr;
        while ((curr->sig) != nullptr) {
            if (curr->data > curr->sig->data) {
                node<T>* temp = curr->sig;
                curr->sig = temp->sig;
                temp->sig = curr;
                if (prev) prev->sig = temp;
                else lista = temp;
                prev = temp;
                cambio = true;
            } else {
                prev = curr;
                curr = curr->sig;
            }
        }
    }
}

template<class T>
void LSLSE<T>::imprime1(node<T>* pos) const{
    std::cout<< pos->data;
}

int main()
{
    LSLSE<SocioClub> milista;
    SocioClub socio;
    int opc,numSocios = 0;
    do{
        std::cout<< "Que deseas realizar?\n";
        std::cout<< "1.Registrar un nuevo socio\n";
        std::cout<< "2.Dar de baja un socio\n";
        std::cout<< "3.Generar un reporte con datos de todos los socios\n";
        std::cout<< "4.Buscar a un socio\n";
        std::cout<< "5.Mostrar numero de socios registrados\n";
        std::cout<< "6.Salir\n";

        std::cin>> opc;

        if (opc==1){
            std::cout<<"\n\n Registrando socio..."<< std::endl;

            std::cin>>socio;
            std::cout<< "\n\n";
            int num = socio.getNumeroSocio();
            if(milista.esRepetido(num)){
                std::cout << "El numero de socio ya esta registrado\n\n\n";
            }
            else{
                milista.insertar(milista.ultimo(), socio);
                numSocios++;
            }
            milista.ordena();
        }
        else if(opc==2){
            if(milista.vacia())
                std::cout<< "La lista esta vacia\n\n";
            else{
                std::string nombre, domicilio;
                SocioClub socio2;

                std::cout<< "\n\nIngresa los datos del socio a dar de baja:\n";
                std::cout<< "Nombre:"; std::cin>> nombre;
                std::cout<< "Domicilio:"; std::cin>> domicilio;

                socio2.setNombreSocio(nombre);
                socio2.setDomicilio(domicilio);

                node<SocioClub>* ptr = milista.localiza(socio2);
                if(ptr == nullptr)
                    std::cout<< "\nNo se encontro el socio";
                else{
                    milista.eliminar(ptr);
                    numSocios--;
                }

                std::cout<< "\n\n";
            }
        }

        else if(opc==3){
            if(milista.vacia())
                std::cout<< "\nLa lista esta vacia\n\n";
            else{
                std::cout<< "\n\nGenerando reporte...\n\n";
                milista.imprimir();
                std::cout<< std::endl << std::endl;
            }
        }

        else if(opc==4){
            std::string nombre, domicilio;
            SocioClub socio2;

            std::cout<< "\n\nIngresa los datos del socio a buscar:\n";
            std::cout<< "Nombre:"; std::cin>> nombre;
            std::cout<< "Domicilio:"; std::cin>> domicilio;

            socio2.setNombreSocio(nombre);
            socio2.setDomicilio(domicilio);


            node<SocioClub>* ptr = milista.localiza(socio2);
            if(ptr != nullptr){
                std::cout<< "\n--- ";
                milista.imprime1(ptr);
                std::cout<< " ---\n";
            }
            else{
                std::cout<< "\nNo se encontro el socio";
            }
            std::cout<< "\n\n";
        }
        else if(opc==5){
            std::cout<< "\n\n\nNumero de socios:\n";
            std::cout<< numSocios << "\n\n\n";
        }
        else if(opc!=6)
            std::cout<< "\nPor favor ingresa un numero del 1 al 5\n\n";
    }while(opc!=6);
    return 0;
}
