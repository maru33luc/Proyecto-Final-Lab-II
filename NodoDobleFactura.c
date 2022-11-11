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

nodoDobleFactura *borrarnodoDobleFacturaXNumComprobante (nodoDobleFactura *lista,char numComprob [])
{
    if(lista!=NULL)
    {
        if(strcmp(lista->dato.numComprobante,numComprob)==0)
        {
            nodoDobleFactura *aux=lista;
            lista=lista->sig;
            free(aux);
            lista->ante=NULL;

        }
        else
        {
            nodoDobleFactura*seg=lista;
            nodoDobleFactura *ante=NULL;

            while(seg!=NULL&&strcmpi(seg->dato.numComprobante,numComprob)!=0)
            {
                seg=seg->sig;
            }
            if(seg!=NULL)
            {
                ante=seg->ante;
                ante->sig=seg->sig;
                nodoDobleFactura *aux1=seg->sig;
                if(seg->sig!=NULL)
                    aux1->ante=ante;
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


void TestLibreriaFactura()
{
    Fecha dato;
    dato.anio=2022;
    dato.mes=5;
    dato.dia=10;

    nodoDobleFactura* lista = inicListaDoble();
    lista = agregarAlPrincipioDoble(lista,crearNodoDoble(cargarUnaFactura("1111111","0","1","0","a",0,dato,"",0,0,0,0)));
    lista = agregarAlPrincipioDoble(lista,crearNodoDoble(cargarUnaFactura("2222222","0","2","0","a",0,dato,"",0,0,0,0)));
    lista = agregarAlPrincipioDoble(lista,crearNodoDoble(cargarUnaFactura("3333333","0","3","0","a",0,dato,"",0,0,0,0)));
    lista = agregarAlFinalDoble(lista,crearNodoDoble(cargarUnaFactura("4444444","0","4","0","a",0,dato,"",0,0,0,0)));

    mostrarListaDoble(lista);

    lista = borrarnodoDobleFacturaXNumComprobante(lista,"1");
    printf("Eliminando Factura con el numero de comprob '1' y cuit 11111111\n");
    system("pause");
    system("cls");
    mostrarListaDoble(lista);
    system("pause");
    system("cls");
    printf("*******************************\n");
    printf("\nBuscando ultimo - Se espera: cuit 44444444\n");
//    printf("Se encontro: %s\n",buscarUltimoDoble(lista)->dato.cuit_cliente_proveedor);

}
