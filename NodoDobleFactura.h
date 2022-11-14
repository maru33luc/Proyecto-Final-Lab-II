#ifndef NODODOBLEFACTURA_H_INCLUDED
#define NODODOBLEFACTURA_H_INCLUDED

#include "NodoSimpleEmpresa.h"
#include "NodoSimpleCP.h"

typedef struct Fecha
{
    int dia;
    int mes;
    int anio;
}Fecha;


typedef struct Registro_Factura{
char nombreEmpresa[50];
char cuit[12];
int activa_emp;

char tipo;// A B o C
char comprobante[30]; // Factura, Recibo, Nota Credito
char punto_venta[5]; //Número de 5cifras rellenado con 0 al principio
char nro_comprobante[10];
int id_interno_factura; //Autoincremental , posicion
Fecha fecha;
char descripcion[100];
float neto;
float iva;
float total;
int activa_fact; //Baja lógica

char nombre_cliente_proveedor[50];
char cp; //Cliente o proveedor
char cuit_cliente_proveedor[12];

}Registro_Factura;


typedef struct Factura
{
    //char cuit_cliente_proveedor[12];
    char comprobante[30];
    char tipo;
    char puntoVenta[5];
    char numComprobante[8];
    Fecha fecha;
   char descripcion[100];
    float neto;
    float iva;
    float total;
    int activa; // 0 inactiva 1 activa
   int id_interno;
} Factura;


typedef struct  nodoDobleFactura{
Factura dato;
struct nodoDobleFactura* sig;
struct nodoDobleFactura* ante;
}nodoDobleFactura;


int validarLetras (char Nombre[]);
int validarNumString (char Nombre[]);
int validarFecha (Fecha dato);

Registro_Factura cargarUnRegistroFactura (Registro_Factura a, nodoSimpleEmpresa *lista);
nodoSimpleEmpresa *persistirRegistrosFactura (char nombreArch[],nodoSimpleEmpresa *lista);
/*Registro_Factura cargarUnRegistroFactura (char nombreEmp[],char cuitEmp[],int activaEmp,char tipo,char comprobante[],char puntoVenta[],char numComprob[],int idInterno,Fecha fecha,char descripcion[],float neto,float iva,float total,int activaFact,char nombreCliProv[],char cp,char cuitCliProv[]);*/
void mostrarUnRegistroFactura (Registro_Factura a);
//void persistirRegistrosFactura (char nombreArch[],Registro_Factura a);
Factura cargarUnaFactura (char cuitCliProv[],char comprobante[],char numComprob[],char puntoVenta[],char tipo,int idInterno,Fecha fecha,char descripcion[],float neto,float iva,float total,int activaFact);
void mostrarUnaFactura (Factura a);
Factura pasarDatosRegistroAUnaFactura(Registro_Factura a);
void mostrarArchivoRegistros (char nombreArch[]);

Empresa pasarDatosRegistroAUnaEmpresa(Registro_Factura a);
Registro_Factura pasarDatosNodoFacturaAUnRegistro(Factura a);
Registro_Factura pasarDatosNodoEmpresaAUnRegistro(Empresa a);

//Factura cargarUnaFactura (Factura a);
//void mostrarUnaFactura (Factura a);

Cliente_Proveedor pasarDatosRegistroAUnClienteProveedor(Registro_Factura a);
Registro_Factura pasarDatosNodoClienteProveedorARegistro(Cliente_Proveedor a);
Fecha crearFecha (int dia, int mes, int anio);


///------------------ LIBRERIA DE LISTA DOBLE FACTURAS----------------------------------------------------


nodoDobleFactura *inicListaDoble ();
nodoDobleFactura *crearNodoDoble (Factura a);
nodoDobleFactura *agregarAlPrincipioDoble (nodoDobleFactura *lista,nodoDobleFactura *nuevo);
nodoDobleFactura *buscarUltimoDoble (nodoDobleFactura *lista);
nodoDobleFactura *agregarAlFinalDoble (nodoDobleFactura *lista,nodoDobleFactura *nuevo);
void mostrarListaDoble (nodoDobleFactura *lista);
nodoDobleFactura *borrarnodoDobleFacturaXNumComprobante (nodoDobleFactura *lista,char numComprob []);
nodoDobleFactura *insertarOrdenadoDobleXNumComprob (nodoDobleFactura *lista,nodoDobleFactura *nuevo);
nodoDobleFactura *buscarFacturaDobleXNumComprob (nodoDobleFactura *lista,char numComprob[]);

int retornarSiFecha1EsMayor (Fecha dato1, Fecha dato2);
int retornarSiFecha1EsMenor (Fecha dato1, Fecha dato2);
nodoDobleFactura *insertarOrdenadoDobleXFecha (nodoDobleFactura *lista,nodoDobleFactura *nuevo);

///---------------TDA COMPUESTA ---------------------------------------------------------

nodoSimpleEmpresa *altaFacturas(nodoSimpleEmpresa *lista,Registro_Factura dato);
nodoDobleFactura* buscarFacturaenTDA(nodoSimpleEmpresa*lista,char nombre_empresa[],char cp,char cuit_cp[],char nro_comprobante[],char punto_venta[]);

#endif // NODODOBLEFACTURA_H_INCLUDED
