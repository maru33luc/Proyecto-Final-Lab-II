#include <stdio.h>
#include <stdlib.h>
#include "Empresa.h"
#include "Cliente.h"
#include "Proveedor.h"
#include "Facturas.h"
#include "Resumenes.h"
#include "NodoSimpleEmpresa.h"
#include "NodoDobleFactura.h"



Factura cargarUnaFactura (Factura a)
{
    printf("\nIngrese el nombre del cliente/proveedor:\n");
    fflush(stdin);
    gets(a.cliente_proveedor);
    printf("\nIngrese el CUIT del cliente/proveedor:\n");
    fflush(stdin);
    gets(a.cuit_cliente_proveedor);
    printf("\nIngrese el tipo de comprobante:\n");
    fflush(stdin);
    gets(a.comprobante);
    printf("\nIngrese el numero de comprobante:\n");
    fflush(stdin);
    gets(a.numComprobante);
    printf("\nIngrese el punto de venta:\n");
    fflush(stdin);
    gets(a.puntoVenta);
    printf("\nIngrese el tipo de comprobante a/b/c:\n");
    fflush(stdin);
    scanf("\n%c",&a.tipo);
    printf("\nIngrese el id de la Factura:\n");
    scanf("%d",&a.idFactura);
    printf("\nIngrese el año de la Factura:\n");
    scanf("%d",&a.datoFecha.anio);
    printf("\nIngrese el mes de la Factura:\n");
    scanf("%d",&a.datoFecha.mes);
    printf("\nIngrese el dia de la Factura:\n");
    scanf("%d",&a.datoFecha.dia);
    printf("\nIngrese la descripcion de la Factura:\n");
    fflush(stdin);
    gets(a.descripcion);
    printf("\nIngrese el valor neto:\n");
    scanf("%f",&a.neto);
    printf("\nIngrese el IVA:\n");
    scanf("%f",&a.iva);
    printf("\nIngrese el valor total:\n");
    scanf("%f",&a.total);
    printf("\nIngrese si esta activa (1) o inactiva (0):\n");
    scanf("%d",&a.activa);
    printf("\nIngrese el id de la Empresa:\n");
    scanf("%d",&a.id_empresa);

    return a;
}

void mostrarUnaFactura (Factura a)
{
    printf("\n------------------------------------------------------\n");
    printf("\nNombre del cliente/proveedor: %s\n",a.cliente_proveedor);
    printf("\nCUIT del cliente/proveedor: %s\n",a.cuit_cliente_proveedor);
    printf("\nTipo de comprobante: %s\n",a.comprobante);
    printf("\nNumero de comprobante: %s\n",a.numComprobante);
    printf("\nPunto de venta: %s\n",a.puntoVenta);
    printf("\nTipo de comprobante a/b/c: %c\n",a.tipo);
    printf("\nId de la Factura: %d\n",a.idFactura);
    printf("\nFecha de contabilizacion: %d/%d/%d\n",a.datoFecha.dia,a.datoFecha.mes,a.datoFecha.anio);
    printf("\nDescripcion de la Factura: %s\n",a.descripcion);
    printf("\nValor neto: %.2f\n",a.neto);
    printf("\nValor de IVA: %.2f\n",a.iva);
    printf("\nValor total: %.2f\n",a.total);
    printf("\nEstado de la Factura: activa (1) o inactiva (0): %d\n",a.activa);
    printf("\nId de la Empresa: %d\n",a.id_empresa);
    printf("\n------------------------------------------------------\n");
}


/*
void persistirFacturasVentas(char nombreArchivoVentas[])
{
    FILE*buf1=fopen(nombreArchivoVentas,"rb");
    Factura e;
    long int idComprob=1;
    char control='s';


    if(buf1==NULL)
    {
        buf1=fopen(nombreArchivoVentas,"wb");

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
            buf1=fopen(nombreArchivoVentas,"ab");

            if(buf1!=NULL)
            {
                idComprob=cantidadRegistrosArchivoGenerica(nombreArchivoVentas,sizeof(Factura))+1;
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


void mostrarArchivoVentas (char nombreArchVentas[])
{
    FILE *buf=fopen(nombreArchVentas,"rb");
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
