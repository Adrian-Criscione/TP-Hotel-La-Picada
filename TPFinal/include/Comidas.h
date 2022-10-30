#ifndef EXCURSIONES_H
#define EXCURSIONES_H
#include "Fecha.h"
#include <cstring>
#include <iostream>
using namespace std;

class Comidas
{
    private:
        int _idComida;
        int _numComida;
        float _precio;
        bool _disponible;

    public:
        int getIdComida();
        int getNumComida();
        float getPrecio();
        bool getDisponible();
        void setIdComida();
        void setNumComida(int numComida);
        void setPrecio(float precio);
        void setDisponible(bool disponible);
        void cargar(int id);
        void mostrar();
};

#endif // COMIDAS_H
