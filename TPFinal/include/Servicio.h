#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED
#include <cstring>
#include <iostream>

using namespace std;
////SIGO MODIFICANDO EL .H////
class Servicio
{
private:
        int _numeroReserva;
        int _codigoServicio;
        char _descripcion[30];
        float _precio;
        bool _activo;
public:
        int getCodigoServicio ();
        int getComida ();
        int getExcursiones ();
        float getPrecio ();
        bool getActivo ();
        void setCodigoServicio (int);
        void setComida (int);
        void setExcursiones (int);
        void setPrecio (float);
        void setActivo (bool);
        void Cargar(int codigoservicio);
        void Mostrar();
<<<<<<< Updated upstream


=======
        ////ESTO SE VA A GUARDAR EN LA RAMA DE PRUEBA/////

<<<<<<< HEAD
=======
        ///////ESPERO QUE FUNCIONE!!!
>>>>>>> 94e5ec1190fed029e08efc126ddf7b737f986f27
>>>>>>> Stashed changes
};
#endif // SERVICIO_H_INCLUDED
