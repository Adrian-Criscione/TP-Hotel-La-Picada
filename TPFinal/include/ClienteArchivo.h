#pragma once
#include "Cliente.h"
class ClienteArchivo
{
public:
    Cliente leer(int nroRegistro);
    bool guardar(Cliente cl);
    bool guardar(Cliente cl, int nroRegistro);
    int getCantidad();
    int buscar(int );
    bool ModificarArchivo(int pos);
};
