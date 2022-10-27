#include <stdio.h>
#include <stdlib.h>

#include "nodoSimple.h"

int main()
{
  testLibreriaNodoSimple();
=======
#include "Compras.h"
#include "Empresa.h"
#include "Ventas.h"
#include "Resumenes.h"


typedef struct Factura
{
    char cliente_proveedor[50];
    char comprobante[30];
    char tipo;
    char puntoVenta[5];
    char numComprobante[8];
    int idFactura;
    char fecha_contabilizacion[8];
    char descripcion[100];
    float neto;
    float iva;
    float total;
    int activa; // 0 inactiva 1 activa
    int id_empresa;
} Factura;

typedef struct Cliente_Proveedor
{
  char nombre[50];
  char cuit[10];
  char mail[50];
  char telefono[12];
  char direccion[50];
}


typedef struct
{
    int dia;
    int mes;
    int anio;
}Fecha;

void persistirFacturasCompras(char nombreArchivoCompras[]) ;








    return 0;
}







///---------------------VALIDACIONES-----------------------------

int validarMail (char Mail[]) /// Funcion para validar la carga de datos que correspondan al mail conteniendo el caracter @
{
    int i=0;
    int flag=0;

    if(strlen(Mail)==0)
        flag=1;
    while (i<strlen(Mail)&&flag==0)
    {
        if (Mail[i]=='@')
        {
            flag=1;
        }
        else
        {
            i++;
        }

    }
    if(flag==0)
    {
        printf("\nError de carga de datos\n");
    }
    return flag;
}



void validarFechas (Fecha A) /// Esta no estaba en formato funcion sino simplemente tenia incluidas estas lineas dentro de la funcion de carga de un pedido
{
do
        {
            printf("\nIngrese el anio del pedido: (2022-2040)\n");
            fflush(stdin);
            flag=scanf("%d",&A.fechaPedido.anio);
            if(flag==0||A.fechaPedido.anio<2022 || A.fechaPedido.anio>2040)
               {
                   printf("\nFormato de anio no valido\n");
                   flag=0;
               }

        }while(flag==0);

     do
        {
            printf("\nIngrese el mes del pedido (1-12)\n");
            fflush(stdin);
            flag=scanf("%d",&A.fechaPedido.mes);
            if(flag==0|| A.fechaPedido.mes<1 || A.fechaPedido.mes>12)
            {
                printf("\nFormato de mes no valido\n");
                flag=0;
            }

        }while(flag==0);

      do
        {
            printf("\nIngrese el dia del pedido (1-30/31)\n");
            fflush(stdin);
            flag=scanf("%d",&A.fechaPedido.dia);
            if(flag==0||A.fechaPedido.dia<1 ||A.fechaPedido.dia>31)
            {   printf("\nFormato de numero no valido\n");
                flag=0;
            }
            else if (A.fechaPedido.mes==4 ||A.fechaPedido.mes==6||A.fechaPedido.mes==9||A.fechaPedido.mes==11)
            {
                if(A.fechaPedido.dia>30)
                {
                    printf("\nFormato de numero no valido\n");
                    flag=0;
                }
            }
            else if (A.fechaPedido.anio%4==0 && A.fechaPedido.mes==2 && A.fechaPedido.dia>29)
            {
                    printf("\nFormato de numero no valido\n");
                    flag=0;
            }
            else if (A.fechaPedido.anio%4!=0 && A.fechaPedido.mes==2 && A.fechaPedido.dia>28)
            {
                    printf("\nFormato de numero no valido\n");
                    flag=0;
            }
        }while(flag==0);
}



