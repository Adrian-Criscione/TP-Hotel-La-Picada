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


int Comidas::cargar(){
    ComidasArchivo ca;
    _idComida= ca.getCantidad()+1;
    cout<< "SELECCION EL TIPO DE SERVICIOS A BRINDAR:"<<endl;
    cout<< "1) SIN SERVICIO  2)DESAYUNO  3)MEDIA PENSION  4)ALL INCLUSIVE"<<endl;
    cin>> _numComida;
  switch (_numComida)
  {case '1':
      {_precio=0;}
     break;
 case '2':
    {
        _precio=100;
    }
    break;
     case '3':
    {
        _precio=200;
    }
    break;
     case '4':
    {
        _precio=500;
    }
    break;

        }
    _disponible = true;
    return _idComida;
}

void Comidas::mostrar(){
    cout<<"CODIGO IDENTIFICADOR DE COMIDA: "<<_idComida<<endl;
    cout<< "INGRESE LA OPCION DE SERVICIO DE COMIDAS: "<<endl;


    cout<<"PRECIO: "<<_precio<<endl;
    cout<<"DISPONIBLE: "<<_disponible<<endl;
}
