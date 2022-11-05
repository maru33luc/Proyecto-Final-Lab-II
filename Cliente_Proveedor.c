#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Cliente_Proveedor.h"

//LIBRERIA ESTRUCTURA CLIENTE_PROVEEDOR
Cliente_Proveedor crearCP(char nombre[],char cuit_cp[],char cp)
{
    Cliente_Proveedor nuevo_cp;
    strcpy(nuevo_cp.nombre,nombre);
    strcpy(nuevo_cp.cuit_cliente_proveedor,cuit_cp);
    nuevo_cp.cp = cp;

    return nuevo_cp;
}

void mostrarUnCP(Cliente_Proveedor CP)
{
    printf("----------------------------\n");
    printf("Nombre: %s\n",CP.nombre);
    printf("CP: %c\n",CP.cp);
    printf("CUIT: %s\n",CP.cuit_cliente_proveedor);
}



//FUNCIONES ANTERIORES
/*
void persistirFacturasCompras(char nombreArchivoCompras[])
{
    FILE*buf1=fopen(nombreArchivoCompras,"rb");
    Factura e;
    long int idComprob=1;
    char control='s';


    if(buf1==NULL)
    {
        buf1=fopen(nombreArchivoCompras,"wb");

        if(buf1!=NULL)
        {
             while (control=='s')
                {
                    e=cargarFactura(e,30);
                    if(e.id_empresa==0)
                        fclose(buf1);
                    else
                    {
                        e.idComprobante=idComprob;
                        fwrite(&e,sizeof(Factura),1, buf1);
                    }
                    printf("\nDesea seguir ingresando pedidos? s/n");
                    fflush(stdin);
                    scanf("%c",&control);
                }

        fclose(buf1);
        }
        else
            printf("\nError de datos - El archivo no pudo ser abierto\n");
    }
    else
    {
            buf1=fopen(nombreArchivoCompras,"ab");

            if(buf1!=NULL)
            {
                idComprob=cantidadRegistrosArchivoGenerica(nombreArchivoCompras,sizeof(Factura))+1;
                while(control=='s')
                {
                    e=cargarFactura(e,30);
                    if(e.id_empresa==0)
                        fclose(buf1);
                    else
                    {
                        e.idComprobante=idComprob;
                        fwrite(&e,sizeof(Factura),1, buf1);
                    }

                    printf("\nDesea seguir ingresando pedidos? s/n");
                    fflush(stdin);
                    scanf("%c",&control);
                    idPedido++;
                }
            fclose(buf1);
            }
            else
                printf("\nError de datos - El archivo no pudo ser abierto\n");
    }
}

int verificarPresenciaFacturaBase (char nombreArchFactura[],char comprobante[])
{
    int flag=0;
    FILE *buf=fopen(nombreArchFactura,"rb");
    Factura e;

    if (buf!=NULL)
    {
        while(fread(&e,sizeof(Factura),1,buf)>0&&flag==0)
        {
            if (strcmp(e.comprobante,comprobante)==0)
            {
                flag=1;
            }
        }
     fclose(buf);
    }
    else
    {
        printf("\nError en la lectura del archivo");
    }
    return flag;
}

void mostrarArchivoCompras (char nombreArchCompras[])
{
    FILE *buf=fopen(nombreArchCompras,"rb");
    Factura e;
    int cant=0;

    if (buf!=NULL)
    {
        while (fread(&e,sizeof(Factura),1,buf)>0)
        {
            mostrarUnaFactura(e);
            cant=ftell(buf)/sizeof(Factura);
            if (cant%2==0)
                system("pause");
        }

       fclose(buf);
    }
    else
    {
        printf("\nError de lectura de datos\n");
    }
}
*/
