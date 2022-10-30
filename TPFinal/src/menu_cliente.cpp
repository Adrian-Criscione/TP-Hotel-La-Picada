#include <iostream>
#include <cstring>
#include "Menu.h"
#include "rlutil.h"
#include "ClienteArchivo.h"


using namespace std;
using namespace rlutil;


//MENU CLIENTES

void mostrar_menucliente()
{
    setBackgroundColor(CYAN);
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
            modificardatos();
        }
        break;
        case '3':
        {
            consulta();

        }
        break;
        case '4':
        {
            bajaCliente();
        }
        break;
        case '5':
        {
            Cliente cl;
            ClienteArchivo ca;
            int pos=0;
            pos=ca.getCantidad();
            for (int i=0; i<pos; i++)
            {
                cl=ca.leer(i);
                if (cl.getActivo()==true)
                {
                    cl.Mostrar();
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
            gotoxy(50,17);
            setColor(YELLOW);
            cls();
            cout<<"OPCION INCORRECTA!!!"<<endl;
            anykey();

        }

        }
        cin.ignore();
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
        cout<< "LOS DATOS SON CORRECTOS? DESEA GUARDARLOS? S/N: ";
        cin.ignore ();
        cin.get (guardar);
        switch (guardar)
        {
        case 's':
        case 'S':
        {
            if (ca.guardar(cl))
            {
                cout<< "CLIENTE GUARDADO CON EXITO";
                cin.get();
            }
            else
            {
                cout<< "SE GENERO UN PROBLEMA AL GUARDARLO TIENE QUE VOLVER A CARGAR LOS DATOS";
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
    }
}
void consulta ()
{
    Cliente cl;
    ClienteArchivo ca;
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
        if(cl.getActivo()==true)
        {
            cl.Mostrar();
            system("pause");
        }
    }
}
void modificardatos()
{

    Cliente cl;
    ClienteArchivo ca;
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
    {   cl=ca.leer(pos);
        cl.Cargar(dni);

        if (ca.ModificarArchivo(pos, cl))
        {
            cout<< "DATOS DE CLIENTES MODIFICADOS: "<<endl;

            cl=ca.leer(pos);
            cl.Mostrar();

            system("pause");
        }
    }
}
void bajaCliente()
{
    ///INGRESAR VALOR A BUSCAR
    ///LEER REGISTRO
    ///MODIFICAR ESTADO DEL REGISTRO
    ///SOBREESCRIBIR REGISTRO MODIFICADO
    Cliente cl;
    ClienteArchivo ca;
    int dni=0,pos=-1;
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
        cl=ca.leer(pos);
        cl.Mostrar();
        if(cl.getActivo()==false)
        {
            cout<<"EL REGISTRO EXISTE PERO YA ESTA DADO DE BAJA"<<endl;
            system("pause");
        }
        else
        {
            cl.setActivo(false);
            if(ca.ModificarArchivo(pos,cl))
            {
                cout<< "SE ELIMINO EL REGISTRO CON EXITO"<<endl;
                system ("pause");
            }

        }

    }
}
