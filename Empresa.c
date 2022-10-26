#include <stdio.h>
#include <stdlib.h>
#include "Compras.h"
#include "Empresa.h"
#include "Ventas.h"
#include "Resumenes.h"


void PersistirEmpresas (char nombreArchEmpresas[])
{
    FILE *buf= fopen(nombreArchEmpresas,"rb");
    Empresa e,a,b;
    char control='s';
    char control2='s';
    char num[30];
    int flag;
    int numEmpresa=1;


    if (buf==NULL)
    {
        buf=fopen(nombreArchEmpresas,"wb");

        if (buf!=NULL)
            {
                while (control=='s')
                {
                    a=cargarUnaEmpresa(a);
                    if(strlen(a.Apellido)==0)
                        fclose(buf);
                    else
                    {
                        e=a;
                        e.id_Empresa=numEmpresa++;
                        fwrite(&e,sizeof(Empresa),1, buf);
                    }
                    printf("\nDesea seguir ingresando clientes? s/n");
                    fflush(stdin);
                    scanf("%c",&control);
                }
             fclose(buf);
            }
        else
            {
            printf("\nError de datos - El archivo no pudo ser abierto\n");
            }
    }
    else
    {
            buf=fopen(nombreArchEmpresas,"ab");

            if(buf!=NULL)
            {
                numEmpresa=cantidadRegistrosArchivoGenerica(nombreArchEmpresas,sizeof(Empresa))+1;
                while (control2=='s')
                {
                    do
                    {
                        printf("\nIngrese el DNI del cliente a ingresar en la base de datos o presione Enter para salir\n");
                        fflush(stdin);
                        gets(num);
                        if(strlen(num)==0)
                        {
                            flag==0;
                            fclose(buf);
                            return;
                        }
                        flag=validarNumString(num);
                    }while(flag==1);

                    flag=verificarPresenciaClienteBase(nombreArchEmpresas,num);

                    if (flag==0)
                    {
                        printf("\nEse numero de DNI no corresponde a ningun cliente de la base de datos\n");

                        a=cargarUnaEmpresa(a);
                        if(strlen(a.Apellido)==0)
                            fclose(buf);
                        else
                        {
                            e=a;
                            e.id_Empresa=numEmpresa;
                            fwrite(&e,sizeof(Empresa),1, buf);
                            numEmpresa++;
                        }
                    }
                    else
                    {
                        printf("\nEl cliente ya se encuentra en la base de datos\n");
                    }
                    printf("\nDesea seguir cargando clientes? s/n\n");
                    fflush(stdin);
                    scanf("%c", &control2);
                }
                fclose(buf);
            }
     }
}

int cantidadRegistrosArchivoGenerica (char nombreArchivo[], int sizeofDato)
{
    FILE *buf= fopen(nombreArchivo,"rb");
    int cant;

    if (buf!=NULL)
    {
        fseek(buf,0,SEEK_END);
        cant= ftell(buf)/sizeofDato;
        fclose(buf);
    }
    else
    {
        printf("El archivo no se pudo abrir");
    }

    return cant;
}
