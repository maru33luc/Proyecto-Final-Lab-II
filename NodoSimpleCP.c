#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Resumenes.h"
#include "NodoSimpleEmpresa.h"
#include "NodoDobleFactura.h"
#include "NodoSimpleCP.h"
#include <windows.h>

void mostrarUnCP(Cliente_Proveedor CP)
{
    printf("----------------------------\n");
    printf("Nombre: %s\n",CP.nombre);
    printf("CP: %c\n",CP.cp);
    printf("CUIT: %s\n",CP.cuit_cliente_proveedor);
}

///----------------LIBRERIA LISTA SIMPLE CLIENTE/PROVEEDOR------------------------------------------------

nodoSimpleCP* inicListaSimpleCP()
{
    return NULL;
}

nodoSimpleCP* crearNodoSimpleCP(Cliente_Proveedor CP)
{
    nodoSimpleCP* aux = malloc(sizeof(nodoSimpleCP));
    aux->dato_cp = CP;
    aux->fact = NULL;
    aux->sig = NULL;
    return aux;
}

nodoSimpleCP* agregarNodoAlPrincipioSimpleCP(nodoSimpleCP* lista, nodoSimpleCP* nuevoNodo)
{
    if(lista != NULL)
    {
        nuevoNodo->sig = lista;
    }
    lista = nuevoNodo;

    return lista;
}

nodoSimpleCP* buscarUltimoSimpleCP(nodoSimpleCP* lista)
{
    nodoSimpleCP* seg = lista;

    if(seg !=NULL)
    {
        while(seg->sig != NULL)
        {
            seg = seg->sig;
        }
    }
    return seg;
}


nodoSimpleCP* buscarNodoXCuitSimpleCP(nodoSimpleCP* lista,char cuit[])
{
    nodoSimpleCP* seg;
    seg = lista;

    while(seg !=NULL && strcmp(seg->dato_cp.cuit_cliente_proveedor,cuit) != 0)
    {
        seg = seg->sig;
    }
    return seg;
}

nodoSimpleCP* agregarNodoAlFinalSimpleCP(nodoSimpleCP* lista,nodoSimpleCP* nuevoNodo)
{
    if(lista != NULL)
    {
        nodoSimpleCP* ultimo = buscarUltimoSimpleCP(lista);
        ultimo->sig = nuevoNodo;
    }
    else
    {
        lista = nuevoNodo;
    }
    return lista;
}

nodoSimpleCP* borrarXCuitSimpleCP(nodoSimpleCP* lista, char cuit[])
{

    if(lista != NULL && strcmp(lista->dato_cp.cuit_cliente_proveedor,cuit)==0)
    {
        nodoSimpleCP* aux = lista;
        lista = lista->sig;
        free(aux);
    }
    else
    {
        nodoSimpleCP* ante = NULL;
        nodoSimpleCP* seg = NULL;
        seg = lista;
        while(seg != NULL && strcmp(seg->dato_cp.cuit_cliente_proveedor,cuit)!=0)
        {
            ante = seg;
            seg = seg->sig;
        }

        if(seg != NULL)
        {
            ante->sig = seg->sig;
            free(seg);
        }
    }
    return lista;
}

void mostrarListaSimpleCP(nodoSimpleCP* lista)
{
    while(lista)
    {
        mostrarUnCP(lista->dato_cp);
        lista = lista->sig;
    }
}


