#include <stdio.h>
#include <stdlib.h>
#include "Compras.h"
#include "Empresa.h"
#include "Ventas.h"
#include "Resumenes.h"



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
