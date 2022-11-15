#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Resumenes.h"
#include "NodoSimpleEmpresa.h"
#include "NodoDobleFactura.h"
#include "NodoSimpleCP.h"
#include <windows.h>


/// ------------LISTADOS FACTURAS-----------------------------------------

NodoListarFacturas *listarTodasFacturasXOrdenFecha (nodoSimpleEmpresa *lista,int admin)
{
    NodoListarFacturas *listaFact=inicListaSimpleListarFacturas();

    nodoSimpleEmpresa *segLista=lista;
    while(segLista!=NULL)
    {
        nodoSimpleCP *segCli=segLista->cli;
        while(segCli!=NULL)
        {
            nodoDobleFactura *segCliFact=segCli->fact;
            while(segCliFact)
            {
              if(!admin){
                if(segCliFact->dato.activa){
                  listaFact=agregarNodoAlFinalNodoListarFacturas(listaFact,crearNodoListarFacturas(segLista->dato.nombre,segCliFact->dato,segCli->dato_cp.nombre,segCli->dato_cp.cp));
                }
              }else{
               listaFact=agregarNodoAlFinalNodoListarFacturas(listaFact,crearNodoListarFacturas(segLista->dato.nombre,segCliFact->dato,segCli->dato_cp.nombre,segCli->dato_cp.cp));
              }

                segCliFact=segCliFact->sig;
            }
            segCli=segCli->sig;
        }
        nodoSimpleCP *segProv=segLista->prov;
        while(segProv!=NULL)
        {
            nodoDobleFactura *segProvFact=segProv->fact;
            while(segProvFact)
            {
              if(!admin){
                if(segProv->fact->dato.activa){
                  listaFact=agregarNodoAlFinalNodoListarFacturas(listaFact,crearNodoListarFacturas(segLista->dato.nombre,segProvFact->dato,segProv->dato_cp.nombre,segProv->dato_cp.cp));
                }
              }else{
              listaFact=agregarNodoAlFinalNodoListarFacturas(listaFact,crearNodoListarFacturas(segLista->dato.nombre,segProvFact->dato,segProv->dato_cp.nombre,segProv->dato_cp.cp));
              }

                segProvFact=segProvFact->sig;
            }
            segProv=segProv->sig;
        }
        segLista=segLista->sig;
    }
    return listaFact;
}

NodoListarFacturas *listarFacturasDetEmpresaXPeriodo (nodoSimpleEmpresa *lista,char nombre_empresa[],Fecha fechaInicio,Fecha fechaFinal,int admin)
{
    NodoListarFacturas *listarFacturas=inicListaSimpleListarFacturas();

    nodoSimpleEmpresa *empresa=buscarNodoXNombreSimpleEmpresa(lista,nombre_empresa);

    if(empresa)
    {
        nodoSimpleCP *segCli=empresa->cli;
        while(segCli!=NULL)
        {
            nodoDobleFactura *segFactCli=segCli->fact;
            while(segFactCli)
            {
                if(retornaSiFechaEstaComprendidaEnPeriodoDado(segFactCli->dato.fecha,fechaInicio,fechaFinal))
                {
                   NodoListarFacturas *aux=crearNodoListarFacturas(lista->dato.nombre,segFactCli->dato,segCli->dato_cp.nombre,segCli->dato_cp.cp);

                  if(!admin){
                    if(segFactCli->dato.activa){
                       listarFacturas=agregarNodoListarFactAlPrincipio(listarFacturas,aux);
                    }
                  }else{
                    listarFacturas=agregarNodoListarFactAlPrincipio(listarFacturas,aux);
                  }

                }
                segFactCli=segFactCli->sig;
            }
            segCli=segCli->sig;
        }

        nodoSimpleCP *segProv=empresa->prov;
        while(segProv!=NULL)
        {
            nodoDobleFactura *segFactProv=segProv->fact;
            while(segFactProv)
            {
                if(retornaSiFechaEstaComprendidaEnPeriodoDado(segFactProv->dato.fecha,fechaInicio,fechaFinal)==1)
                {
                    NodoListarFacturas *aux2=crearNodoListarFacturas(lista->dato.nombre,segFactProv->dato,segProv->dato_cp.nombre,segProv->dato_cp.cp);

                  if(admin==0){
                    if(segFactProv->dato.activa){
                      listarFacturas=agregarNodoListarFactAlPrincipio(listarFacturas,aux2);
                    }
                  }else{
                  listarFacturas=agregarNodoListarFactAlPrincipio(listarFacturas,aux2);
                  }

                }
                segFactProv=segFactProv->sig;
            }
            segProv=segProv->sig;
        }
    }

    return listarFacturas;
}

