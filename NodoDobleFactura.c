#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Empresa.h"
#include "Cliente.h"
#include "Proveedor.h"
#include "Facturas.h"
#include "Resumenes.h"
#include "nodoSimpleEmpresa.h"
#include "nodoDobleFactura.h"

nodoDobleFactura *inicListaDoble ()
{
    return NULL;
}

nodoDobleFactura *crearNodoDoble (Factura a)
{
    nodoDobleFactura *aux=malloc(sizeof(nodoDobleFactura));

    aux->dato=a;
    aux->ante=NULL;
    aux->sig=NULL;

    return aux;
}

nodoDobleFactura *agregarAlPrincipioDoble (nodoDobleFactura *lista,nodoDobleFactura *nuevo)
{
    if(lista!=NULL)
    {
        nuevo->sig=lista;
        lista->ante=nuevo;
    }
    return nuevo;
}

nodoDobleFactura *buscarUltimoDoble (nodoDobleFactura *lista)
{
    nodoDobleFactura *seg=lista;

    if(seg!=NULL)
    {
        while(seg->sig!=NULL)
        {
            seg=seg->sig;
        }
    }
    return seg;
}

nodoDobleFactura *agregarAlFinalDoble (nodoDobleFactura *lista,nodoDobleFactura *nuevo)
{
    if(lista==NULL)
        lista=nuevo;
    else
    {
        nodoDobleFactura *ult=buscarUltimoDoble(lista);
        nuevo->ante=ult;
        ult->sig=nuevo;
    }
    return lista;
}

void mostrarListaDoble (nodoDobleFactura *lista)
{
    while(lista!=NULL)
    {
        mostrarUnaFactura(lista->dato);
        lista=lista->sig;
    }
}

nodoDobleFactura *borrarnodoDobleFacturaXNumComprobantee (nodoDobleFactura *lista,char numComprob [])
{
    if(lista!=NULL)
    {
        if(strcmp(lista->dato.numComprobante,numComprob)==0)
        {
            nodoDobleFactura *aux=lista;
            lista=lista->sig;
            lista->ante=NULL;
            free(aux);
        }
        else
        {
            nodoDobleFactura*seg=lista;
            nodoDobleFactura *ante;

            while(seg!=NULL&&strcmpi(lista->dato.numComprobante,numComprob)!=0)
            {
                seg=seg->sig;
            }
            if(seg!=NULL)
            {
                ante=seg->ante;
                ante->sig=seg->sig;
                if(seg->sig!=NULL)
                    seg->sig->ante=ante;
                free(seg);
            }
        }
    }
    return lista;
}

nodoDobleFactura *insertarOrdenadoDobleXNumComprob (nodoDobleFactura *lista,nodoDobleFactura *nuevo)
{
    if(lista==NULL)
        lista=nuevo;
    else
    {
        if(strcmpi(lista->dato.numComprobante,nuevo->dato.numComprobante)>0)
            lista=agregarAlPrincipioDoble(lista,nuevo);
        else
        {
            nodoDobleFactura *seg=lista;
            while(seg!=NULL&&strcmpi(lista->dato.numComprobante,nuevo->dato.numComprobante)<0)
                seg=seg->sig;
            if(seg==NULL)
                lista=agregarAlFinalDoble(lista,nuevo);
            else
            {
                nuevo->sig=seg;
                nuevo->ante=seg->ante;
                seg->ante->sig=nuevo;
                seg->ante=nuevo;
            }
        }
    }
    return lista;
}

nodoDobleFactura *buscarFacturaDobleXNumComprob (nodoDobleFactura *lista,char numComprob[])
{
    nodoDobleFactura *seg=lista;

    while(seg!=NULL&&strcmpi(seg->dato.numComprobante,numComprob)!=0)
        seg=seg->sig;

    return seg;
}
