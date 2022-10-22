#pragma once
#include "Servicio.h"
class ServicioArchivo
{
public:
    Servicio leer(int nroRegistro);
    bool guardar(Servicio ser);
    bool guardar(Servicio ser, int nroRegistro);
    int getCantidad();
    int buscar(int );
};
