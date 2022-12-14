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
NodoListarFacturas* crearNodoListarFacturas(char nombreEmp[],Factura a, char nombreCliProv[],char cp);
NodoListarFacturas* agregarNodoListarFactAlPrincipio(NodoListarFacturas* lista, NodoListarFacturas* nuevoNodo);
NodoListarFacturas* buscarUltimoNodoListarFacturas(NodoListarFacturas* lista);
NodoListarFacturas* agregarNodoAlFinalNodoListarFacturas(NodoListarFacturas* lista,NodoListarFacturas* nuevoNodo);


///-----------LISTADOS FACTURAS--------------------------------------------

NodoListarFacturas *listarFacturasDetEmpresaXPeriodo (nodoSimpleEmpresa *lista,char nombre_empresa[],Fecha fechaInicio,Fecha fechaFinal,int admin);
NodoListarFacturas *listarFacturasDetEmpresa (nodoSimpleEmpresa *lista,char nombre_empresa[],int admin);
NodoListarFacturas *listarTodasFacturasXOrdenFecha (nodoSimpleEmpresa *lista,int admin);
NodoListarFacturas* listarVentasDetEmpresaXPeriodo (nodoSimpleEmpresa *lista,char nombre_empresa[],Fecha fechaInicio,Fecha fechaFinal,int admin);
NodoListarFacturas* listarComprasDetEmpresaXPeriodo (nodoSimpleEmpresa *lista,char nombre_empresa[],Fecha fechaInicio,Fecha fechaFinal,int admin);
int retornaSiFechaEstaComprendidaEnPeriodoDado (Fecha dato, Fecha limInf, Fecha limSup);


void gotoxy (int x, int y);
void mostrarFacturasGo(NodoListarFacturas* lista);
void mostrarClientesProveedoresGo(nodoSimpleCP* lista,char nombreEmpresa[]);
nodoSimpleCP* listarTodosCPXEmpresa(nodoSimpleEmpresa* lista,char nombre_empresa[]);
void listarCPDeEmpresa(nodoSimpleEmpresa* lista);
void mostrarFacturasGoAll(NodoListarFacturas* lista);

#endif // RESUMENES_H_INCLUDED
