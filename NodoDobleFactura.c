#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Resumenes.h"
#include "NodoSimpleEmpresa.h"
#include "NodoDobleFactura.h"
#include "NodoSimpleCP.h"
#include <windows.h>

int validarLetras (char Nombre[]) /// Funcion para validar la carga de datos que sean letras con formato char
{
    int i=0;
    int flag=0;
    int esLetra;

    while (i<strlen(Nombre)&& flag==0)
    {
        esLetra=isalpha(Nombre[i]) || isspace(Nombre[i]);
        if (esLetra!=0)
        {
            i++;
        }
        else
        {
            printf("\nError de carga de datos\n");
            flag=1;
        }
    }
    return flag;
}

int validarNumString (char Nombre[]) /// Funcion para validar la carga de datos que sean numeros con formato char
{
    int i=0;
    int flag=0;
    int esNum;

    while (i<strlen(Nombre)&& flag==0)
    {
        esNum=isdigit(Nombre[i]);
        if (esNum!=0)
        {
            i++;
        }
        else
        {
            printf("\nError de carga de datos\n");
            flag=1;
        }
    }
    return flag;
}

int validarFecha (Fecha a) /// Retorna 0 si es valida, 1 si no lo es
{
    int rta=0;

    if(a.anio<1980 || a.anio>2030)
        rta=1;
    else if(a.mes<1 || a.mes>12)
        rta=1;
    else if(a.dia<1 ||a.dia>31)
        rta=1;
    else if (a.mes==4 ||a.mes==6||a.mes==9||a.mes==11)
    {
        if(a.dia>30)
            rta=1;
    }
    else if (a.mes==4 ||a.mes==6||a.mes==9||a.mes==11)
    {
        if(a.dia>30)
            rta=1;
    }
    else if (a.anio%4==0 && a.mes==2 && a.dia>29)
        rta=1;
    else if (a.anio%4!=0 && a.mes==2 && a.dia>28)
        rta= 1;
    return rta;
}

