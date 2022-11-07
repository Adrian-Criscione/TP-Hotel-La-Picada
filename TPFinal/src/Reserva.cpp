#include <iostream>
#include "Reserva.h"
#include "Servicio.h"
#include "Fecha.h"
#include "rlutil.h"

using namespace std;
using namespace rlutil;

int Reserva::getNumeroReserva()
{

    return _numeroreserva;
}
int Reserva::getDniCliente()
{

    return _dniCliente;
}

int Reserva::getCodigoServicio()
{

    return _codigoServicio;
}

int Reserva::getMedioDePago()
{

    return _medioDePago;
}

Fecha Reserva::getFechaReserva()
{

    return _fechaReserva;
}

int Reserva::getCanalDeReserva()
{

    return _canalDeReserva;
}

float Reserva::getMonto()
{

    return _monto;
}

bool Reserva::getAbonado()
{

    return _abonado;
}
bool Reserva::getActivo()
{

    return _activo;
}
void Reserva::setNumeroReserva (int numeroreserva)
{

    _numeroreserva=numeroreserva;
}
void Reserva::setDniCliente(int dni)
{

    _dniCliente=dni;
}

void Reserva::setCodigoServicio(int codigoServicio)
{

    _codigoServicio=codigoServicio;
}

void Reserva::setMedioDePago(int medioDePago)
{
    _medioDePago=medioDePago;
}

void Reserva::setFechaReserva(Fecha fechaReserva)
{

    _fechaReserva = fechaReserva;
}

void Reserva::setCanalDeReserva(int canalDeReserva)
{

    _canalDeReserva=canalDeReserva;
}

void Reserva::setMonto(float monto)
{

    _monto = monto;
}

void Reserva::setAbonado(bool abonado)
{

    _abonado = abonado;
}

void Reserva::setActivo(bool activo)
{

    _activo = activo;
}

void Reserva::Cargar(int numeroreserva, int dni,int hab)
{
    char op;
    int dia, mes, anio;
    _numeroreserva =numeroreserva;
    _dniCliente=dni;
    _numerohabitacion=hab;
    Servicio ser;
    ser.Cargar(numeroreserva);
    cout<< "Ingrese el Medio de Pago: "<<endl;
    cout<< "1)Efectivo 2)Tarjeta 3)Mercado Pago "<<endl;
    cin>> _medioDePago;
    cout<<"Ingrese dia de comienzo reserva: "<<endl;
    cin>>dia;
    _fechaReserva.setDia(dia);
    cout<<"Ingrese mes de comienzo reserva: "<<endl;
    cin>>mes;
    _fechaReserva.setMes(mes);
    cout<<"Ingrese anio de comienzo reserva: "<<endl;
    cin>>anio;
    _fechaReserva.setAnio(anio);
    cout<< "Ingrese Canal de Reserva: "<<endl;
    cout<< "1) Pagina Web 2) Booking 3) Almundo 4) Despegar"<<endl;
    cin>> _canalDeReserva;

//// FUNCION PARA CALCULAR TOTAL DE RESERVA

    cout<<"La reserva fue abonada? s/n: ";
    cin.get(op);
    cin.ignore();
    switch (op)
    {
    case 's':
    case 'S':
    {
        _abonado=true;
    }
    break;
    case 'n':
    case 'N':
    {
        _abonado=false;
    }
    break;

    }
    _activo=true;
}

void Reserva::Mostrar()
{

    cout<< "NUMERO RESERVA "<< _numeroreserva<<endl;
    cout<< "DNI CLIENTE "<< _dniCliente<<endl;
    cout<< "NUMERO HABITACION "<< _numerohabitacion<<endl;
    cout<< "CODIGO SERVICIO "<< _codigoServicio<<endl;
    cout<< "MEDIO PAGO "<< _medioDePago<<endl ;
///    cout<< "FECHA " <<_fechaReserva<<endl;
    cout<< "CANAL RESERVA "<< _canalDeReserva<<endl;
    cout<< "MONTO "<< _monto<<endl;
    cout<< "ABONADO "<< _abonado<<endl;
    cout<< "ACTIVO "<< _activo<<endl;

}


