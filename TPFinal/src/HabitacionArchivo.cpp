#include "HabitacionArchivo.h"

Habitacion HabitacionArchivo::leer(int nroRegistro) {
  Habitacion h;
  FILE* p;
  p = fopen("habitacion.dat", "rb");
  if (p == NULL) {
    return h;
  }
  fseek(p, nroRegistro * sizeof(Habitacion), SEEK_SET);
  fread(&h, sizeof(Habitacion), 1, p);
  fclose(p);
  return h;
}

bool HabitacionArchivo::guardar(Habitacion h) {
  FILE* p = fopen("habitacion.dat", "ab");
  if (p == NULL) {
    return false;
  }
  bool ok = fwrite(&h, sizeof(Habitacion), 1, p);
  fclose(p);
  return ok;
}

bool HabitacionArchivo::guardar(Habitacion h, int nroRegistro) {
  FILE* p = fopen("habitacion.dat", "rb+");
  if (p == NULL) {
    return false;
  }
  fseek(p, nroRegistro * sizeof(Habitacion), SEEK_SET);
  bool ok = fwrite(&h, sizeof(Habitacion), 1, p);
  fclose(p);
  return ok;
}

int HabitacionArchivo::getCantidad() {
  FILE* p = fopen("habitacion.dat", "rb");
  if (p == NULL) {
    return 0;
  }
  fseek(p, 0, SEEK_END);
  int cant = ftell(p) / sizeof(Habitacion);
  fclose(p);
  return cant;
}

int HabitacionArchivo::buscar(int numero) {
  int cant = getCantidad();
  Habitacion h;
  for (int i = 0; i < cant; i++) {
    h = leer(i);
    if (h.getNumero() == numero) {
      return i;
    }
  }
  return -1;
}


bool HabitacionArchivo::modificarArchivo(int pos,Habitacion ha)
{
    FILE *p;
    p=fopen("habitacion.dat","rb+");
    if(p==NULL) return false;
    fseek(p, pos * sizeof(Habitacion), 0);

    bool escribio=fwrite(&ha, pos * sizeof (Habitacion), 1, p);
    fclose(p);
    return escribio;

}
