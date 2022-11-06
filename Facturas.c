#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Empresa.h"
#include "Facturas.h"
#include "Resumenes.h"
#include "NodoSimpleEmpresa.h"
#include "NodoDobleFactura.h"
#include "Cliente_Proveedor.h"
#include "NodoSimpleCP.h"




///Hice estos mockeos(Funciones falsas) que son las dos funciones que estan abajo para que compile, que es necesario rearmarlas con los datos nuevos de factura.
/// El tipo de carga manual de facturas no es necesaria, solo necesitamos una funcion de "Factura crearFacturas(numComprobante,cuit cliente_proveedor, etc...)" que retorne una nueva factura.
/*
Factura cargarUnaFactura(Factura a)
{
    Factura FacturaFalsa;

    return  FacturaFalsa;
}

void mostrarUnaFactura(Factura a)
{
    printf("Mostrando una factura...\n");
}
*/
Registro_Factura cargarUnRegistroFactura (char nombreEmp[],char cuitEmp[],int activaEmp,char tipo,char comprobante[],char puntoVenta[],char numComprob[],int idInterno,Fecha fecha,char descripcion[],float neto,float iva,float total,int activaFact,char nombreCliProv[],char cp,char cuitCliProv[])
{
    Registro_Factura a;

    strcpy(a.nombreEmpresa,nombreEmp);
    strcpy(a.cuit,cuitEmp);
    a.activa_emp=activaEmp;
    a.tipo=tipo;
    strcpy(a.comprobante,comprobante);
    strcpy(a.punto_venta,puntoVenta);
    strcpy(a.nro_comprobante,numComprob);
    a.id_interno_factura=idInterno;
    a.fecha=fecha;
    strcpy(a.descripcion,descripcion);
    a.neto=neto;
    a.iva=iva;
    a.total=total;
    a.activa_fact=activaFact;
    strcpy(a.nombre_cliente_proveedor,nombreCliProv);
    a.cp=cp;
    strcpy(a.cuit_cliente_proveedor,cuitCliProv);

    return a;

}

void mostrarUnRegistroFactura (Registro_Factura a)
{
    printf("\n------------------------------------------------------\n");
    printf("\nNombre de la Empresa: %s\n",a.nombreEmpresa);
    printf("\nCUIT de la Empresa: %s\n",a.cuit);
    printf("\nEstado de la Empresa (activa=0,inactiva=1: %d\n",a.activa_emp);
    printf("\nNombre del cliente/proveedor: %s\n",a.nombre_cliente_proveedor);
    printf("\nCUIT del cliente/proveedor: %s\n",a.cuit_cliente_proveedor);
    printf("\nCliente/ Proveedor (c/p) : %c\n",a.cp);
    printf("\nTipo de comprobante: %s\n",a.comprobante);
    printf("\nNumero de comprobante: %s\n",a.nro_comprobante);
    printf("\nPunto de venta: %s\n",a.punto_venta);
    printf("\nTipo de comprobante a/b/c: %c\n",a.tipo);
    printf("\nId de la Factura: %d\n",a.id_interno_factura);
    printf("\nFecha de contabilizacion: %d/%d/%d\n",a.fecha.dia,a.fecha.mes,a.fecha.anio);
    printf("\nDescripcion de la Factura: %s\n",a.descripcion);
    printf("\nValor neto: %.2f\n",a.neto);
    printf("\nValor de IVA: %.2f\n",a.iva);
    printf("\nValor total: %.2f\n",a.total);
    printf("\nEstado de la Factura: activa (1) o inactiva (0): %d\n",a.activa_fact);
    printf("\n------------------------------------------------------\n");

}

//void persistirRegistrosFactura (char nombreArch[])





Factura cargarUnaFactura (char cuitCliProv[],char comprobante[],char numComprob[],char puntoVenta[],char tipo,int idInterno,Fecha fecha,char descripcion[],float neto,float iva,float total,int activaFact)
{
Factura a;

    strcpy(a.cuit_cliente_proveedor,cuitCliProv);
    strcpy(a.comprobante,comprobante);
    strcpy(a.numComprobante,numComprob);
    strcpy(a.puntoVenta,puntoVenta);
    a.tipo=tipo;
    a.id_interno=idInterno;
    a.fecha=fecha;
    strcpy(a.descripcion,descripcion);
    a.neto=neto;
    a.iva=iva;
    a.total=total;
    a.activa=activaFact;

    return a;
}

void mostrarUnaFactura (Factura a)
{
    printf("\n------------------------------------------------------\n");
    printf("\nCUIT del cliente/proveedor: %s\n",a.cuit_cliente_proveedor);
    printf("\nTipo de comprobante: %s\n",a.comprobante);
    printf("\nNumero de comprobante: %s\n",a.numComprobante);
    printf("\nPunto de venta: %s\n",a.puntoVenta);
    printf("\nTipo de comprobante a/b/c: %c\n",a.tipo);
    printf("\nId de la Factura: %d\n",a.id_interno);
    printf("\nFecha de contabilizacion: %d/%d/%d\n",a.fecha.dia,a.fecha.mes,a.fecha.anio);
    printf("\nDescripcion de la Factura: %s\n",a.descripcion);
    printf("\nValor neto: %.2f\n",a.neto);
    printf("\nValor de IVA: %.2f\n",a.iva);
    printf("\nValor total: %.2f\n",a.total);
    printf("\nEstado de la Factura: activa (1) o inactiva (0): %d\n",a.activa);
    printf("\n------------------------------------------------------\n");
}



