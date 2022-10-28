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
    void Cargar(int dni);
    void Mostrar();



private:
    int _dni;
    char _nombre [50];
    char _apellido [50];
    int _edad;
    char _mail[50];
    Fecha _fechaNacimiento;
    bool _activo;

};

#endif // CLIENTE_H
