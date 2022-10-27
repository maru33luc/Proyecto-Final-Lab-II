#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Compras.h"
#include "Empresa.h"
#include "Ventas.h"

void mostrarEmpresa(Empresa e)
{
    printf("Id: %i \n",e.id);
    printf("El nombre de la empresa es: %s \n",e.nombre);
    printf("Codigo de IVA: %s \n",e.codIVA);
    printf("CUIT: %s \n",e.cuit);
    printf("Estado: ");
    e.activo?printf("Activo\n"):printf("Inactivo\n");
}

Empresa crearEmpresa(int id,char nombre[],char cuit[],char codIVA[],int activo){
    Empresa e;
    e.id = id;
    strcpy(e.nombre,nombre);
    strcpy(e.cuit,cuit);
    strcpy(e.codIVA,codIVA);
    e.activo = activo;

    return e;
}
