#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Empresa.h"
#include "Cliente.h"
#include "Proveedor.h"
#include "Facturas.h"
#include "Resumenes.h"
#include "NodoSimpleEmpresa.h"
#include "NodoDobleFactura.h"


nodoSimpleEmpresa* inicListaSimple()
{
    return NULL;
}

nodoSimpleEmpresa* crearNodoSimple(Empresa e)
{
    nodoSimpleEmpresa* aux = malloc(sizeof(nodoSimpleEmpresa));
    aux->dato = e;
    aux->sig = NULL;

    return aux;
}

nodoSimpleEmpresa* agregarNodoAlPrincipioSimple(nodoSimpleEmpresa* lista, nodoSimpleEmpresa* nuevoNodo)
{
    if(lista != NULL)
    {
        nuevoNodo->sig = lista;
    }
    lista = nuevoNodo;

    return lista;
}

nodoSimpleEmpresa* buscarUltimoSimple(nodoSimpleEmpresa* lista)
{
    nodoSimpleEmpresa* seg = lista;

    if(seg !=NULL)
    {
        while(seg->sig != NULL)
        {
            seg = seg->sig;
        }
    }
    return seg;
}

nodoSimpleEmpresa* buscarNodoXCuitSimple(nodoSimpleEmpresa* lista,char cuit[])
{
    nodoSimpleEmpresa* seg;
    seg = lista;
    while(seg !=NULL && strcmp(seg->dato.cuit,cuit) != 0)
    {
        seg = seg->sig;
    }
    return seg;
}

nodoSimpleEmpresa* agregarNodoAlFinalSimple(nodoSimpleEmpresa* lista,nodoSimpleEmpresa* nuevoNodo)
{
    if(lista != NULL)
    {
        nodoSimpleEmpresa* ultimo = buscarUltimoSimple(lista);
        ultimo->sig = nuevoNodo;
    }
    else
    {
        lista = nuevoNodo;
    }
    return lista;
}

nodoSimpleEmpresa* borrarXCuitSimple(nodoSimpleEmpresa* lista, char cuit[])
{

    if(lista != NULL && strcmp(lista->dato.cuit,cuit)==0)
    {
        nodoSimpleEmpresa* aux = lista;
        lista = lista->sig;
        free(aux);
    }
    else
    {
        nodoSimpleEmpresa* ante = NULL;
        nodoSimpleEmpresa* seg = NULL;
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

void mostrarListaSimpleEmpresa(nodoSimpleEmpresa* lista)
{
    while(lista)
    {
        mostrarUnaEmpresa(lista->dato);
        lista = lista->sig;
    }
}

void TestLibreriaEmpresa()
{
    nodoSimpleEmpresa* lista = inicListaSimple();
    lista = agregarNodoAlPrincipioSimple(lista,crearNodoSimple(crearEmpresa("Coca Cola","45459875674")));
    lista = agregarNodoAlPrincipioSimple(lista,crearNodoSimple(crearEmpresa("Pepsi","46459875674")));
    lista = agregarNodoAlPrincipioSimple(lista,crearNodoSimple(crearEmpresa("Manaos","47459875674")));
    lista = agregarNodoAlPrincipioSimple(lista,crearNodoSimple(crearEmpresa("Chori Champion","42459875674")));
    lista = agregarNodoAlFinalSimple(lista,crearNodoSimple(crearEmpresa("Cuatro Cabezas","42455555554")));
      mostrarListaSimpleEmpresa(lista);

    lista = borrarXCuitSimple(lista,"42459875674");
    printf("Eliminando empresa con el CUIT: 42459875674 - Nombre: Chori Champion\n");
    system("pause");
    system("cls");
    mostrarListaSimpleEmpresa(lista);
    system("pause");
    system("cls");
    printf("*******************************\n");
    printf("\nBuscando ultimo - Se espera: CUATRO CABEZAS\n");
    printf("Se encontro: %s\n",buscarUltimoSimple(lista)->dato.nombre);

}
