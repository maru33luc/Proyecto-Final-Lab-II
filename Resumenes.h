#ifndef RESUMENES_H_INCLUDED
#define RESUMENES_H_INCLUDED

#include "NodoDobleFactura.h"
#include "NodoSimpleEmpresa.h"

typedef struct NodoListarFacturas{
    char nombreEmpresa [30];
    Factura dato;
    char nombreClienteProveedor [30];
    char cp;
    struct NodoListarFacturas *sig;
}NodoListarFacturas;


///--------------LIBRERIA LISTA SIMPLE LISTADOS FACTURAS-------------

NodoListarFacturas* inicListaSimpleListarFacturas();
NodoListarFacturas* crearNodoListarFacturas(char nombreEmp[],Factura a, char nombreCliProv[],char cp;
NodoListarFacturas* agregarNodoListarFactAlPrincipio(NodoListarFacturas* lista, NodoListarFacturas* nuevoNodo);


void listarTodasFacturasXOrdenFecha (nodoSimpleEmpresa *lista);

nodoDobleFactura *listarFacturasDetEmpresaXPeriodo (nodoSimpleEmpresa *lista,char nombre_empresa[],Fecha fechaInicio,Fecha fechaFinal);

nodoDobleFactura* listarVentasDetEmpresaXPeriodo (nodoSimpleEmpresa *lista,char nombre_empresa[],Fecha fechaInicio,Fecha fechaFinal);

nodoDobleFactura* listarComprasDetEmpresaXPeriodo (nodoSimpleEmpresa *lista,char nombre_empresa[],Fecha fechaInicio,Fecha fechaFinal);

int retornaSiFechaEstaComprendidaEnPeriodoDado (Fecha dato, Fecha limInf, Fecha limSup);

#endif // RESUMENES_H_INCLUDED