Registro_Factura cargarUnRegistroFactura (Registro_Factura a, nodoSimpleEmpresa *lista)
{
    int flag=0;

    do
    {
        printf("\nIngrese el nombre de la Empresa o presione Enter para salir\n");
        fflush(stdin);

        gets(a.nombreEmpresa);
        if(strlen(a.nombreEmpresa)==0)
            return a;
        else
            flag= validarLetras(a.nombreEmpresa);
    }
    while(flag==1);

    do
    {
        printf("\nIngrese si es una compra ('p') o una venta ('c'):\n");
        fflush(stdin);
        scanf("%c",&a.cp);
        if(a.cp=='c'||a.cp=='C'||a.cp=='p'||a.cp=='P')
            flag=1;
        else
            flag=0;
    }
    while(flag==0);

    do
    {
        printf("\nIngrese el Numero de CUIT del Cliente/Proveedor:\n");
        fflush(stdin);
        gets(a.cuit_cliente_proveedor);
        flag= validarNumString(a.cuit_cliente_proveedor);
    }
    while(flag==1);

    do
    {
        printf("\nIngrese el punto de venta de la Factura: \n");
        fflush(stdin);
        gets(a.punto_venta);
        flag=validarNumString(a.punto_venta);
    }
    while(flag==1);

    do
    {
        printf("\nIngrese el numero de Factura: \n");
        fflush(stdin);
        gets(a.nro_comprobante);
        flag=validarNumString(a.nro_comprobante);
    }
    while(flag==1);

    nodoDobleFactura *aux=buscarFacturaenTDA(lista,a.nombreEmpresa,a.cp,a.cuit_cliente_proveedor,a.nro_comprobante,a.punto_venta);
    if(aux!=NULL)
    {
        printf("\nLa Factura ya se encuentra en la base de datos\n");
        return;
    }
    else
    {
        do
        {
            printf("\nIngrese el Numero de CUIT de la Empresa\n");
            fflush(stdin);
            gets(a.cuit);
            flag= validarNumString(a.cuit);
        }
        while(flag==1);

        do
        {
            printf("\nIngrese el tipo de Factura: (A/B/C)\n");
            fflush(stdin);
            scanf("%c",&a.tipo);
            if(a.tipo=='c'||a.tipo=='C'||a.tipo=='A'||a.tipo=='a'||a.tipo=='B'||a.tipo=='b')
                flag=1;
            else
                flag=0;
        }
        while(flag==0);

        do
        {
            printf("\nIngrese si la factura es Recibo/Factura/Nota Credito: \n");
            fflush(stdin);
            gets(a.comprobante);
            flag=validarLetras(a.comprobante);
        }
        while(flag==1);

        do
        {
            printf("\nIngrese el año de la Factura: (1980-2030)\n");
            fflush(stdin);
            scanf("%d",&a.fecha.anio);
            printf("\nIngrese el mes de la Factura: (1-12)\n");
            fflush(stdin);
            scanf("%d",&a.fecha.mes);
            printf("\nIngrese el dia de la Factura: (1-30/31)\n");
            fflush(stdin);
            scanf("%d",&a.fecha.dia);
            flag=validarFecha(a.fecha);
            if(flag==1)
                printf("\nFormato de Fecha no valido intente nuevamente\n");
        }
        while(flag==1);

        do
        {
            printf("\nIngrese la descripcion de la Factura: \n");
            fflush(stdin);
            gets(a.descripcion);
            flag=validarLetras(a.descripcion);
        }
        while(flag==1);

        do
        {
            printf("\nIngrese el valor neto: \n");
            flag=scanf("%f",&a.neto);
        }
        while(flag==0);

        do
        {
            printf("\nIngrese el porcentaje de IVA: \n");
            flag=scanf("%f",&a.iva);
        }
        while(flag==0);

        do
        {
            printf("\nIngrese el valor total: \n");
            flag=scanf("%f",&a.total);
        }
        while(flag==0);

        do
        {
            printf("\nIngrese el nombre del Cliente/Proveedor: \n");
            fflush(stdin);
            gets(a.nombre_cliente_proveedor);
            flag=validarLetras(a.nombre_cliente_proveedor);
        }
        while(flag==1);


    }
    a.activa_fact=1;
    a.activa_emp=1;

    return a;
}

void mostrarUnRegistroFactura (Registro_Factura a)
{
    printf("\n------------------------------------------------------\n");
    printf("\nNombre de la Empresa: %s\n",a.nombreEmpresa);
    printf("\nCUIT de la Empresa: %s\n",a.cuit);
    printf("\nEstado de la Empresa (activa=0,inactiva=1: %d\n",a.activa_emp);
    printf("\nNombre del cliente/proveedor: %s\n",a.nombre_cliente_proveedor);
    printf("\nCUIT del cliente/proveedor: %s\n",a.cuit_cliente_proveedor);
    printf("\nCliente/ Proveedor (c/p) : %c\n",a.cp);
    printf("\nTipo de comprobante: %s\n",a.comprobante);
    printf("\nNumero de comprobante: %s\n",a.nro_comprobante);
    printf("\nPunto de venta: %s\n",a.punto_venta);
    printf("\nTipo de comprobante a/b/c: %c\n",a.tipo);
    printf("\nFecha de contabilizacion: %d/%d/%d\n",a.fecha.dia,a.fecha.mes,a.fecha.anio);
    printf("\nDescripcion de la Factura: %s\n",a.descripcion);
    printf("\nValor neto: %.2f\n",a.neto);
    printf("\nValor de IVA: %.2f\n",a.iva);
    printf("\nValor total: %.2f\n",a.total);
    printf("\nEstado de la Factura: activa (1) o inactiva (0): %d\n",a.activa_fact);
    printf("\n------------------------------------------------------\n");
}

