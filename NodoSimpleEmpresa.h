#ifndef NODOSIMPLEEMPRESA_H_INCLUDED
#define NODOSIMPLEEMPRESA_H_INCLUDED


#include "NodoSimpleCP.h"
#include "NodoDobleFactura.h"


typedef struct Empresa
{
    char nombre[50];
    char cuit[12];
    int activa_emp; // ACTIVAS:1   INACTIVAS:0
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
void mostrarArchivoDeEmpresas (char nombreArch[]);
Empresa cargarUnaEmpresa (Empresa e);

///------------ARCHIVO DE EMPRESAS--------------------------------------------------

nodoSimpleEmpresa *persistirEmpresasEnArchivo (char nombreArch[],nodoSimpleEmpresa *lista);
nodoSimpleEmpresa *pasarDatosArchivoFacturasATDA (char nombreArch[],nodoSimpleEmpresa *lista);
nodoSimpleEmpresa *pasarDatosArchivoEmpresasATDA (char nombreArch[],nodoSimpleEmpresa *lista);
int buscarUnaEmpresaXCuitEnArchivoYRetornaPosicionRegistro (char nombreArchEmpresas[],char cuit[]);
int buscarUnaEmpresaXNombreEnArchivoYRetornaPosicionRegistro (char nombreArchEmpresas[],char nombre[]);
void verUnaEmpresa(nodoSimpleEmpresa* lista);
void bajaEmpresaEnArchivo (char nombreArch[],char empresa[]);

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

///-------------TDA COMPUESTA-----------------------------------------------

void persistirTDAEnArchivo (char nombreArch[],nodoSimpleEmpresa *lista);
nodoSimpleEmpresa *BajaEmpresa (char nombreArch[],nodoSimpleEmpresa *lista,char empresa[]);

void TestPersistenciaYDespersistenciaEnTDA();
void mostrarTDACompleto (nodoSimpleEmpresa *lista);


#endif
