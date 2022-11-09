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
        const char* getDescricion();
        float getPrecio ();
        bool getActivo ();
        void setNumeroreserva();
        void setCodigoServicio (int);
        void setDescripcion(const char *descripcion);
        void setPrecio (float);
        void setActivo (bool);
        void Cargar(int codigoservicio);
        void Mostrar();
        ////ESTO SE VA A GUARDAR EN LA RAMA DE PRUEBA/////
};
#endif // SERVICIO_H_INCLUDED
