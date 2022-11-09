#include <iostream>
#include <cstring>
#include "rlutil.h"
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
    cout<<"5 - LISTADO DE CLIENTES"<<endl;
    gotoxy(50,16);
    cout<<"---------------------"<<endl;
    gotoxy(50,17);
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
            ConsultaCliente();

        }
        break;
        case '4':
        {
            bajaCliente();
        }
        break;
        case '5':
        {
            cls ();
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
            msjerror ();

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
    if (dni==0)
    {
        return;
    }
    pos=ca.buscar(dni);
    if(pos>=0)
    {
        cl=ca.leer(pos);
        if(cl.getActivo())
        {

            cout<<"EL NUMERO DE DNI DE CLIENTE YA SE ENCUENTRA EN NUESTROS REGISTROS"<<endl;
            system("pause");
        }
        else
        {
            char alta;
            cout<< "EL NUMERO DE DNI DE CLIENTE YA SE ENCUENTRA EN NUESTROS REGISTROS PERO ESTA DADO DE BAJA"<<endl;
            cout<< "DESEA DARLE DE ALTA? S/N: ";
            cin.ignore();
            cin.get(alta);
            switch (alta)
            {
            case 's':
            case 'S':
            {
                cl.setActivo(true);
                ca.guardar(cl,pos);
                cl.Mostrar();
                cin.get();
            }
            break;

            case 'n':
            case 'N':
            {
                return;
            }
            break;

            default:
            {
                msjerror ();
            }

            }

        }
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
                cout<< "CLIENTE GUARDADO CON EXITO"<<endl;
                cin.get();
            }
            else
            {
                cout<< "SE GENERO UN PROBLEMA AL GUARDARLO TIENE QUE VOLVER A CARGAR LOS DATOS"<<endl;
                cin.get();
            }
        }
        break;

        case 'n':
        case 'N':
        {
            cout<< "LOS DATOS NO HAN SIDO GUARDADOS"<<endl;
            cin.get();
        }
        break;

        default:
        {
            msjerror ();
        }


        }
    }
}
int ConsultaCliente ()
{
    Cliente cl;
    ClienteArchivo ca;
    char op;
    cls();

    int dni,pos;
    cout<< "INGRESE EL NUMERO DE DNI DE CLIENTE: ";
    cin>>dni;
    pos=ca.buscar(dni);
    if(pos<0)
    {
        cout<<"EL NUMERO DE DNI CLIENTE NO ESTA REGISTRADO"<<endl;
        cout<< "DESEA DARLO DE ALTA?? S/N:";
        cin.ignore();
        cin.get(op);
        switch (op)
        {
        case 's':
        case 'S':
        {
            altaCliente();
        }
        break;
        case 'n':
        case 'N':
        {
            return 0;
        }
        default:
        {
            msjerror ();

        }
        }
        system("pause");
    }
    else
    {
        cl=ca.leer(pos);
        if(cl.getActivo())
        {
            cl.Mostrar();
            system("pause");
        }
        else
        {
            cout<< "EL CLIENTE ESTA DADO DE BAJA";
            cin.get();
        }
    }
    return dni;
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
    {
        cl=ca.leer(pos);
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
    Cliente cl;
    ClienteArchivo ca;
    int dni,pos=-1;
    cls ();
    cout<< "INGRESE EL DNI DEL CLIENTE QUE QUIERE BORRAR DE REGISTROS: ";
    cin>> dni;
    pos=ca.buscar(dni);
    if(pos<0)
    {
        char alta;
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

