#include <iostream>
#include "Habitacion.h"
using namespace std;

int Habitacion:: getNumero()
{
    return _numero;
}
int Habitacion::getDniCliente ()
{
    return _dniCliente;
}
int Habitacion::getLegajoEmpleado ()
{
    return _legajoEmpleado;
}
int Habitacion::getCodigoServicio ()
{
    return _codigoServicio;
}
string Habitacion::getMedioDePago ()
{
    return _medioDePago;
}

Fecha Habitacion::getFechaReserva ()
{

}
string Habitacion::getCanalDeReserva ()
{
    return _canalDeReserva;
}

float Habitacion::getPrecio ()
{
    return _precio;
}
bool Habitacion::getAbonado ()
{
    return _abonado;
}
bool Habitacion::getActivo ()
{
    return _activo;
}
void Habitacion::setNumero (int numero)
{
    _numero=numero;
}
void Habitacion::setDniCliente (int dni)
{
    _dniCliente=dni;
}
void Habitacion::setLegajoEmpleado (int legajo)
{
    _legajoEmpleado=legajo;
}
void Habitacion::setCodigoServicio (int servicio)
{
    _codigoServicio=servicio;
}
void Habitacion::setMedioDePago (string medio)
{
    strcpy(_medioDePago, medio.c_str());
}

void Habitacion::setFechaReserva (Fecha f)
{
    _fechaReserva=f;
}
void Habitacion::setCanalDeReserva (string canal)
{
    strcpy(_canalDeReserva, canal.c_str());
}
void Habitacion::setPrecio (float precio)
{
    _precio=precio;
}
void Habitacion::setAbonado (bool abonado)
{
    _abonado=abonado;
}
void Habitacion::setActivo (bool activo)
{
    _activo=activo;
}

