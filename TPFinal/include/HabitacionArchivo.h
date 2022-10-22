#pragma once
#include "Habitacion.h"
class HabitacionArchivo
{
public:
    Habitacion leer(int nroRegistro);
    bool guardar(Habitacion h);
    bool guardar(Habitacion h, int nroRegistro);
    int getCantidad();
    int buscar(int );
};
