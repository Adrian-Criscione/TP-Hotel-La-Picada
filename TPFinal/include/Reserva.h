#ifndef RESERVA_H
#define RESERVA_H
#include <cstring>
#include <iostream>
#include "Fecha.h"
using namespace std;

class Reserva
{
private:
    int _dniCliente;
    int _legajoEmpleado;
    int _codigoServicio;
    char _medioDePago [50];
    Fecha _fechaReserva;
    char _canalDeReserva [50];
    float _monto;
    bool _abonado;

public:
    int getDniCliente ();
    int getLegajoEmpleado ();
    int getCodigoServicio ();
    string getMedioDePago ();
    Fecha getFechaReserva ();
    string getCanalDeReserva ();
    float getMonto();
    bool getAbonado ();
    void setDniCliente (int dniCliente);
    void setLegajoEmpleado (int legajoEmpleado);
    void setCodigoServicio (int codigoServicio);
    void setMedioDePago (string medioDePago);
    void setFechaReserva (Fecha fechaReserva);
    void setCanalDeReserva (string canalDeReserva);
    void setMonto (float monto);
    void setAbonado (bool abonado);
};

#endif // RESERVA_H
