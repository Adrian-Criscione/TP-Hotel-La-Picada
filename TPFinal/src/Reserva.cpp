#include <iostream>
#include "Reserva.h"
using namespace std;
int Reserva::getNumeroReserva(){

    return _numeroreserva;
}
int Reserva::getDniCliente(){

    return _dniCliente;
}

int Reserva::getLegajoEmpleado(){

    return _legajoEmpleado;
}

int Reserva::getCodigoServicio(){

    return _codigoServicio;
}

string Reserva::getMedioDePago(){

    return _medioDePago;
}

Fecha Reserva::getFechaReserva(){

    return _fechaReserva;
}

string Reserva::getCanalDeReserva(){

    return _canalDeReserva;
}

float Reserva::getMonto(){

    return _monto;
}

bool Reserva::getAbonado(){

    return _abonado;
}
bool Reserva::getActivo(){

    return _activo;
}
void Reserva::setNumeroReserva (int numeroreserva){

    _numeroreserva=numeroreserva;
}
void Reserva::setDniCliente(int dni){

    _dniCliente=dni;
}

void Reserva::setLegajoEmpleado(int legajoEmpleado){

    _legajoEmpleado= legajoEmpleado;
}

void Reserva::setCodigoServicio(int codigoServicio){

    _codigoServicio=codigoServicio;
}

void Reserva::setMedioDePago(string medioDePago){

   strcpy(_medioDePago,medioDePago.c_str());
}

void Reserva::setFechaReserva(Fecha fechaReserva){

    _fechaReserva = fechaReserva;
}

void Reserva::setCanalDeReserva(string canalDeReserva){

   strcpy(_canalDeReserva,canalDeReserva.c_str());
}

void Reserva::setMonto(float monto){

    _monto = monto;
}

void Reserva::setAbonado(bool abonado){

    _abonado = abonado;
}
void Reserva::setActivo(bool activo){

    _activo = activo;
}
