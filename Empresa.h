#ifndef EMPRESA_H_INCLUDED
#define EMPRESA_H_INCLUDED

typedef struct Empresa//Para revisar
{
    int id_empresa;
    char nombre[50];
    char cuit[10];
    char codIVA[2];//CF RI MT EX
} Empresa;

void PersistirEmpresas (char nombreArch[]);
int cantidadRegistrosArchivoGenerica (char nombreArchivo[], int sizeofDato);






#endif // EMPRESA_H_INCLUDED