NodoListarFacturas* listarVentasDetEmpresaXPeriodo (nodoSimpleEmpresa *lista,char nombre_empresa[],Fecha fechaInicio,Fecha fechaFinal,int admin)
{
    NodoListarFacturas* destino =  inicListaSimpleListarFacturas();
    nodoSimpleEmpresa *empresaEncontrada = buscarNodoXNombreSimpleEmpresa(lista,nombre_empresa);
    if(empresaEncontrada)
    {
        nodoSimpleCP *segCli=empresaEncontrada->cli;
        while(segCli!=NULL)
        {
            nodoDobleFactura *segFactCli=segCli->fact;
            while(segFactCli)
            {
                if(retornaSiFechaEstaComprendidaEnPeriodoDado(segFactCli->dato.fecha,fechaInicio,fechaFinal))
                {
                  if(!admin){
                    if(segFactCli->dato.activa){
                      destino = agregarNodoAlFinalNodoListarFacturas(destino,crearNodoListarFacturas(nombre_empresa,segFactCli->dato,segCli->dato_cp.nombre,segCli->dato_cp.cp));
                    }
                  }else{
                  destino = agregarNodoAlFinalNodoListarFacturas(destino,crearNodoListarFacturas(nombre_empresa,segFactCli->dato,segCli->dato_cp.nombre,segCli->dato_cp.cp));
                  }

                }
                segFactCli=segFactCli->sig;
            }
            segCli=segCli->sig;
        }
    }
    return destino;
}

NodoListarFacturas* listarComprasDetEmpresaXPeriodo (nodoSimpleEmpresa *lista,char nombre_empresa[],Fecha fechaInicio,Fecha fechaFinal,int admin)
{
    NodoListarFacturas* destino = inicListaSimpleListarFacturas();
    nodoSimpleEmpresa *empresaEncontrada = buscarNodoXNombreSimpleEmpresa(lista,nombre_empresa);
    if(empresaEncontrada)
    {
        nodoSimpleCP *segPro=empresaEncontrada->prov;
        while(segPro!=NULL)
        {
            nodoDobleFactura *segFactPro=segPro->fact;
            while(segFactPro)
            {
                if(retornaSiFechaEstaComprendidaEnPeriodoDado(segFactPro->dato.fecha,fechaInicio,fechaFinal))
                {
                  if(!admin){
                    if(segFactPro->dato.activa){
                    destino = agregarNodoAlFinalNodoListarFacturas(destino,crearNodoListarFacturas(nombre_empresa,segFactPro->dato,segPro->dato_cp.nombre,segPro->dato_cp.cp));
                    }
                  }else{
                  destino = agregarNodoAlFinalNodoListarFacturas(destino,crearNodoListarFacturas(nombre_empresa,segFactPro->dato,segPro->dato_cp.nombre,segPro->dato_cp.cp));
                  }
                }
                segFactPro=segFactPro->sig;
            }
            segPro=segPro->sig;
        }
    }
    return destino;
}

int retornaSiFechaEstaComprendidaEnPeriodoDado (Fecha dato, Fecha limInf, Fecha limSup)
{
    if(retornarSiFecha1EsMayor(dato,limInf)&&retornarSiFecha1EsMenor(dato,limSup))
        return 1;
    else
        return 0;
}

