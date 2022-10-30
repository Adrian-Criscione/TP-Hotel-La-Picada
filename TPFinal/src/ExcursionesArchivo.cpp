#include "ExcursionesArchivo.h"

Excursiones ExcursionesArchivo::leer(int nroRegistro)
{
    Excursiones ex;
    FILE* p;
    p = fopen("excursiones.dat", "rb");
    if (p == NULL)
    {
        return ex;
    }
    fseek(p, nroRegistro * sizeof(Excursiones), SEEK_SET);
    fread(&ex, sizeof(Excursiones), 1, p);
    fclose(p);
    return ex;
}

bool ExcursionesArchivo::guardar(Excursiones ex)
{
    FILE* p = fopen("excursiones.dat", "ab");
    if (p == NULL)
    {
        return false;
    }
    bool ok = fwrite(&ex, sizeof(Excursiones), 1, p);
    fclose(p);
    return ok;
}


bool ExcursionesArchivo::guardar(Excursiones ex, int nroRegistro)
{
    FILE* p = fopen("excursiones.dat", "rb+");
    if (p == NULL)
    {
        return false;
    }
    fseek(p, nroRegistro * sizeof(Excursiones), SEEK_SET);
    bool ok = fwrite(&ex, sizeof(Excursiones), 1, p);
    fclose(p);
    return ok;
}

int ExcursionesArchivo::getCantidad()
{
    FILE* p = fopen("excursiones.dat", "rb");
    if (p == NULL)
    {
        return 0;
    }
    fseek(p, 0, SEEK_END);
    int cant = ftell(p) / sizeof(Excursiones);
    fclose(p);
    return cant;
}

int ExcursionesArchivo::buscar(int numExcursion)
{
    int cant = getCantidad();
    Excursiones ex;
    for (int i = 0; i < cant; i++)
    {
        ex = leer(i);
        if (ex.getNumExcursion() == numExcursion)
        {
            return i;
        }
    }

    return -1;
}



bool ExcursionesArchivo::ModificarArchivo(int pos, Excursiones ex)

{
    FILE *p;
    p=fopen("excursiones.dat","rb+");
    if(p==NULL) return false;
    fseek(p, pos * sizeof(Excursiones), 0);

    bool escribio=fwrite(&ex,pos * sizeof (Excursiones), 1, p);

    fclose(p);
    return escribio;

}
