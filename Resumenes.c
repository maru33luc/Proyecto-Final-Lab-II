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

void listarTodasFacturasXOrdenFecha (nodoSimpleEmpresa *lista)
{
    while(lista!=NULL)
    {
        mostrarUnaEmpresa(lista->dato);
        printf("\n-----------Lista de Clientes:----------------\n");
        while(lista->cli!=NULL)
        {
            mostrarUnCP(lista->cli->dato_cp);
            mostrarListaDoble(lista->cli->fact);
            lista->cli=lista->cli->sig;
        }
        printf("\n-----------Lista de Proveedores:----------------\n");
        while(lista->prov!=NULL)
        {
            mostrarUnCP(lista->prov->dato_cp);
            mostrarListaDoble(lista->prov->fact);
            lista->prov=lista->prov->sig;
        }
        lista=lista->sig;
    }
}