NodoListarFacturas *listarFacturasDetEmpresa (nodoSimpleEmpresa *lista,char nombre_empresa[],int admin)
{
    NodoListarFacturas *listarFacturas=inicListaSimpleListarFacturas();

    nodoSimpleEmpresa *empresa=buscarNodoXNombreSimpleEmpresa(lista,nombre_empresa);

    if(empresa)
    {
        nodoSimpleCP *segCli=empresa->cli;
        while(segCli!=NULL)
        {
            nodoDobleFactura *segFactCli=segCli->fact;
            while(segFactCli)
            {
               NodoListarFacturas *aux=crearNodoListarFacturas(lista->dato.nombre,segFactCli->dato,segCli->dato_cp.nombre,segCli->dato_cp.cp);
              if(!admin){
                if(segFactCli->dato.activa){
                   listarFacturas=agregarNodoListarFactAlPrincipio(listarFacturas,aux);
                }
              }else{
               listarFacturas=agregarNodoListarFactAlPrincipio(listarFacturas,aux);
              }

                segFactCli=segFactCli->sig;
            }
            segCli=segCli->sig;
        }
        nodoSimpleCP *segProv=empresa->prov;
        while(segProv!=NULL)
        {
            nodoDobleFactura *segFactProv=segProv->fact;
            while(segFactProv)
            {
                NodoListarFacturas *aux2=crearNodoListarFacturas(lista->dato.nombre,segFactProv->dato,segProv->dato_cp.nombre,segProv->dato_cp.cp);
                if(!admin){
                  if(segFactProv->dato.activa){
                    listarFacturas=agregarNodoListarFactAlPrincipio(listarFacturas,aux2);
                  }
                }else{
                listarFacturas=agregarNodoListarFactAlPrincipio(listarFacturas,aux2);
                }
                segFactProv=segFactProv->sig;
            }
            segProv=segProv->sig;
        }

    }
    return listarFacturas;
}


//-----------LIBRERIA LISTA SIMPLE NODOSLISTARFACTURAS-------------------------

NodoListarFacturas* inicListaSimpleListarFacturas()
{
    return NULL;
}

NodoListarFacturas* crearNodoListarFacturas(char nombreEmp[],Factura a, char nombreCliProv[],char cp)
{
    NodoListarFacturas* aux = malloc(sizeof(NodoListarFacturas));
    aux->dato=a;
    aux->cp=cp;
    strcpy(aux->nombreEmpresa,nombreEmp);
    strcpy(aux->nombreClienteProveedor,nombreCliProv);
    aux->sig = NULL;

    return aux;
}

NodoListarFacturas* agregarNodoListarFactAlPrincipio(NodoListarFacturas* lista, NodoListarFacturas* nuevoNodo)
{
    if(lista != NULL)
    {
        nuevoNodo->sig = lista;
    }
    lista = nuevoNodo;

    return lista;
}

NodoListarFacturas* buscarUltimoNodoListarFacturas(NodoListarFacturas* lista)
{
    NodoListarFacturas* seg = lista;

    if(seg !=NULL)
    {
        while(seg->sig != NULL)
        {
            seg = seg->sig;
        }
    }
    return seg;
}

NodoListarFacturas* agregarNodoAlFinalNodoListarFacturas(NodoListarFacturas* lista,NodoListarFacturas* nuevoNodo)
{
    if(lista != NULL)
    {
        NodoListarFacturas* ultimo = buscarUltimoNodoListarFacturas(lista);
        ultimo->sig = nuevoNodo;
    }
    else
    {
        lista = nuevoNodo;
    }
    return lista;
}

void mostrarNodoListarFacturas (NodoListarFacturas *lista)
{
    while(lista)
    {
        mostrarUnNodoListarFacturas(lista);
        lista=lista->sig;
    }
}

void mostrarUnNodoListarFacturas (NodoListarFacturas *nodo)
{
    printf("\nNombre Empresa: %s",nodo->nombreEmpresa);
    mostrarUnaFactura(nodo->dato);
    printf("Nombre Cliente/Proveedor: %s",nodo->nombreClienteProveedor);
    printf("\nCP: %c",nodo->cp);
}

