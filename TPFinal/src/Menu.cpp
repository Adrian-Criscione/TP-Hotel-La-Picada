#include <iostream>
#include <cstring>
#include "Menu.h"
#include "rlutil.h"
#include "HabitacionArchivo.h"
#include "menu_cliente.h"
#include "menu_habitacion.h"

using namespace std;
using namespace rlutil;

void Menu()
{
    bool salir=false; ///VARIABLE PARA EL while
    char op;          ///VARIABLE PARA LA OPCION
    char exi;        ///VARIABLE PARA LA SALIDA

    while(!salir)            ///MIENTRAS SEA DISTINTO DE SALIR
    {
         setConsoleTitle("HOTEL LA PICADA");///CAMBIA EL NOMBRE DE LA CONSOLA
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
            cls ();
             setBackgroundColor(MAGENTA);
            MenuReservas();
        }
        break;

        case '2':
        {
            cls ();
             setBackgroundColor(CYAN);
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
            case 'S':
            {
                salir=true;

            }
            break;
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
        break;

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




