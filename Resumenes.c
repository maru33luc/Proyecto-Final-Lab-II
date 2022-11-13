#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Resumenes.h"
#include "NodoSimpleEmpresa.h"
#include "NodoDobleFactura.h"
#include "NodoSimpleCP.h"

NodoListarFacturas *listarTodasFacturasXOrdenFecha (nodoSimpleEmpresa *lista)
{
    NodoListarFacturas *listaFact=inicListaSimpleListarFacturas();

    nodoSimpleEmpresa *segLista=lista;
    while(segLista!=NULL)
    {
        nodoSimpleCP *segCli=segLista->cli;
        while(segCli!=NULL)
        {
            nodoDobleFactura *segCliFact=segCli->fact;
            while(segCliFact)
            {
                listaFact=agregarNodoAlFinalNodoListarFacturas(listaFact,crearNodoListarFacturas(segLista->dato.nombre,segCliFact->dato,segCli->dato_cp.nombre,segCli->dato_cp.cp));
                segCliFact=segCliFact->sig;
            }
            segCli=segCli->sig;
        }
        nodoSimpleCP *segProv=segLista->prov;
        while(segProv!=NULL)
        {
            nodoDobleFactura *segProvFact=segProv->fact;
            while(segProvFact)
            {
                listaFact=agregarNodoAlFinalNodoListarFacturas(listaFact,crearNodoListarFacturas(segLista->dato.nombre,segProvFact->dato,segProv->dato_cp.nombre,segProv->dato_cp.cp));
                segProvFact=segProvFact->sig;
            }
            segProv=segProv->sig;
        }
        segLista=segLista->sig;
    }
    return listaFact;
}

NodoListarFacturas *listarFacturasDetEmpresaXPeriodo (nodoSimpleEmpresa *lista,char nombre_empresa[],Fecha fechaInicio,Fecha fechaFinal)
{
    NodoListarFacturas *listarFacturas=inicListaSimpleListarFacturas();

    nodoSimpleEmpresa *empresa=buscarNodoXNombreSimpleEmpresa(lista,nombre_empresa);

    nodoSimpleCP *segCli=empresa->cli;
    while(segCli!=NULL)
    {
        nodoDobleFactura *segFactCli=segCli->fact;
        while(segFactCli)
        {
            if(retornaSiFechaEstaComprendidaEnPeriodoDado(segFactCli->dato.fecha,fechaInicio,fechaFinal))
            {
                NodoListarFacturas *aux=crearNodoListarFacturas(lista->dato.nombre,segFactCli->dato,segCli->dato_cp.nombre,segCli->dato_cp.cp);
                listarFacturas=agregarNodoListarFactAlPrincipio(listarFacturas,aux);
            }
            segFactCli=segFactCli->sig;
        }
        segCli=segCli->sig;
    }

    nodoSimpleCP *segProv=empresa->prov;
    while(segProv!=NULL)
    {
        nodoDobleFactura *segFactProv=segProv->fact;
        while(segFactProv)
        {
            if(retornaSiFechaEstaComprendidaEnPeriodoDado(segFactProv->dato.fecha,fechaInicio,fechaFinal)==1)
            {
                NodoListarFacturas *aux2=crearNodoListarFacturas(lista->dato.nombre,segFactProv->dato,segProv->dato_cp.nombre,segProv->dato_cp.cp);
                listarFacturas=agregarNodoListarFactAlPrincipio(listarFacturas,aux2);
            }
            segFactProv=segFactProv->sig;
        }
        segProv=segProv->sig;
    }
    return listarFacturas;
}

