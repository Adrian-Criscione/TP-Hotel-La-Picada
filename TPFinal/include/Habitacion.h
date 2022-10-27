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
    int _tipoHabitacion;
    bool _disponible;
public:
    int getNumero();
    float getPrecio ();
    int getTipoHabitacion();
    bool getDisponible ();
    void setNumero (int);
    void setDniCliente (int);
    void setPrecio (float);
    void setTipoHabitacion(int);
    void setDisponible (bool);
    void Cargar();
    void Mostrar();
};


#endif // HABITACION_H_INCLUDED