void mostrarArchivoRegistros (char nombreArch[])
{
    Registro_Factura a;

    FILE *buf=fopen(nombreArch,"rb");

    if(buf)
    {
        while(fread(&a,sizeof(Registro_Factura),1,buf)>0)
            mostrarUnRegistroFactura(a);
        fclose(buf);
    }
}

void mostrarUnaFactura (Factura a)
{
    printf("\n-----------------FACTURA NUMERO %s--------------------\n",a.numComprobante);
    //printf("\nCUIT del cliente/proveedor: %s\n",a.cuit_cliente_proveedor);
    printf("\nTipo de comprobante: %s\n",a.comprobante);
    printf("\nNumero de comprobante: %s\n",a.numComprobante);
    printf("\nPunto de venta: %s\n",a.puntoVenta);
    printf("\nTipo de comprobante a/b/c: %c\n",a.tipo);
    printf("\nId de la Factura: %d\n",a.id_interno);
    printf("\nFecha de contabilizacion: %d/%d/%d\n",a.fecha.dia,a.fecha.mes,a.fecha.anio);
    printf("\nDescripcion de la Factura: %s\n",a.descripcion);
    printf("\nValor neto: %.2f\n",a.neto);
    printf("\nValor de IVA: %.2f\n",a.iva);
    printf("\nValor total: %.2f\n",a.total);
    printf("\nEstado de la Factura: activa (1) o inactiva (0): %d\n",a.activa);
    printf("\n------------------------------------------------------\n");
}

Factura pasarDatosRegistroAUnaFactura(Registro_Factura a)
{
    Factura dato;

    strcpy(dato.numComprobante,a.nro_comprobante);
    dato.tipo=a.tipo;
    strcpy(dato.puntoVenta,a.punto_venta);
    strcpy(dato.comprobante,a.comprobante);
    dato.fecha=a.fecha;
    strcpy(dato.descripcion,a.descripcion);
    dato.neto=a.neto;
    dato.iva=a.iva;
    dato.total=a.total;
    dato.activa=a.activa_fact;

    return dato;
}

Empresa pasarDatosRegistroAUnaEmpresa(Registro_Factura a)
{
    Empresa dato;

    strcpy(dato.nombre,a.nombreEmpresa);
    strcpy(dato.cuit,a.cuit);
    dato.activa_emp=a.activa_emp;

    return dato;
}

Registro_Factura pasarDatosNodoFacturaAUnRegistro(Factura a)
{
    Registro_Factura dato;

    strcpy(dato.nro_comprobante,a.numComprobante);
    dato.tipo=a.tipo;
    strcpy(dato.punto_venta,a.puntoVenta);
    strcpy(dato.comprobante,a.comprobante);
    dato.fecha=a.fecha;
    strcpy(dato.descripcion,a.descripcion);
    dato.neto=a.neto;
    dato.iva=a.iva;
    dato.total=a.total;
    dato.activa_fact=a.activa;

    return dato;
}

Registro_Factura pasarDatosNodoEmpresaAUnRegistro(Empresa a)
{
    Registro_Factura dato;

    strcpy(dato.nombreEmpresa,a.nombre);
    strcpy(dato.cuit,a.cuit);
    dato.activa_emp=a.activa_emp;

    return dato;
}

Cliente_Proveedor pasarDatosRegistroAUnClienteProveedor(Registro_Factura a)
{
    Cliente_Proveedor dato;

    strcpy(dato.nombre,a.nombre_cliente_proveedor);
    strcpy(dato.cuit_cliente_proveedor,a.cuit_cliente_proveedor);
    dato.cp=a.cp;

    return dato;
}

Registro_Factura pasarDatosNodoClienteProveedorARegistro(Cliente_Proveedor a)
{
    Registro_Factura dato;

    strcpy(dato.nombre_cliente_proveedor,a.nombre);
    strcpy(dato.cuit_cliente_proveedor,a.cuit_cliente_proveedor);
    dato.cp=a.cp;

    return dato;
}

