#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Empresa.h"
#include "Facturas.h"
#include "Resumenes.h"
#include "NodoSimpleEmpresa.h"
#include "NodoDobleFactura.h"
#include "Cliente_Proveedor.h"
#include "NodoSimpleCP.h"

nodoSimpleEmpresa* inicListaSimpleEmpresa()
{
    return NULL;
}

nodoSimpleEmpresa* crearNodoSimpleEmpresa(Empresa e)
{
    nodoSimpleEmpresa* aux = malloc(sizeof(nodoSimpleEmpresa));
    aux->dato = e;
    aux->sig = NULL;
    aux->prov = NULL;
    aux->cli = NULL;

    return aux;
}

nodoSimpleEmpresa* agregarNodoAlPrincipioSimpleEmpresa(nodoSimpleEmpresa* lista, nodoSimpleEmpresa* nuevoNodo)
{
    if(lista != NULL)
    {
        nuevoNodo->sig = lista;
    }
    lista = nuevoNodo;

    return lista;
}

nodoSimpleEmpresa* buscarUltimoSimpleEmpresa(nodoSimpleEmpresa* lista)
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

nodoSimpleEmpresa* buscarNodoXCuitSimpleEmpresa(nodoSimpleEmpresa* lista,char cuit[])
{
    nodoSimpleEmpresa* seg;
    seg = lista;
    while(seg !=NULL && strcmp(seg->dato.cuit,cuit) != 0)
    {
        seg = seg->sig;
    }
    return seg;
}

nodoSimpleEmpresa* agregarNodoAlFinalSimpleEmpresa(nodoSimpleEmpresa* lista,nodoSimpleEmpresa* nuevoNodo)
{
    if(lista != NULL)
    {
        nodoSimpleEmpresa* ultimo = buscarUltimoSimpleEmpresa(lista);
        ultimo->sig = nuevoNodo;
    }
    else
    {
        lista = nuevoNodo;
    }
    return lista;
}

nodoSimpleEmpresa* borrarXCuitSimpleEmpresa(nodoSimpleEmpresa* lista, char cuit[])
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
    nodoSimpleEmpresa* lista = inicListaSimpleEmpresa();
    lista = agregarNodoAlPrincipioSimpleEmpresa(lista,crearNodoSimpleEmpresa(crearEmpresa("Coca Cola","45459875674")));
    lista = agregarNodoAlPrincipioSimpleEmpresa(lista,crearNodoSimpleEmpresa(crearEmpresa("Pepsi","46459875674")));
    lista = agregarNodoAlPrincipioSimpleEmpresa(lista,crearNodoSimpleEmpresa(crearEmpresa("Manaos","47459875674")));
    lista = agregarNodoAlPrincipioSimpleEmpresa(lista,crearNodoSimpleEmpresa(crearEmpresa("Chori Champion","42459875674")));
    lista = agregarNodoAlFinalSimpleEmpresa(lista,crearNodoSimpleEmpresa(crearEmpresa("Cuatro Cabezas","42455555554")));
      mostrarListaSimpleEmpresa(lista);

    lista = borrarXCuitSimpleEmpresa(lista,"42459875674");
    printf("Eliminando empresa con el CUIT: 42459875674 - Nombre: Chori Champion\n");
    system("pause");
    system("cls");
    mostrarListaSimpleEmpresa(lista);
    system("pause");
    system("cls");
    printf("*******************************\n");
    printf("\nBuscando ultimo - Se espera: CUATRO CABEZAS\n");
    printf("Se encontro: %s\n",buscarUltimoSimpleEmpresa(lista)->dato.nombre);

}
