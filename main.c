#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Empresa.h"
#include "Facturas.h"
#include "Cliente_Proveedor.h"
#include "Resumenes.h"
#include "NodoSimpleEmpresa.h"
#include "NodoDobleFactura.h"
#include "NodoSimpleCP.h"
#include <time.h>
int main()
{



    printf("El proyecto compila correctamente.");

//TestLibreriaEmpresa();


//TestLibreriaFactura();

TestPersistenciaYDespersistenciaEnTDA();
    /*
    Fecha dato1;

    dato1.anio=2021;
    dato1.mes=8;
    dato1.dia=10;

    Fecha dato2;

    dato2.anio=2022;
    dato2.mes=3;
    dato2.dia=10;


    int rta=retornarSiFecha1EsMayor(dato1,dato2);
    if(rta==1)
        printf("\nEl dato1 es mayor\n");
    else
        printf("\nEl dato2 es mayor\n");
    system("pause");


    Fecha dato;
    dato.anio=2022;
    dato.mes=5;
    dato.dia=10;

    Fecha dato1;
    dato1.anio=2022;
    dato1.mes=10;
    dato1.dia=20;

    Fecha dato2;
    dato2.anio=2021;
    dato2.mes=5;
    dato2.dia=10;

    nodoDobleFactura *listaF=inicListaDoble();

    Registro_Factura a=cargarUnRegistroFactura("Coca","12",0,"a","0","0","0",1,dato,"",0,0,0,0,"MarinaCli",'c',"28");

    Factura dato4=pasarDatosRegistroAUnaFactura(a);

    listaF=insertarOrdenadoDobleXFecha(listaF,crearNodoDoble(dato4));

    Registro_Factura b=cargarUnRegistroFactura("Pepsi","13",0,"a","0","0","0",1,dato1,"",0,0,0,0,"MarinaCli",'c',"30");

    Factura dato5=pasarDatosRegistroAUnaFactura(b);

    listaF=insertarOrdenadoDobleXFecha(listaF,crearNodoDoble(dato5));

    Registro_Factura c=cargarUnRegistroFactura("Malboro","14",0,"a","0","0","0",1,dato2,"",0,0,0,0,"MarinaCli",'c',"32");

    Factura dato6=pasarDatosRegistroAUnaFactura(c);

    listaF=insertarOrdenadoDobleXFecha(listaF,crearNodoDoble(dato6));

    mostrarListaDoble(listaF);
    system("pause");
*/

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