Fecha cargarFecha (Fecha dato)
{
    int salir=1;
    do
    {
        printf("\nIngrese el dia:\n");
        scanf("%d",&dato.dia);
        printf("\nIngrese el mes:\n");
        scanf("%d",&dato.mes);
        printf("\nIngrese el año:\n");
        scanf("%d",&dato.anio);

        int flag=validarFecha(dato);
        if (flag==0)
            salir=0;
        else
            printf("\nFormato de fecha no valido intente nuevamente\n");
    }
    while(salir==1);

    return dato;
}

///------------------ LIBRERIA DE LISTA DOBLE FACTURAS----------------------------------------

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


nodoDobleFactura *insertarOrdenadoDobleXFecha (nodoDobleFactura *lista,nodoDobleFactura *nuevo)
{
    int rta=0;

    if(lista==NULL)
        lista=nuevo;
    else
    {
        nodoDobleFactura *seg=lista;
        rta=retornarSiFecha1EsMayor(lista->dato.fecha,nuevo->dato.fecha);
        if(rta==1)
            lista=agregarAlPrincipioDoble(lista,nuevo);
        else
        {
            while(seg!=NULL&&rta==0)
            {
                rta=retornarSiFecha1EsMayor(seg->dato.fecha,nuevo->dato.fecha);
                seg=seg->sig;
            }
            if(seg==NULL)
                lista=agregarAlFinalDoble(lista,nuevo);
            else
            {
                nuevo->sig=seg;
                nuevo->ante=seg->ante;
                (seg->ante)->sig=nuevo;
                seg->ante=nuevo;
            }
        }
    }
    return lista;
}

int retornarSiFecha1EsMayor (Fecha dato1, Fecha dato2)
{
    int rta=1; /// RETORNA 1 SI ES MAYOR, 0 SI ES MENOR

    if(dato1.anio<dato2.anio)
        rta=0;
    else if(dato1.anio==dato2.anio)
    {
        if(dato1.mes<dato2.mes)
            rta=0;
        else if (dato1.mes==dato2.mes)
        {
            if(dato1.dia<dato2.dia)
                rta=0;
        }
    }
    return rta;
}

int retornarSiFecha1EsMenor (Fecha dato1, Fecha dato2)
{
    int rta=1; /// RETORNA 1 SI ES MENOR, 0 SI ES MAYOR

    if(dato1.anio>dato2.anio)
        rta=0;
    else if(dato1.anio==dato2.anio)
    {
        if(dato1.mes>dato2.mes)
            rta=0;
        else if (dato1.mes==dato2.mes)
        {
            if(dato1.dia>dato2.dia)
                rta=0;
        }
    }
    return rta;
}

nodoDobleFactura *buscarFacturaDobleXNumComprob (nodoDobleFactura *lista,char numComprob[])
{
    nodoDobleFactura *seg=lista;

    while(seg!=NULL&&strcmpi(seg->dato.numComprobante,numComprob)!=0)
        seg=seg->sig;

    return seg;
}

///--------------- ESTRUCTURA COMPUESTA ------------------------------------------

nodoSimpleEmpresa *cargarRegistrosFacturaEnTDA(nodoSimpleEmpresa *lista)
{
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
    return lista;
}

