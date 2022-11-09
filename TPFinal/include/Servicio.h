#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED
#include <cstring>
#include <iostream>

using namespace std;

class Servicio
{
private:
        int _numeroReserva;
        int _codigoServicio;
        char _descripcion[30];
        float _precio;
        bool _activo;
public:
        int getNumeroReserva ();
        int getCodigoServicio ();
        float getPrecio ();
        bool getActivo ();
        void setCodigoServicio (int);
        void setComida (int);
        void setExcursiones (int);
        void setPrecio (float);
        void setActivo (bool);
        void Cargar(int codigoservicio);
        void Mostrar();


};
#endif // SERVICIO_H_INCLUDED
