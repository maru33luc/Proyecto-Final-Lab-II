#ifndef NODOSIMPLECP_H_INCLUDED
#define NODOSIMPLECP_H_INCLUDED

typedef struct nodoSimpleCP{
Cliente_Proveedor dato_cliente;
struct nodoDobleFactura* fact;
struct nodoSimpleCP* sig;
}nodoSimpleCP;

#endif // NODOSIMPLECP_H_INCLUDED
