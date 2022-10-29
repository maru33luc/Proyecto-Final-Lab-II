#ifndef NODOSIMPLEEMPRESA_H_INCLUDED
#define NODOSIMPLEEMPRESA_H_INCLUDED

#include "Empresa.h"

typedef struct NodoSimpleEmpresa
{
    Empresa dato;
    struct NodoSimpleEmpresa* sig;
} NodoSimpleEmpresa;

NodoSimpleEmpresa* inicListaSimple();
NodoSimpleEmpresa* crearNodoSimple(Empresa e);
NodoSimpleEmpresa* agregarNodoAlPrincipio(NodoSimpleEmpresa* lista, NodoSimpleEmpresa* nuevoNodo);
NodoSimpleEmpresa* buscarUltimo(NodoSimpleEmpresa* lista);
NodoSimpleEmpresa* buscarNodoXCuitSimple(NodoSimpleEmpresa* lista,char cuit[]);
NodoSimpleEmpresa* agregarNodoAlFinalSimple(NodoSimpleEmpresa* lista,NodoSimpleEmpresa* nuevoNodo);
NodoSimpleEmpresa* borrarXCuitSimple(NodoSimpleEmpresa* lista, char cuit[]);

#endif
