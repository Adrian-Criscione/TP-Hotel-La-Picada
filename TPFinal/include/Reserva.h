#ifndef RESERVA_H
#define RESERVA_H
#include <cstring>
#include <iostream>
#include "Fecha.h"
using namespace std;

class Reserva
{
private:
    int _numeroreserva;
    int _dniCliente;
    int _legajoEmpleado;
    int _codigoServicio;
    char _medioDePago [50];
    Fecha _fechaReserva;
    char _canalDeReserva [50];
    float _monto;
    bool _abonado;
    bool _activo;

public:
    int getNumeroReserva ();
    int getDniCliente ();
    int getLegajoEmpleado ();
    int getCodigoServicio ();
    string getMedioDePago ();
    Fecha getFechaReserva ();
    string getCanalDeReserva ();
    float getMonto();
    bool getAbonado ();
    bool getActivo ();
    void setNumeroReserva (int numeroreserva);
    void setDniCliente (int dniCliente);
    void setLegajoEmpleado (int legajoEmpleado);
    void setCodigoServicio (int codigoServicio);
    void setMedioDePago (string medioDePago);
    void setFechaReserva (Fecha fechaReserva);
    void setCanalDeReserva (string canalDeReserva);
    void setMonto (float monto);
    void setAbonado (bool abonado);
    void setActivo (bool activo);
};

#endif // RESERVA_H
