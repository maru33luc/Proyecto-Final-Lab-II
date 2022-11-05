#ifndef FACTURAS_H_INCLUDED
#define FACTURAS_H_INCLUDED

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
    char cuit_cliente_proveedor[12];
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





Factura cargarUnaFactura (Factura a);
void mostrarUnaFactura (Factura a);




//void mostrarArchivoVentas (char nombreArchVentas[]);



#endif // FACTURAS_H_INCLUDED
