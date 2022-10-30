#include <iostream>
#include <cstring>
#include "Menu.h"
#include "rlutil.h"
#include "menu_habitacion.h"
#include "Habitacion.h"
#include "HabitacionArchivo.h"
#include "ClienteArchivo.h"
#include "menu_cliente.h"
using namespace std;
using namespace rlutil;

void mostrar_menuhabitacion()
{
    gotoxy(50,9);
    setColor(WHITE);
    cout<<" MENU HABITACIONES"<<endl;
    gotoxy(50,10);
    cout<<"---------------------"<<endl;
    gotoxy(50,11);
    cout<<"1 - ALTA DE HABITACION"<<endl;
    gotoxy(50,12);
    cout<<"2 - MODIFICACION DATOS DE HABITACION"<<endl;
    gotoxy(50,13);
    cout<<"3 - CONSULTAS POR NUMERO DE HABITACION"<<endl;
    gotoxy(50,14);
    cout<<"4 - DESHABILITAR HABITACION"<<endl;
    gotoxy(50,15);
    cout<<"---------------------"<<endl;
    gotoxy(50,16);
    setColor(YELLOW);
    cout<<"0 - VOLVER AL MENU PRINCIPAL"<<endl;
}


void MenuHabitacion ()
{

    bool salir=false;
    char op;
    char exi;
    while(!salir)
    {
        cls();
        mostrar_menuhabitacion();
        setColor(WHITE);
        gotoxy(50,16);
        cout<<endl;
        gotoxy(50,18);
        cout<<"INGRESE UNA OPCION: ";
        cin.get(op);
        cin.ignore();
        switch(op)
        {
        case '1':
        {

            altaHabitacion();

        }
        break;

        case '2':
        {
            modificarDatosHabitacion();
        }
        break;

        case '3':
        {
            consultaHabitacion();
        }
        break;
        case '4':
        {

        }
        break;

        case '5':
        {

        }
        break;


        case '0':
        {
            cls();
            gotoxy(50,19);
            cout<<"Seguro que desea volver al menu principal??  S/N: ";
            cin.ignore();
            cin.get(exi);
            switch (exi)
            {
            case 's':
            case 'S':
            {
                Menu();
                cls();
            }
            break;

            case 'n':
            case 'N':
            {
                MenuCliente();
            }
            break;
            default:
            {
                gotoxy(60,19);
                cls ();
                setColor(WHITE);
                cout<<"OPCION INCORRECTA!!!"<<endl;
                cls();
                system("pause");
                mostrar_menu ();
            }

            }
        }
        break;

        default:
        {
            gotoxy(50,17);
            setColor(YELLOW);
            cls();
            cout<<"OPCION INCORRECTA!!!"<<endl;
            cin.get();

        }

        }
    //cin.ignore();
    }



}


void altaHabitacion ()
{
    char guardar;
    Habitacion ha;
    HabitacionArchivo har;
    cls ();
    int numero, pos;
    cout<<"INGRESE NUMERO DE HABITACION A CARGAR: ";
    cin>>numero;
    pos=har.buscar(numero);
    if(pos>=0)
    {
        cout<<"EL NUMERO DE HABITACION YA SE ENCUENTRA EN NUESTROS REGISTROS"<<endl;
        system("pause");
    }
    else
    {
        ha.Cargar(numero);
        ha.Mostrar ();
        cout<< "LOS DATOS SON CORRECTOS? DESEA GUARDARLOS? S/N: ";
        cin.ignore ();
        cin.get (guardar);
        switch (guardar)
        {
        case 's':
        case 'S':
        {
            if (har.guardar(ha))
            {
                cout<< "HABITACION GUARDADA CON EXITO";
                cin.get();
            }
            else
            {
                cout<< "SE GENERO UN PROBLEMA AL GUARDARLA TIENE QUE VOLVER A CARGAR LOS DATOS";
                cin.get();
            }
        }
        break;

        case 'n':
        case 'N':
        {
            cout<< "LOS DATOS NO HAN SIDO GUARDADOS";
            cin.get();
            return;
        }
        break;

        default:
        {
            gotoxy(50,17);
            setColor(YELLOW);
            cls();
            cout<<"OPCION INCORRECTA!!!"<<endl;
            cin.get();
            system ("pause");
        }


        }
        cin.ignore();
    }
}

void consultaHabitacion()
{
    Habitacion ha;
    HabitacionArchivo har;
    cls();
    int numero,pos;
    cout<< "INGRESE EL NUMERO HABITACION PARA BUSCAR EN LOS REGISTROS: ";
    cin>>numero;
    pos=har.buscar(numero);
    if(pos<0)
    {
        cout<<"EL NUMERO DE HABITACION NO EXISTE EN LOS REGISTROS"<<endl;
        system("pause");
    }
    else
    {
        ha=har.leer(pos);
        if(ha.getDisponible()==true)
        {
            ha.Mostrar();
            system("pause");
        }
    }
}

void modificarDatosHabitacion()
{

    Habitacion ha;
    HabitacionArchivo har;
    cls();
    int numero,pos;
    cout<< "INGRESE EL NUMERO HABITACION A MODIFICAR: ";
    cin>>numero;
    pos=har.buscar(numero);
    cout<< "NUMERO    "<< numero<< "   POS     "<< pos<<endl;
    if(pos<0)
    {
        cout<<"EL NUMERO DE HABITACION NO ESTA REGISTRADO"<<endl;
        system("pause");
    }
    else
    {
        ha.Cargar(numero);
        if (har.modificarArchivo(pos,ha))
        {
            cout<< "DATOS DE HABITACION MODIFICADOS: "<<endl;
            cout<< "NUMERO   "<< numero<< "    POS   "<< pos;
            ha=har.leer(pos);
            ha.Mostrar();

            system("pause");
        }
    }
}
