#include "Servicio.h"
#include <iostream>

using namespace std;

int Servicio:: getCodigoServicio ()
{
    return CodigoServicio;
}
int Servicio:: getComida ()
{
    return Comida;
}
int Servicio:: getExcursiones ()
{
    return Excursiones;
}
float Servicio:: getPrecio ()
{
    return Precio;
}
bool Servicio:: getActivo ()
{
    return Activo;
}
void Servicio:: setCodigoServicio (int codigo)
{
    CodigoServicio=codigo;
}


void Servicio:: setComida (int comida)
{
    Comida=comida;
}
void Servicio:: setExcursiones (int excursiones)
{
    Excursiones=excursiones;
}
void Servicio:: setPrecio (float precio)
{
    Precio=precio;
}
void Servicio:: setActivo (bool activo)
{
    Activo=activo;
}

void Servicio::Cargar()
{
    cout << "Ingrese el Codigo de Servicio"<<endl;
    cin>> CodigoServicio;
    cout<<endl;
    cout << "Ingrese el Codigo de Comida"<<endl;
    cin>>Comida;
    cout<<endl;
    cout << "Ingrese el Codigo de Excursiones"<<endl;
    cin>>Excursiones;
    cout<<endl;
    cout << "Ingrese el Precio"<<endl;
    cout<<endl;
    cin>>Precio;
    cout<<endl;

    Activo=true;
}

void Servicio::Mostrar ()
{
    cout<< "El Codigo de Servicio es: "<<CodigoServicio<<endl;
    cout<< "El codigo de Comida es: "<<Comida<<endl;
    cout<< "El codigo de Excursiones es: "<<Excursiones<<endl;
    cout<< "El Precio es: "<<Precio<<endl;
}
