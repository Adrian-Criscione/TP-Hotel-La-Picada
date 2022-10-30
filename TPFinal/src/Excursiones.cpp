#include <cstring>
#include <iostream>
#include "Excursiones.h"
#include "ExcursionesArchivo.h"
using namespace std;

int Excursiones::getIdExcursion(){
    return _idExcursion;
}
int Excursiones::getNumExcursion(){
    return _numExcursion;
}

float Excursiones::getPrecio(){
    return _precio;
}

bool Excursiones::getDisponible(){
    return _disponible;
}

void Excursiones::setIdExcursion(){
    ExcursionesArchivo exa;
    int id = exa.getCantidad();
    id++;
    _idExcursion=id;
}

void Excursiones::setNumExcursion(int numExcursion){
    _numExcursion = numExcursion;
}

void Excursiones::setPrecio(float precio){
    _precio = precio;
}

void Excursiones::setDisponible(bool disponible){
    _disponible = disponible;
}

void Excursiones::cargar(int id){
    _idExcursion = id;
    cout<<"INGRESE PRECIO DE LA EXCURSION X PERSONA: "<<endl;
    cin>>_precio;
    _disponible = true;

}

void Excursiones::mostrar(){
    cout<<"CODIGO IDENTIFICADOR DE LA EXCURSION: "<<_idExcursion<<endl;
    cout<<"PRECIO DE LA EXCURSION X PERSONA: "<<_precio<<endl;
    cout<<"DISPONIBLE: "<<endl;
}
