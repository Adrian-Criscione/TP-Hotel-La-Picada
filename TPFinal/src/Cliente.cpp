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

void Cliente::Cargar (int dni)
{
    int dia, mes, anio;
    _dni=dni;
    cout<< "Ingrese Nombre: "<<endl;
    cin>> _nombre;
    cout<<"Ingrese Apellido: "<<endl;
    cin>>_apellido;
    cout<<"Ingrese Edad: "<<endl;
    cin>>_edad;
    cout<<"Ingrese Email: "<<endl;
    cin>>_mail;
    cout<<"Ingrese dia de nacimiento: "<<endl;
    cin>>dia;
    _fechaNacimiento.setDia(dia);
    cout<<"Ingrese mes de nacimiento: "<<endl;
    cin>>mes;
    _fechaNacimiento.setMes(mes);
    cout<<"Ingrese anio de nacimiento: "<<endl;
    cin>>anio;
    _fechaNacimiento.setAnio(anio);
    _activo=true;
}


void Cliente::Mostrar()
{
    cout<<_nombre<<"  "<<_apellido<<"  "<<"DNI: "<<_dni<<endl;
    cout<<"Edad: "<<_edad<<"  "<<"Email: "<<_mail<<"  "<<endl;
}
