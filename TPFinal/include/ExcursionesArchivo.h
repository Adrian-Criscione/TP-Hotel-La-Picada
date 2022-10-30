#pragma once
#include "Excursiones.h"

class ExcursionesArchivo
{
public:
    Excursiones leer(int nroRegistro);
    bool guardar(Excursiones ex);
    bool guardar(Excursiones ex, int nroRegistro);
    int getCantidad();
    int buscar(int );
    bool ModificarArchivo(int pos, Excursiones ex);

};



