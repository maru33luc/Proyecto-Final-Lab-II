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


Cliente_Proveedor crearCP(char nombre[],char cuit_cp[],char cp)
{
    Cliente_Proveedor nuevo_cp;
    strcpy(nuevo_cp.nombre,nombre);
    strcpy(nuevo_cp.cuit_cliente_proveedor,cuit_cp);
    nuevo_cp.cp = cp;

    return nuevo_cp;
}

void mostrarUnCP(Cliente_Proveedor CP)
{
    printf("----------------------------\n");
    printf("Nombre: %s\n",CP.nombre);
    printf("CP: %c\n",CP.cp);
    printf("CUIT: %s\n",CP.cuit_cliente_proveedor);
}

Cliente_Proveedor pasarDatosRegistroAUnClienteProveedor(Registro_Factura a)
{
    Cliente_Proveedor dato;

    strcpy(dato.nombre,a.nombre_cliente_proveedor);
    strcpy(dato.cuit_cliente_proveedor,a.cuit_cliente_proveedor);
    dato.cp=a.cp;

    return dato;
}











