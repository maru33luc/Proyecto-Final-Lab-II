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

void listarFacturasDetEmpresaXPeriodo (nodoSimpleEmpresa *lista,char cuit[],Fecha fechaInicio,Fecha fechaFinal)
{

    nodoSimpleEmpresa *empresa=buscarNodoXCuitSimpleEmpresa(lista,cuit);
    mostrarUnaEmpresa(empresa->dato);


        printf("\n-----------Facturas de Clientes:----------------\n");
        nodoSimpleCP *segCli=empresa->cli;
        while(segCli!=NULL)
        {
            mostrarUnCP(segCli->dato_cp);
            nodoDobleFactura *segFactCli=segCli->fact;
            while(segFactCli)
            {
                if(retornaSiFechaEstaComprendidaEnPeriodoDado(segFactCli->dato.fecha,fechaInicio,fechaFinal))
                mostrarUnaFactura(segFactCli->dato);
                segFactCli=segFactCli->sig;
            }
            segCli=segCli->sig;
        }
        printf("\n-----------Facturas de Proveedores:----------------\n");
        nodoSimpleCP *segProv=empresa->prov;
        while(segProv!=NULL)
        {
            mostrarUnCP(segProv->dato_cp);
            nodoDobleFactura *segFactProv=segProv->fact;
            while(segFactProv)
            {
                if(retornaSiFechaEstaComprendidaEnPeriodoDado(segFactProv->dato.fecha,fechaInicio,fechaFinal)==1)
                mostrarUnaFactura(segFactProv->dato);
                segFactProv=segFactProv->sig;
            }
            segProv=segProv->sig;
        }

}

int retornaSiFechaEstaComprendidaEnPeriodoDado (Fecha dato, Fecha limInf, Fecha limSup)
{
    if(retornarSiFecha1EsMayor(dato,limInf)&&retornarSiFecha1EsMenor(dato,limSup))
        return 1;
    else
        return 0;
}
