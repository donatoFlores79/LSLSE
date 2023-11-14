#include "SocioClub.h"

using namespace std;

template<class T>
class LSLSE;

template<class T>
class node{
private:
    T data;
    node<T>* sig;
public:
    node():sig(nullptr){};

    void imprimir() const;
    friend class LSLSE<T>;
};

template<class T>
class LSLSE{
private:
    node<T>* lista;
public:
    LSLSE():lista(nullptr){};
    bool vacia()const;
    node<T>* ultimo()const;
    node<T>* primero()const;
    node<T>* anterior(node<T>* pos)const;
    void insertar(node<T>* pos, T elem);
    void insertar(T elem);
    node<T>* buscar(string&, string&) const;
    bool eliminar(node<T>* pos);
    void imprimir()const;
    int numSocios()const;
};

template <class T>
void node<T>::imprimir() const{
    cout<< data;
}
template<class T>
void LSLSE<T>::imprimir()const{
    node<T>* aux=lista;
    while(aux!=nullptr){
        std::cout<<aux->data<<"-> ";
        aux=aux->sig;
    }
    cout<< "\n\n";
}

template <class T>
node<T>* LSLSE<T>::buscar(string& nombre, string& domicilio) const{
    node<T>* actual = lista;
    while(actual != nullptr){
        if(actual->data.getNombre() == nombre && actual->data.getDomicilio() == domicilio)
            return actual;
        actual = actual->sig;
    }

    return nullptr;
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

template <class T>
void LSLSE<T>::insertar(T elem){
    node<T>* aux = new node<T>;
    aux->data = elem;

    node<T>* actual = lista;
    node<T>* anterior = nullptr;
    while(actual != nullptr){
        if(aux->data < actual->data)
            break;
        anterior = actual;
        actual = actual->sig;
    }

    if(anterior == nullptr){
        aux->sig = actual;
        lista = aux;
    }
    else{
        aux->sig = actual;
        anterior->sig = aux;
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

template <class T>
int LSLSE<T>::numSocios() const{
    int contador = 0;

    node<T>* actual = lista;
    while(actual != nullptr){
        contador++;
        actual = actual->sig;
    }

    return contador;
}

int main()
{
    LSLSE<SocioClub> milista;
    int opcion = 1;

    while(opcion != 6){
        cout<< "1.Registrar\n";
        cout<< "2.Dar de baja\n";
        cout<< "3.Generar reporte\n";
        cout<< "4.Buscar\n";
        cout<< "5.Total de socios\n";
        cout<< "6.Salir\n";
        cout<< " --->";
        cin>> opcion;

        switch(opcion){
        case 1:
            {
            SocioClub c;
            cin>> c;
            milista.insertar(c);

            cout<< "\n\n";
            break;
            }
        case 2:
            {
            string nombre, domicilio;
            cout<< "Nombre del socio a dar de baja:";
            cin>> nombre;
            cout<< "Domicilio del socio a dar de baja:";
            cin>> domicilio;

            node<SocioClub>* buscado = milista.buscar(nombre, domicilio);

            if(!milista.eliminar(buscado))
                cout<< "No se encontro el socio a eliminar";

            cout<< "\n\n";
            break;
            }
        case 3:
            milista.imprimir();
            break;
        case 4:
            {
            string nombre, domicilio;
            cout<< "Nombre del socio buscado:";
            cin>> nombre;
            cout<< "Domicilio del socio buscado:";
            cin>> domicilio;

            node<SocioClub>* buscado = milista.buscar(nombre, domicilio);
            if(buscado == nullptr)
                cout<< "No se encontro el socio buscado";
            else
                buscado->imprimir();

            cout<< "\n\n";

            break;
            }
        case 5:
            cout<< "Hay " << milista.numSocios() << " socios en el club\n\n";
        }
    }
    return 0;
}
