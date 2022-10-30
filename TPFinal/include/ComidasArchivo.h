#pragma once
#include "Comidas.h"

class ComidasArchivo
{
public:
    Comidas leer(int nroRegistro);
    bool guardar(Comidas co);
    bool guardar(Comidas co, int nroRegistro);
    int getCantidad();
    int buscar(int );
    bool ModificarArchivo(int pos, Comidas co);

};


