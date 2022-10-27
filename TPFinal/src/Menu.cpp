#include <iostream>
#include <cstring>
#include "Menu.h"
#include "rlutil.h"
#include "ClienteArchivo.h"

using namespace std;
using namespace rlutil;


////////////////////////////FIXME NO SIEMPRE FUNCIONA LA OPCION DE SALIR DE MENU



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

void mostrar_menucliente()
{
    gotoxy(50,9);
    setColor(WHITE);
    cout<<" MENU CLIENTE"<<endl;
    gotoxy(50,10);
    cout<<"---------------------"<<endl;
    gotoxy(50,11);
    cout<<"1 - ALTA DE CLIENTE"<<endl;
    gotoxy(50,12);
    cout<<"2 - MODIFICACION DATOS DE CLIENTES"<<endl;
    gotoxy(50,13);
    cout<<"3 - CONSULTAS POR DNI"<<endl;
    gotoxy(50,14);
    cout<<"4 - ELIMINAR CLIENTE"<<endl;
    gotoxy(50,15);
    cout<<"---------------------"<<endl;
    gotoxy(50,16);
    setColor(YELLOW);
    cout<<"0 - VOLVER AL MENU PRINCIPAL"<<endl;
}
void MenuCliente ()
{
    Cliente cl;
    ClienteArchivo clarchivo;

    bool salir=false;
    char op;
    char exi;
    while(!salir)
    {
        cls();
        mostrar_menucliente();
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
            ///CARGAR REGISTRO
            ///VALIDAR REGISTRO
            ///GRABAR REGISTRO SI VALIDO

            int dni, pos;
            cout<<"CARGUE NUMERO DE DNI DEL CLIENTE: ";
            cin>>dni;
            pos=clarchivo.buscar(dni);
            if(pos>=0)
            {
                cout<<"EL NUMERO DE DNI DE CLIENTE YA SE ENCUENTRA EN NUESTROS REGISTROS"<<endl;
                system("pause");
            }
            else
            {
                cl.Cargar(dni);
                cl.Mostrar();
                system("pause");
                cout<< "LOS DATOS SON CORRECTOS? ";
                cin.get();

                clarchivo.guardar(cl);
                cls();
            }
        }
        break;

        case '2':
        {
            cls();
            int dni,pos;
            cout<< "INGRESE EL NUMERO DE CLIENTE A MODIFICAR: ";
            cin>>dni;
            pos=clarchivo.buscar(dni);
            if(pos<0)
            {
                cout<<"EL NUMERO DE DNI CLIENTE NO ESTA REGISTRADO"<<endl;
                system("pause");
            }
            else
            {

                clarchivo.ModificarArchivo(clarchivo.buscar(dni));

                system("pause");
            }
        }

        break;

        case '3':
        {
            cls();
             int dni,pos;
            cout<< "INGRESE EL NUMERO DE DNI DE CLIENTE PARA BUSCAR EN REGISTROS: ";
            cin>>dni;
            pos=clarchivo.buscar(dni);
            clarchivo.leer(pos);
            cl.Mostrar(dni);
                system ("pause");
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
            cin.get(exi);    ///LEE UN CARACTER POR TECLADO
            cin.ignore();  ///BORRA EL BUFER DEL TECLADO
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
    cin.get();/// DETIENE LA PANTALLA

}





