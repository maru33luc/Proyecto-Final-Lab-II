#ifndef EMPRESA_H_INCLUDED
#define EMPRESA_H_INCLUDED

typedef struct Empresa
{
int id; //AUTOGENERADO
char nombre[50];
char cuit[13];
char codIVA[2]; //Posibles valores: CF RI MT EX
int activo;
}Empresa;

Empresa crearEmpresa(int,char[],char[],char[],int);
#endif
=======

void PersistirEmpresas (char nombreArch[]);
int cantidadRegistrosArchivoGenerica (char nombreArchivo[], int sizeofDato);
void mostrarUnaEmpresa(Empresa a);
int verificarPresenciaEmpresaBase (char nombreArchEmpresa[],char cuit[]) ;
void mostrarArchivoEmpresas (char nombreArchEmpresas[]) ;
int buscarIdEmpresaXCUIT (char nombreArchEmpresa[], char num[]);
void mostrarRegistroEmpresaXIdEmpresa (char nombreArchEmpresa [],int id) ;



#endif // EMPRESA_H_INCLUDED

