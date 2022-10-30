#include <iostream>
#include "Habitacion.h"
using namespace std;

int Habitacion:: getNumero()
{
    return _numero;
}

float Habitacion::getPrecio ()
{
    return _precio;
}
int Habitacion::getTipoHabitacion()
{
    return _tipoHabitacion;
}
bool Habitacion::getDisponible ()
{
    return _disponible;
}
void Habitacion::setNumero (int numero)
{
    _numero=numero;
}

void Habitacion::setPrecio (float precio)
{
    _precio=precio;
}
void Habitacion::setTipoHabitacion(int tipoHabitacion)
{
    _tipoHabitacion = tipoHabitacion;
}
void Habitacion::setDisponible (bool disponible)
{
    _disponible=disponible;
}
void Habitacion::Cargar(int numero){
    _numero = numero;
    _disponible=true;
    cout<<"Ingrese tipo de habitacion (1-5): "<<endl;
    cout<<"1-HABITACION SIMPLE STANDARD"<<endl;
    cout<<"2-HABITACION DOBLE STANDARD"<<endl;
    cout<<"3-HABITACION TRIPLE STANDARD"<<endl;
    cout<<"4-HABITACION DOBLE PREMIUM"<<endl;
    cout<<"5-HABITACION TRIPLE PREMIUM"<<endl;
    cin>>_tipoHabitacion;
    cout<<"Ingrese precio x noche"<<endl;
    cin>>_precio;

}
void Habitacion::Mostrar()
{
    cout<<_numero<<"  "<<"Tipo de habitacion: "<<_tipoHabitacion<<endl;
    cout<<"Precio X noche: "<<_precio<<endl;
    cout<<"Disponible: "<<_disponible<<endl;
}
