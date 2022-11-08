#include <iostream>
#include "Reserva.h"
#include "Servicio.h"
#include "Fecha.h"
#include "Comidas.h"
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
int Reserva::getNumeroHabitacion ()
{
    return _numerohabitacion;
}
int Reserva::getCodigoComida()
{

    return _codigoComida;
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
void Reserva::setCodigoComida(int codigoComida)
{
    _codigoComida=codigoComida;
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
    Comidas com;
    _codigoComida=com.cargar();
    cout<< "Ingrese el Medio de Pago: "<<endl;
    cout<< "1)Efectivo 2)Tarjeta 3)Mercado Pago "<<endl;
    cin>> _medioDePago;
    cout<<"Ingrese fecha de comienzo reserva: ";
    cin>>dia;
    cout<<"/";
    cin>>mes;
    cout<<"/";
    cin>>anio;
    Fecha(dia,mes,anio);
    cout<<endl;
    _fechaReserva.setAnio(anio);
    cout<< "Ingrese Canal de Reserva: "<<endl;
    cout<< "1) Pagina Web 2) Booking 3) Almundo 4) Despegar"<<endl;
    cin>> _canalDeReserva;

//// FUNCION PARA CALCULAR TOTAL DE RESERVA

    cout<<"La reserva fue abonada? s/n: ";
    cin.ignore();
    cin.get(op);
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
    _monto+=com.getPrecio();
    _activo=true;
}

void Reserva::Mostrar()
{

    cout<< "NUMERO RESERVA "<< _numeroreserva<<endl;
    cout<< "DNI CLIENTE "<< _dniCliente<<endl;
    cout<< "NUMERO HABITACION "<< _numerohabitacion<<endl;
    cout<< "CODIGO COMIDA "<< _codigoComida<<endl;
    cout<< "MEDIO PAGO "<< _medioDePago<<endl ;
    cout<< "FECHA " <<_fechaReserva.toString()<<endl;
    cout<< "CANAL RESERVA "<< _canalDeReserva<<endl;
    cout<< "MONTO "<< _monto<<endl;
    cout<< "ABONADO ";
    if (_abonado==true)
    {
        cout<< "SI"<<endl;
    }
    else
    {
        cout<< "NO"<<endl;
    }

    /// cout<< "ACTIVO "<< _activo<<endl;

}


