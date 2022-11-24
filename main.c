#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Resumenes.h"
#include "NodoSimpleEmpresa.h"
#include "NodoDobleFactura.h"
#include "NodoSimpleCP.h"
#include <windows.h>
#include <conio.h>

int main()
{
    char nombreArchEmpresas[30]="ArchivoEmpresas";
    char nombreArchFacturas[30]="ArchivoFacturas";

    nodoSimpleEmpresa *lista=inicListaSimpleEmpresa();

    lista=pasarDatosArchivoEmpresasATDA(nombreArchEmpresas,lista);
    lista=pasarDatosArchivoFacturasATDA(nombreArchFacturas,lista);

    int admin=0;
    char num[30];
    int cant;

    int flag=0,id;
    long int cantx,cantdni,dnip;
    char dninum[30];


    int idx;

    int opcionPantallaPrincipal;
    char controlopciones='s';
    int idxx,idp, opcion2;


    const char *const verde = "\033[0;40;32m";
    const char *const subrayado_fazul_verde = "\033[4;44;32m";
    const char *const normal = "\033[0m";
    const char *const rojo = "\033[0;40;31m";
    const char *const azul = "\033[0;40;34m";

    int numVista;

    system("color 01");
    printf("\nSeleccione una vista: \n\nVista Administrador [1]\n\nVista Usuario [2]\n\n");
    scanf("%d",&numVista);
    if(numVista==1)
        admin=1;

    do
    {
        system("cls");
        printf("\n%sIngrese la opcion a la cual desea ingresar:\n\n[1]-Empresas \n \n[2]-Facturas\n \n[3]-Salir\n\n%s",azul, normal);
        scanf("%d", &opcionPantallaPrincipal);
        if(opcionPantallaPrincipal==3)
            return;
        switch (opcionPantallaPrincipal)
        {
            int opcion1;
            char nombreEmp[30];
            nodoDobleFactura *fact;
        case 1:
            system("cls");
            printf("\n%sIngrese la opcion deseada\n \n[1]-Alta Empresas \n\n[2]-Baja Empresas\n \n[3]-Listar Empresas\n\n[0]-salir\n\n%s", azul, normal);
            fflush(stdin);
            scanf("%d",&opcion1);
            switch(opcion1)
            {
            case 1:
                lista=persistirEmpresasEnArchivo(nombreArchEmpresas,lista);
                break;
            case 2:
                system("cls");
                printf("\nIngrese el nombre de la Empresa:\n");
                fflush(stdin);
                gets(nombreEmp);
                lista=BajaEmpresa(nombreArchEmpresas,lista,nombreEmp);
                system("pause");
                break;

            case 3:
                system("cls");
                printf("\n%sIngrese la opcion deseada\n \n[1]-Lista Empresas ordenados alfabeticamente\n\n[2]-Lista Una Empresa Por Nombre\n\n[0]-Salir\n\n%s", azul, normal);
                scanf("%d", &opcion1);

                switch(opcion1)
                {
                case 1:
                    system("cls");
                    printf("\nLista de Empresas Ordenadas Alfabeticamente:\n");
                    mostrarListaSimpleEmpresa(lista);
                    system("pause");
                    break;
                case 2:
                    system("cls");
                    verUnaEmpresa(lista);
                    system("pause");
                    break;
                }
                break;
            }
            break;
        case 2:
            system("cls");
            printf("\n%sIngrese la opcion deseada\n \n[1]-Alta Factura\n \n[2]-Baja Factura \n\n[3]-Modificacion de Factura\n \n[4]-Listados \n\n[0]-salir\n\n%s", azul, normal);
            fflush(stdin);
            scanf("%d",&opcion1);
            switch(opcion1)
            {
            case 1:
                system("cls");
                lista=cargarRegistrosFacturaEnTDA(lista);
                persistirTDAEnArchivo("ArchivoFacturas",lista);
                break;
            case 2:
                system("cls");
                char cp;
                char cuit_cp[15];
                char num_comprob[20];
                char punto_venta[8];
                cargarBusquedaFactura(nombreEmp,&cp,cuit_cp,num_comprob,punto_venta);
                lista=bajaFactura(lista,nombreEmp,cp,cuit_cp,num_comprob,punto_venta);
                persistirTDAEnArchivo(nombreArchFacturas,lista);
                break;

            case 3:
                system("cls");
                cargarBusquedaFactura(nombreEmp,&cp,cuit_cp,num_comprob,punto_venta);
                lista=modificarFactura(lista,nombreEmp,cp,cuit_cp,num_comprob,punto_venta);
                persistirTDAEnArchivo(nombreArchFacturas,lista);
                break;

            case 4:
                system("cls");
                printf("\n%sIngrese la opcion deseada \n\n[1]-Listar Facturas por Empresa\n \n[2]-Listar Facturas por Empresa por periodo determinado\n \n[3]-Todas las Facturas Ordenadas por Fecha\n \n[4]-Listar Ventas de determinada Empresa por Periodo\n\n[5]-Listar Compras de determinada Empresa por Periodo\n\n[6]-Listar Clientes/Proveedores de determinada Empresa\n\n[0]-salir\n\n%s", azul, normal);
                fflush(stdin);
                scanf("%d", &opcion1);
                NodoListarFacturas *listaFact;

                Fecha inicio;
                Fecha final;
                switch (opcion1)
                {
                case 1:
                    system("cls");
                    listaFact=inicListaSimpleListarFacturas();
                    printf("\nIngrese el nombre de la Empresa:\n");
                    fflush(stdin);
                    gets(nombreEmp);
                    listaFact = listarFacturasDetEmpresa(lista,nombreEmp,admin);
                    if(listaFact->nombreEmpresa)
                    {
                        system("cls");
                        printf("\n%s",nombreEmp);
                        mostrarFacturasGo(listaFact);
                    }
                    else
                        printf("\nLa Empresa no tiene cargada Facturas\n");
                    system("pause");
                    break;

                case 2:
                    system("cls");
                    listaFact=inicListaSimpleListarFacturas();
                    printf("\nIngrese el nombre de la Empresa:\n");
                    fflush(stdin);
                    gets(nombreEmp);
                    inicio=cargarFecha(inicio);
                    final=cargarFecha(final);
                    listaFact=listarFacturasDetEmpresaXPeriodo(lista,nombreEmp,inicio,final,admin);
                    if(listaFact->nombreEmpresa)
                    {
                        system("cls");
                        printf("\n%s",nombreEmp);
                        mostrarFacturasGo(listaFact);
                    }
                    else
                        printf("\nLa Empresa no tiene cargadas Facturas en ese periodo\n");
                    system("pause");
                    break;
                case 3:
                    system("cls");
                    listaFact=inicListaSimpleListarFacturas();
                    listaFact = listarTodasFacturasXOrdenFecha(lista,admin);
                    if(listaFact)
                        mostrarFacturasGoAll(listaFact);
                    else
                        printf("\nNo hay Facturas en la base de datos\n");
                    system("pause");
                    break;
                case 4:
                    system("cls");
                    listaFact=inicListaSimpleListarFacturas();
                    printf("\nIngrese el nombre de la Empresa:\n");
                    fflush(stdin);
                    gets(nombreEmp);
                    inicio=cargarFecha(inicio);
                    final=cargarFecha(final);
                    listaFact=listarVentasDetEmpresaXPeriodo(lista,nombreEmp,inicio,final,admin);
                    if(listaFact->nombreEmpresa)
                    {
                        system("cls");
                        printf("\n%s",nombreEmp);
                        mostrarFacturasGo(listaFact);
                    }
                    else
                        printf("\nLa Empresa no tiene Facturas de Ventas en ese periodo\n");
                    system("pause");
                    break;
                case 5:
                    system("cls");
                    listaFact=inicListaSimpleListarFacturas();
                    printf("\nIngrese el nombre de la Empresa:\n");
                    fflush(stdin);
                    gets(nombreEmp);
                    inicio=cargarFecha(inicio);
                    final=cargarFecha(final);
                    listaFact=listarComprasDetEmpresaXPeriodo(lista,nombreEmp,inicio,final,admin);
                    if(listaFact->nombreEmpresa)
                    {
                        system("cls");
                        printf("\n%s",nombreEmp);
                        mostrarFacturasGo(listaFact);
                    }
                    else
                        printf("\nLa Empresa no tiene Facturas de Compras en ese periodo\n");
                    system("pause");
                    break;
                case 6:
                    system("cls");
                    listarCPDeEmpresa(lista);
                    system("pause");
                    break;

                }
            }
        }



        system("cls");
        printf("\n%sDesea seguir en el sistema? s/n\n\n%s", azul, normal);
        fflush(stdin);
        scanf("%c", &controlopciones);
    }
    while(controlopciones=='s');


    return 0;
}

