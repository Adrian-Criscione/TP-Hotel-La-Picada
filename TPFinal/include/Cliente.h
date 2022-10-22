#ifndef CLIENTE_H
#define CLIENTE_H
#include "Fecha.h"
#include <cstring>
#include <iostream>
using namespace std;

class Cliente
{
public:
    int getDni ();
   string getNombre ();
    string getApellido ();
    int getEdad ();
    string getMail ();
    Fecha getFechaNacimiento ();
    bool getActivo ();

    void setDni (int);
    void setNombre (string);
    void setApellido (string);
    void setEdad (int);
    void setMail (string);
    void setFechaNacimiento (Fecha);
    void setActivo (bool);



private:
    int Dni;
    char Nombre [50];
    char Apellido [50];
    int Edad;
    char Mail[50];
    Fecha FechaNacimiento;
    bool Activo;

};

#endif // CLIENTE_H