nodoDobleFactura* listarVentasDetEmpresaXPeriodo (nodoSimpleEmpresa *lista,char nombre_empresa[],Fecha fechaInicio,Fecha fechaFinal)
{
    nodoDobleFactura* destino = inicListaDoble();
    nodoSimpleEmpresa *empresaEncontrada = buscarNodoXNombreSimpleEmpresa(lista,nombre_empresa);
    if(empresaEncontrada)
    {
        nodoSimpleCP *segCli=empresaEncontrada->cli;
        while(segCli!=NULL)
        {
            nodoDobleFactura *segFactCli=segCli->fact;
            while(segFactCli)
            {
                if(retornaSiFechaEstaComprendidaEnPeriodoDado(segFactCli->dato.fecha,fechaInicio,fechaFinal))
                {
                    destino = agregarAlFinalDoble(destino,segFactCli);
                }
                segFactCli=segFactCli->sig;
            }
            segCli=segCli->sig;
        }
    }
    return destino;
}

nodoDobleFactura* listarComprasDetEmpresaXPeriodo (nodoSimpleEmpresa *lista,char nombre_empresa[],Fecha fechaInicio,Fecha fechaFinal)
{
    nodoDobleFactura* destino = inicListaDoble();
    nodoSimpleEmpresa *empresaEncontrada = buscarNodoXNombreSimpleEmpresa(lista,nombre_empresa);
    if(empresaEncontrada)
    {
        nodoSimpleCP *segPro=empresaEncontrada->prov;
        while(segPro!=NULL)
        {
            nodoDobleFactura *segFactPro=segPro->fact;
            while(segFactPro)
            {
                if(retornaSiFechaEstaComprendidaEnPeriodoDado(segFactPro->dato.fecha,fechaInicio,fechaFinal))
                {
                    destino = agregarAlFinalDoble(destino,segFactPro);
                }
                segFactPro=segFactPro->sig;
            }
            segPro=segPro->sig;
        }
    }
    return destino;
}

int retornaSiFechaEstaComprendidaEnPeriodoDado (Fecha dato, Fecha limInf, Fecha limSup)
{
    if(retornarSiFecha1EsMayor(dato,limInf)&&retornarSiFecha1EsMenor(dato,limSup))
        return 1;
    else
        return 0;
}

//-----------LIBRERIA LISTA SIMPLE NODOSLISTARFACTURAS-------------------------

NodoListarFacturas* inicListaSimpleListarFacturas()
{
    return NULL;
}

NodoListarFacturas* crearNodoListarFacturas(char nombreEmp[],Factura a, char nombreCliProv[],char cp)
{
    NodoListarFacturas* aux = malloc(sizeof(NodoListarFacturas));
    aux->dato=a;
    aux->cp=cp;
    strcpy(aux->nombreEmpresa,nombreEmp);
    strcpy(aux->nombreClienteProveedor,nombreCliProv);
    aux->sig = NULL;

    return aux;
}

NodoListarFacturas* agregarNodoListarFactAlPrincipio(NodoListarFacturas* lista, NodoListarFacturas* nuevoNodo)
{
    if(lista != NULL)
    {
        nuevoNodo->sig = lista;
    }
    lista = nuevoNodo;

    return lista;
}

NodoListarFacturas* buscarUltimoNodoListarFacturas(NodoListarFacturas* lista)
{
    NodoListarFacturas* seg = lista;

    if(seg !=NULL)
    {
        while(seg->sig != NULL)
        {
            seg = seg->sig;
        }
    }
    return seg;
}

NodoListarFacturas* agregarNodoAlFinalNodoListarFacturas(NodoListarFacturas* lista,NodoListarFacturas* nuevoNodo)
{
    if(lista != NULL)
    {
        NodoListarFacturas* ultimo = buscarUltimoNodoListarFacturas(lista);
        ultimo->sig = nuevoNodo;
    }
    else
    {
        lista = nuevoNodo;
    }
    return lista;
}

void mostrarNodoListarFacturas (NodoListarFacturas *lista)
{
    while(lista)
    {
        mostrarUnNodoListarFacturas(lista);
        lista=lista->sig;
    }
}

void mostrarUnNodoListarFacturas (NodoListarFacturas *nodo)
{
    printf("\nNombre Empresa: %s",nodo->nombreEmpresa);
    mostrarUnaFactura(nodo->dato);
    printf("Nombre Cliente/Proveedor: %s",nodo->nombreClienteProveedor);
    printf("\nCP: %c",nodo->cp);
}

