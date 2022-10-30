#ifndef EXCURSIONES_H
#define EXCURSIONES_H


class Excursiones
{
    private:
       int _idExcursion;
       float _precio;
       bool _disponible;

    public:
        int getIdExcursion();
        float getPrecio();
        bool getDisponible();
        void setIdExcursion(int idExcursion);
        void setPrecio(float precio);
        void setDisponible(bool disponible);
        void cargar(int id);
        void mostrar();
};

#endif // EXCURSIONES_H
