#include <stdio.h>
#include <stdlib.h>
#include "Empresa.h"
#include "Cliente.h"
#include "Proveedor.h"
#include "Facturas.h"
#include "Resumenes.h"
#include "NodoSimpleEmpresa.h"
#include "NodoDobleFactura.h"




NodoDobleFactura *inicListaDoble ()
{
    return NULL;
}

NodoDobleFactura *crearNodoDoble (Factura a)
{
    NodoDobleFactura *aux=malloc(sizeof(NodoDobleFactura));

    aux->dato=a;
    aux->ant=NULL;
    aux->sig=NULL;

    return aux;
}

NodoDobleFactura *agregarAlPrincipioDoble (NodoDobleFactura *lista,NodoDobleFactura *nuevo)
{
    if(lista!=NULL)
    {
        nuevo->sig=lista;
        lista->ant=nuevo;
    }
    return nuevo;
}

NodoDobleFactura *buscarUltimoDoble (NodoDobleFactura *lista)
{
    NodoDobleFactura *seg=lista;

    if(seg!=NULL)
    {
        while(seg->sig!=NULL)
        {
            seg=seg->sig;
        }
    }
    return seg;
}

NodoDobleFactura *agregarAlFinalDoble (NodoDobleFactura *lista,NodoDobleFactura *nuevo)
{
    if(lista==NULL)
        lista=nuevo;
    else
    {
        NodoDobleFactura *ult=buscarUltimoDoble(lista);
        nuevo->ant=ult;
        ult->sig=nuevo;
    }
    return lista;
}

void mostrarListaDoble (NodoDobleFactura *lista)
{
    while(lista!=NULL)
    {
        mostrarUnaFactura(lista->dato);
        lista=lista->sig;
    }
}

NodoDobleFactura *borrarNodoDobleFacturaXNumComprobante (NodoDobleFactura *lista,char numComprob [])
{
    if(lista!=NULL)
    {
        if(strcmpi(lista->dato.numComprobante,numComprob)==0)
        {
            NodoDobleFactura *aux=lista;
            lista=lista->sig;
            lista->ant=NULL;
            free(aux);
        }
        else
        {
            NodoDobleFactura*seg=lista;
            NodoDobleFactura *ant;

            while(seg!=NULL&&strcmpi(lista->dato.numComprobante,numComprob)!=0)
            {
                seg=seg->sig;
            }
            if(seg!=NULL)
            {
                ant=seg->ant;
                ant->sig=seg->sig;
                if(seg->sig!=NULL)
                    seg->sig->ant=ant;
                free(seg);
            }
        }
    }
    return lista;
}

NodoDobleFactura *insertarOrdenadoDobleXNumComprob (NodoDobleFactura *lista,NodoDobleFactura *nuevo)
{
    if(lista==NULL)
        lista=nuevo;
    else
    {
        if(strcmpi(lista->dato.numComprobante,nuevo->dato.numComprobante)>0)
            lista=agregarAlPrincipioDoble(lista,nuevo);
        else
        {
            NodoDobleFactura *seg=lista;
            while(seg!=NULL&&strcmpi(lista->dato.numComprobante,nuevo->dato.numComprobante)<0)
                seg=seg->sig;
            if(seg==NULL)
                lista=agregarAlFinalDoble(lista,nuevo);
            else
            {
                nuevo->sig=seg;
                nuevo->ant=seg->ant;
                seg->ant->sig=nuevo;
                seg->ant=nuevo;
            }
        }
    }
    return lista;
}

NodoDobleFactura *buscarFacturaDobleXNumComprob (NodoDobleFactura *lista,char numComprob[])
{
    NodoDobleFactura *seg=lista;

    while(seg!=NULL&&strcmpi(seg->dato.numComprobante,numComprob)!=0)
        seg=seg->sig;

    return seg;
}
