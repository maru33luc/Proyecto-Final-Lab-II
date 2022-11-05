#include <stdio.h>
#include <stdlib.h>
#include "Empresa.h"
#include "Cliente.h"
#include "Proveedor.h"
#include "Facturas.h"
#include "Resumenes.h"
#include "NodoSimpleEmpresa.h"
#include "NodoDobleFactura.h"

void mostrarUnProveedor(Proveedor p)
{
    printf("\---------------------------------------------------------\n");
    printf("\nNombre de la empresa: %s\n", p.nombre);
    printf("\nNumero de CUIT de la Empresa: %s\n", p.cuit);
    printf("\---------------------------------------------------------\n");
}

