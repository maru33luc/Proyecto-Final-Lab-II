#ifndef NODOSIMPLEEMPRESA_H_INCLUDED
#define NODOSIMPLEEMPRESA_H_INCLUDED

#include "Cliente_Proveedor.h"

typedef struct nodoSimpleEmpresa {
Empresa dato;
struct nodoSimpleCP* prov;
struct nodoSimpleCP* cli;
struct nodoSimpleEmpresa* sig;
}nodoSimpleEmpresa;


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
nodoSimpleEmpresa *altaFacturas(nodoSimpleEmpresa *lista,Factura fact,Cliente_Proveedor cliProv, Empresa emp);
void persistirTDAEnArchivo (char nombreArch[],nodoSimpleEmpresa *lista);

void mostrarTDACompleto (nodoSimpleEmpresa *lista);

Fecha crearFecha (int dia, int mes, int anio);


#endif
