#include <cstring>
#include <iostream>
#include "Cliente.h"

using namespace std;

/////////////////////// NOSE COMO CARGAR LA FECHA DE NACIMIENTO EN LA FUNCION CARGAR Y MOSTRAR


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
<<<<<<< HEAD

    _dni=dni;
    cout<<"INGRESE NOMBRE DEL CLIENTE: "<<endl;
    cin>>_nombre;
    cout<<endl;
    cout<< "INGRESE APELLIDO DEL CLIENTE: ";
    cin>>_apellido;
    cout<<endl;
    cout<< "INGRESE EDAD DEL CLIENTE: ";
    cin>> _edad;
    cout<<endl;
    cout<< "INGRESE MAIL DEL CLIENTE: ";
    cin>>_mail;
    cout<<endl;
    cout<< "INGRESE FECHA DE NACIMIENTO DEL CLIENTE: "<<endl;
///    cin>> _fechaNacimiento;
    _activo=true;
    cout<<endl;
=======
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
    cout<<"Fecha de nacimiento: Ingrese dia: "<<endl;
    cin>>dia;
    _fechaNacimiento.setDia(dia);
    cout<<"Fecha de nacimiento: Ingrese mes: "<<endl;
    cin>>mes;
    _fechaNacimiento.setMes(mes);
    cout<<"Fecha de nacimiento: Ingrese anio: "<<endl;
    cin>>anio;
    _fechaNacimiento.setAnio(anio);
    _activo=true;
}


void Cliente::Mostrar(){
    cout<<_nombre<<"  "<<_apellido<<"  "<<"DNI: "<<_dni<<endl;
    cout<<"Edad: "<<_edad<<"  "<<"Email: "<<_mail<<"  "<<endl;
>>>>>>> e0b7acd9d14889715ff2d49205eefd7256714f61
}

void Cliente::Mostrar()
{
    cout<< "DNI DEL CLIENTE: "<<_dni<<endl;
    cout<< "NOMBRE Y APELLIDO DEL CLIENTE: "<<_nombre<<", "<<_apellido<<endl;
    cout<< "EDAD DEL CLIENTE: "<<_edad<<endl;
    cout<< "MAIL DEL CLIENTE: "<<_mail<<endl;
    cout<< "FECHA DE NACIMIENTO DEL CLIENTE: "<<endl;
}

