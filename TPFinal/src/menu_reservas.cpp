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
            BuscarReserva ();
        }
        break;

        case '3':
        {
            CancelarReserva ();
        }
        break;
        case '5':
        {
            Reserva r;
            ReservaArchivo ra;
            int pos=0;
            pos=ra.getCantidad();
            for (int i=0; i<pos; i++)
            {
                r=ra.leer(i);
                if (r.getActivo()==true)
                {
                    r.Mostrar();
                    cout<< endl;
                    cout<< "**"<<endl;
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
    cout<<"---------------------"<<endl;
    gotoxy(50,15);
    setColor(YELLOW);
    cout<<"0 - SALIR"<<endl;
}

void CargarReserva ()
{
    Reserva r;
    ReservaArchivo ra;
/////FUNCION QUE CARGUE NUMERO DE RESERVA

    int nr;
    int dni,hab;
    dni=ConsultaCliente ();
    hab=consultaHabitacion();
    r.Cargar(nr,dni,hab);
    ra.guardar (r);
    nr++;


}
void BuscarReserva (){}

void CancelarReserva (){}