nodoSimpleEmpresa *altaFacturas(nodoSimpleEmpresa *lista,Registro_Factura dato)
{
    Empresa emp;
    Cliente_Proveedor cliProv;
    Factura fact;

    emp=pasarDatosRegistroAUnaEmpresa(dato);
    cliProv=pasarDatosRegistroAUnClienteProveedor(dato);
    fact=pasarDatosRegistroAUnaFactura(dato);

    nodoSimpleCP *aux=crearNodoSimpleCP(cliProv);
    nodoSimpleEmpresa *busqC=buscarNodoXCuitSimpleEmpresa(lista,emp.cuit);
    nodoSimpleEmpresa * buscN = buscarNodoXNombreSimpleEmpresa(lista,emp.nombre);

    if(!busqC && !buscN)
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
            ult->cli->fact=insertarOrdenadoDobleXFecha(ult->cli->fact,aux1);
        }
        else
        {
            ult->prov=agregarNodoAlPrincipioSimpleCP(ult->prov,aux);
            ult->prov->fact=inicListaDoble();
            ult->prov->fact=insertarOrdenadoDobleXFecha(ult->prov->fact,aux1);
        }
    }
    else
    {
        nodoDobleFactura *aux1=crearNodoDoble(fact);

        if(cliProv.cp=='c')
        {
            nodoSimpleCP *busq2=buscarNodoXCuitSimpleCP(buscN->cli,cliProv.cuit_cliente_proveedor);
            if(busq2==NULL)
            {
                buscN->cli=agregarNodoAlPrincipioSimpleCP(buscN->cli,aux);
                buscN->cli->fact=inicListaDoble();
                buscN->cli->fact=insertarOrdenadoDobleXFecha(buscN->cli->fact,aux1);
            }
            else
                busq2->fact=insertarOrdenadoDobleXFecha(busq2->fact,aux1);
        }
        else
        {
            nodoSimpleCP *busq2=buscarNodoXCuitSimpleCP(buscN->prov,cliProv.cuit_cliente_proveedor);
            if(busq2==NULL)
            {
                buscN->prov=agregarNodoAlPrincipioSimpleCP(buscN->prov,aux);
                buscN->prov->fact=inicListaDoble();
                buscN->prov->fact=insertarOrdenadoDobleXFecha(buscN->prov->fact,aux1);
            }
            else
                busq2->fact=insertarOrdenadoDobleXFecha(busq2->fact,aux1);
        }
    }
    return lista;
}

nodoDobleFactura* buscarFacturaenTDA(nodoSimpleEmpresa*lista,char nombre_empresa[],char cp,char cuit_cp[],char nro_comprobante[],char punto_venta[])
{
    nodoDobleFactura* nodoEncontrado = NULL;

    nodoSimpleEmpresa* segEmpresa = lista;
    while(segEmpresa && strcmpi(segEmpresa->dato.nombre,nombre_empresa)!= 0)
    {
        segEmpresa = segEmpresa->sig;
    }
    if(segEmpresa)
    {
        nodoSimpleCP* segCP = NULL;
        if(cp == 'c' || cp == 'C')
        {
            segCP = segEmpresa->cli;
        }
        else
        {
            segCP = segEmpresa->prov;
        }
        while(segCP && strcmp(segCP->dato_cp.cuit_cliente_proveedor,cuit_cp)!=0)
        {
            segCP = segCP->sig;
        }
        if(segCP)
        {
            nodoDobleFactura* segFactura = segCP->fact;
            while(segFactura && strcmp(segFactura->dato.numComprobante,nro_comprobante)!=0 && strcmp(segFactura->dato.puntoVenta,punto_venta)!=0)
            {
                segFactura = segFactura->sig;
            }
            if(segFactura)
            {
                nodoEncontrado = segFactura;
            }
        }
    }
    return nodoEncontrado;
}

nodoSimpleEmpresa *bajaFactura (nodoSimpleEmpresa *lista,char nombreEmp[],char cp,char cuit_cp[],char num_comprob[],char punto_venta[])
{
    nodoDobleFactura *fact=buscarFacturaenTDA(lista,nombreEmp,cp,cuit_cp,num_comprob,punto_venta);

    if(fact)
    {
        printf("PRINTEANDO LA FACT ENCONTRADA");
        mostrarUnaFactura(fact->dato);
        system("pause");
        fact->dato.activa=0;
    }
    else
        printf("\nFactura no existente en la base de datos\n");

    return lista;
}

