#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Resumenes.h"
#include "NodoSimpleEmpresa.h"
#include "NodoDobleFactura.h"
#include "NodoSimpleCP.h"
#include <windows.h>


///---------------- CARGA Y MUESTRA EMPRESAS----------------------------------

void mostrarUnaEmpresa(Empresa e)
{
    printf("\n---------------------------------------------------------\n");
    printf("\nNombre de la empresa: %s\n", e.nombre);
    printf("\nCUIT de la empresa: %s\n", e.cuit);
    printf("\nEstado de la empresa: ");
    e.activa_emp? printf("ACTIVA\n"):printf("INACTIVA\n");
    printf("\n---------------------------------------------------------\n");
}

void verUnaEmpresa(nodoSimpleEmpresa* lista)
{
    char nombre_empresa[50];
    int flag = 0;
    while(!flag)
    {
        printf("Ingrese el nombre de la empresa(Max. 50 caracteres): \n");
        fflush(stdin);
        gets(nombre_empresa);
        if(strlen(nombre_empresa)<50)
        {
            flag = 1;
        }
    }
    nodoSimpleEmpresa* encontrada = buscarNodoXNombreSimpleEmpresa(lista,nombre_empresa);
    if(encontrada)
    {
        mostrarUnaEmpresa(encontrada->dato);
    }
    else
    {
        printf("La empresa ingresada no se encuentra en la base de datos.\n");
    }
    system("pause");
}

Empresa cargarUnaEmpresa (Empresa e)
{
    int flag=0;

    do
    {
        printf("\nIngrese el nombre de la Empresa:\n");
        fflush(stdin);
        gets(e.nombre);
        if(strlen(e.nombre)==0)
            return e;
        else
            flag= validarLetras(e.nombre);
    }
    while(flag==1);

    do
    {
        printf("\nIngrese el CUIT de la Empresa\n");
        fflush(stdin);
        gets(e.cuit);
        flag= validarNumString(e.cuit);
    }
    while(flag==1);

    return e;
}

void persistirEmpresasEnArchivo (char nombreArch[])
{
    FILE *buf=fopen(nombreArch,"ab");
    char control='s';
    Empresa dato;
    nodoSimpleEmpresa* listaEmpresasTemp = inicListaSimpleEmpresa();
    if(buf)
    {
        while(control=='s')
        {
            dato=cargarUnaEmpresa(dato);
            if(strlen(dato.nombre)!=0)
            {
                int busNombre = buscarUnaEmpresaXNombreEnArchivoYRetornaPosicionRegistro(nombreArch,dato.nombre);
                int bus = buscarUnaEmpresaXCuitEnArchivoYRetornaPosicionRegistro(nombreArch,dato.cuit);
                nodoSimpleEmpresa* encontradoNombre = buscarNodoXNombreSimpleEmpresa(listaEmpresasTemp,dato.nombre);
                nodoSimpleEmpresa* encontradoCuit = buscarNodoXCuitSimpleEmpresa(listaEmpresasTemp,dato.cuit);

                if(bus==-1 && busNombre == -1 && !encontradoCuit && !encontradoNombre)
                {
                    Empresa dato2;
                    dato2=dato;
                    listaEmpresasTemp = agregarNodoAlPrincipioSimpleEmpresa(listaEmpresasTemp,crearNodoSimpleEmpresa(dato2));
                    fwrite(&dato2,sizeof(Empresa),1,buf);
                }

                else
                    printf("\nLa Empresa ya se encuentra en la base de datos\n");

            }
            printf("\nDesea seguir ingresando Empresas? s/n\n");
            fflush(stdin);
            scanf("%c",&control);
        }
        fclose(buf);
    }
}

void mostrarArchivoDeEmpresas (char nombreArch[])
{
    FILE *buf=fopen(nombreArch,"rb");
    Empresa a;

    if(buf)
    {
        while(fread(&a,sizeof(Empresa),1,buf)>0)
            mostrarUnaEmpresa(a);
        fclose(buf);
    }
}

int buscarUnaEmpresaXCuitEnArchivoYRetornaPosicionRegistro (char nombreArchEmpresas[],char cuit[])
{
    FILE *buf=fopen(nombreArchEmpresas,"rb");
    Empresa a;
    int num=-1;

    if(buf)
    {
        while(fread(&a,sizeof(Empresa),1,buf)>0)
        {
            if(strcmpi(a.cuit,cuit)==0)
                num= ftell(buf)/sizeof(Empresa);
        }
        fclose(buf);
    }

    return num;
}

int buscarUnaEmpresaXNombreEnArchivoYRetornaPosicionRegistro (char nombreArchEmpresas[],char nombre[])
{
    FILE *buf=fopen(nombreArchEmpresas,"rb");
    Empresa a;
    int num=-1;

    if(buf)
    {
        while(fread(&a,sizeof(Empresa),1,buf)>0)
        {
            if(strcmpi(a.nombre,nombre)==0)
                num= ftell(buf)/sizeof(Empresa);
        }
        fclose(buf);
    }

    return num;
}

///-------------- LIBRERIA DE LISTA SIMPLE EMPRESAS----------------------------------

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

nodoSimpleEmpresa* buscarNodoXNombreSimpleEmpresa(nodoSimpleEmpresa* lista,char nombre[])
{
    nodoSimpleEmpresa* seg;
    seg = lista;
    while(seg !=NULL && strcmpi(seg->dato.nombre,nombre) != 0)
    {
        seg = seg->sig;
    }
    return seg;
}

