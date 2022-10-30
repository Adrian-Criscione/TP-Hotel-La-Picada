#include <cstring>
#include <iostream>
#include "Comidas.h"
#include "ComidasArchivo.h"
using namespace std;
int Comidas::getIdComida(){
    return _idComida;
}
int Comidas::getNumComida(){
    return _numComida;
}
float Comidas::getPrecio(){
    return _precio;
}

bool Comidas::getDisponible(){
    return _disponible;
}

void Comidas::setIdComida(){
      ComidasArchivo coa;
    int id = coa.getCantidad();
    id++;
    _idComida=id;
}

void Comidas::setNumComida(int numComida){
    _numComida = numComida;
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
