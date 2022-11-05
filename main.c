#include <stdio.h>
#include <stdlib.h>
#include "Empresa.h"
#include "Cliente.h"
#include "Proveedor.h"
#include "Facturas.h"
#include "Resumenes.h"
#include "NodoSimpleEmpresa.h"
#include "NodoDobleFactura.h"

int main()
{
  /*
char control='s';
Factura a;
nodoDobleFactura *lista=inicListaDoble();

while(control=='s')
{
    a=cargarUnaFactura(a);
    nodoDobleFactura *aux=crearNodoDoble(a);
    lista=insertarOrdenadoDobleXNumComprob(lista,aux);
    printf("\nDesea seguir ingresando Facturas? s/n\n");
    fflush(stdin);
    scanf("%c",&control);
}
mostrarListaDoble(lista);


lista=borrarnodoDobleFacturaXNumComprobante(lista,"123");
printf("Mostrando lista doble de Facturas sin el comprob 123\n");
mostrarListaDoble(lista);


nodoDobleFactura *aux=buscarFacturaDobleXNumComprob(lista,"123");
if(aux!=NULL)
{
    printf("Mostrando la factura numero 123\n");
    mostrarUnaFactura(aux->dato);
}*/

printf("El proyecto compila correctamente.");

TestLibreriaEmpresa();



    return 0;
}







///---------------------VALIDACIONES-----------------------------
/*
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
*/