void mostrarFacturasGo(NodoListarFacturas* lista)
{
    int t=6;
    Factura facturaActual = lista->dato;
    gotoxy(2,3);
    printf("|COMPROBANTE");
    gotoxy(15,3);
    printf("|TIPO");
    gotoxy(21,3);
    printf("|P VENTA");
    gotoxy(30,3);
    printf("|N COMP");
    gotoxy(40,3);
    printf("|FECHA");
    gotoxy(52,3);
    printf("|DESCRIPCION");
    gotoxy(65,3);
    printf("|NETO");
    gotoxy(76,3);
    printf("|IVA");
    gotoxy(81,3);
    printf("|TOTAL");
    gotoxy(93,3);
    printf("|ESTADO");
    gotoxy(104,3);
    printf("|NOMBRE C/P");
    gotoxy(112,3);
    printf("|Compra/Venta");

    gotoxy(0,4);
    printf("\n-----------------------------------------------------------------------------------------------------------------------------\n");

    while(lista)
    {
        facturaActual = lista->dato;
        gotoxy(2,t);
        printf("| %s",facturaActual.comprobante );
        gotoxy(15,t);
        printf("| %c",facturaActual.tipo);
        gotoxy(21,t);
        printf("| %s",facturaActual.puntoVenta );
        gotoxy(30,t);
        printf("| %s", facturaActual.numComprobante);
        gotoxy(40,t);
        printf("| %i/%i/%i",facturaActual.fecha.dia,facturaActual.fecha.mes,facturaActual.fecha.anio );
        gotoxy(52,t);
        printf("| %s", facturaActual.descripcion);
        gotoxy(65,t);
        printf("| %.1f", facturaActual.neto);
        gotoxy(76,t);
        printf("| %.1f", facturaActual.iva);
        gotoxy(81,t);
        printf("| %.1f", facturaActual.total);
        gotoxy(93,t);
        facturaActual.activa == 1? printf("| ACTIVA"):printf("| INACTIVA");
        gotoxy(104,t);
        printf("| %s",lista->nombreClienteProveedor);
        gotoxy(112,t);
        if(lista->cp =='c')
        {
            printf("| VENTA");
        }
        else
            printf("| COMPRA");
        t++;

        lista = lista->sig;
    }
    printf("\n-----------------------------------------------------------------------------------------------------------------------------\n");
}

void mostrarFacturasGoAll(NodoListarFacturas* lista)
{
    int t=6;
    Factura facturaActual = lista->dato;
    gotoxy(1,3);
    printf("|COMPROBANTE");
    gotoxy(14,3);
    printf("|TIPO");
    gotoxy(20,3);
    printf("|P VENTA");
    gotoxy(29,3);
    printf("|N COMP");
    gotoxy(39,3);
    printf("|FECHA");
    gotoxy(51,3);
    printf("|DESCRIPCION");
    gotoxy(64,3);
    printf("|NETO");
    gotoxy(75,3);
    printf("|IVA");
    gotoxy(80,3);
    printf("|TOTAL");
    gotoxy(92,3);
    printf("|ESTADO");
    gotoxy(103,3);
    printf("|NOM.C/P");
    gotoxy(113,3);
    printf("|C/V");
    gotoxy(120,3);
    printf("|EMPRESA");


    gotoxy(0,4);
    printf("\n----------------------------------------------------------------------------------------------------------------------------------\n");

    while(lista)
    {
        facturaActual = lista->dato;
        gotoxy(1,t);
        printf("| %s",facturaActual.comprobante );
        gotoxy(14,t);
        printf("| %c",facturaActual.tipo);
        gotoxy(20,t);
        printf("| %s",facturaActual.puntoVenta );
        gotoxy(29,t);
        printf("| %s", facturaActual.numComprobante);
        gotoxy(39,t);
        printf("| %i/%i/%i",facturaActual.fecha.dia,facturaActual.fecha.mes,facturaActual.fecha.anio );
        gotoxy(51,t);
        printf("| %s", facturaActual.descripcion);
        gotoxy(64,t);
        printf("| %.1f", facturaActual.neto);
        gotoxy(75,t);
        printf("| %.1f", facturaActual.iva);
        gotoxy(80,t);
        printf("| %.1f", facturaActual.total);
        gotoxy(92,t);
        facturaActual.activa == 1? printf("| ACTIVA"):printf("| INACTIVA");
        gotoxy(103,t);
        printf("| %s",lista->nombreClienteProveedor);
        gotoxy(113,t);
        if(lista->cp=='p')
        {
            printf("| COMP.");
        }
        else
            printf("| VENT.");
        gotoxy(120,t);
        printf("| %s",lista->nombreEmpresa);
        t++;

        lista = lista->sig;
    }
    printf("\n----------------------------------------------------------------------------------------------------------------------------------\n");
}

