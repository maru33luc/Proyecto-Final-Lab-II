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

typedef struct NodoPalabra
{
    char palabra[50];
    struct NodoPalabra* siguiente;
    struct NodoPalabra* anterior;
}NodoPalabra;

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
nodoSimpleEmpresa* buscarNodoXNombreSimpleEmpresa(nodoSimpleEmpresa* lista,char nombre[]);

nodoSimpleEmpresa *pasarDatosArchivoFacturasATDA (char nombreArch[],nodoSimpleEmpresa *lista);

void persistirTDAEnArchivo (char nombreArch[],nodoSimpleEmpresa *lista);

void TestPersistenciaYDespersistenciaEnTDA();
void mostrarTDACompleto (nodoSimpleEmpresa *lista);


NodoPalabra *IniciarListaPalabras();
NodoPalabra* CrearNodoPalabra(char palabra[]);
NodoPalabra *AgregarNodoPalabraAlfabeticamente(NodoPalabra* listaPalabras, char palabra[]);

#endif
