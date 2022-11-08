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
    int _codigoServicio;
    int _medioDePago;
    Fecha _fechaComienzo;
    Fecha _fechaFin;
    int _diasreserva;
    int _canalDeReserva;
    int _numComida;
    float _monto;
    bool _abonado;
    bool _activo;

public:
    int getNumeroReserva ();
    int getDniCliente ();
    int getNumeroHabitacion ();
    int getCodigoServicio ();
    int getMedioDePago ();
    Fecha getFechaComienzo ();
    Fecha getFechaFin ();
    int getDiasReserva ();
    int getCanalDeReserva ();
    int getnumComida ();
    float getMonto();
    bool getAbonado ();
    bool getActivo ();
    ///////
    void setNumeroReserva (int numeroreserva);
    void setDniCliente (int dniCliente);
    void setNumeroHabitacion (int numerohabitacion);
    void setCodigoServicio (int codigoServicio);
    void setMedioDePago (int medioDePago);
    void setFechaComienzo (Fecha fechaReserva);
    void setFechaFin (Fecha fechaReserva);
    void setDiasReservas (int diasreserva);
    void setCanalDeReserva (int canalDeReserva);
    void setNumComida (int numComida);
    void setMonto (float monto);
    void setAbonado (bool abonado);
    void setActivo (bool activo);
    void Cargar(int numeroreserva, int dni,int habitacion);
    void Mostrar();
};


#endif // RESERVA_H