nodoSimpleEmpresa* agregarOrdenadoXNombreSimpleEmpresa(nodoSimpleEmpresa*lista,nodoSimpleEmpresa* nuevoNodo)
{
    if(!lista)
    {
        lista = nuevoNodo;
    }
    else
    {
        if(strcmpi(lista->dato.nombre,nuevoNodo->dato.nombre)>0)
        {
            lista = agregarNodoAlPrincipioSimpleEmpresa(lista, nuevoNodo);
        }
        else
        {
            nodoSimpleEmpresa* seg = lista->sig;
            nodoSimpleEmpresa* ante= lista;
            while(seg && strcmpi(seg->dato.nombre,nuevoNodo->dato.nombre)<0)
            {
                ante = seg;
                seg = seg->sig;
            }
            nuevoNodo->sig = seg;
            ante->sig = nuevoNodo;
        }
    }
    return lista;
}

///------------------------- TDA COMPUESTA---------------------------------

nodoSimpleEmpresa *pasarDatosArchivoFacturasATDA (char nombreArch[],nodoSimpleEmpresa *lista)
{
    FILE *buf=fopen(nombreArch,"rb");
    Registro_Factura a;

    if(buf)
    {
        while(fread(&a,sizeof(Registro_Factura),1,buf)>0)
            lista=altaFacturas(lista,a);

        fclose(buf);
    }

    return lista;
}

void mostrarTDACompleto (nodoSimpleEmpresa *lista)
{

    nodoSimpleEmpresa *segLista=lista;
    while(segLista!=NULL)
    {
        mostrarUnaEmpresa(segLista->dato);
        printf("\n-----------Lista de Clientes:----------------\n");
        nodoSimpleCP *segCli=segLista->cli;
        while(segCli!=NULL)
        {
            mostrarUnCP(segCli->dato_cp);
            mostrarListaDoble(segCli->fact);
            segCli=segCli->sig;
        }
        printf("\n-----------Lista de Proveedores:----------------\n");
        nodoSimpleCP *segProv=segLista->prov;
        while(segProv!=NULL)
        {
            mostrarUnCP(segProv->dato_cp);
            mostrarListaDoble(segProv->fact);
            segProv=segProv->sig;
        }
        segLista=segLista->sig;
    }
}

void TestPersistenciaYDespersistenciaEnTDA()
{
    nodoSimpleEmpresa *lista=inicListaSimpleEmpresa();

    lista=pasarDatosArchivoFacturasATDA("ArchivoFacturas",lista);

    persistirEmpresasEnArchivo("ArchivoEmpresas");
    printf("\nMOSTRANDO ARCHIVO DE EMPRESAS\n");
    mostrarArchivoDeEmpresas("ArchivoEmpresas");

    lista=cargarRegistrosFacturaEnTDA(lista);


    printf("\n-------------TDA Completo-----------------------------\n\n");
    mostrarTDACompleto(lista);
    system("pause");

    persistirTDAEnArchivo("ArchivoFacturas",lista);

    printf("\nMOSTRANDO ARCHIVO DE FACTURAS\n");
    mostrarArchivoRegistros("ArchivoFacturas");

    NodoListarFacturas *listaFact=inicListaSimpleListarFacturas();


    printf("\n----PROBANDO LISTADOS FACTURAS POR EMPRESA -----------------");
    listaFact = listarFacturasDetEmpresa(lista,"Coca");


    mostrarFacturasGo(listaFact);

    system("pause");

    NodoListarFacturas *testlista =  inicListaSimpleListarFacturas();
    testlista  = listarTodasFacturasXOrdenFecha(lista);
    system("cls");
    mostrarFacturasGo(testlista);

}

void persistirTDAEnArchivo (char nombreArch[],nodoSimpleEmpresa *lista)
{
    FILE *buf=fopen(nombreArch,"wb");

    Registro_Factura a;

    if(buf)
    {
        nodoSimpleEmpresa *segEmp=lista;
        while(segEmp!=NULL)
        {
            nodoSimpleCP *segCli=segEmp->cli;
            while(segCli!=NULL)
            {
                nodoDobleFactura *segFact=segCli->fact;
                while(segFact)
                {
                    a= pasarDatosNodoEmpresaAUnRegistro(segEmp->dato);
                    a=pasarDatosNodoClienteProveedorARegistro(segCli->dato_cp);
                    a=pasarDatosNodoFacturaAUnRegistro(segFact->dato);
                    fwrite(&a,sizeof(Registro_Factura),1,buf);
                    segFact=segFact->sig;
                }
                segCli=segCli->sig;
            }
            nodoSimpleCP *segProv=segEmp->prov;
            while(segProv)
            {
                nodoDobleFactura *segFactProv=segProv->fact;
                while(segFactProv)
                {
                    a= pasarDatosNodoEmpresaAUnRegistro(segEmp->dato);
                    a=pasarDatosNodoClienteProveedorARegistro(segProv->dato_cp);
                    a=pasarDatosNodoFacturaAUnRegistro(segFactProv->dato);
                    fwrite(&a,sizeof(Registro_Factura),1,buf);
                    segFactProv=segFactProv->sig;
                }
                segProv=segProv->sig;
            }
            segEmp=segEmp->sig;
        }
        fclose(buf);
    }
}



