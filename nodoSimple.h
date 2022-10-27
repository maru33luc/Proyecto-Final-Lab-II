#ifndef NODOSIMPLEEMPRESA_H_INCLUDED
#define NODOSIMPLEEMPRESA_H_INCLUDED
#include "Empresa.h"
typedef struct nodoSimpleEmpresa{

  Empresa dato;
  struct nodoSimpleEmpresa* sig;
}nodoSimpleEmpresa;

nodoSimpleEmpresa* inicListaEmpresa();
nodoSimpleEmpresa* agregarAlPpio(nodoSimpleEmpresa*,nodoSimpleEmpresa*);
nodoSimpleEmpresa* buscarUltimo(nodoSimpleEmpresa*);
nodoSimpleEmpresa* agregarAlFinal(nodoSimpleEmpresa*,nodoSimpleEmpresa*);
nodoSimpleEmpresa* buscarXcuit(nodoSimpleEmpresa*,char[]);
nodoSimpleEmpresa* borrarXcuit(nodoSimpleEmpresa*,char[]);
void testLibreriaNodoSimple();

#endif // NODOSIMPLEEMPRESA_H_INCLUDED
