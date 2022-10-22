#ifndef HABITACION_H_INCLUDED
#define HABITACION_H_INCLUDED
#include <cstring>
#include <iostream>
#include "Fecha.h"
using namespace std;

class Habitacion
{
private:
    int _numero;
    float _precio;
    bool _disponible;

public:
    int getNumero();
    float getPrecio ();
    bool getDisponible ();
    void setNumero (int);
    void setDniCliente (int);
    void setPrecio (float);
    void setDisponible (bool);


};


#endif // HABITACION_H_INCLUDED
