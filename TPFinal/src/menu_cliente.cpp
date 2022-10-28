#include <iostream>
#include <cstring>
#include "Menu.h"
#include "rlutil.h"
#include "ClienteArchivo.h"
#include "menu_cliente.h"

using namespace std;
using namespace rlutil;


//MENU CLIENTES
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
    cout<<"4 - DAR DE BAJA A UN CLIENTE"<<endl;
    gotoxy(50,15);
    cout<<"---------------------"<<endl;
    gotoxy(50,16);
    setColor(YELLOW);
    cout<<"0 - VOLVER AL MENU PRINCIPAL"<<endl;
}


void MenuCliente ()
{
    Cliente cl;
    ClienteArchivo ca;
    bool salir=false;
    char po;
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
        cin.get(po);    ///LEE UN CARACTER POR TECLADO
        cin.ignore();  ///BORRA EL BUFER DEL TECLADO

        switch(po)     ///DEPENDIENDO DE LA OPCION QUE INGRESE EL USUARIO
        {
        case '1':
        {
            altaCliente ();
        }
        break;
        case '2':
        {
            cls();
            int dni,pos;
            cout<< "INGRESE EL NUMERO DE CLIENTE A MODIFICAR: ";
            cin>>dni;
            pos=ca.buscar(dni);
            if(pos<0)
            {
                cout<<"EL NUMERO DE DNI CLIENTE NO ESTA REGISTRADO"<<endl;
                system("pause");
            }
            else
            {

                ca.ModificarArchivo(ca.buscar(dni));

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
            pos=ca.buscar(dni);
            if(pos<0)
            {
                cout<<"EL NUMERO DE DNI CLIENTE NO ESTA REGISTRADO"<<endl;
                system("pause");
            }
            else
            {
                cl=ca.leer(pos);
                cl.Mostrar();
                system("pause");
            }

        }
        break;
        case '4':
        {
            bajaCliente();
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
            case 'S':
            {
                return;
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
            cin.ignore();

        }

        }
    }

}
void altaCliente ()
{
    char guardar;
    Cliente cl;
    ClienteArchivo ca;
    cls ();
    int dni, pos;
    cout<<"CARGUE NUMERO DE DNI DEL CLIENTE: ";
    cin>>dni;
    pos=ca.buscar(dni);
    if(pos>=0)
    {
        cout<<"EL NUMERO DE DNI DE CLIENTE YA SE ENCUENTRA EN NUESTROS REGISTROS"<<endl;
        system("pause");
    }
    else
    {
        cl.Cargar(dni);
        cl.Mostrar ();
        cout<< "LOS DATOS SON CORRECOTOS? DESEA GUARDARLOS? S/N: ";
        cin.ignore ();
        cin.get (guardar);
        switch (guardar)
        {
        case 's':
        {
            ca.guardar(cl);
            system("pause");
        }
        break;

        case 'S':
        {
            ca.guardar(cl);
            system("pause");
        }
        break;
        case 'n':
        {
            altaCliente();
        }
        break;
        case 'N':
        {
            altaCliente();
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
    }
}

bool bajaCliente()
{
    ///INGRESAR VALOR A BUSCAR
    ///LEER REGISTRO
    ///MODIFICAR ESTADO DEL REGISTRO
    ///SOBREESCRIBIR REGISTRO MODIFICADO
    Cliente cl;
    ClienteArchivo ca;
    int dni,pos;
    cls ();
    cout<< "INGRESE EL DNI DEL CLIENTE QUE QUIERE BORRAR DE REGISTROS: ";
    cin>> dni;
    pos=ca.buscar(dni);
    if(pos<0)
    {
        cout<<"EL NUMERO DE DNI CLIENTE NO ESTA REGISTRADO"<<endl;
        system("pause");
    }
    else
    {

        ca.leer(pos);
///FIXME

        if(cl.getActivo() ==false)
        {
            cout<<"EL REGISTRO EXISTE PERO YA ESTA DADO DE BAJA"<<endl;
            system("pause");
            return false;
        }
        else
        {
            cl.setActivo(false);
            cout<< "SE ELIMINO EL REGISTRO CON EXITO";
            system ("pause");
        }
        return true;
    }
}
