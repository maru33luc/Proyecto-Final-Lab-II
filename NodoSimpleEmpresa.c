#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Resumenes.h"
#include "NodoSimpleEmpresa.h"
#include "NodoDobleFactura.h"
#include "NodoSimpleCP.h"
#include <windows.h>


///---------------- ARCHIVO DE EMPRESAS----------------------------------

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
        printf("\nIngrese el CUIT del cliente\n");
        fflush(stdin);
        gets(e.cuit);
        flag= validarNumString(e.cuit);
    }
    while(flag==1);

    return e;
}

Empresa crearEmpresa(char nombre[],char cuit[])
{
    Empresa emp;
    strcpy(emp.nombre,nombre);
    strcpy(emp.cuit,cuit);
    emp.activa_emp = 1;
    return emp;
}

/*
void persistirUnaEmpresaEnArchivo (char nombreArchEmpresas[],Empresa a)
{
    FILE *buf=fopen(nombreArchEmpresas,"ab");
    Empresa e=a;
    if(buf)
    {
        fwrite(&e,sizeof(Empresa),1,buf);
        fclose(buf);
    }
}
*/

void persistirEmpresasEnArchivo (char nombreArch[])
{
    FILE *buf=fopen(nombreArch,"ab");
    char control='s';
    Empresa dato;

    if(buf)
    {
        while(control=='s')
        {
            dato=cargarUnaEmpresa(dato);
            if(strlen(dato.nombre)!=0)
            {
                int bus=buscarUnaEmpresaXCuitEnArchivoYRetornaPosicionRegistro(nombreArch,dato.cuit);
                if(bus==-1)
                    {
                        Empresa dato2;
                        dato2=dato;
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

NodoPalabra *pasarEmpresasDelArchivoAListaSimple (char nombreArchEmpresas[])
{
    NodoPalabra *lista=IniciarListaPalabras();

    FILE *buf=fopen(nombreArchEmpresas,"rb");
    Empresa a;

    if(buf)
    {
        while(fread(&a,sizeof(Empresa),1,buf)>0)
            lista=AgregarNodoPalabraAlfabeticamente(lista,a.nombre);

        fclose(buf);
    }

    return lista;
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

///--------------LIBRERIA DE LISTAS NODOPALABRAS-------------------------

NodoPalabra *IniciarListaPalabras()
{
    return NULL;
}

NodoPalabra* CrearNodoPalabra(char palabra[])
{
    NodoPalabra* aux = malloc(sizeof(NodoPalabra));
    strcpy(aux->palabra, palabra);
    aux->siguiente = NULL;

    return aux;
}

NodoPalabra *AgregarNodoPalabraAlfabeticamente(NodoPalabra* listaPalabras, char palabra[])
{
    NodoPalabra* nuevoNodo = CrearNodoPalabra(palabra);

    if(listaPalabras== NULL)
        listaPalabras = nuevoNodo;
    else
    {
        if(strcmpi(listaPalabras->palabra, palabra) > 0)
        {
            nuevoNodo->siguiente = listaPalabras;
            listaPalabras->anterior = nuevoNodo;
            listaPalabras = nuevoNodo;
        }
        else
        {
            NodoPalabra* seg = listaPalabras->siguiente;
            NodoPalabra* ant = listaPalabras;

            while(seg != NULL && strcmpi(seg->palabra, palabra) < 0)
            {
                ant = seg;
                seg = seg->siguiente;
            }
            if(seg != NULL)
            {
                ant->siguiente = nuevoNodo;
                nuevoNodo->siguiente = seg;
            }
            else
                ant->siguiente = nuevoNodo;
        }
    }
    return listaPalabras;
}

void mostrarListaNodoPalabras (NodoPalabra *lista)
{
    while(lista)
    {
        printf("Palabra: %s\n",lista->palabra);
        lista=lista->siguiente;
    }
}

void TestNodoPalabra ()
{
    NodoPalabra *lista=IniciarListaPalabras();

    lista=AgregarNodoPalabraAlfabeticamente(lista,"Marina");
    lista=AgregarNodoPalabraAlfabeticamente(lista,"Arnaldo");
    lista=AgregarNodoPalabraAlfabeticamente(lista,"Carlos");
    lista=AgregarNodoPalabraAlfabeticamente(lista,"Josefa");

    mostrarListaNodoPalabras(lista);
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
    while(seg !=NULL && strcmp(seg->dato.nombre,nombre) != 0)
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

    system("pause");
    system("cls");
    printf("Probando carga ordenada por Nombre de empresa.\n");
    nodoSimpleEmpresa* listaOrdenada = inicListaSimpleEmpresa();

    //TEST Agregar Ordenado
    listaOrdenada = agregarOrdenadoXNombreSimpleEmpresa(listaOrdenada,crearNodoSimpleEmpresa(crearEmpresa("Coca Cola","45459875674")));
    listaOrdenada = agregarOrdenadoXNombreSimpleEmpresa(listaOrdenada,crearNodoSimpleEmpresa(crearEmpresa("Pepsi","46459875674")));
    listaOrdenada = agregarOrdenadoXNombreSimpleEmpresa(listaOrdenada,crearNodoSimpleEmpresa(crearEmpresa("Manaos","47459875674")));
    listaOrdenada = agregarOrdenadoXNombreSimpleEmpresa(listaOrdenada,crearNodoSimpleEmpresa(crearEmpresa("Chori Champion","42459875674")));
    listaOrdenada = agregarOrdenadoXNombreSimpleEmpresa(listaOrdenada,crearNodoSimpleEmpresa(crearEmpresa("Cuatro Cabezas","42455555554")));
    listaOrdenada = agregarOrdenadoXNombreSimpleEmpresa(listaOrdenada,crearNodoSimpleEmpresa(crearEmpresa("ChOri CHaMpInIoN","42455555554")));

    mostrarListaSimpleEmpresa(listaOrdenada);
}

///------------------------- TDA COMPUESTA---------------------------------

nodoSimpleEmpresa *pasarDatosArchivoFacturasATDA (FILE *buf,nodoSimpleEmpresa *lista) // NO SIRVE
{
    Registro_Factura a;

    fread(&a,sizeof(Registro_Factura),1,buf);
    Empresa emp=pasarDatosRegistroAUnaEmpresa(a);
    Cliente_Proveedor cliProv=pasarDatosRegistroAUnClienteProveedor(a);
    Factura fact=pasarDatosRegistroAUnaFactura(a);
    lista=altaFacturas(lista,a);

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
    /*Registro_Factura a=cargarUnRegistroFactura("Coca","12",0,"a","0","0","0",1,crearFecha(10,3,2020),"",0,0,0,0,"MarinaCli",'c',"28");

    persistirRegistrosFactura("ArchivoFacturas",a);

    Registro_Factura b=cargarUnRegistroFactura("Coca","12",0,"a","0","0","0",1,crearFecha(3,11,2019),"",0,0,0,0,"SanchezProv",'p',"30");

    persistirRegistrosFactura("ArchivoFacturas",b);

    Registro_Factura c=cargarUnRegistroFactura("Lacteos Amanecer","14",0,"a","0","0","0",1,crearFecha(20,4,2020),"",0,0,0,0,"SanchezProv",'p',"30");

    persistirRegistrosFactura("ArchivoFacturas",c);

    Registro_Factura d=cargarUnRegistroFactura("Coca","12",0,"a","0","12","120",1,crearFecha(10,8,2020),"",0,0,0,0,"SanchezProv",'p',"30");

    persistirRegistrosFactura("ArchivoFacturas",d);

    Registro_Factura e=cargarUnRegistroFactura("Coca","12",0,"a","0","0","0",1,crearFecha(30,10,2022),"",0,0,0,0,"MarinaCli",'c',"28");

    persistirRegistrosFactura("ArchivoFacturas",e);

    Registro_Factura f=cargarUnRegistroFactura("Coca","12",0,"a","0","0","0",1,crearFecha(20,5,2021),"",0,0,0,0,"CeramicosMdP",'p',"32");

    persistirRegistrosFactura("ArchivoFacturas",f);
    */
    printf("Persiste todo");
    //mostrarArchivoRegistros("ArchivoFacturas");

    nodoSimpleEmpresa *lista=inicListaSimpleEmpresa();
    //lista=pasarDatosArchivoFacturasATDA("ArchivoFacturas",lista);
    //printf("\n-------------TDA Completo-----------------------------\n\n");
    //mostrarTDACompleto(lista);
    system("pause");


    persistirEmpresasEnArchivo("ArchivoEmpresas");
    printf("\nMOSTRANDO ARCHIVO DE EMPRESAS\n");
    mostrarArchivoDeEmpresas("ArchivoEmpresas");

    Registro_Factura reg;
    char control='s';
    while (control=='s')
    {
        reg=cargarUnRegistroFactura(reg,lista);
        if(strlen(reg.nombreEmpresa)!=0)
        {
            Registro_Factura dato;
            dato=reg;
            lista=altaFacturas(lista,dato);
        }


        printf("Desea seguir?");
        fflush(stdin);
        scanf("%c",&control);
    }



    //lista=persistirRegistrosFactura("ArchivoFacturas",lista);

    printf("\n-------------TDA Completo-----------------------------\n\n");
    mostrarTDACompleto(lista);
    system("pause");

    persistirTDAEnArchivo("ArchivoFacturas",lista);

    printf("\nMOSTRANDO ARCHIVO DE FACTURAS\n");
    mostrarArchivoRegistros("ArchivoFacturas");

    /*
    printf("\n----PROBANDO LISTADOS FACTURAS POR EMPRESA -----------------");

    NodoListarFacturas *listaFact=inicListaSimpleListarFacturas();
    //    listaFact=listarTodasFacturasXOrdenFecha(lista);
    listaFact = listarFacturasDetEmpresa(lista,"Coca");
    mostrarNodoListarFacturas(listaFact);


    printf("\n-----LISTANDO FACTURAS POR PERIODO DEL 11/3/2020 AL 21/5/2021----------\n");



    listarFacturasDetEmpresaXPeriodo(lista,"12",crearFecha(11,3,2020),crearFecha(21,5,2021));

    printf("\nPROBANDO FUNCION BUSQUEDA FACTURA\n");
    nodoDobleFactura *nodo=buscarFacturaenTDA(lista,"Coca",'p',"30","120","12");
    if(nodo)
        mostrarUnaFactura(nodo->dato);
    else
        printf("\nNo se encontro esa factura\n");



    char nombreArch2[30]="ArchPruebaPersEnTDA";
    persistirTDAEnArchivo(nombreArch2,lista);
    system("pause");
    printf("\nMostrando el nuevo Archivo una vez persistido el TDA\n");
    mostrarArchivoRegistros(nombreArch2);
    */
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

