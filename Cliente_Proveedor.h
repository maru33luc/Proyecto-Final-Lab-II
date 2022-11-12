#ifndef CLIENTE_PROVEEDOR_H_INCLUDED
#define CLIENTE_PROVEEDOR_H_INCLUDED



typedef struct Cliente_Proveedor
{
  char nombre[50];
  char cuit_cliente_proveedor[12];
  char cp;
}Cliente_Proveedor;

Cliente_Proveedor crearCP(char nombre[],char cuit_cp[],char cp);
void mostrarUnCP(Cliente_Proveedor dato);
Cliente_Proveedor pasarDatosRegistroAUnClienteProveedor(Registro_Factura a);
Registro_Factura pasarDatosNodoClienteProveedorARegistro(Cliente_Proveedor a);


#endif // CLIENTE_PROVEEDOR_H_INCLUDED
