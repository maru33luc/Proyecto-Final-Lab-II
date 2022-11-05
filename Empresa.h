#ifndef EMPRESA_H_INCLUDED
#define EMPRESA_H_INCLUDED

typedef struct Empresa
{
    char nombre[50];
    char cuit[11];
    int activa_emp;
} Empresa;



void PersistirEmpresas (char nombreArch[]);
int cantidadRegistrosArchivoGenerica (char nombreArchivo[], int sizeofDato);
void mostrarUnaEmpresa(Empresa a);
int verificarPresenciaEmpresaBase (char nombreArchEmpresa[],char cuit[]) ;
void mostrarArchivoEmpresas (char nombreArchEmpresas[]) ;
int buscarIdEmpresaXCUIT (char nombreArchEmpresa[], char num[]);
void mostrarRegistroEmpresaXIdEmpresa (char nombreArchEmpresa [],int id) ;
Empresa crearEmpresa(char nombre[],char cuit[]);
void TestLibreriaEmpresa();

#endif // EMPRESA_H_INCLUDED
