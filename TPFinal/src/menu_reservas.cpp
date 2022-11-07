#include <iostream>
#include <cstring>
#include "rlutil.h"
#include "Menu.h"
#include "Reserva.h"
#include "ReservaArchivo.h"

using namespace std;
using namespace rlutil;

void MenuReservas ()
{
    bool salir=false; ///VARIABLE PARA EL while
    char op;          ///VARIABLE PARA LA OPCION
    char exi;        ///VARIABLE PARA LA SALIDA

    while(!salir)            ///MIENTRAS SEA DISTINTO DE SALIR
    {

        cls();                     ///LIMPIA LA PANTALLA
        mostrar_menureservas();

        setColor(WHITE);
        gotoxy(50,16);
        cout<<endl;
        gotoxy(50,18);
        cout<<"INGRESE UNA OPCION: ";
        cin.get(op);    ///LEE UN CARACTER POR TECLADO
        cin.ignore();  ///BORRA EL BUFER DEL TECLADO

        switch(op)     ///DEPENDIENDO DE LA OPCION QUE INGRESE EL USUARIO
        {
        case '1':
        {
            cls ();
            CargarReserva();
        }
        break;

        case '2':
        {
            cls ();
            BuscarReserva ();
        }
        break;

        case '3':
        {
            cls ();
            CancelarReserva ();
        }
        break;
        case '4':
        {
            cout<< "/-*";
            Reserva r;
            ReservaArchivo ra;
            int pos=0;
            pos=ra.getCantidad();
            cout<<endl<<pos;
            for (int i=0; i<pos; i++)
            {
                r=ra.leer(i);

                if (r.getActivo()==true)
                {
                    r.Mostrar();
                    cout<< "**"<<endl;
                    cout<< endl;
                }
            }

        }
        break;

        case '0':
        {
            setBackgroundColor(BLACK);
            return;
        }
        break;

        default:
        {
            msjerror ();
        }
        break;
        }


        cin.get();/// DETIENE LA PANTALLA

    }
}

void mostrar_menureservas()
{
    gotoxy(50,9);
    setColor(WHITE);
    cout<<" MENU RESERVAS"<<endl;
    gotoxy(50,10);
    cout<<"---------------------"<<endl;
    gotoxy(50,11);
    cout<<"1 - CARGAR NUEVA RESERVA"<<endl;
    gotoxy(50,12);
    cout<<"2 - BUSCAR RESERVA"<<endl;
    gotoxy(50,13);
    cout<<"3 - CANCELAR RESERVA"<<endl;
    gotoxy(50,14);
    cout<< "4 - MOSTRAR RESERVAS ACTIVAS"<<endl;
    gotoxy(50,15);
    cout<<"---------------------"<<endl;
    gotoxy(50,16);
    setColor(YELLOW);
    cout<<"0 - SALIR"<<endl;
}

void CargarReserva ()
{
    Reserva r;
    ReservaArchivo ra;
    int nr=ra.getCantidad()+1;///carga el numero de reserva segun la cantidad de registros de reservas q haya +1
    int dni,hab;
    dni=ConsultaCliente ();///analiza si esta en archivos el dni del cliente
    if (dni==0)
        return;
    hab=consultaHabitacion(); ///analiza si esta en archivos la habitacion
    if (hab==0)
        return;
    r.Cargar(nr,dni,hab);
    ra.guardar (r);

}

void BuscarReserva ()
{
    Reserva r;
    ReservaArchivo ra;
    bool salir=false;
    char po;
    while(!salir)
    {
        cls();
        mostrar_menubuscarreservas();

        setColor(WHITE);
        gotoxy(50,16);
        cout<<endl;
        gotoxy(50,18);
        cout<<"INGRESE UNA OPCION: ";
        cin.get(po);    ///LEE UN CARACTER POR TECLADO
        cin.ignore();  ///BORRA EL BUFER DEL TECLADO

        switch(po)     ///DEPENDIENDO DE LA OPCION QUE INGRESE EL USUARIO
        {
        case '1':
        {
            cls();
            BuscarReservaPorNumeroReserva ();
        }
        break;
        case '2':
        {
            cls();
            BuscarReservaPorNumeroDni();
        }
        break;
        case '3':
        {
            cls();
            BuscarReservaPorNumeroHabitacion();

        }
        break;

        case '0':
        {

            return;
        }
        break;

        default:
        {
            msjerror ();

        }

        }
        cin.ignore();
    }


}

