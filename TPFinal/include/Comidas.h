#ifndef COMIDAS_H
#define COMIDAS_H


class Comidas
{
    private:
        int _idComida;
        float _precio;
        bool _disponible;

    public:
        int getIdComida();
        float getPrecio();
        bool getDisponible();
        void setIdComida(int idComida);
        void setPrecio(float precio);
        void setDisponible(bool disponible);
        void cargar(int id);
        void mostrar();
};

#endif // COMIDAS_H
