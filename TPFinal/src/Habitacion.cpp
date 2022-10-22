#include <iostream>
#include "Habitacion.h"
using namespace std;

int Habitacion:: getNumero()
{
    return _numero;
}

float Habitacion::getPrecio ()
{
    return _precio;
}

bool Habitacion::getDisponible ()
{
    return _disponible;
}
void Habitacion::setNumero (int numero)
{
    _numero=numero;
}

void Habitacion::setPrecio (float precio)
{
    _precio=precio;
}

void Habitacion::setDisponible (bool disponible)
{
    _disponible=disponible;
}

