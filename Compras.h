#ifndef COMPRAS_H_INCLUDED
#define COMPRAS_H_INCLUDED

typedef struct Fecha
{
    int dia;
    int mes;
    int anio;
}Fecha;


typedef struct Factura
{
    char cliente_proveedor[50];
    char cuit_cliente_proveedor[20];
    char comprobante[30];
    char tipo;
    char puntoVenta[5];
    char numComprobante[8];
    int idFactura;
    Fecha datoFecha;
    char descripcion[100];
    float neto;
    float iva;
    float total;
    int activa; // 0 inactiva 1 activa
    int id_empresa;
} Factura;

typedef struct Cliente_Proveedor
{
  char nombre[50];
  char cuit_cliente_proveedor[20];
  char mail[50];
  char telefono[12];
  char direccion[50];
}Cliente_Proveedor;


/*
void persistirFacturasCompras(char nombreArchivoCompras[]) ;
int verificarPresenciaFacturaBase (char nombreArchFactura[],char comprobante[]) ;
void mostrarArchivoCompras (char nombreArchCompras[]) ;
*/

#endif // COMPRAS_H_INCLUDED
