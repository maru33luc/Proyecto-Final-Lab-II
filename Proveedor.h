#ifndef PROVEEDOR_H_INCLUDED
#define PROVEEDOR_H_INCLUDED

typedef struct nodoSimpleProveedor{
Cliente_Proveedor dato_proveedor;
struct nodoDobleFactura* fact;
struct nodoSimpleProveedor* sig;
}nodoSimpleProveedor;


#endif // PROVEEDOR_H_INCLUDED
