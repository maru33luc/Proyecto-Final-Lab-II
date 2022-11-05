#ifndef NODOSIMPLEEMPRESA_H_INCLUDED
#define NODOSIMPLEEMPRESA_H_INCLUDED

#include "Empresa.h"

typedef struct nodoSimpleEmpresa {
Empresa dato;
struct nodoSimpleProveedor* prov;
struct nodoSimpleCliente* cli;
struct nodoSimpleEmpresa*  sig;
}nodoSimpleEmpresa;




nodoSimpleEmpresa* inicListaSimple();
nodoSimpleEmpresa* crearNodoSimple(Empresa e);
nodoSimpleEmpresa* agregarNodoAlPrincipioSimple(nodoSimpleEmpresa* lista, nodoSimpleEmpresa* nuevoNodo);
nodoSimpleEmpresa* buscarUltimoSimple(nodoSimpleEmpresa* lista);
nodoSimpleEmpresa* buscarNodoXCuitSimple(nodoSimpleEmpresa* lista,char cuit[]);
nodoSimpleEmpresa* agregarNodoAlFinalSimple(nodoSimpleEmpresa* lista,nodoSimpleEmpresa* nuevoNodo);
nodoSimpleEmpresa* borrarXCuitSimple(nodoSimpleEmpresa* lista, char cuit[]);
void mostrarListaSimpleEmpresa(nodoSimpleEmpresa*);

#endif
