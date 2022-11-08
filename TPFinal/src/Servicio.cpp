#include "Servicio.h"
#include <iostream>

using namespace std;

int Servicio:: getCodigoServicio ()
{
    return _codigoServicio;
}
int Servicio:: getComida ()
{
    return _comida;
}
int Servicio:: getExcursiones ()
{
    return _excursiones;
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

void Servicio:: setComida (int comida)
{
    _comida=comida;
}
void Servicio:: setExcursiones (int excursiones)
{
    _excursiones=excursiones;
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
    cin>> _excursiones;
    cout<<endl;
     ///_precio
         _activo=true;
}

void Servicio::Mostrar ()
{
    cout<< "El Codigo de Servicio es: "<< _codigoServicio<<endl;
    cout<< "El codigo de Comida es: "<< _comida<<endl;
    cout<< "El codigo de Excursiones es: "<< _excursiones<<endl;
    cout<< "El Precio es: "<< _precio<<endl;
}
