#include <cstring>
#include <iostream>
#include "Comidas.h"
using namespace std;
int Comidas::getIdComida(){
    return _idComida;
}

float Comidas::getPrecio(){
    return _precio;
}

bool Comidas::getDisponible(){
    return _disponible;
}

void Comidas::setIdComida(int idComida){
    _idComida = idComida;
}

void Comidas::setPrecio(float precio){
    _precio = precio;
}

void Comidas::setDisponible(bool disponible){
    _disponible = disponible;
}

void Comidas::cargar(int id){
    _idComida = id;
    cout<<"INGRESE PRECIO DE LA COMIDA: "<<endl;
    cin>>_precio;
    _disponible = true;

}

void Comidas::mostrar(){
    cout<<"CODIGO IDENTIFICADOR DE COMIDA: "<<_idComida<<endl;
    cout<<"PRECIO: "<<_precio<<endl;
    cout<<"DISPONIBLE: "<<_disponible<<endl;
}