void gotoxy (int x, int y)
{

    HANDLE manipulador;
    COORD coordenadas;
    manipulador = GetStdHandle (STD_OUTPUT_HANDLE);
    coordenadas.X = x;
    coordenadas.Y = y;
    SetConsoleCursorPosition (manipulador, coordenadas);
}

void listarCPDeEmpresa(nodoSimpleEmpresa* lista)
{
    char nombre_empresa[50];
    int flag = 0;
    do
    {
        printf("Ingrese el nombre de la empresa: \n");
        fflush(stdin);
        scanf("%s",&nombre_empresa);
        if(strlen(nombre_empresa)<50)
        {
            flag = 1;
        }
    }
    while(flag == 0);

    nodoSimpleCP* listaCP = listarTodosCPXEmpresa(lista,nombre_empresa);
    if(listaCP)
    {
        mostrarClientesProveedoresGo(lista,nombre_empresa);
    }
    else
    {
        printf("Empresa no encontrada.\n");
    }

}

nodoSimpleCP* listarTodosCPXEmpresa(nodoSimpleEmpresa* lista,char nombre_empresa[])
{
    nodoSimpleCP* listaCP = inicListaSimpleCP();
    nodoSimpleEmpresa* empresaEncontrada = buscarNodoXNombreSimpleEmpresa(lista,nombre_empresa);
    if(empresaEncontrada)
    {
        nodoSimpleCP* segCli = empresaEncontrada->cli;
        nodoSimpleCP* segProv= empresaEncontrada->prov;
        while(segCli)
        {
            listaCP = agregarNodoAlFinalSimpleCP(listaCP,crearNodoSimpleCP(segCli->dato_cp));
            segCli = segCli->sig;
        }
        while(segProv)
        {
            listaCP = agregarNodoAlFinalSimpleCP(listaCP,crearNodoSimpleCP(segProv->dato_cp));
            segProv = segProv->sig;
        }
    }
    return listaCP;
}

void mostrarClientesProveedoresGo(nodoSimpleCP* lista,char nombreEmpresa[])
{
    printf("\n  EMPRESA: %s",nombreEmpresa);
    int t=6;
    Cliente_Proveedor cpActual;
    gotoxy(2,3);
    printf("|NOMBRE");
    gotoxy(20,3);
    printf("|CUIT CLIENTE/PROV");
    gotoxy(33,3);
    printf("|CP");
    gotoxy(0,4);
    printf("\n----------------------------------------------------------------------------------------------------------------------\n");

    while(lista)
    {
        cpActual = lista->dato_cp;
        gotoxy(2,t);
        printf("| %s",cpActual.nombre );
        gotoxy(20,t);
        printf("| %s",cpActual.cuit_cliente_proveedor);
        gotoxy(33,t);
        if(cpActual.cp == 'c'||cpActual.cp =='C')
            printf("| CLIENTE");
        else
            printf("| PROVEEDOR");
        t++;

        lista = lista->sig;
    }
    printf("\n----------------------------------------------------------------------------------------------------------------------\n");
}
