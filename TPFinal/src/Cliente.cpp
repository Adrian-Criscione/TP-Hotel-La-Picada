#include <cstring>
#include <iostream>
#include "Cliente.h"

using namespace std;

int Cliente::getDni ()
{
    return Dni;
}
string Cliente::getNombre ()
{
    return Nombre;
}

string Cliente::getApellido ()
{
    return Apellido;
}


int Cliente::getEdad ()
{
    return Edad;
}
string Cliente::getMail ()
{
    return Mail;
}
Fecha Cliente::getFechaNacimiento ()
{
    return FechaNacimiento;
}

bool Cliente::getActivo ()
{
    return Activo;
}
void Cliente::setDni (int dni)
{
    Dni=dni;
}
void Cliente::setNombre (string)
{

}
void Cliente::setApellido (string)
{

}
void Cliente::setEdad (int edad)
{
    Edad=edad;
}
void Cliente::setMail (string)
{

}
void Cliente::setFechaNacimiento (Fecha f)
{
    FechaNacimiento=f;
}
void Cliente::setActivo (bool activo)
{
    Activo=activo;
}
