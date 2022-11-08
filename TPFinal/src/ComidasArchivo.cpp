#include "ComidasArchivo.h"

Comidas ComidasArchivo::leer(int nroRegistro)
{
    Comidas co;
    FILE* p;
    p = fopen("comidas.dat", "rb");
    if (p == NULL)
    {
        return co;
    }
    fseek(p, nroRegistro * sizeof(Comidas), SEEK_SET);
    fread(&co, sizeof(Comidas), 1, p);
    fclose(p);
    return co;
}

bool ComidasArchivo::guardar(Comidas co)
{
    FILE* p = fopen("comidas.dat", "ab");
    if (p == NULL)
    {
        return false;
    }
    bool ok = fwrite(&co, sizeof(Comidas), 1, p);
    fclose(p);
    return ok;
}


bool ComidasArchivo::guardar(Comidas co, int nroRegistro)
{
    FILE* p = fopen("comidas.dat", "rb+");
    if (p == NULL)
    {
        return false;
    }
    fseek(p, nroRegistro * sizeof(Comidas), SEEK_SET);
    bool ok = fwrite(&co, sizeof(Comidas), 1, p);
    fclose(p);
    return ok;
}

int ComidasArchivo::getCantidad()
{
    FILE* p = fopen("comidas.dat", "rb");
    if (p == NULL)
    {
        return 0;
    }
    fseek(p, 0, SEEK_END);
    int cant = ftell(p) / sizeof(Comidas);
    fclose(p);
    return cant;
}

int ComidasArchivo::buscar(int numComida)
{
    int cant = getCantidad();
    Comidas co;
    for (int i = 0; i < cant; i++)
    {
        co = leer(i);
        if (co.getNumComida() == numComida)
        {
            return i;
        }
    }

    return -1;
}

bool ComidasArchivo::ModificarArchivo(int pos, Comidas co)

{
    FILE *p;
    p=fopen("comidas.dat","rb+");
    if(p==NULL) return false;
    fseek(p, pos * sizeof(Comidas), 0);

    bool escribio=fwrite(&co,pos * sizeof (Comidas), 1, p);

    fclose(p);
    return escribio;

}
