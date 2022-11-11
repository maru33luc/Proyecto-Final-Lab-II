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

nodoSimpleEmpresa *pasarDatosArchivoFacturasATDA (char nombreArch[],nodoSimpleEmpresa *lista)
{
    FILE *buf=fopen(nombreArch,"rb");
    Registro_Factura a;

    if(buf)
    {
        while(fread(&a,sizeof(Registro_Factura),1,buf)>0)
        {
            Empresa emp=pasarDatosRegistroAUnaEmpresa(a);
            Cliente_Proveedor cliProv=pasarDatosRegistroAUnClienteProveedor(a);
            Factura fact=pasarDatosRegistroAUnaFactura(a);
            lista=altaFacturas(lista,fact,cliProv,emp);
        }
        fclose(buf);
    }
    return lista;
}

nodoSimpleEmpresa *altaFacturas(nodoSimpleEmpresa *lista,Factura fact,Cliente_Proveedor cliProv, Empresa emp)
{
    nodoSimpleCP *aux=crearNodoSimpleCP(cliProv);
    nodoSimpleEmpresa *busq=buscarNodoXCuitSimpleEmpresa(lista,emp.cuit);

    if(busq==NULL)
    {
        lista=agregarNodoAlFinalSimpleEmpresa(lista,crearNodoSimpleEmpresa(emp));
        nodoSimpleEmpresa *ult=buscarUltimoSimpleEmpresa(lista);
        nodoDobleFactura *aux1=crearNodoDoble(fact);
        ult->cli=inicListaSimpleCP();
        ult->prov=inicListaSimpleCP();
        if(cliProv.cp=='c')
        {
            ult->cli=agregarNodoAlPrincipioSimpleCP(ult->cli,aux);
            ult->cli->fact=inicListaDoble();
            ult->cli->fact=agregarAlPrincipioDoble(ult->cli->fact,aux1);
        }
        else
        {
            ult->prov=agregarNodoAlPrincipioSimpleCP(ult->prov,aux);
            ult->prov->fact=inicListaDoble();
            ult->prov->fact=agregarAlPrincipioDoble(ult->prov->fact,aux1);
        }
    }
    else
    {
        nodoDobleFactura *aux1=crearNodoDoble(fact);

        if(cliProv.cp=='c')
        {
            nodoSimpleCP *busq2=buscarNodoXCuitSimpleCP(busq->cli,cliProv.cuit_cliente_proveedor);
            if(busq2==NULL)
            {
                busq->cli=agregarNodoAlPrincipioSimpleCP(busq->cli,aux);
                busq->cli->fact=inicListaDoble();
                busq->cli->fact=agregarAlPrincipioDoble(busq->cli->fact,aux1);
            }
            else
                busq2->fact=agregarAlPrincipioDoble(busq2->fact,aux1);
        }
        else
        {
            nodoSimpleCP *busq2=buscarNodoXCuitSimpleCP(busq->prov,cliProv.cuit_cliente_proveedor);
            if(busq2==NULL)
            {
                busq->prov=agregarNodoAlPrincipioSimpleCP(busq->prov,aux);
                busq->prov->fact=inicListaDoble();
                busq->prov->fact=agregarAlPrincipioDoble(busq->prov->fact,aux1);
            }
            else
                busq2->fact=agregarAlPrincipioDoble(busq2->fact,aux1);
        }
    }
    return lista;
}


void mostrarTDACompleto (nodoSimpleEmpresa *lista)
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

void TestPersistenciaYDespersistenciaEnTDA()
{
    Fecha dato;
    dato.anio=2022;
    dato.mes=5;
    dato.dia=10;

    Registro_Factura a=cargarUnRegistroFactura("Coca","12",0,"a","0","0","0",1,dato,"",0,0,0,0,"MarinaCli",'c',"28");

    persistirRegistrosFactura("ArchivoFacturas",a);

    Registro_Factura b=cargarUnRegistroFactura("Pepsi","13",0,"a","0","0","0",1,dato,"",0,0,0,0,"LopezProv",'p',"30");

    persistirRegistrosFactura("ArchivoFacturas",b);

    Registro_Factura c=cargarUnRegistroFactura("Malboro","14",0,"a","0","0","0",1,dato,"",0,0,0,0,"SanchezProv",'p',"32");

    persistirRegistrosFactura("ArchivoFacturas",c);

    printf("Persiste todo");
    mostrarArchivoRegistros("ArchivoFacturas");

    nodoSimpleEmpresa *lista=inicListaSimpleEmpresa();
    lista=pasarDatosArchivoFacturasATDA("ArchivoFacturas",lista);
    printf("\n-------------TDA Completo-----------------------------\n\n");
    mostrarTDACompleto(lista);


}















