#include "ClienteArchivo.h"

Cliente ClienteArchivo::leer(int nroRegistro)
{
    Cliente cl;
    FILE* p;
    p = fopen("cliente.dat", "rb");
    if (p == NULL)
    {
        return cl;
    }
    fseek(p, nroRegistro * sizeof(Cliente), SEEK_SET);
    fread(&cl, sizeof(Cliente), 1, p);
    fclose(p);
    return cl;
}

bool ClienteArchivo::guardar(Cliente cl)
{
    FILE* p = fopen("cliente.dat", "ab");
    if (p == NULL)
    {
        return false;
    }
    bool ok = fwrite(&cl, sizeof(Cliente), 1, p);
    fclose(p);
    return ok;
}

bool ClienteArchivo::guardar(Cliente cl, int nroRegistro)
{
    FILE* p = fopen("cliente.dat", "rb+");
    if (p == NULL)
    {
        return false;
    }
    fseek(p, nroRegistro * sizeof(Cliente), SEEK_SET);
    bool ok = fwrite(&cl, sizeof(Cliente), 1, p);
    fclose(p);
    return ok;
}

int ClienteArchivo::getCantidad()
{
    FILE* p = fopen("cliente.dat", "rb");
    if (p == NULL)
    {
        return 0;
    }
    fseek(p, 0, SEEK_END);
    int cant = ftell(p) / sizeof(Cliente);
    fclose(p);
    return cant;
}

int ClienteArchivo::buscar(int dni)
{
    if (dni==0)
    {
        return-1;
    }

    int cant = getCantidad();
    Cliente cl;
    for (int i = 0; i < cant; i++)
    {
        cl = leer(i);
        if (cl.getDni() == dni)
        {
            return i;
        }
    }

    return -1;
}

bool ClienteArchivo::ModificarArchivo(int pos, Cliente cl)

{
    FILE *p;
    p=fopen("cliente.dat","rb+");
    if(p==NULL) return false;
    fseek(p, pos * sizeof(Cliente), 0);

    bool escribio=fwrite(&cl,pos * sizeof (Cliente), 1, p);

    fclose(p);
    return escribio;

}

