#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Resumenes.h"
#include "NodoSimpleEmpresa.h"
#include "NodoDobleFactura.h"
#include "NodoSimpleCP.h"

void listarTodasFacturasXOrdenFecha (nodoSimpleEmpresa *lista)
{
    while(lista!=NULL)
    {
        mostrarUnaEmpresa(lista->dato);
        printf("\n-----------Lista de Clientes:----------------\n");
        while(lista->cli!=NULL)
        {
            mostrarUnCP(lista->cli->dato_cp);
            mostrarListaDoble(lista->cli->fact);
            lista->cli=lista->cli->sig;
        }
        printf("\n-----------Lista de Proveedores:----------------\n");
        while(lista->prov!=NULL)
        {
            mostrarUnCP(lista->prov->dato_cp);
            mostrarListaDoble(lista->prov->fact);
            lista->prov=lista->prov->sig;
        }
        lista=lista->sig;
    }
}

nodoDobleFactura *listarFacturasDetEmpresaXPeriodo (nodoSimpleEmpresa *lista,char nombre_empresa[],Fecha fechaInicio,Fecha fechaFinal)
{
    NodoListarFacturas *listarFacturas=inicListaSimpleCP();

    nodoSimpleEmpresa *empresa=buscarNodoXNombreSimpleEmpresa(lista,nombre);

        nodoSimpleCP *segCli=empresa->cli;
        while(segCli!=NULL)
        {
            nodoDobleFactura *segFactCli=segCli->fact;
            while(segFactCli)
            {
                if(retornaSiFechaEstaComprendidaEnPeriodoDado(segFactCli->dato.fecha,fechaInicio,fechaFinal))
                NodoListarFacturas *aux=crearNodoListarFacturas(lista->dato.nombre,segFactCli->dato,segCli->dato_cp.nombre,segCli->dato_cp.cp);
                listarFacturas=agregarNodoListarFactAlPrincipio(listarFacturas,aux);
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
                NodoListarFacturas *aux2=crearNodoListarFacturas(lista->dato.nombre,segFactProv->dato,segProv->dato_cp.nombre,segProv->dato_cp.cp);
                listarFacturas=agregarNodoListarFactAlPrincipio(listarFacturas,aux2);
                segFactProv=segFactProv->sig;
            }
            segProv=segProv->sig;
        }
    return listarFacturas;
}

nodoDobleFactura* listarVentasDetEmpresaXPeriodo (nodoSimpleEmpresa *lista,char nombre_empresa[],Fecha fechaInicio,Fecha fechaFinal)
{
    nodoDobleFactura* destino = inicListaDoble();
    nodoSimpleEmpresa *empresaEncontrada = buscarNodoXNombreSimpleEmpresa(lista,nombre);
    if(empresaEncontrada){
        nodoSimpleCP *segCli=empresaEncontrada->cli;
        while(segCli!=NULL)
        {
            nodoDobleFactura *segFactCli=segCli->fact;
            while(segFactCli)
            {
                if(retornaSiFechaEstaComprendidaEnPeriodoDado(segFactCli->dato.fecha,fechaInicio,fechaFinal)){
                  destino = agregarAlFinalDoble(destino,segFactCli->dato);
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
    nodoSimpleEmpresa *empresaEncontrada = buscarNodoXNombreSimpleEmpresa(lista,nombre);
    if(empresaEncontrada){
        nodoSimpleCP *segPro=empresaEncontrada->prov;
        while(segPro!=NULL)
        {
            nodoDobleFactura *segFactPro=segPro->fact;
            while(segFactPro)
            {
                if(retornaSiFechaEstaComprendidaEnPeriodoDado(segFactPro->dato.fecha,fechaInicio,fechaFinal)){
                  destino = agregarAlFinalDoble(destino,segFact->dato);
                }
                segFactPro=segFactPro->sig;
            }
            segPro=segPro->sig;
        }
    }
  return destino;

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
