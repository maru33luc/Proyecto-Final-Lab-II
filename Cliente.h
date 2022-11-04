#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED



typedef struct Cliente_Proveedor
{
  char nombre[50];
  char cuit_cliente_proveedor[12];
  char cp;
}Cliente_Proveedor;

typedef struct nodoSimpleCliente{
Cliente_Proveedor dato_cliente;
struct nodoDobleFactura* fact;
struct nodoSimpleProveedor* sig;
}nodoSimpleCliente;


/*
void persistirFacturasCompras(char nombreArchivoCompras[]) ;
int verificarPresenciaFacturaBase (char nombreArchFactura[],char comprobante[]) ;
void mostrarArchivoCompras (char nombreArchCompras[]) ;
*/


#endif // CLIENTE_H_INCLUDED