void mostrar_menubuscarreservas()
{
    gotoxy(50,9);
    setColor(WHITE);
    cout<<" BUSCAR RESERVAS"<<endl;
    gotoxy(50,10);
    cout<<"---------------------"<<endl;
    gotoxy(50,11);
    cout<<"1 - BUSCAR POR NUMERO DE RESERVA"<<endl;
    gotoxy(50,12);
    cout<<"2 - BUSCAR RESERVA POR DNI CLIENTE"<<endl;
    gotoxy(50,13);
    cout<<"3 - BUSCAR RESERVA POR NUMERO HABITACION"<<endl;
    gotoxy(50,14);
    cout<<"---------------------"<<endl;
    gotoxy(50,15);
    setColor(YELLOW);
    cout<<"0 - SALIR"<<endl;
}

void BuscarReservaPorNumeroReserva ()
{
    Reserva r;
    ReservaArchivo ra;
    cls();

    int num,pos;
    cout<< "INGRESE EL NUMERO DE RESERVA: ";
    cin>>num;
    pos=ra.buscar(num);
    if(pos<0)
    {
        cout<<"EL NUMERO DE RESERVA NO ESTA REGISTRADA"<<endl;
        system("pause");
    }
    else
    {
        r=ra.leer(pos);
        if(r.getActivo())
        {
            r.Mostrar();
            system("pause");
        }
        else
        {
            cout<< "LA RESERVA HA SIDO CANCELADA"<<endl;
            cin.get();
        }

    }

}

void BuscarReservaPorNumeroDni ()
{

    Reserva r;
    ReservaArchivo ra;
    int dni;
    cout<< "INGRE NUMERO DNI DEL CLIENTE PARA BUSCAR RESERVA: ";
    cin>>dni;
    int cant=ra.getCantidad();
    bool noreserva=true;
    for (int i=0; i<cant; i++)
    {
        r=ra.leer(i);
        if (r.getActivo())
        {
            if(r.getDniCliente()==dni)
            {
        cout<<"*/*/*/*/*/*/*/*/*/*/*"<<endl;
        r.Mostrar();
        cout<<"*/*/*/*/*/*/*/*/*/*/*"<<endl;
        cin.get();
        noreserva=false;
            }
        }

    }
    if (noreserva)
    {
        cout<< "EL CLIENTE NO TIENE RESERVAS ACTIVAS"<<endl;
        cin.get();
    }

}

void BuscarReservaPorNumeroHabitacion () {

    Reserva r;
    ReservaArchivo ra;
    int hab;
    cout<< "INGRE NUMERO HABITACION PARA BUSCAR RESERVA: ";
    cin>>hab;
    int cant=ra.getCantidad();
    bool noreserva=true;
    for (int i=0; i<cant; i++)
    {
        r=ra.leer(i);
        if (r.getActivo())
        {
            if(r.getNumeroHabitacion()==hab)
            {
        r.Mostrar();
        cin.get();
        noreserva=false;
            }
        }

    }
    if (noreserva)
    {
        cout<< "LA HABITACION NO TIENE RESERVAS ACTIVAS"<<endl;
        cin.get();
    }

}

void CancelarReserva ()
{
    Reserva r;
    ReservaArchivo ra;
    cls();

    int num,pos;
    cout<< "INGRESE EL NUMERO DE RESERVA QUE DESEA CANCELAR: ";
    cin>>num;
    pos=ra.buscar(num);
    if(pos<0)
    {
        cout<<"EL NUMERO DE RESERVA NO ESTA REGISTRADA"<<endl;
        system("pause");
    }
    else
    {
        r=ra.leer(pos);
        if(r.getActivo())
        {
            r.setActivo(false);
            ra.guardar(r,pos);
            cout<< "LA RESERVA HA SIDO CANCELADA"<<endl;
            system("pause");

        }
        else
        {
            cout<< "LA RESERVA YA FUE CANCELADA"<<endl;
            cin.get();
        }

    }

}
