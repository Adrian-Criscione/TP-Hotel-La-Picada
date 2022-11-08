#include <iostream>
#include "menu_cliente.h"
#include "menu_habitacion.h"
using namespace std;

void Menu ();
void mostrar_menu();
void msjerror ();



void MenuHabitacion();
////////////////////
///MENU RESERVAS
///////////////////
void MenuReservas ();
void mostrar_menureservas();
void CargarReserva();
void BuscarReserva ();
void mostrar_menubuscarreservas();
void BuscarReservaPorNumeroReserva ();
void BuscarReservaPorNumeroDni ();
void BuscarReservaPorNumeroHabitacion ();

void CancelarReserva ();

////////////////////
///MENU CLIENTE
///////////////////
void MenuCliente();
void altaCliente ();
int alta();
void bajaCliente();
int ConsultaCliente ();
void modificardatos ();
////////////////////
///MENU HABITACIONES
///////////////////
void MenuHabitacion();
void altaHabitacion();
int consultaHabitacion();
void modificarDatosHabitacion();
void bajaHabitacion();
