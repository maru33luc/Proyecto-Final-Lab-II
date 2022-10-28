#ifndef NODOSIMPLEEMPRESA_H_INCLUDED
#define NODOSIMPLEEMPRESA_H_INCLUDED

typedef struct NodoSimpleEmpresa
{
    Empresa dato;
    NodoSimpleEmpresa* sig;
} NodoSimpleEmpresa;

NodoSimpleEmpresaSimpleEmpresa* inicListaSimple();
NodoSimpleEmpresaSimpleEmpresa* crearNodoSimple(Empresa e);
NodoSimpleEmpresaSimpleEmpresa* agregarAlPrincipioSimple(NodoSimpleEmpresaSimpleEmpresa*, NodoSimpleEmpresaSimpleEmpresa*);
NodoSimpleEmpresaSimpleEmpresa* buscarUltimoSimple(NodoSimpleEmpresaSimpleEmpresa*);
NodoSimpleEmpresaSimpleEmpresa* buscarXCuitSimple(NodoSimpleEmpresaSimpleEmpresa*,char[]);
NodoSimpleEmpresaSimpleEmpresa* agregarAlFinalSimple(NodoSimpleEmpresaSimpleEmpresa*,NodoSimpleEmpresaSimpleEmpresa*);
NodoSimpleEmpresaSimpleEmpresa* borrarXCuitSimple(NodoSimpleEmpresaSimpleEmpresa*, char[]);

#endif
