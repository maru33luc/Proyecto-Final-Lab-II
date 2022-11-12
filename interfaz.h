#ifndef INTERFAZ_H_INCLUDED
#define INTERFAZ_H_INCLUDED


typedef struct NodoPalabra
{
    char palabra[50];
    struct NodoPalabra* siguiente;
    struct NodoPalabra* anterior;
}NodoPalabra;

typedef struct Fecha
{
  int dia;
  int mes;
  int anio;
}Fecha;

typedef struct FechaChar
{
    char dia [4];
    char mes [4];
    char anio [6];
}FechaChar;

typedef struct Empresa//Para revisar
{
    int id;
    char nombre[50];
    char cuit[10];
    char codIVA[2];//CF RI MT EX
} Empresa;

typedef struct OtrosImpuestos
{
    float oi1;
    float oi2;
    float oi3;
    float oi4;
} OtrosImpuestos;

typedef struct Netos
{
  // Alicuotas
    float _0;//0%
    float _588;//5,88%
    float _105; //10,5%
    float _210; //21%
    float _270; //27%
} Netos;

typedef struct Ivas
{
    float iva_21;
    float iva_105;
    float iva_27;
    float iva_588;
}Ivas;


typedef struct Factura
{
    char cliente_proveedor[50];
	char cuit_cliente_proveedor[20];  /// CHICOS PARA PODER TENER UN ID UNICO PARA RELACIONAR CON LA STRUCT CLIENTE_PROVEEDOR 
    char comprobante[30];
    char tipo;
    char puntoVenta[6];
    char numComprobante[10];
    int idFactura;
    FechaChar fecha_emision;
    FechaChar fecha_contabilizacion;
    char descripcion[100];
    Netos neto;
    Ivas iva;
    OtrosImpuestos otrosImpuestos;
    float noGravado;
    float exento;
    float p_iibb;
    float p_iva;
    float netoGravadoTotal;
    float ivaTotal;
    float total;
    int activa; // 0 inactiva 1 activa
    int id_empresa;
} Factura;


void VentanaFacturaCompra();
void Fullscreen();
int SetPosicionCursor(int* tecla, int* posicionCursor);
void TABSetPosicionCursor(int* posicionCursor);
void ENTERSetPosicionCursor(int* posicionCursor);
void FlechaAbajoSetPosicionCursor(int* posicionCursor);
void FlechaArribaSetPosicionCursor(int* posicionCursor);
void IniciarListaPalabras(NodoPalabra** listaPalabras);
NodoPalabra* CrearNodoPalabra(char palabra[]);
void AgregarNodoPalabraAlfabeticamente(NodoPalabra** listaPalabras, char palabra[]);
void MostrarLista(NodoPalabra* listaPalabras);
void GetStringPredictivo(char string[], int dimension, int* tecla, int x, int y, int color, NodoPalabra* listaPalabras);
void AutoCompletarpredictivo(char string[], int dimension, int x, int y, int color, int i, NodoPalabra** listaPalabras);
void AltaFecha(int* tecla);
int FechaValida(int dia, int mes, int anio);
void AltaFechaChar(FechaChar* fecha, int* tecla, int x, int y, int* salir);
void GetFechaChar(char string[], int dimension, int* tecla, int x, int y, int color);
void AltaTipoNumeroFactura(char* tipo, char ptoVenta[], int* tecla, int x, int y);
void AltaNumeroFactura(char numeroFactura[], int* tecla, int x, int y);
void AltaFacturaCompra(int* posicionCursor, int* tecla, NodoPalabra* listaPalabras);
void AltaFloats(float* numeroFloat, int* tecla, int x, int y);
void BorrarVentanaAuxiliar();
void MenuPrincipal(int* tecla, int* posicionCursor);
#endif