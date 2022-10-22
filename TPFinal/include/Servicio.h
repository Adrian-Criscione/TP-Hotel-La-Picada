#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED


class Servicio
{
private:
        int _codigoServicio;
        int _comida;
        int _excursiones;
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
        void Cargar();
        void Mostrar();


};
#endif // SERVICIO_H_INCLUDED
