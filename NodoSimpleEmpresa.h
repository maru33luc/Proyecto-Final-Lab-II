#ifndef NODOSIMPLEEMPRESA_H_INCLUDED
#define NODOSIMPLEEMPRESA_H_INCLUDED

#include "Empresa.h"

typedef struct nodoSimpleEmpresa {
Empresa dato;
struct nodoSimpleProveedor* prov;
struct nodoSimpleCliente* cli;
struct nodoSimpleEmpresa*  sig;
}nodoSimpleEmpresa;




NodoSimpleEmpresa* inicListaSimple();
NodoSimpleEmpresa* crearNodoSimple(Empresa e);
NodoSimpleEmpresa* agregarNodoAlPrincipio(NodoSimpleEmpresa* lista, NodoSimpleEmpresa* nuevoNodo);
NodoSimpleEmpresa* buscarUltimo(NodoSimpleEmpresa* lista);
NodoSimpleEmpresa* buscarNodoXCuitSimple(NodoSimpleEmpresa* lista,char cuit[]);
NodoSimpleEmpresa* agregarNodoAlFinalSimple(NodoSimpleEmpresa* lista,NodoSimpleEmpresa* nuevoNodo);
NodoSimpleEmpresa* borrarXCuitSimple(NodoSimpleEmpresa* lista, char cuit[]);

#endif
