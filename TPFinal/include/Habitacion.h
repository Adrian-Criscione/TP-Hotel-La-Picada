#ifndef HABITACION_H_INCLUDED
#define HABITACION_H_INCLUDED
#include <cstring>
#include <iostream>
#include "Fecha.h"
using namespace std;

class Habitacion
{
private:
    int _numero;
    int _dniCliente;
    int _legajoEmpleado;
    int _codigoServicio;
    char _medioDePago [50];
    Fecha _fechaReserva;
    char _canalDeReserva [50];
    float _precio;
    bool _abonado;
    bool _activo;

public:
    int getNumero();
    int getDniCliente ();
    int getLegajoEmpleado ();
    int getCodigoServicio ();
    string getMedioDePago ();
    Fecha getFechaReserva ();
    string getCanalDeReserva ();
    float getPrecio ();
    bool getAbonado ();
    bool getActivo ();
    void setNumero (int);
    void setDniCliente (int);
    void setLegajoEmpleado (int);
    void setCodigoServicio (int);
    void setMedioDePago (string);
    void setFechaReserva (Fecha);
    void setCanalDeReserva (string);
    void setPrecio (float);
    void setAbonado (bool);
    void setActivo (bool);


    };


#endif // HABITACION_H_INCLUDED
