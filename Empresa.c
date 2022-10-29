#include <stdio.h>
#include <stdlib.h>
#include "Compras.h"
#include "Empresa.h"
#include "Ventas.h"
#include "Resumenes.h"
#include "NodoDobleFactura.h"

/*
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
}*/

void mostrarUnaEmpresa(Empresa a)
{
    printf("\n---------------------------------------------------------\n");
    printf("\nNombre de la empresa: %s\n", a.nombre);
    printf("\nId de la Empresa: %d\n", a.id_empresa);
    printf("\nNumero de CUIT de la Empresa: %s\n", a.cuit);
    printf("\nCodigo de IVA: %s\n", a.codIVA);
    printf("\n---------------------------------------------------------\n");
}
/*
int verificarPresenciaEmpresaBase (char nombreArchEmpresa[],char cuit[])
{
    int flag=0;
    FILE *buf=fopen(nombreArchEmpresa,"rb");
    Empresa e;

    if (buf!=NULL)
    {
        while(fread(&e,sizeof(Empresa),1,buf)>0&&flag==0)
        {
            if (strcmp(e.cuit,cuit)==0)
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

void mostrarArchivoEmpresas (char nombreArchEmpresas[])
{
    FILE *buf=fopen(nombreArchEmpresas,"rb");
    Empresa e;
    int cant=0;

    if (buf!=NULL)
    {
        while (fread(&e,sizeof(Empresa),1,buf)>0)
        {
            mostrarUnaEmpresa(e);
            cant=ftell(buf)/sizeof(Empresa);
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

int buscarIdEmpresaXCUIT (char nombreArchEmpresa[], char num[])
{
    FILE *buf=fopen(nombreArchEmpresa,"rb");
    Empresa e;
    int flag=0,cant=0;

    if(buf!=NULL)
    {
        while(flag==0 &&fread(&e,sizeof(Empresa),1,buf)>0)
            {
                if (strcmp(e.cuit,num)==0)
                {
                    cant=e.id_empresa;
                    flag=1;
                }
            }
        if(flag==0)
                {
                    printf("\nEse numero de CUIT no figura en la base de empresas\n");
                }

        fclose(buf);
    }
    else
    {
        printf("\nError en la apertura del archivo\n");
    }
    return cant;
}

void mostrarRegistroEmpresaXIdEmpresa (char nombreArchEmpresa [],int id)
{
    FILE *buf=fopen(nombreArchEmpresa,"rb");
    Empresa e;
    int flag=0, cant=0;

    if (buf!=NULL)
    {
      while(flag==0 && fread(&e,sizeof(Empresa),1,buf)>0)
            {
                if(e.id_empresa==id)
                {
                    mostrarUnaEmpresa(e);
                    flag=1;
                }

            }
            if(flag==0)
                {
                    printf("\nIdEmpresa inexistente\n");
                }

        fclose(buf);
    }
    else
    {
        printf("\nError de lectura del archivo\n");
    }
}
*/
