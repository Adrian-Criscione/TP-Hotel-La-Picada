#include "ServicioArchivo.h"

Servicio ServicioArchivo::leer(int nroRegistro){
  Servicio ser;
  FILE* p;
  p = fopen("servicio.dat", "rb");
  if (p == NULL){
    return ser;
  }
  fseek(p, sizeof(Servicio) * nroRegistro, SEEK_SET);
  fread(&ser, sizeof(Servicio), 1, p);
  fclose(p);
  return ser;
}

bool ServicioArchivo::guardar(Servicio ser) {
  FILE* p = fopen("servicio.dat", "ab");
  if (p == NULL) {
    return false;
  }
  bool ok = fwrite(&ser, sizeof(Servicio), 1, p);
  fclose(p);
  return ok;
}

bool ServicioArchivo::guardar(Servicio ser, int nroRegistro) {
  FILE* p = fopen("servicio.dat", "rb+");
  if (p == NULL) {
    return false;
  }
  fseek(p, nroRegistro * sizeof(Servicio), SEEK_SET);
  bool ok = fwrite(&ser, sizeof(Servicio), 1, p);
  fclose(p);
  return ok;
}

int ServicioArchivo::getCantidad() {
  FILE* p = fopen("servicio.dat", "rb");
  if (p == NULL) {
    return 0;
  }
  fseek(p, 0, SEEK_END);
  int cant = ftell(p) / sizeof(Servicio);
  fclose(p);
  return cant;
}

int ServicioArchivo::buscar(int numero) {
  int cant = getCantidad();
  Servicio ser;
  for (int i = 0; i < cant; i++) {
    ser = leer(i);
    if (ser.getCodigoServicio()==numero) {
      return i;
    }
  }
  return -1;
}

