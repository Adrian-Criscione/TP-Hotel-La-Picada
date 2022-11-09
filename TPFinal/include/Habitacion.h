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
    bool _activa;
public:
    int getNumero();
    float getPrecio ();
    int getTipoHabitacion();
    bool getActiva ();
    void setNumero (int);
    void setDniCliente (int);
    void setPrecio (float);
    void setTipoHabitacion(int);
    void setActiva (bool);
    void Cargar(int numero);
    void Mostrar();
};


#endif // HABITACION_H_INCLUDED
