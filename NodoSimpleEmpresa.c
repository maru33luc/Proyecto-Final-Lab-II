#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "NodoSimpleEmpresa.h"
#include "Empresa.h"


NodoSimpleEmpresa* inicListaSimple()
{
    return NULL;
}

NodoSimpleEmpresa* crearNodoSimple(Empresa e)
{
    NodoSimpleEmpresa* aux = malloc(sizeof(NodoSimpleEmpresa));
    aux->dato = e;
    aux->sig = NULL;

    return aux;
}

NodoSimpleEmpresa* agregarNodoAlPrincipio(NodoSimpleEmpresa* lista, NodoSimpleEmpresa* nuevoNodo)
{
    if(lista != NULL)
    {
        nuevoNodo->sig = lista;
    }
    lista = nuevoNodo;

    return lista;
}

NodoSimpleEmpresa* buscarUltimo(NodoSimpleEmpresa* lista)
{
    NodoSimpleEmpresa* seg = lista;

    if(seg !=NULL)
    {
        while(seg->sig != NULL)
        {
            seg = seg->sig;
        }
    }
    return seg;
}

NodoSimpleEmpresa* buscarNodoXCuitSimple(NodoSimpleEmpresa* lista,char cuit[])
{
    NodoSimpleEmpresa* seg;
    seg = lista;
    while(seg !=NULL && strcmpi(seg->dato.cuit,cuit) != 0)
    {
        seg = seg->sig;
    }
    return seg;
}

NodoSimpleEmpresa* agregarNodoAlFinalSimple(NodoSimpleEmpresa* lista,NodoSimpleEmpresa* nuevoNodo)
{
    if(lista != NULL)
    {
        NodoSimpleEmpresa* ultimo = buscarUltimo(lista);
        ultimo->sig = nuevoNodo;
    }
    else
    {
        lista = nuevoNodo;
    }
    return lista;
}

NodoSimpleEmpresa* borrarXCuitSimple(NodoSimpleEmpresa* lista, char cuit[])
{

    if(lista != NULL && strcmp(lista->dato.cuit,cuit)==0)
    {
        NodoSimpleEmpresa* aux = lista;
        lista = lista->sig;
        free(aux);
    }
    else
    {
      NodoSimpleEmpresa* ante = NULL;
      NodoSimpleEmpresa* seg = NULL;
        seg = lista;
        while(seg != NULL && strcmp(seg->dato.cuit,cuit)!=0)
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
