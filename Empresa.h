#ifndef EMPRESA_H_INCLUDED
#define EMPRESA_H_INCLUDED



typedef struct Empresa
{
    char nombre[50];
    char cuit[12];
    int activa_emp;
} Empresa;


void mostrarUnaEmpresa(Empresa a);
Empresa crearEmpresa(char nombre[],char cuit[]);
void TestLibreriaEmpresa();

#endif // EMPRESA_H_INCLUDED
