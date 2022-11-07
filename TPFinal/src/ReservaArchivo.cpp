#include "ReservaArchivo.h"

Reserva ReservaArchivo::leer(int nroRegistro) {
  Reserva r;
  FILE* p;
  p = fopen("reservas.dat", "rb");
  if (p == NULL) {
    return r;
  }
  fseek(p, nroRegistro * sizeof(Reserva), SEEK_SET);
  fread(&r, sizeof(Reserva), 1, p);
  fclose(p);
  return r;
}

bool ReservaArchivo::guardar(Reserva r) {
  FILE* p = fopen("reservas.dat", "ab");
  if (p == NULL) {
    return false;
  }
  bool ok = fwrite(&r, sizeof(Reserva), 1, p);
  fclose(p);
  return ok;
}

bool ReservaArchivo::guardar(Reserva r, int nroRegistro) {
  FILE* p = fopen("reservas.dat", "rb+");
  if (p == NULL) {
    return false;
  }
  fseek(p, nroRegistro * sizeof(Reserva), SEEK_SET);
  bool ok = fwrite(&r, sizeof(Reserva), 1, p);
  fclose(p);
  return ok;
}

int ReservaArchivo::getCantidad() {
  FILE* p = fopen("reservas.dat", "rb");
  if (p == NULL) {
    return 0;
  }
  fseek(p, 0, SEEK_END);
  int cant = ftell(p) / sizeof(Reserva);
  fclose(p);
  return cant;
}

int ReservaArchivo::buscar(int numero) {
  int cant = getCantidad();
  Reserva r;
  for (int i = 0; i < cant; i++) {
    r = leer(i);
    if (r.getNumeroReserva() == numero) {
      return i;
    }
  }
  return -1;
}
