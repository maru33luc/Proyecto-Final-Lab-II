#ifndef NODOSIMPLEEMPRESA_H_INCLUDED
#define NODOSIMPLEEMPRESA_H_INCLUDED


#include "NodoSimpleCP.h"
#include "NodoDobleFactura.h"


typedef struct Empresa
{
    char nombre[50];
    char cuit[12];
    int activa_emp;
} Empresa;


typedef struct nodoSimpleEmpresa {
Empresa dato;
struct nodoSimpleCP* prov;
struct nodoSimpleCP* cli;
struct nodoSimpleEmpresa* sig;
}nodoSimpleEmpresa;

void mostrarUnaEmpresa(Empresa a);
Empresa crearEmpresa(char nombre[],char cuit[]);
void TestLibreriaEmpresa();

///------------ LIBRERIA DE LISTA SIMPLE EMPRESAS----------------------------

nodoSimpleEmpresa* inicListaSimpleEmpresa();
nodoSimpleEmpresa* crearNodoSimpleEmpresa(Empresa e);
nodoSimpleEmpresa* agregarNodoAlPrincipioSimpleEmpresa(nodoSimpleEmpresa* lista, nodoSimpleEmpresa* nuevoNodo);
nodoSimpleEmpresa* buscarUltimoSimpleEmpresa(nodoSimpleEmpresa* lista);
nodoSimpleEmpresa* buscarNodoXCuitSimpleEmpresa(nodoSimpleEmpresa* lista,char cuit[]);
nodoSimpleEmpresa* agregarNodoAlFinalSimpleEmpresa(nodoSimpleEmpresa* lista,nodoSimpleEmpresa* nuevoNodo);
nodoSimpleEmpresa* borrarXCuitSimpleEmpresa(nodoSimpleEmpresa* lista, char cuit[]);
void mostrarListaSimpleEmpresa(nodoSimpleEmpresa*);
nodoSimpleEmpresa* agregarOrdenadoXNombreSimpleEmpresa(nodoSimpleEmpresa*lista,nodoSimpleEmpresa* nuevoNodo);

nodoSimpleEmpresa *pasarDatosArchivoFacturasATDA (char nombreArch[],nodoSimpleEmpresa *lista);

void persistirTDAEnArchivo (char nombreArch[],nodoSimpleEmpresa *lista);

void mostrarTDACompleto (nodoSimpleEmpresa *lista);




#endif
