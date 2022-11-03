#pragma once
#include "Reserva.h"
class ReservaArchivo
{
public:
    Reserva leer(int nroRegistro);
    bool guardar(Reserva r);
    bool guardar(Reserva r, int nroRegistro);
    int getCantidad();
    //int buscar(int );

};
