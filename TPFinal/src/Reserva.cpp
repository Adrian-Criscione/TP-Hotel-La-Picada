#include <iostream>
#include "Reserva.h"
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

string Reserva::getMedioDePago()
{

    return _medioDePago;
}

Fecha Reserva::getFechaReserva()
{

    return _fechaReserva;
}

string Reserva::getCanalDeReserva()
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

void Reserva::setMedioDePago(string medioDePago)
{

    strcpy(_medioDePago,medioDePago.c_str());
}

void Reserva::setFechaReserva(Fecha fechaReserva)
{

    _fechaReserva = fechaReserva;
}

void Reserva::setCanalDeReserva(string canalDeReserva)
{

    strcpy(_canalDeReserva,canalDeReserva.c_str());
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

void Reserva::Cargar(int numeroreserva)
{
    char op;
    int dia, mes, anio;

    _numeroreserva =numeroreserva;
    cout<< "INGRESE DNI DEL CLIENTE: "<<endl;
    cin>> _dniCliente;
    cout<< "Ingrese el numero de habitacion: "<<endl;
    cin>> _numerohabitacion;

//// funcion SERVICIOS TOTALES


    cout<< "Ingrese el Medio de Pago: "<<endl;
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
   /* default:
    {
        gotoxy(50,17);
        setColor(YELLOW);
        cls();
        cout<<"OPCION INCORRECTA!!!"<<endl;
        cin.get();


    }
    break;*/

    }
    _activo=true;
}


void Mostrar() {}


