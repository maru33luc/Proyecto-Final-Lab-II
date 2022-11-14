#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Resumenes.h"
#include "NodoSimpleEmpresa.h"
#include "NodoDobleFactura.h"
#include "NodoSimpleCP.h"
#include <windows.h>

int main()
{
//TestPersistenciaYDespersistenciaEnTDA();

char nombreArchEmpresas[30]="ArchivoEmpresas";
char nombreArchFacturas[30]="ArchivoFacturas";

nodoSimpleEmpresa *lista=inicListaSimpleEmpresa();

lista=pasarDatosArchivoFacturasATDA(nombreArchFacturas,lista);

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
    case 1:
            system("cls");
            printf("\n%sIngrese la opcion deseada\n \n[1]-Alta Empresas \n\n[2]-Baja Empresas\n \n[3]-Modificacion de Empresas\n \n[4]-Listar Empresas\n \n[0]-salir\n\n%s", azul, normal);
            fflush(stdin);
            scanf("%d",&opcion1);
            switch(opcion1)
                {
                case 1:
                        persistirEmpresasEnArchivo(nombreArchEmpresas);
                        break;
                case 2: /// FALTA DESARROLLAR ----------------------------
                        system("cls");
                        break;

                case 3: /// FALTA DESARROLLAR ----------------------------

                        system("cls");

                        break;

                case 4:
                        system("cls");
                        printf("\n%sIngrese la opcion deseada\n \n[1]-Lista Empresas ordenados alfabeticamente\n\n[2]-Lista Una Empresa Por Nombre\n[0]-Salir\n\n%s", azul, normal);
                        scanf("%d", &opcion1);

                        switch(opcion1)
                        {
                        case 1:
                                system("cls");
                                printf("\nMOSTRANDO ARCHIVO DE EMPRESAS\n");
                                mostrarArchivoDeEmpresas("ArchivoEmpresas");
                                system("pause");
                                break;
                        case 2:
                                system("cls");
                                nodoSimpleEmpresa *aux=buscarNodoXNombreSimpleEmpresa(lista,nombreEmp);
                                verUnaEmpresa(aux);
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
                case 2: /// FALTA DESARROLLAR------------------------------------
                        system("cls");

                        break;
                        }

                case 3:
                        system("cls");

                        break;

                case 4:
                        system("cls");
                        printf("\n%sIngrese la opcion deseada \n\n[1]-Listar Facturas por Empresa\n \n[2]-Listar Facturas por Empresa por periodo determinado\n \n[3]-Todas las Facturas Ordenadas por Fecha\n \n[4]-Listar Ventas de determinada Empresa por Periodo\n \n[5]-Listar Compras de determinada Empresa por Periodon[6]-Listar Clientes/Proveedores de determinada Empresa\n\n%s", azul, normal);
                        fflush(stdin);
                        scanf("%d", &opcion1);
                        switch (opcion1)
                        {
                        case 1:
                                system("cls");


                                break;

                        case 2:
                                system("cls");

                                break;
                        case 3:
                                system("cls");

                                break;
                        case 4:
                                system("cls");


                                break;
                        case 5:
                                system("cls");

                                break;
                        case 6:
                                system("cls");

                                break;

                        }
}


system("cls");
printf("\n%sDesea seguir en el sistema? s/n\n\n%s", azul, normal);
fflush(stdin);
scanf("%c", &controlopciones);
}while(controlopciones=='s');












    return 0;
}
