#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Empresa.h"
#include "Facturas.h"
#include "Resumenes.h"
#include "NodoSimpleEmpresa.h"
#include "NodoDobleFactura.h"
#include "Cliente_Proveedor.h"
#include "NodoSimpleCP.h"


void mostrarUnaEmpresa(Empresa a)
{

    printf("\n---------------------------------------------------------\n");
    printf("\nNombre de la empresa: %s\n", a.nombre);
    printf("\nNumero de CUIT de la Empresa: %s\n", a.cuit);
    printf("\nEstado de la Empresa (0 activa; 1 inactiva: %d\n",a.activa_emp);
    printf("\n---------------------------------------------------------\n");
}

Empresa crearEmpresa(char nombre[],char cuit[]){
  Empresa emp;
  strcpy(emp.nombre,nombre);
  strcpy(emp.cuit,cuit);
  emp.activa_emp = 1;
  return emp;
}


