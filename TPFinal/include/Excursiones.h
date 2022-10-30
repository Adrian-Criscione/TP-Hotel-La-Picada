#ifndef EXCURSIONES_H
#define EXCURSIONES_H
#include "Fecha.h"
#include <cstring>
#include <iostream>
using namespace std;

class Excursiones
{
    private:
       int _idExcursion;
       int _numExcursion;
       float _precio;
       bool _disponible;

    public:
        int getIdExcursion();
        int getNumExcursion();
        float getPrecio();
        bool getDisponible();
        void setIdExcursion();
        void setNumExcursion(int numExcursion);
        void setPrecio(float precio);
        void setDisponible(bool disponible);
        void cargar(int id);
        void mostrar();
};

#endif // EXCURSIONES_H
