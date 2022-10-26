#include <cstring>
#include <iostream>
#include "Cliente.h"

using namespace std;

int Cliente::getDni ()
{
    return _dni;
}
string Cliente::getNombre ()
{
    return _nombre;
}

string Cliente::getApellido ()
{
    return _apellido;
}

int Cliente::getEdad ()
{
    return _edad;
}
string Cliente::getMail ()
{
    return _mail;
}
Fecha Cliente::getFechaNacimiento ()
{
    return _fechaNacimiento;
}

bool Cliente::getActivo ()
{
    return _activo;
}
void Cliente::setDni (int dni)
{
    _dni=dni;
}
void Cliente::setNombre (string nombre)
{
    strcpy(_nombre, nombre.c_str());
}
void Cliente::setApellido (string apellido)
{
    strcpy(_apellido, apellido.c_str());
}
void Cliente::setEdad (int edad)
{
    _edad=edad;
}
void Cliente::setMail (string mail)
{
    strcpy(_mail, mail.c_str());
}

void Cliente::setFechaNacimiento (Fecha f)
{
    _fechaNacimiento=f;
}
void Cliente::setActivo (bool activo)
{
    _activo=activo;
}

void Cliente::Cargar ()
{
    int dia, mes, anio;
    cout<< "Ingrese numero de DNI del cliente: "<<endl;
    cin>> _dni;
    cout<< "Ingrese Nombre: "<<endl;
    cin>> _nombre;
    cout<<"Ingrese Apellido: "<<endl;
    cin>>_apellido;
    cout<<"Ingrese Edad: "<<endl;
    cin>>_edad;
    cout<<"Ingrese Email: "<<endl;
    cin>>_mail;
    cout<<"Fecha de nacimiento: Ingrese dia: "<<endl;
    cin>>dia;
    _fechaNacimiento.setDia(dia);
    cout<<"Fecha de nacimiento: Ingrese mes: "<<endl;
    cin>>mes;
    _fechaNacimiento.setMes(mes);
    cout<<"Fecha de nacimiento: Ingrese anio: "<<endl;
    cin>>anio;
    _fechaNacimiento.setAnio(anio);

}

void Cliente::Mostrar(){
    cout<<_nombre<<"  "<<_apellido<<"  "<<"DNI: "<<_dni<<endl;
    cout<<"Edad: "<<_edad<<"  "<<"Email: "<<_mail<<"  "<<endl;
    cout<<"Activo: "<<_activo<<endl;
}