void cargarBusquedaFactura(char nombreEmp[],char* cp,char cuit_cp[],char num_comprob[],char punto_venta[])
{
    int flag = 0;
    do
    {
        printf("\nIngrese el nombre de la Empresa o presione Enter para salir\n");
        fflush(stdin);

        gets(nombreEmp);
        if(strlen(nombreEmp)==0)
            return;
        else
            flag= validarLetras(nombreEmp);
    }
    while(flag==1);

    do
    {
        printf("\nIngrese si es una compra ('p') o una venta ('c'):\n");
        fflush(stdin);
        scanf("%c",cp);
        if((*cp)=='c'||(*cp)=='C'||(*cp)=='p'||(*cp)=='P')
            flag=1;
        else
            flag=0;
    }
    while(flag==0);

    do
    {
        printf("\nIngrese el Numero de CUIT del Cliente/Proveedor:\n");
        fflush(stdin);
        gets(cuit_cp);
        flag= validarNumString(cuit_cp);
    }
    while(flag==1);

    do
    {
        printf("\nIngrese el punto de venta de la Factura: \n");
        fflush(stdin);
        gets(punto_venta);
        flag=validarNumString(punto_venta);
    }
    while(flag==1);

    do
    {
        printf("\nIngrese el numero de Factura: \n");
        fflush(stdin);
        gets(num_comprob);
        flag=validarNumString(num_comprob);
    }
    while(flag==1);
}

nodoSimpleEmpresa *modificarFactura (nodoSimpleEmpresa *lista,char nombreEmp[],char cp,char cuit_cp[],char num_comprob[],char punto_venta[])
{
    int opcion;

    nodoDobleFactura *fact=buscarFacturaenTDA(lista,nombreEmp,cp,cuit_cp,num_comprob,punto_venta);

    if(fact)
    {
        printf("PRINTEANDO LA FACT ENCONTRADA");
        mostrarUnaFactura(fact->dato);
        system("pause");

        printf("\nElija el campo que desea modificar\n\n[1]Fecha de la Factura-\n\n[2]-Descripcion\n \n[3]-Valor Neto\n \n[4]-Numero Comprobante\n\n[5]-Punto de Venta\n\n[6]-Alta de Factura\n\n[0]-salir\n\n");
        scanf("%d",&opcion);

        switch(opcion)
        {
            char controlN;
            int flag=0;
        case 1:

            do
            {
                printf("\nIngrese el año de la Factura: (1980-2030)\n");
                fflush(stdin);
                scanf("%d",fact->dato.fecha.anio);
                printf("\nIngrese el mes de la Factura: (1-12)\n");
                fflush(stdin);
                scanf("%d",fact->dato.fecha.mes);
                printf("\nIngrese el dia de la Factura: (1-30/31)\n");
                fflush(stdin);
                scanf("%d",fact->dato.fecha.dia);
                flag=validarFecha(fact->dato.fecha);
                if(flag==1)
                    printf("\nFormato de Fecha no valido intente nuevamente\n");
            }
            while(flag==1);
            break;

        case 2:

            do
            {
                printf("\nIngrese la descripcion de la Factura: \n");
                fflush(stdin);
                gets(fact->dato.descripcion);
                flag=validarLetras(fact->dato.descripcion);
            }
            while(flag==1);

            break;

        case 3:

            do
            {
                printf("\nIngrese el valor neto: \n");
                flag=scanf("%f",fact->dato.neto);
            }
            while(flag==0);

            break;

        case 4:
            do
            {
                printf("\nIngrese el numero de Factura: \n");
                fflush(stdin);
                gets(fact->dato.numComprobante);
                flag=validarNumString(fact->dato.numComprobante);
            }
            while(flag==1);
            break;

        case 5:

            do
            {
                printf("\nIngrese el punto de venta de la Factura: \n");
                fflush(stdin);
                gets(fact->dato.puntoVenta);
                flag=validarNumString(fact->dato.puntoVenta);
            }
            while(flag==1);
            break;

        case 6:

            printf("\nDesea dar de alta esta factura? s/n\n");
            fflush(stdin);
            scanf("%c",&controlN);
            if(controlN=='s')
                fact->dato.activa=1;
            break;
        }

    }

    return lista;
}


