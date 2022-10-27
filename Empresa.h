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

void mostrarEmpresa(Empresa);
Empresa crearEmpresa(int,char[],char[],char[],int);
#endif
