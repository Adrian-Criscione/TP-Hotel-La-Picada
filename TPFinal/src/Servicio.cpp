#include "Servicio.h"
#include <iostream>

using namespace std;

int Servicio:: getCodigoServicio ()
{
    return _codigoServicio;
}

float Servicio:: getPrecio ()
{
    return _precio;
}
bool Servicio:: getActivo ()
{
    return _activo;
}
void Servicio:: setCodigoServicio (int codigo)
{
    _codigoServicio=codigo;
}

void Servicio:: setPrecio (float precio)
{
    _precio=precio;
}
void Servicio:: setActivo (bool activo)
{
    _activo=activo;
}

void Servicio::Cargar(int codigoservicio)
{
   _codigoServicio=codigoservicio;
    cout<<endl;
       cout << "Ingrese el Codigo de Excursiones"<<endl;

    cout<<endl;
     ///_precio
         _activo=true;
}

void Servicio::Mostrar ()
{
    cout<< "El Codigo de Servicio es: "<< _codigoServicio<<endl;


    cout<< "El Precio es: "<< _precio<<endl;
}
