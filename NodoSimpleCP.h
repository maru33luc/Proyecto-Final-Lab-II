#ifndef NODOSIMPLECP_H_INCLUDED
#define NODOSIMPLECP_H_INCLUDED


#include "NodoDobleFactura.h"
#include "NodoSimpleEmpresa.h"

typedef struct Cliente_Proveedor
{
  char nombre[50];
  char cuit_cliente_proveedor[12];
  char cp;
}Cliente_Proveedor;

typedef struct nodoSimpleCP{
Cliente_Proveedor dato_cp;
struct nodoDobleFactura* fact;
struct nodoSimpleCP* sig;
}nodoSimpleCP;


void mostrarUnCP(Cliente_Proveedor dato);

///------------------LIBRERIA LISTA SIMPLE CLIENTE/PROVEEDOR--------------------------------------------------

nodoSimpleCP* inicListaSimpleCP();
nodoSimpleCP* crearNodoSimpleCP(Cliente_Proveedor CP);
nodoSimpleCP* agregarNodoAlPrincipioSimpleCP(nodoSimpleCP* lista, nodoSimpleCP* nuevoNodo);
nodoSimpleCP* buscarUltimoSimpleCP(nodoSimpleCP* lista);
nodoSimpleCP* buscarNodoXCuitSimpleCP(nodoSimpleCP* lista,char cuit[]);
nodoSimpleCP* agregarNodoAlFinalSimpleCP(nodoSimpleCP* lista,nodoSimpleCP* nuevoNodo);
nodoSimpleCP* borrarXCuitSimpleCP(nodoSimpleCP* lista, char cuit[]);
void mostrarListaSimpleCP(nodoSimpleCP* lista);



#endif // NODOSIMPLECP_H_INCLUDED
