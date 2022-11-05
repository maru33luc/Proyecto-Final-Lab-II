#ifndef NODOSIMPLECP_H_INCLUDED
#define NODOSIMPLECP_H_INCLUDED
#include "Cliente_Proveedor.h"

typedef struct nodoSimpleCP{
Cliente_Proveedor dato_cp;
struct nodoDobleFactura* fact;
struct nodoSimpleCP* sig;
}nodoSimpleCP;

nodoSimpleCP* inicListaSimpleCP();

#endif // NODOSIMPLECP_H_INCLUDED
