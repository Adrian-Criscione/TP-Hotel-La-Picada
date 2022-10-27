#include <iostream>
#include <cstring>
#include "Menu.h"
#include "rlutil.h"
#include "ClienteArchivo.h"
#include "HabitacionArchivo.h"
#include "menu_cliente.h"
using namespace std;
using namespace rlutil;

void Menu()
{
    bool salir=false; ///VARIABLE PARA EL while
    char op;          ///VARIABLE PARA LA OPCION
    char exi;        ///VARIABLE PARA LA SALIDA

    while(!salir)            ///MIENTRAS SEA DISTINTO DE SALIR
    {
        cls();                     ///LIMPIA LA PANTALLA
        mostrar_menu(); ///LLAMA A MOSTRAR MENU
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
        }
        break;

        case '2':
        {
            cls ();
            MenuCliente();

        }
        break;

        case '3':
        {
            cls();
            MenuHabitacion();
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
            cout<<"Seguro que desea salir??  S/N: ";
            cin.get(exi);    ///LEE UN CARACTER POR TECLADO
            cin.ignore();  ///BORRA EL BUFER DEL TECLADO
            switch (exi)
            {
            case 's':
            {
                salir=true;

            }
            break;
            case 'S':
            {
                salir=true;

            }
            break;
            case 'n':
            {
                Menu();
            }
            break;
            case 'N':
            {
                Menu();
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
    }
    cin.get();/// DETIENE LA PANTALLA

}

void mostrar_menu()
{
    gotoxy(50,9);
    setColor(WHITE);
    cout<<" MENU PRINCIPAL"<<endl;
    gotoxy(50,10);
    cout<<"---------------------"<<endl;
    gotoxy(50,11);
    cout<<"1 - RESERVA"<<endl;
    gotoxy(50,12);
    cout<<"2 - CLIENTES"<<endl;
    gotoxy(50,13);
    cout<<"3 - HABITACIONES"<<endl;
    gotoxy(50,14);
    cout<<"4 - SERVICIOS"<<endl;
    gotoxy(50,15);
    cout<<"5 - INFORMES"<<endl;
    gotoxy(50,16);
    cout<<"---------------------"<<endl;
    gotoxy(50,17);
    setColor(YELLOW);
    cout<<"0 - SALIR"<<endl;
}


//MENU HABITACIONES
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
    Habitacion hab;
    HabitacionArchivo hab_ar;
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
            cls ();
            hab.setDisponible(true);
            hab.Cargar();
            cls();
            cout<<"Habitacion agregada: "<<endl;
            hab.Mostrar();
            hab_ar.guardar(hab);
            system("pause");

        }
        break;

        case '2':
        {

        }
        break;

        case '3':
        {

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
            cin.get(exi);
            cin.ignore();
            switch (exi)
            {
            case 's':
            {
                Menu();
                cls;
            }
            break;
            case 'S':
            {
                Menu();
                cls;
            }
            break;
            case 'n':
            {
                MenuCliente();
            }
            break;
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
    }
    cin.get();

}

