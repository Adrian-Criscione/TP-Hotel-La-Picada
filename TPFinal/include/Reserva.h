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
    int _numerohabitacion;
    int _codigoComida;
    int _medioDePago;
    Fecha _fechaReserva;
    int _canalDeReserva;
    float _monto;
    bool _abonado;
    bool _activo;

public:
    int getNumeroReserva ();
    int getDniCliente ();
    int getNumeroHabitacion ();

    int getCodigoComida ();
    int getMedioDePago ();
    Fecha getFechaReserva ();
    int getCanalDeReserva ();
    float getMonto();
    bool getAbonado ();
    bool getActivo ();
    void setNumeroReserva (int numeroreserva);
    void setDniCliente (int dniCliente);
    void setNumeroHabitacion (int numerohabitacion);
    void setCodigoComida (int codigoComida);
    void setMedioDePago (int medioDePago);
    void setFechaReserva (Fecha fechaReserva);
    void setCanalDeReserva (int canalDeReserva);
    void setMonto (float monto);
    void setAbonado (bool abonado);
    void setActivo (bool activo);
    void Cargar(int numeroreserva, int dni,int habitacion);
    void Mostrar();
};

#endif // RESERVA_H
