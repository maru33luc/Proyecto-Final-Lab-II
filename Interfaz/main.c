//cd desktop/vs projects/tp 2.1
//gcc -o tp2test main.c libreria.c

#include "libreria.h"


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

typedef struct Empresa
{
    char nombre[50];
    char cuit[12];
    int activa_emp;
} Empresa;

typedef struct NodoEmpresa
{
    Empresa empresa;
    struct NodoEmpresa* siguiente;
    struct NodoEmpresa* anterior;
}NodoEmpresa;

typedef struct Cliente_Proveedor
{
    char nombre[50];
    char cuit_cliente_proveedor[12];
    char cp;
}Cliente_Proveedor;

typedef struct Factura
{
    char cliente_proveedor[50];
	char cuit_cliente_proveedor[20];  
    char comprobante[30];
    char tipo;
    char puntoVenta[6];
    char numComprobante[10];
    int idFactura;
    FechaChar fecha_emision;
    FechaChar fecha_contabilizacion;
    char descripcion[100];
    float neto;
    float iva;
    float total;
    int activa; 
    int id_empresa;
} Factura;

typedef struct Registro_Factura{
char nombreEmpresa[50];
char cuit[12];
int activa_emp;

char tipo;
char comprobante[30]; 
char punto_venta[5]; 
char nro_comprobante[10];
int id_interno_factura; 
FechaChar fecha_emision;
FechaChar fecha_contabilizacion;
char descripcion[100];
float neto;
float iva;
float total;
int activa_fact; 

char nombre_cliente_proveedor[50];
char cp; 
char cuit_cliente_proveedor[12];

}Registro_Factura;

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
void MenuPrincipal(int* tecla);
int MenuEmpresas(int* tecla);
void MenuFacturas(int* tecla);
Empresa AgregarEmpresa(int* tecla, NodoPalabra* listaEmpresas);
void PersistirUnaEmpresaEnArchivo (char nombreArchEmpresas[], Empresa a);
NodoPalabra* PasarEmpresasDelArchivoAListaSimple (char nombreArchEmpresas[]);
NodoPalabra* PasarCuitDelArchivoAListaSimple (char nombreArchEmpresas[]);
void MenuListarEmpresas(int* tecla);
void IniciarListaEmpresa(NodoEmpresa** listaEmpresas);
NodoEmpresa* CrearNodoEmpresa(Empresa empresa);
void AgregarNodoEmpresaAlfabeticamente(NodoEmpresa** listaEmpresas, Empresa empresa);
void DarDeBajaEmpresa(int* tecla, NodoPalabra* listaNombresEmpresas, NodoEmpresa* listaEmpresas);
int buscarUnaEmpresaXCuitEnArchivoYRetornaPosicionRegistro(char nombreArchEmpresas[],char cuit[]);
NodoEmpresa* PasarEmpresasFullDelArchivoAListaSimple (char nombreArchEmpresas[]);
void PrintearTodasLasEmpresas(int* tecla, NodoEmpresa* listaEmpresas);
void MostrarUnaEmpresa(int* tecla, NodoEmpresa* listaEmpresas, NodoPalabra* listaNombresEmpresas);
void CargarFactura(int* tecla, NodoPalabra* listaNombresEmpresas);
void AltaFactura(int* posicionCursor, int* tecla, NodoPalabra* listaPalabras, Registro_Factura* aux);
VOID WINAPI SetConsoleColors(WORD attribs);

void main()
{

    /*Fullscreen();

    char palabra[30] = {0};
    Sleep(100);


    VentanaFacturaCompra();
    
    GetString(palabra, 30, 39, 8, 240);
    int tecla = 0;
    int posicionCrusor = 0;
    while(tecla != 27)
    {
        tecla = getch();
        printf("%d\n", tecla);
        SetPosicionCursor(&tecla, &posicionCrusor);

    }*/
    
    //SetConsoleColors(BACKGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);

    NodoPalabra* listaPalabras;

    IniciarListaPalabras(&listaPalabras);

    AgregarNodoPalabraAlfabeticamente(&listaPalabras, "juan");
    AgregarNodoPalabraAlfabeticamente(&listaPalabras, "eduardo");
    AgregarNodoPalabraAlfabeticamente(&listaPalabras, "alberto");
    AgregarNodoPalabraAlfabeticamente(&listaPalabras, "enzo");
    AgregarNodoPalabraAlfabeticamente(&listaPalabras, "marina");
    AgregarNodoPalabraAlfabeticamente(&listaPalabras, "chapu");
    AgregarNodoPalabraAlfabeticamente(&listaPalabras, "sinomatamonomatamo");
    AgregarNodoPalabraAlfabeticamente(&listaPalabras, "abigail");
    AgregarNodoPalabraAlfabeticamente(&listaPalabras, "albertario");
    AgregarNodoPalabraAlfabeticamente(&listaPalabras, "juani");
    AgregarNodoPalabraAlfabeticamente(&listaPalabras, "TRES65");


    /*int tecla = 0;
    char palabraTest[50] = {0};
    GetStringPredictivo(palabraTest, 50, &tecla, 0, 0, 15, listaPalabras);
    system("pause");*/
    
    
    /*int tecla = 0;
    Factura factura;
    FechaChar* p_fecha = &factura.fecha_emision;
    AltaFechaChar(&factura.fecha_emision, &tecla, 0, 0);
    printf("\n%s/%s/%s\n", factura.fecha_emision.dia, factura.fecha_emision.mes, factura.fecha_emision.anio);*/
    
    /*int tecla = 0;
    Factura factura;
    AltaTipoNumeroFactura(factura.tipo, factura.puntoVenta, &tecla, 0, 0);*/

    /*int tecla = 0;
    Factura factura;
    AltaNumeroFactura(factura.numComprobante, &tecla, 0, 0);*/

    
    int tecla = 0;
    Fullscreen();
    Sleep(200);
    //AltaFacturaCompra(&posicionCursor, &tecla, listaPalabras);

    MenuPrincipal(&tecla); 

    system("pause");

    
}

VOID WINAPI SetConsoleColors(WORD attribs) {
    HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_SCREEN_BUFFER_INFOEX cbi;
    cbi.cbSize = sizeof(CONSOLE_SCREEN_BUFFER_INFOEX);
    GetConsoleScreenBufferInfoEx(hOutput, &cbi);
    cbi.wAttributes = attribs;
    SetConsoleScreenBufferInfoEx(hOutput, &cbi);
}

void IniciarListaPalabras(NodoPalabra** listaPalabras)
{
    *listaPalabras = NULL;
}

NodoPalabra* CrearNodoPalabra(char palabra[])
{
    NodoPalabra* aux = malloc(sizeof(NodoPalabra));
    strcpy(aux->palabra, palabra);
    aux->siguiente = NULL;
    aux->anterior = NULL;

    return aux;
}

void AgregarNodoPalabraAlfabeticamente(NodoPalabra** listaPalabras, char palabra[])
{
    NodoPalabra* nuevoNodo = CrearNodoPalabra(palabra);

    if((*listaPalabras) == NULL)
    {
        (*listaPalabras) = nuevoNodo;
       
    }
    else 
    {
        if(strcmpi((*listaPalabras)->palabra, palabra) > 0)
        {
            nuevoNodo->siguiente = (*listaPalabras);
            (*listaPalabras)->anterior = nuevoNodo;
            (*listaPalabras) = nuevoNodo;
            
        }
        else
        {
            NodoPalabra* seg = (*listaPalabras)->siguiente;
            NodoPalabra* ant = (*listaPalabras);

            while(seg != NULL && strcmpi(seg->palabra, palabra) < 0)
            {
                
                ant = seg;
                seg = seg->siguiente;
                
                
            }
            if(seg != NULL)
            {
                ant->siguiente = nuevoNodo;
                nuevoNodo->anterior = ant;
                nuevoNodo->siguiente = seg;
                seg->anterior = nuevoNodo;
            }
            else
            {
                ant->siguiente = nuevoNodo;
                nuevoNodo->anterior = ant;
                
                
            }

            

        }
        
    }
    
}

void MostrarLista(NodoPalabra* listaPalabras)
{
    while(listaPalabras != NULL)
    {
        printf("%s\n", listaPalabras->palabra);
        listaPalabras = listaPalabras->siguiente;
    }
}

void Fullscreen()
{
    INPUT ip;
    ip.type = INPUT_KEYBOARD;
    ip.ki.wScan = 0;
    ip.ki.time = 0;
    ip.ki.dwExtraInfo = 0;
    //Aprieta tecla windows izquierda
    ip.ki.wVk = VK_LWIN;
    ip.ki.dwFlags = 0; 
    SendInput(1, &ip, sizeof(INPUT));

    //Aprieta tecla flechita arriba
    ip.ki.wVk = VK_UP;
    ip.ki.dwFlags = 0; 
    SendInput(1, &ip, sizeof(INPUT));


    //Suelta tecla windows izquierda
    ip.ki.wVk = VK_LWIN;
    ip.ki.dwFlags = KEYEVENTF_KEYUP; 
    SendInput(1, &ip, sizeof(INPUT));

    //Suelta tecla flechita arriba
    ip.ki.wVk = VK_UP;
    ip.ki.dwFlags = KEYEVENTF_KEYUP; 
    SendInput(1, &ip, sizeof(INPUT));
}

void VentanaFacturaCompra()
{
    //MARCO
    
    
    PrintSolidSquare(121, 1, 25, 5);
    
    PrintString(80, 5, "COMPRAS", 160);
    
    
    PrintSquare(120, 35, 25, 6, 10);
    
    //PRIMER RENGLON
    PrintSquare(12, 2, 27, 7, 10);
    PrintString(28, 8, "COMPROBANTE", 10);
    PrintString(42, 8, "FACTURA", 15);

    PrintSquare(10, 2, 54, 7, 10);
    PrintString(55, 8, "PROVEEDOR", 10);
    PrintSquare(50, 2, 65, 7, 15);

    //PrintSquare(6, 2, 118, 7, 10);
    PrintString(118, 8, "FECHA", 10);
    PrintSquare(15, 2, 125, 7, 15);
    PrintString(126, 8, "    /  /     ", 15);

    //SEGUNDO RENGLON
    PrintString(28, 11, "Tipo-P.Vta", 10);
    PrintSquare(8, 2, 38, 10, 15);
    PrintString(40, 11, "-", 10);
    PrintString(47, 11, "N-", 10);
    PrintSquare(10, 2, 49, 10, 15);
    PrintString(60, 11, "Descripcion", 10);
    PrintSquare(44, 2, 71, 10, 15);
    PrintString(118, 11, "CONT.", 10);
    PrintSquare(15, 2, 125, 10, 15);
    PrintString(126, 11, "    /  /      ", 15);

    //TERCER RENGLON
    PrintSquare(70, 6, 50, 14, 10);


    //PARTE DE NUMEROS
    PrintString(28, 23, "NETOS  21%", 10);
    PrintSquare(20, 2, 38, 22, 15);
    PrintString(60, 23, "10.5%", 10);
    PrintSquare(20, 2, 65, 22, 15);
    PrintString(87, 23, "27%", 10);
    PrintSquare(20, 2, 90, 22, 15);
    PrintString(113, 23, "5.88%", 10);
    PrintSquare(20, 2, 118, 22, 15);


    PrintString(28, 26, "IVA    21%", 10);
    PrintSquare(20, 2, 38, 25, 15);
    PrintString(60, 26, "10.5%", 10);
    PrintSquare(20, 2, 65, 25, 15);
    PrintString(87, 26, "27%", 10);
    PrintSquare(20, 2, 90, 25, 15);
    PrintString(113, 26, "5.88%", 10);
    PrintSquare(20, 2, 118, 25, 15);


    PrintString(28, 29, "NO GRAVADO", 10);
    PrintSquare(20, 2, 38, 28, 15);
    PrintString(60, 29, "EXEN.", 10);
    PrintSquare(20, 2, 65, 28, 15);
    PrintString(86, 29, "P.IB", 10);
    PrintSquare(20, 2, 90, 28, 15);
    PrintString(112, 29, "P.IVA", 10);
    PrintSquare(20, 2, 118, 28, 15);



    PrintString(28, 32, "OTROS IMP.", 10);
    PrintSquare(20, 2, 38, 31, 15);
    PrintString(60, 32, "     ", 10);
    PrintSquare(20, 2, 65, 31, 15);
    PrintString(86, 32, "    ", 10);
    PrintSquare(20, 2, 90, 31, 15);
    PrintString(112, 32, "     ", 10);
    PrintSquare(20, 2, 118, 31, 15);


    PrintString(28, 35, "NETO GRAVADO TOTAL", 10);
    PrintSquare(27, 2, 48, 34, 15);
    PrintString(81, 35, "IMP.VAL.AGR. TOTAL", 10);
    PrintSquare(27, 2, 101, 34, 15);

    PrintString(62, 39, "TOTAL FACTURA", 160);
    //PrintSquare(16, 2, 60, 38, 10);
    PrintSquare(30, 2, 80, 38, 10);

}

#define P_SELECCIONAR_COMPROBANTE -1
#define P_COMPROBANTE 0
#define P_PROVEEDOR 1
#define P_FECHA_EMISION 2
#define P_TIPO_PVENTA 3
#define P_NUMERO_FACTURA 4
#define P_DESCRIPCION 5
#define P_FECHA_CONT 6
#define P_NETO_21 7
#define P_NETO_105 8
#define P_NETO_27 9
#define P_NETO_588 10
#define P_NO_GRAVADO 11
#define P_EXENTO 12
#define P_PERCEPCION_IIBB 13
#define P_PERCEPCION_IVA 14
#define P_OTROS_IMPUESTOS_1 15
#define P_OTROS_IMPUESTOS_2 16
#define P_OTROS_IMPUESTOS_3 17
#define P_OTROS_IMPUESTOS_4 18
#define P_CONFIRMNAR_FACTURA 19



int SetPosicionCursor(int* tecla, int* posicionCursor)
{
    if(*tecla == 9)//TAB
    {
        TABSetPosicionCursor(posicionCursor);
    }
    else if(*tecla == 224)
    {
        *tecla = getch();
        if(*tecla == 80)//FECHITA ABAJO
        {
           FlechaAbajoSetPosicionCursor(posicionCursor); 
        }
        else if(*tecla == 72)//FLECHITA ARRIBA
        {
            FlechaArribaSetPosicionCursor(posicionCursor);   
        }
        else if(*tecla == 77)//FLECHITA DERECHA
        {
            if(*posicionCursor >= 0 && *posicionCursor < 19)
            {
                *posicionCursor = *posicionCursor + 1;
            }
            
        }
        else if(*tecla == 75)//FLECHITA IZQUIERDA
        {
            if(*posicionCursor > 0 && *posicionCursor <= 19)
            {
                *posicionCursor = *posicionCursor -1;  
            }
        }
          
    }
    else if(*tecla == 13)
    {
        ENTERSetPosicionCursor(posicionCursor);
    }
    
}

void TABSetPosicionCursor(int* posicionCursor)
{
    if(*posicionCursor == P_COMPROBANTE)
    {
        *posicionCursor = P_PROVEEDOR;
    }
    else if(*posicionCursor == P_PROVEEDOR)
    {
        *posicionCursor = P_FECHA_EMISION;
    }
    else if(*posicionCursor == P_FECHA_EMISION)
    {
        *posicionCursor = P_FECHA_CONT;
    }
    else if(*posicionCursor == P_FECHA_CONT)
    {
        *posicionCursor = P_TIPO_PVENTA;
    }
    else if(*posicionCursor == P_TIPO_PVENTA)
    {
        *posicionCursor = P_NUMERO_FACTURA;
    }
    else if(*posicionCursor == P_NUMERO_FACTURA)
    {
        *posicionCursor = P_NETO_21;
    }
    else if(*posicionCursor == P_NETO_21)
    {
        *posicionCursor = P_NO_GRAVADO;
    }
    else if(*posicionCursor == P_NO_GRAVADO)
    {
        *posicionCursor = P_CONFIRMNAR_FACTURA;
    }
}

void ENTERSetPosicionCursor(int* posicionCursor)
{
    if(*posicionCursor == P_COMPROBANTE)
    {
        *posicionCursor = P_SELECCIONAR_COMPROBANTE;
    }
    else if(*posicionCursor == P_PROVEEDOR)
    {
        *posicionCursor = P_FECHA_EMISION;
    }
    else if(*posicionCursor == P_FECHA_EMISION)
    {
        *posicionCursor = P_FECHA_CONT;
    }
    else if(*posicionCursor == P_FECHA_CONT)
    {
        *posicionCursor = P_TIPO_PVENTA;
    }
    else if(*posicionCursor == P_TIPO_PVENTA)
    {
        *posicionCursor = P_NUMERO_FACTURA;
    }
    else if(*posicionCursor == P_NUMERO_FACTURA)
    {
        *posicionCursor = P_NETO_21;
    }
    else if(*posicionCursor == P_NETO_21)
    {
        *posicionCursor = P_NO_GRAVADO;
    }
    else if(*posicionCursor == P_NO_GRAVADO)
    {
        *posicionCursor = P_CONFIRMNAR_FACTURA;
    }
    else if(*posicionCursor == P_CONFIRMNAR_FACTURA)
    {
        *posicionCursor = P_PROVEEDOR;
    }
    else if(*posicionCursor == P_SELECCIONAR_COMPROBANTE)
    {
        *posicionCursor = P_PROVEEDOR;
    }    
}

void FlechaAbajoSetPosicionCursor(int* posicionCursor)
{
    if(*posicionCursor == P_COMPROBANTE)
    {
        *posicionCursor = P_TIPO_PVENTA;
    }
    else if(*posicionCursor == P_PROVEEDOR)
    {
        *posicionCursor = P_DESCRIPCION;
    }    
    else if(*posicionCursor == P_FECHA_EMISION)
    {
        *posicionCursor = P_FECHA_CONT;
    }
    else if(*posicionCursor == P_FECHA_CONT)
    {
        *posicionCursor = P_NETO_588;
    }
    else if(*posicionCursor == P_TIPO_PVENTA)
    {
        *posicionCursor = P_NETO_21;
    }
    else if(*posicionCursor == P_NUMERO_FACTURA)
    {
        *posicionCursor = P_NETO_21;
    }
    else if(*posicionCursor == P_DESCRIPCION)
    {
        *posicionCursor = P_NETO_105;
    }
    else if(*posicionCursor == P_NETO_21)
    {
        *posicionCursor = P_NO_GRAVADO;
    }
    else if(*posicionCursor == P_NETO_105)
    {
        *posicionCursor = P_EXENTO;
    }
    else if(*posicionCursor == P_NETO_27)
    {
        *posicionCursor = P_PERCEPCION_IIBB;
    }
    else if(*posicionCursor == P_NETO_588)
    {
        *posicionCursor = P_PERCEPCION_IVA;
    }
    else if(*posicionCursor == P_NO_GRAVADO)
    {
        *posicionCursor = P_OTROS_IMPUESTOS_1;
    }
    else if(*posicionCursor == P_EXENTO)
    {
        *posicionCursor = P_OTROS_IMPUESTOS_2;
    }
    else if(*posicionCursor == P_PERCEPCION_IIBB)
    {
        *posicionCursor = P_OTROS_IMPUESTOS_3;
    }
    else if(*posicionCursor == P_PERCEPCION_IVA)
    {
        *posicionCursor = P_OTROS_IMPUESTOS_4;
    }
    else if(*posicionCursor == P_OTROS_IMPUESTOS_1 || *posicionCursor == P_OTROS_IMPUESTOS_2 || *posicionCursor == P_OTROS_IMPUESTOS_3 || *posicionCursor == P_OTROS_IMPUESTOS_4)
    {
        *posicionCursor = P_CONFIRMNAR_FACTURA;
    }
}

void FlechaArribaSetPosicionCursor(int* posicionCursor)
{
    if(*posicionCursor == P_FECHA_CONT)
    {
        *posicionCursor = P_FECHA_EMISION;
    }
    else if(*posicionCursor == P_TIPO_PVENTA)
    {
        *posicionCursor = P_COMPROBANTE;
    }
    else if(*posicionCursor == P_NUMERO_FACTURA)
    {
        *posicionCursor = P_PROVEEDOR;
    }
    else if(*posicionCursor == P_DESCRIPCION)
    {
        *posicionCursor = P_PROVEEDOR;
    }
    else if(*posicionCursor == P_NETO_21)
    {
        *posicionCursor = P_TIPO_PVENTA;
    }
    else if(*posicionCursor == P_NETO_105)
    {
        *posicionCursor = P_DESCRIPCION;
    }
    else if(*posicionCursor == P_NETO_27)
    {
        *posicionCursor = P_DESCRIPCION;
    }
    else if(*posicionCursor == P_NETO_588)
    {
        *posicionCursor = P_FECHA_CONT;
    }
    else if(*posicionCursor == P_NO_GRAVADO)
    {
        *posicionCursor = P_NETO_21;
    }
    else if(*posicionCursor == P_EXENTO)
    {
        *posicionCursor = P_NETO_105;
    }
    else if(*posicionCursor == P_PERCEPCION_IIBB)
    {
        *posicionCursor = P_NETO_27;
    }
    else if(*posicionCursor == P_PERCEPCION_IVA)
    {
        *posicionCursor = P_NETO_588;
    }
    else if(*posicionCursor == P_OTROS_IMPUESTOS_1)
    {
        *posicionCursor = P_NO_GRAVADO;
    }
    else if(*posicionCursor == P_OTROS_IMPUESTOS_2)
    {
        *posicionCursor = P_EXENTO;
    }
    else if(*posicionCursor == P_OTROS_IMPUESTOS_3)
    {
        *posicionCursor = P_PERCEPCION_IIBB;
    }
    else if(*posicionCursor == P_OTROS_IMPUESTOS_4)
    {
        *posicionCursor = P_PERCEPCION_IVA;
    }
}

/*void AltaFacturaCompra(int* posicionCursor, int* tecla, NodoPalabra* listaNombreClientes_Proveedores, Registro_Factura* aux)
{
    

    aux.neto._0 = 0; aux.neto._105 = 0; aux.neto._210 = 0; aux.neto._270 = 0; aux.neto._588 = 0;
    aux.iva.iva_105 = 0; aux.iva.iva_21 = 0; aux.iva.iva_27 = 0; aux.iva.iva_588 = 0; aux.noGravado = 0;
    aux.exento = 0; aux.p_iibb = 0; aux.p_iva = 0; aux.otrosImpuestos.oi1 = 0; aux.otrosImpuestos.oi2 = 0;
    aux.otrosImpuestos.oi3 = 0; aux.otrosImpuestos.oi4 = 0; aux.netoGravadoTotal = 0; aux.ivaTotal = 0;
    aux.total = 0; 

    VentanaFacturaCompra();

    while(*tecla != 27)
    {
        SetPosicionCursor(tecla, posicionCursor);

        if(*posicionCursor == P_COMPROBANTE)
        {
            PrintString(28, 8, "COMPROBANTE", 160);
            *tecla = getch();
            
            if(*tecla != 13)//ENTER
            PrintString(28, 8, "COMPROBANTE", 10);
        }
        else if(*posicionCursor == P_PROVEEDOR)
        {
            GetStringPredictivo(aux.cliente_proveedor, 50, tecla, 66, 8, 15, listaPalabras);
            GoToxy(0, 0); printf("%s", aux.cliente_proveedor);
        }
        else if(*posicionCursor == P_FECHA_EMISION)
        {
            int salir = 0;
            AltaFechaChar(&aux.fecha_emision, tecla, 128, 8, &salir);
            GoToxy(0, 1); printf("%s/%s/%s", aux.fecha_emision.dia, aux.fecha_emision.mes, aux.fecha_emision.anio);
            salir = 0;
        }
        else if(*posicionCursor == P_FECHA_CONT)
        {
            int salir = 0;
            strcpy(aux.fecha_contabilizacion.dia, aux.fecha_emision.dia); 
            strcpy(aux.fecha_contabilizacion.mes, aux.fecha_emision.mes);
            strcpy(aux.fecha_contabilizacion.anio, aux.fecha_emision.anio);

            GoToxy(128, 11); printf("%s", aux.fecha_contabilizacion.dia);
            GoToxy(131, 11); printf("%s", aux.fecha_contabilizacion.mes);
            GoToxy(134, 11); printf("%s", aux.fecha_contabilizacion.anio);

            AltaFechaChar(&aux.fecha_contabilizacion, tecla, 128, 11, &salir);
            GoToxy(0, 2); printf("%s/%s/%s", aux.fecha_contabilizacion.dia, aux.fecha_contabilizacion.mes, aux.fecha_contabilizacion.anio);
            salir = 0;
        }
        else if(*posicionCursor == P_TIPO_PVENTA)
        {
            AltaTipoNumeroFactura(&aux.tipo, aux.puntoVenta, tecla, 39, 11);
            GoToxy(0, 3); printf("%c-", aux.tipo); printf("%s", aux.puntoVenta);
        }
        else if(*posicionCursor == P_NUMERO_FACTURA)
        {
            AltaNumeroFactura(aux.numComprobante, tecla, 50, 11);
            GoToxy(0, 4); printf("%s", aux.numComprobante);
        }
        else if(*posicionCursor == P_NETO_21)
        {
            AltaFloats(&aux.neto._210, tecla, 39, 23);

            aux.iva.iva_21 = (aux.neto._210 * 0.21);
            GoToxy(39, 23); printf("%.2f", aux.neto._210);
            GoToxy(39, 26); printf("%.2f", aux.iva.iva_21);

            aux.ivaTotal = aux.iva.iva_105 + aux.iva.iva_21 + aux.iva.iva_27 + aux.iva.iva_588;
            GoToxy(102, 35); printf("%.2f", aux.ivaTotal);

            aux.netoGravadoTotal = (aux.neto._0 + aux.neto._105 + aux.neto._210 + aux.neto._270 + aux.neto._588);
            GoToxy(49, 35); printf("%.2f", aux.netoGravadoTotal);

            aux.total = (aux.neto._0 + aux.neto._105 + aux.neto._210 + aux.neto._270 + aux.neto._588 + aux.iva.iva_105
            + aux.iva.iva_21 + aux.iva.iva_27 + aux.iva.iva_588 + aux.noGravado + aux.exento + aux.otrosImpuestos.oi1 
            + aux.otrosImpuestos.oi2 + aux.otrosImpuestos.oi3 + aux.otrosImpuestos.oi4);
            GoToxy(81, 39); printf("%.2f", aux.total);

        }
        else if(*posicionCursor == P_NO_GRAVADO)    
        {
            AltaFloats(&aux.noGravado, tecla, 39, 29);

            aux.total = (aux.neto._0 + aux.neto._105 + aux.neto._210 + aux.neto._270 + aux.neto._588 + aux.iva.iva_105
            + aux.iva.iva_21 + aux.iva.iva_27 + aux.iva.iva_588 + aux.noGravado + aux.exento + aux.otrosImpuestos.oi1 
            + aux.otrosImpuestos.oi2 + aux.otrosImpuestos.oi3 + aux.otrosImpuestos.oi4);
            GoToxy(81, 39); printf("%.2f", aux.total);
        }
        else if(*posicionCursor == P_CONFIRMNAR_FACTURA)
        {
            PrintString(71, 16, "DESEA CONFIRMAR EL COMPROBANTE?", 10);
            PrintString(80 , 18, "1-SI", 160); PrintString(87, 18, "2-NO", 10);
            int posOpcion = 0;
            while(*tecla != 13)
            {
                *tecla = getch();

                if(*tecla == 50 && posOpcion == 0)
                {
                    posOpcion++;
                    PrintString(80, 18, "1-SI", 10); PrintString(87, 18, "2-NO", 160);
                }
                else if(*tecla == 49 && posOpcion == 1)
                {
                    posOpcion--;
                    PrintString(80, 18, "1-SI", 160); PrintString(87, 18, "2-NO", 10);
                }
                else if(*tecla == 13)
                {
                    if(posOpcion == 0)
                    {
                        BorrarVentanaAuxiliar();
                        ClearScreen(49, 1, 66, 8);//BORRA BARRITA PROVEEDORES
                        ClearScreen(1, 1, 39, 11); 
                        ClearScreen(5, 1, 41, 11);//BORRA BARRITA TIPO PTO VENTA
                        ClearScreen(9, 1, 50, 11);//BORRA BARRITA NUMERO DE COMPROBANTE
                        ClearScreen(43, 1, 72, 11);//BORRA DESCRIPCION

                        ClearScreen(19, 1, 39, 23);//BORRA NETO 21
                        ClearScreen(19, 1, 66, 23);//BORRA NETO 105
                        ClearScreen(19, 1, 91, 23);//BORRA NETO 27
                        ClearScreen(19, 1, 119, 23);//BORRA NETO 588

                        ClearScreen(19, 1, 39, 26);//BORRA IVA 21
                        ClearScreen(19, 1, 66, 26);//BORRA IVA 105
                        ClearScreen(19, 1, 91, 26);//BORRA IVA 27
                        ClearScreen(19, 1, 119, 26);//BORRA IVA 588

                        ClearScreen(19, 1, 39, 29);//BORRA NO GRAVADO
                        ClearScreen(19, 1, 66, 29);//BORRA EXENTO
                        ClearScreen(19, 1, 91, 29);//BORRA P_IIBB
                        ClearScreen(19, 1, 119, 29);//BORRA P_IVA

                        ClearScreen(19, 1, 39, 32);//BORRA OI1
                        ClearScreen(19, 1, 66, 32);//BORRA OI2
                        ClearScreen(19, 1, 91, 32);//BORRA OI3
                        ClearScreen(19, 1, 119, 32);//BORRA OI4

                        ClearScreen(26, 1, 49, 35);//BORRA NETO GRAVADO TOTAL
                        ClearScreen(26, 1, 102, 35);//BORRA IVA TOTAL

                        ClearScreen(29, 1, 81, 39);//BORRA TOTAL COMPROBANTE


                        aux.neto._0 = 0; aux.neto._105 = 0; aux.neto._210 = 0; aux.neto._270 = 0; aux.neto._588 = 0;
                        aux.iva.iva_105 = 0; aux.iva.iva_21 = 0; aux.iva.iva_27 = 0; aux.iva.iva_588 = 0; aux.noGravado = 0;
                        aux.exento = 0; aux.p_iibb = 0; aux.p_iva = 0; aux.otrosImpuestos.oi1 = 0; aux.otrosImpuestos.oi2 = 0;
                        aux.otrosImpuestos.oi3 = 0; aux.otrosImpuestos.oi4 = 0; aux.netoGravadoTotal = 0; aux.ivaTotal = 0;
                        aux.total = 0;


                        int dia = atoi(aux.fecha_emision.dia);



                        
                        *tecla = getch();
                    }
                }
            } 
        }   
        else if(*posicionCursor == P_SELECCIONAR_COMPROBANTE)
        {
            int opcionComprobante = 1;
            //PrintSquare(70, 6, 50, 14, 10);
            PrintString(60, 15, "1-FACTURA", 160);
            PrintString(80, 15, "2-NOTA CREDITO", 10);
            PrintString(100, 15, "3-NOTA DEBITO", 10);
            PrintString(60, 16, "4-RECIBO", 10);
            PrintString(80, 16, "5-FAC. CRED. ELEC.", 10);
            PrintString(100, 16, "6-TICKET", 10);

            *tecla = 0;
            while(*tecla != 13)
            {
                *tecla = getch();

                if(*tecla == 49)
                {
                    PrintString(60, 15, "1-FACTURA", 160);
                    PrintString(80, 15, "2-NOTA CREDITO", 10);
                    PrintString(100, 15, "3-NOTA DEBITO", 10);
                    PrintString(60, 16, "4-RECIBO", 10);
                    PrintString(80, 16, "5-FAC. CRED. ELEC.", 10);
                    PrintString(100, 16, "6-TICKET", 10);

                    opcionComprobante = 1;
                }
                else if(*tecla == 50)
                {
                    PrintString(60, 15, "1-FACTURA", 10);
                    PrintString(80, 15, "2-NOTA CREDITO", 160);
                    PrintString(100, 15, "3-NOTA DEBITO", 10);
                    PrintString(60, 16, "4-RECIBO", 10);
                    PrintString(80, 16, "5-FAC. CRED. ELEC.", 10);
                    PrintString(100, 16, "6-TICKET", 10);

                    opcionComprobante = 2;
                }
                else if(*tecla == 51)
                {
                    PrintString(60, 15, "1-FACTURA", 10);
                    PrintString(80, 15, "2-NOTA CREDITO", 10);
                    PrintString(100, 15, "3-NOTA DEBITO", 160);
                    PrintString(60, 16, "4-RECIBO", 10);
                    PrintString(80, 16, "5-FAC. CRED. ELEC.", 10);
                    PrintString(100, 16, "6-TICKET", 10);

                    opcionComprobante = 3;
                }
                else if(*tecla == 52)
                {
                    PrintString(60, 15, "1-FACTURA", 10);
                    PrintString(80, 15, "2-NOTA CREDITO", 10);
                    PrintString(100, 15, "3-NOTA DEBITO", 10);
                    PrintString(60, 16, "4-RECIBO", 160);
                    PrintString(80, 16, "5-FAC. CRED. ELEC.", 10);
                    PrintString(100, 16, "6-TICKET", 10);

                    opcionComprobante = 4;
                }
                else if(*tecla == 53)
                {
                    PrintString(60, 15, "1-FACTURA", 10);
                    PrintString(80, 15, "2-NOTA CREDITO", 10);
                    PrintString(100, 15, "3-NOTA DEBITO", 10);
                    PrintString(60, 16, "4-RECIBO", 10);
                    PrintString(80, 16, "5-FAC. CRED. ELEC.", 160);
                    PrintString(100, 16, "6-TICKET", 10);

                    opcionComprobante = 5;
                }
                else if(*tecla == 54)
                {
                    PrintString(60, 15, "1-FACTURA", 10);
                    PrintString(80, 15, "2-NOTA CREDITO", 10);
                    PrintString(100, 15, "3-NOTA DEBITO", 10);
                    PrintString(60, 16, "4-RECIBO", 10);
                    PrintString(80, 16, "5-FAC. CRED. ELEC.", 10);
                    PrintString(100, 16, "6-TICKET", 160);

                    opcionComprobante = 6;
                }
                else if(*tecla == 13)
                {
                    if(opcionComprobante == 1)
                    {
                        strcpy(aux.comprobante, "FACTURA");
                        ClearScreen(10, 1, 42, 8);
                        PrintString(42, 8, "FACTURA", 15);
                    }
                    else if(opcionComprobante == 2)
                    {
                        strcpy(aux.comprobante, "N/C");
                        ClearScreen(10, 1, 42, 8);
                        PrintString(42, 8, "N/C", 15);
                    }
                    else if(opcionComprobante == 3)
                    {
                        strcpy(aux.comprobante, "N/D");
                        PrintString(42, 8, "N/D", 15);
                    }
                    else if(opcionComprobante == 4)
                    {
                        strcpy(aux.comprobante, "RECIBO");
                        PrintString(42, 8, "RECIBO", 15);
                    }
                    else if(opcionComprobante == 5)
                    {
                        strcpy(aux.comprobante, "F.EL.CRED");
                        PrintString(42, 8, "F.EL.CRED", 15);
                    }
                    else if(opcionComprobante == 6)
                    {
                        strcpy(aux.comprobante, "TICKET");
                        PrintString(42, 8, "TICKET", 15);
                    }
                    *posicionCursor = P_COMPROBANTE;
                    *tecla = 9;
                    BorrarVentanaAuxiliar();
                }
            }
        }
    }
}*/

void GetStringPredictivo(char string[], int dimension, int* tecla, int x, int y, int color, NodoPalabra* listaPalabras)
{
    
    int i = 0;
    int salir = 0;
    int posicionXCursor = x;
    NodoPalabra* seguidora = listaPalabras;

    GoToxy(x, y);

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
    
    while(salir == 0)
    {
        *tecla = getch();
        if((*tecla >= 65 && *tecla <= 122) || (*tecla == 32) || (*tecla >= 48 && *tecla <= 57))
        {
            if(i < dimension)
            {
                string[i] = *tecla;
                printf("%c", string[i]);
                AutoCompletarpredictivo(string, dimension, x, y, color, i, &seguidora);
                i++;
                posicionXCursor++;
            }
            

        }
        else if(*tecla == 13 || *tecla == 9)//ENTER
        {
            if(seguidora != NULL)
            {
                strcpy(string, seguidora->palabra);
            }
            GoToxy(x, y);
            printf("%s", string);
            salir = 1;
        }
        else if(*tecla == 8)//BORRAR
        {   
            if(i > 0)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
                i--;
                string[i] = 0;
                ClearScreen(dimension - i-1, 1, x+i, y);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
                GoToxy(x+i, y);
                seguidora = listaPalabras;
            }
                    
        }
        else if(*tecla == 27)//ESCAPE
        {
            int i2 = 0;
            while(i2 < dimension)
            {
                string[i2] = 0;
                i2++;
            }
            salir = 1;
        }
        else if(*tecla == 224)
        {
            *tecla = getch();
            if(*tecla == 80)//FECHITA ABAJO
            {
                if(seguidora != NULL)
            {
                strcpy(string, seguidora->palabra);
            }
            
            printf("\n%s\n", string);
            break;;
            }
            else if(*tecla == 72)//FLECHITA ARRIBA
            {
                if(seguidora != NULL)
                {
                    strcpy(string, seguidora->palabra);
                }
            
                printf("\n%s\n", string);
                break;
            }
            else if(*tecla == 77)//FLECHITA DERECHA
            {
                if(seguidora != NULL)
                {
                    strcpy(string, seguidora->palabra);
                }
            
                printf("\n%s\n", string);
                break;;
            }
            else if(*tecla == 75)//FLECHITA IZQUIERDA
            {
                if(seguidora != NULL)
            {
                strcpy(string, seguidora->palabra);
            }
            
                printf("\n%s\n", string);
                break;
            }
        }
    }
}

void AutoCompletarpredictivo(char string[], int dimension, int x, int y, int color, int i, NodoPalabra** seguidora)
{

    while(((*seguidora) != NULL) && (strncmp(string, (*seguidora)->palabra, i+1)))
    {
        (*seguidora) = (*seguidora)->siguiente;
    }

    if((*seguidora) != NULL)
    {
        if(strcmp(string, (*seguidora)->palabra) == 0)
        {
            ClearScreen(dimension - i-2, 1, x+i+1, y);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
            GoToxy(x+i+1, y);
        }
        else
        {
            PrintString(x, y, (*seguidora)->palabra, 240);
            ClearScreen(dimension - strlen((*seguidora)->palabra)-1, 1, x + strlen((*seguidora)->palabra), y);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
            GoToxy(x, y);
            int i2 = 0;
            while(i2 < i+1)
            {
                printf("%c", (*seguidora)->palabra[i2]);
                i2++;
            }
        }
        
    }
    else 
    {
        ClearScreen(dimension - i-2, 1, x+i+1, y);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
        GoToxy(x+i+1, y);
    }
}

void GetFechaChar(char string[], int dimension, int* tecla, int x, int y, int color)
{
    
    int salir = 0;
    int i = 0;
    int posicionXCursor = x;
    
    GoToxy(x, y);

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
    
    while(salir == 0)
    {
        *tecla = getch();
        if((*tecla >= 48 && *tecla <= 57))
        {
            if(i < dimension)
            {
                string[i] = *tecla;
                printf("%c", string[i]);
                i++;
                posicionXCursor++;
                if(i == dimension)
                {
                    salir = 1;
                    string[i] = 0;
                }
            }
            

        }
        else if(*tecla == 13 || *tecla == 9)//ENTER
        {
            salir = 1;
        }
        /*else if(*tecla == 8)//BORRAR
        {   
            if(i > 0)
            {
                posicionXCursor--;
                GoToxy(posicionXCursor, y);
                printf("%c", 255);
                GoToxy(posicionXCursor, y); 
                i--;
                string[i] = 0;
            }
                    
        }
        else if(*tecla == 27)//ESCAPE
        {
            int i2 = 0;
            while(i2 < dimension)
            {
                string[i2] = 0;
                i2++;
            }
        }
        else if(*tecla == 224)
        {
            *tecla = getch();
            if(*tecla == 80)//FECHITA ABAJO
            {
                break;
            }
            else if(*tecla == 72)//FLECHITA ARRIBA
            {
                break;
            }
            else if(*tecla == 77)//FLECHITA DERECHA
            {
                break;
            }
            else if(*tecla == 75)//FLECHITA IZQUIERDA
            {
                break;
            }
        }*/
    }
}  

void AltaFechaChar(FechaChar* fecha, int* tecla, int x, int y, int* salir)
{
    GoToxy(x, y);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    
    int fechaValida = 0;
    int dia = 0;
    int mes = 0;
    int anio = 0;
    int salirAux = *salir;
    
    
    while(fechaValida == 0)
    {
        GetFechaChar(fecha->dia, 2, tecla, x, y, 15);
        if(*tecla == 13 || *tecla == 9)
        {
            break;
        }
        GetFechaChar(fecha->mes, 2, tecla, x+3, y, 15);
        
        GetFechaChar(fecha->anio, 4, tecla, x+6, y, 15);

        dia = atoi(fecha->dia);
        mes = atoi(fecha->mes);
        anio = atoi(fecha->anio);

        fechaValida = FechaValida(dia, mes, anio);

    }
    
    
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    *tecla = 9;
    
}

int FechaValida(int dia, int mes, int anio)
{
    

    if(anio < 1900 || mes < 1 || mes > 12 || dia < 1 || dia > 31)
    {
        PrintString(20, 10, "Fecha invalida", 160);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        return 0;
    }
    else
    {
        if(mes == 4 || mes == 6 || mes == 9 || mes == 11)
        {
            if(dia > 30)
            {
                PrintString(20, 10, "Fecha invalida", 160);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                return 0;   
            }
            
        }
        else if(mes == 2 && anio % 4 == 0)
        {
            if(dia > 29)
            {
                PrintString(20, 10, "Fecha invalida", 160);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                return 0; 
            }
        }
        else if(mes == 2)
        {
            if(dia > 28)
            {
                PrintString(20, 10, "Fecha invalida", 160);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                return 0; 
            }
        }

    }
    
    return 1;
}

void AltaTipoNumeroFactura(char* tipo, char ptoVenta[], int* tecla, int x, int y)
{
    
    int salir = 0;
    int i = 0;
    int tipoCargado = 0;
    int posicionXCursor = x;

    while(i < 6)
    {
        if(i != 5)
        ptoVenta[i] = 255;
        else
        ptoVenta[i] = 0;
        
        i++;
    }

    i = 0;
    GoToxy(x+2, y); printf("%s", ptoVenta);
    GoToxy(x, y);

    while(salir == 0)
    {
        *tecla = getch();
        if(*tecla == 97 || *tecla == 98 || *tecla == 99 || *tecla == 109 || *tecla == 122)
        {
            if(tipoCargado == 0)
            {
                *tipo = toupper(*tecla);
                printf("%c", *tipo);
                tipoCargado = 1;
                GoToxy(x+2, y);
                posicionXCursor = posicionXCursor + 2;
            }
        }
        else if(*tecla == 65 || *tecla == 66 || *tecla == 67 || *tecla == 77 || *tecla == 90)
        {
            if(tipoCargado == 0)
            {
                *tipo = *tecla;
                printf("%c", *tipo);
                tipoCargado = 1;
                GoToxy(x+2, y);
                posicionXCursor = posicionXCursor + 2;
            }
        }
        else if((*tecla >= 48 && *tecla <= 57) && tipoCargado == 1)
        {
            if(i <= 4)
            {
                ptoVenta[i] = *tecla;
                printf("%c", ptoVenta[i]);
                i++;
                posicionXCursor++;
                if(i == 5)
                {
                    ptoVenta[i] = 0;
                }
            }
        }
        else if(*tecla == 8)//BORRAR
        {
            if(i > 0)
            {
                posicionXCursor--;
                GoToxy(posicionXCursor, y);
                printf("%c", 255);
                GoToxy(posicionXCursor, y); 
                i--;
                ptoVenta[i] = 0;
            }

        }
        else if(*tecla == 13 || *tecla == 9)
        {
            salir = 1;
            ptoVenta[i] = 0;
            
            GoToxy(x+2, y);
            printf("%s\n", ptoVenta);
            
        }

        else if(*tecla == 224)
        {
            *tecla = getch();
            if(*tecla == 80)//FECHITA ABAJO
            {
                salir = 1;
                ptoVenta[i] = 0;
                
                GoToxy(x+2, y);
                printf("%s\n", ptoVenta);
            }
            else if(*tecla == 72)//FLECHITA ARRIBA
            {
                salir = 1;
                ptoVenta[i] = 0;
                
                GoToxy(x+2, y);
                printf("%s\n", ptoVenta);
            }
            else if(*tecla == 77)//FLECHITA DERECHA
            {
                salir = 1;
                ptoVenta[i] = 0;
                
                GoToxy(x+2, y);
                printf("%s\n", ptoVenta);
            }
            else if(*tecla == 75)//FLECHITA IZQUIERDA
            {
                GoToxy(x, y);
                tipoCargado = 0;
            }
        }    
    }
    

}

void AltaNumeroFactura(char numeroFactura[], int* tecla, int x, int y)
{
    int salir = 0;
    int i = 0;
    int posicionXCursor = x;

    while(i < 10)
    {
        if(i != 9)
        numeroFactura[i] = 255;
        else
        numeroFactura[i] = 0;
        
        i++;
    }
    i = 0;
    GoToxy(x, y); printf("%s", numeroFactura); GoToxy(x, y);
    
    while(salir == 0)
    {
        *tecla = getch();
        if(*tecla >= 48 && *tecla <= 57)
        {
            if(i <= 8)
            {
                numeroFactura[i] = *tecla;
                printf("%c", numeroFactura[i]);
                i++;
                posicionXCursor++;
                if(i == 9)
                {
                    numeroFactura[i] = 0;
                }
            }
        }
        else if(*tecla == 8)
        {
            if(i > 0)
            {
                posicionXCursor--;
                GoToxy(posicionXCursor, y);
                printf("%c", 255);
                GoToxy(posicionXCursor, y); 
                i--;
                numeroFactura[i] = 0;
            }
        }
        else if(*tecla == 13 || *tecla == 9)
        {
            salir = 1;
            numeroFactura[i] = 0;
            
            
        }

        else if(*tecla == 224)
        {
            *tecla = getch();
            if(*tecla == 80)//FECHITA ABAJO
            {
                salir = 1;
                numeroFactura[i] = 0;
                
                GoToxy(x+2, y);
                printf("%s\n", numeroFactura);
            }
            else if(*tecla == 72)//FLECHITA ARRIBA
            {
                salir = 1;
                numeroFactura[i] = 0;
                
                GoToxy(x+2, y);
                printf("%s\n", numeroFactura);
            }
            else if(*tecla == 77)//FLECHITA DERECHA
            {
                salir = 1;
                numeroFactura[i] = 0;
                
                GoToxy(x+2, y);
                printf("%s\n", numeroFactura);
            }
            else if(*tecla == 75)//FLECHITA IZQUIERDA
            {
                salir = 1;
                numeroFactura[i] = 0;
                
                GoToxy(x+2, y);
                printf("%s\n", numeroFactura);
            }
        }    
    }
}

void AltaFloats(float* numeroFloat, int* tecla, int x, int y)
{
    int salir = 0;
    int i = 0;
    int posicionXCursor = x;
    GoToxy(x, y);
    scanf("%f", numeroFloat);
    *tecla = 9;
}

void BorrarVentanaAuxiliar()
{
    ClearScreen(68, 4, 51, 15);
}

void MenuPrincipal(int* tecla)
{
    int opcionMenuPrincipal = 1;
    int salir = 0;
    PrintSolidSquare(41, 1, 68, 13);
    PrintString(82, 13, "MENU PRINCIPAL", 160);
    PrintSquare(40, 10 , 68, 14, 10);
    PrintString(69, 18, "1-EMPRESAS                             ", 160);
    PrintString(69, 20, "2-FACTURAS                             ", 10);
    
    while(salir == 0)
    {
       
        *tecla = getch();
        if(*tecla == 49)
        {
            
            PrintString(69, 18, "1-EMPRESAS                             ", 160);
            PrintString(69, 20, "2-FACTURAS                             ", 10);
            opcionMenuPrincipal = 1;
        }
        else if(*tecla == 50)
        {
            PrintString(69, 18, "1-EMPRESAS                             ", 10);
            PrintString(69, 20, "2-FACTURAS                             ", 160);
            opcionMenuPrincipal = 2;
        }
        else if(*tecla == 13)
        {
            if(opcionMenuPrincipal == 1)
            {
                ClearScreen(39, 9, 69, 15);
                opcionMenuPrincipal = MenuEmpresas(tecla);
            }
            else if(opcionMenuPrincipal == 2)
            {
                ClearScreen(39, 9, 69, 15);
                MenuFacturas(tecla);
            }
        }
        else if(*tecla == 27)
        {
            salir = 1;
        }
    }

}

int MenuEmpresas(int* tecla)
{
    int opcionMenuEmpresas = 1;
    int salir = 0;
    PrintSolidSquare(41, 1, 68, 13);
    PrintString(82, 13, "MENU EMPRESAS", 160);

    PrintString(69, 17, "1-AGREGAR EMPRESA                      ", 160);
    PrintString(69, 19, "2-DAR DE BAJA EMPRESA                  ", 10);
    PrintString(69, 21, "3-LISTAR EMPRESAS                      ", 10);
            
    
    while(salir == 0)
    {
        *tecla = getch();
        if(*tecla == 49)
        {
            //ClearScreen(39, 9, 39, 9);
            PrintString(69, 17, "1-AGREGAR EMPRESA                      ", 160);
            PrintString(69, 19, "2-DAR DE BAJA EMPRESA                  ", 10);
            PrintString(69, 21, "3-LISTAR EMPRESAS                      ", 10);
            
            opcionMenuEmpresas = 1;
        }
        else if(*tecla == 50)
        {
            PrintString(69, 17, "1-AGREGAR EMPRESA                      ", 10);
            PrintString(69, 19, "2-DAR DE BAJA EMPRESA                  ", 160);
            PrintString(69, 21, "3-LISTAR EMPRESAS                      ", 10);
            opcionMenuEmpresas = 2;
        }
        else if(*tecla == 51)
        {
            PrintString(69, 17, "1-AGREGAR EMPRESA                      ", 10);
            PrintString(69, 19, "2-DAR DE BAJA EMPRESA                  ", 10);
            PrintString(69, 21, "3-LISTAR EMPRESAS                      ", 160);
            opcionMenuEmpresas = 3;   
        }
        else if(*tecla == 13)
        {
            if(opcionMenuEmpresas == 1)
            {
                ClearScreen(42, 13, 67, 13);
                AgregarEmpresa(tecla, PasarCuitDelArchivoAListaSimple("Empresas"));
            }
            else if(opcionMenuEmpresas == 2)
            {
                ClearScreen(42, 13, 67, 13);
                NodoPalabra* listaNombresEmpresas = PasarEmpresasDelArchivoAListaSimple("Empresas");
                NodoEmpresa* listaEmpresas = PasarEmpresasFullDelArchivoAListaSimple("Empresas");
                DarDeBajaEmpresa(tecla, listaNombresEmpresas, listaEmpresas);
            }
            else if(opcionMenuEmpresas == 3)
            {
                ClearScreen(39, 9, 69, 15);
                MenuListarEmpresas(tecla);
            }
        }
        else if(*tecla == 27)
        {
            ClearScreen(39, 9, 69, 15);
            PrintSolidSquare(41, 1, 68, 13);
            PrintString(82, 13, "MENU PRINCIPAL", 160);
            PrintString(69, 18, "1-EMPRESAS                             ", 160);
            PrintString(69, 20, "2-FACTURAS                             ", 10);
            salir = 1;
            return 1;
        }
    }
}

void MenuFacturas(int* tecla)
{
    int opcionMenuFacturas = 1;
    int salir = 0;
    PrintString(69, 16, "1-CARGAR FACTURA                       ", 160);
    PrintString(69, 18, "2-MODIFICAR FACTURA                    ", 10);
    PrintString(69, 20, "3-BORRAR FACTURA                       ", 10);
    PrintString(69, 22, "4-LISTAR FACTURAS                      ", 10);
            
    
    while(salir == 0)
    {
        *tecla = getch();
        if(*tecla == 49)
        {
            PrintString(69, 16, "1-CARGAR FACTURA                       ", 160);
            PrintString(69, 18, "2-MODIFICAR FACTURA                    ", 10);
            PrintString(69, 20, "3-BORRAR FACTURA                       ", 10);
            PrintString(69, 22, "4-LISTAR FACTURAS                      ", 10);
            
            opcionMenuFacturas = 1;
        }
        else if(*tecla == 50)
        {
            PrintString(69, 16, "1-CARGAR FACTURA                       ", 10);
            PrintString(69, 18, "2-MODIFICAR FACTURA                    ", 160);
            PrintString(69, 20, "3-BORRAR FACTURA                       ", 10);
            PrintString(69, 22, "4-LISTAR FACTURAS                      ", 10);
            opcionMenuFacturas = 2;
        }
        else if(*tecla == 51)
        {
            PrintString(69, 16, "1-CARGAR FACTURA                       ", 10);
            PrintString(69, 18, "2-MODIFICAR FACTURA                    ", 10);
            PrintString(69, 20, "3-BORRAR FACTURA                       ", 160);
            PrintString(69, 22, "4-LISTAR FACTURAS                      ", 10);
            opcionMenuFacturas = 3;   
        }
        else if(*tecla == 52)
        {
            PrintString(69, 16, "1-CARGAR FACTURA                       ", 10);
            PrintString(69, 18, "2-MODIFICAR FACTURA                    ", 10);
            PrintString(69, 20, "3-BORRAR FACTURA                       ", 10);
            PrintString(69, 22, "4-LISTAR FACTURAS                      ", 160);
        }
        else if(*tecla == 13)
        {
            if(opcionMenuFacturas == 1)
            {
                NodoPalabra* listaNombresEmpresas = PasarEmpresasDelArchivoAListaSimple("Empresas");
                CargarFactura(tecla, listaNombresEmpresas);
            }
        }
        else if(*tecla == 27)
        {
            ClearScreen(39, 9, 69, 15);
            PrintString(69, 18, "1-EMPRESAS                             ", 10);
            PrintString(69, 20, "2-FACTURAS                             ", 160);
            salir = 1;
        }
    }
}

void CargarFactura(int* tecla, NodoPalabra* listaNombresEmpresas)
{
    Registro_Factura aux;

    ClearScreen(42, 13, 67, 13);
    PrintSolidSquare(61, 1, 58, 14);
    PrintString(82, 14, "CARGAR FACTURA", 160);
    PrintSquare(60, 15 , 58, 15, 10);

    PrintString(59, 19, "EMPRESA", 10);
    PrintSquare(50, 2, 67, 18, 15);

    PrintString(78, 25, "1-COMPRA", 10);
    PrintString(95, 25, "2-VENTA", 10);

    GetStringPredictivo(aux.nombreEmpresa, 50, tecla, 68, 19, 15, listaNombresEmpresas);

    int salir = 0;
    int opcion = 1;

    PrintString(78, 25, "1-COMPRA", 160);
    PrintString(95, 25, "2-VENTA", 10);

    while(salir == 0)
    {
        *tecla = getch();
        if(*tecla == 49)
        {
            PrintString(78, 25, "1-COMPRA", 160);
            PrintString(95, 25, "2-VENTA", 10);
            opcion = 1;
        }
        else if(*tecla == 50)
        {   
            PrintString(78, 25, "1-COMPRA", 10);
            PrintString(95, 25, "2-VENTA", 160);
            opcion = 2;
        }
        else if(*tecla == 13)
        {
            if(opcion == 1)
            {
                aux.cp = 'p';
                NodoPalabra* listaPalabras;
                IniciarListaPalabras(&listaPalabras);
                AgregarNodoPalabraAlfabeticamente(&listaPalabras, "juan");
                AgregarNodoPalabraAlfabeticamente(&listaPalabras, "eduardo");
                AgregarNodoPalabraAlfabeticamente(&listaPalabras, "alberto");
                AgregarNodoPalabraAlfabeticamente(&listaPalabras, "enzo");
                AgregarNodoPalabraAlfabeticamente(&listaPalabras, "marina");
                AgregarNodoPalabraAlfabeticamente(&listaPalabras, "chapu");
                AgregarNodoPalabraAlfabeticamente(&listaPalabras, "sinomatamonomatamo");
                int posicionCursor = 0;
                ClearScreen(100, 30, 20, 7);
                *tecla = 0;
                AltaFactura(&posicionCursor, tecla, listaPalabras, &aux);
            }
            else if(opcion == 2)
            {
                aux.cp = 'c';
                ClearScreen(100, 50, 20, 7);
                VentanaFacturaCompra();
            }
        }
        



    }

}

Empresa AgregarEmpresa(int* tecla, NodoPalabra* listaCuits)
{
    Empresa aux;
    aux.nombre[0] = 0;
    aux.cuit[0] = 0;
    NodoPalabra* seguidora = listaCuits;
    int salir = 0;
    int posicionCursor = 0;
    
    int cuitRepetido = 0;

    PrintSolidSquare(61, 1, 58, 14);
    PrintString(82, 14, "AGREGAR EMPRESA", 160);

    PrintSquare(60, 15 , 58, 15, 10);

    PrintString(59, 17, "NOMBRE", 10);
    PrintSquare(50, 2, 66, 16, 15);

    PrintString(60, 21, "CUIT", 10);
    PrintSquare(50, 2, 66, 20, 15);

    PrintString(75, 27, "CONFIRMAR", 10);
    PrintSquare(10, 2, 74, 26, 10);

    PrintString(94, 27, "CANCELAR", 10);
    PrintSquare(9, 2, 93, 26, 10);

    *tecla = 0;

    while(salir == 0)
    {
        if(*tecla == 9)
        {
            if(posicionCursor == 0 || posicionCursor == 1 || posicionCursor == 2)
            {
                posicionCursor++;
            }
            else if(posicionCursor == 3)
            {
                posicionCursor = 0;
            }
        }
        else if(*tecla == 13)
        {
            if(posicionCursor == 0 || posicionCursor == 1)
            {
                posicionCursor++;
            }
            else if(posicionCursor == 2)
            {
                if(cuitRepetido == 0)
                {
                    aux.activa_emp = 1;
                    PersistirUnaEmpresaEnArchivo("Empresas", aux);

                    ClearScreen(70, 20, 55, 13);
                    PrintSolidSquare(41, 1, 68, 13);
                    PrintString(82, 13, "MENU EMPRESAS", 160);
                    PrintString(69, 17, "1-AGREGAR EMPRESA                      ", 160);
                    PrintString(69, 19, "2-DAR DE BAJA EMPRESA                  ", 10);
                    PrintString(69, 21, "3-LISTAR EMPRESAS                      ", 10);
                    PrintSquare(40, 10 , 68, 14, 10);

                    return aux;
                }
                else
                {
                    PrintString(82, 24, "CUIT REPETIDO!!", 160);
                    *tecla = 0;
                    while(*tecla != 13)
                    {
                        *tecla = getch();
                    }
                    ClearScreen(18, 1, 79, 24);
                }
                
                
            }
            else if(posicionCursor == 3)
            {
                aux.activa_emp = 0;
                aux.cuit[0] = 0;
                aux.nombre[0] = 0;

                ClearScreen(70, 20, 55, 13);
                PrintSolidSquare(41, 1, 68, 13);
                PrintString(82, 13, "MENU EMPRESAS", 160);
                PrintString(69, 17, "1-AGREGAR EMPRESA                      ", 160);
                PrintString(69, 19, "2-DAR DE BAJA EMPRESA                  ", 10);
                PrintString(69, 21, "3-LISTAR EMPRESAS                      ", 10);
                PrintSquare(40, 10 , 68, 14, 10);
                return aux;
            }
        }

        if(posicionCursor == 0)
        {
            if(strlen(aux.nombre) == 0)
            {
                PrintString(75, 27, "CONFIRMAR", 10);
                PrintString(94, 27, "CANCELAR", 10);
                GetString(aux.nombre, 49, tecla, 67, 17, 15);
                GoToxy(0, 0); printf("%s", aux.nombre);
                
            }
            else
            {
                PrintString(67, 17, aux.nombre, 240);
                PrintString(75, 27, "CONFIRMAR", 10);
                PrintString(94, 27, "CANCELAR", 10);
                GoToxy(67+strlen(aux.nombre), 17);
                *tecla = getch();
                if(*tecla == 9)
                {
                    PrintString(67, 17, aux.nombre, 15);
                }
                else if(*tecla == 13)
                {
                    ClearScreen(49, 1, 67, 17);
                    GetString(aux.nombre, 49, tecla, 67, 17, 15);
                    GoToxy(0, 0); printf("%s", aux.nombre);
                }
            }

            
        }
        else if(posicionCursor == 1)
        {
           if(strlen(aux.cuit) == 0)
            {
                GetStringNumber(aux.cuit, 11, tecla, 67, 21, 15);
                GoToxy(0, 1); printf("%s", aux.cuit);
                while(seguidora != NULL)
                {
                    if(strcmp(seguidora->palabra, aux.cuit) != 0)
                    {
                        seguidora = seguidora->siguiente;
                    }
                    else
                    {
                        PrintString(82, 24, "CUIT REPETIDO!!", 160);
                        *tecla = 0;
                        while(*tecla != 13)
                        {
                            *tecla = getch();
                        }
                        ClearScreen(18, 1, 79, 24);
                        
                        cuitRepetido = 1;
                        break;
                    }
                        
                }
                if(seguidora == NULL)
                {
                    cuitRepetido = 0;
                }
                seguidora = listaCuits;
                
            }
            else
            {
                PrintString(67, 21, aux.cuit, 240);
                GoToxy(67+strlen(aux.cuit), 21);
               
                *tecla = getch();
                if(*tecla == 9)
                {
                    PrintString(67, 21, aux.cuit, 15);
                }
                else if(*tecla == 13)
                {
                    ClearScreen(49, 1, 67, 21);
                    GetStringNumber(aux.cuit, 11, tecla, 67, 21, 15);
                    GoToxy(0, 1); printf("%s", aux.cuit);
                    while(seguidora != NULL)
                    {
                        if(strcmp(seguidora->palabra, aux.cuit) != 0)
                        {
                            seguidora = seguidora->siguiente;
                        }
                        else
                        {
                            PrintString(82, 24, "CUIT REPETIDO!!", 160);
                            *tecla = 0;
                            while(*tecla != 13)
                            {
                                *tecla = getch();
                            }
                            ClearScreen(18, 1, 79, 24);
                            
                            cuitRepetido = 1;
                            break;
                        }    
                    }
                    if(seguidora == NULL)
                    {
                        cuitRepetido = 0;
                    }
                    seguidora = listaCuits;   
                }
            }
        }
        else if(posicionCursor == 2)
        {
            PrintString(75, 27, "CONFIRMAR", 160);
            PrintString(94, 27, "CANCELAR", 10);
            *tecla = getch();
        }
        else if(posicionCursor == 3)
        {
            PrintString(75, 27, "CONFIRMAR", 10);
            PrintString(94, 27, "CANCELAR", 160);
            *tecla = getch();
        }
    }



    return aux;

}

void DarDeBajaEmpresa(int* tecla, NodoPalabra* listaNombresEmpresas, NodoEmpresa* listaEmpresas)
{
    PrintSolidSquare(61, 1, 58, 14);
    PrintString(82, 14, "BAJA EMPRESA", 160);
    PrintSquare(60, 15 , 58, 15, 10);
    PrintString(59, 17, "NOMBRE", 10);
    PrintSquare(50, 2, 66, 16, 15);

    PrintString(60, 21, "CUIT", 10);
    PrintSquare(50, 2, 66, 20, 15);
    char aux[50];
    int salir = 0;
    NodoPalabra* seguidoraNombresEmpresa = listaNombresEmpresas;
    NodoEmpresa* seguidoraEmpresas = listaEmpresas;


    while(salir == 0)
    {   
        aux[0] = 0;
        seguidoraNombresEmpresa = listaNombresEmpresas;
        seguidoraEmpresas = listaEmpresas;
        ClearScreen(49, 1, 67, 17);
        ClearScreen(49, 1, 67, 21);
        GetStringPredictivo(aux, 50, tecla, 67, 17, 15, seguidoraNombresEmpresa);

        if(*tecla == 13 || *tecla == 9)
        {
            while(seguidoraEmpresas != NULL && strcmp(seguidoraEmpresas->empresa.nombre, aux) != 0)
            {
                seguidoraEmpresas = seguidoraEmpresas->siguiente;
            }
            if(seguidoraEmpresas != NULL)
            {
                PrintString(67, 21, seguidoraEmpresas->empresa.cuit, 15);
                if(seguidoraEmpresas->empresa.activa_emp == 0)
                {
                    PrintString(69, 24, "LA EMPRESA YA SE ENCUENTRA DADA DE BAJA", 192);
                    PrintString(79, 26, "DESEA DARLA DE ALTA?", 160);
                    PrintString(84, 28, "1-SI", 160); PrintString(90, 28, "2-NO", 10);
                    
                    int opcion = 1;
                    int salir2 = 0;
                   
                    while(salir2 == 0)
                    {
                        *tecla = getch();
                        if(*tecla == 49)
                        {
                            PrintString(84, 28, "1-SI", 160); PrintString(90, 28, "2-NO", 10);
                            opcion = 1;
                        }
                        else if(*tecla == 50)
                        {
                            PrintString(84, 28, "1-SI", 10); PrintString(90, 28, "2-NO", 160);
                            opcion = 2;
                        }
                        else if(*tecla == 13)
                        {
                            if(opcion == 1)
                            {
                                {
                               int posArchivo = buscarUnaEmpresaXCuitEnArchivoYRetornaPosicionRegistro("Empresas", seguidoraEmpresas->empresa.cuit);
                               GoToxy(3, 0); printf("%d", posArchivo);
                               seguidoraEmpresas->empresa.activa_emp = 1;
                               Empresa aux = seguidoraEmpresas->empresa;
                               FILE* buf = fopen("Empresas", "r+b");
                               if(buf)
                               { 
                                    fseek(buf, (posArchivo * sizeof(Empresa)) - sizeof(Empresa), SEEK_SET);
                                    fwrite(&aux, sizeof(Empresa), 1, buf);
                                    fclose(buf); 


                                    ClearScreen(50, 7, 68, 23);
                                    PrintString(75, 24, "EMPRESA DADA DE ALTA CON EXITO", 160);
                                    PrintString(78, 27, "1-CONTINUAR", 160); PrintString(92, 27, "2-VOLVER", 10);
                                    opcion = 1;
                                    while(salir2 == 0)
                                    {
                                        *tecla = getch();
                                        if(*tecla == 49)
                                        {
                                            PrintString(78, 27, "1-CONTINUAR", 160); PrintString(92, 27, "2-VOLVER", 10);
                                            opcion = 1;
                                        }
                                        else if(*tecla == 50)
                                        {
                                            PrintString(78, 27, "1-CONTINUAR", 10); PrintString(92, 27, "2-VOLVER", 160);
                                            opcion = 2;
                                        }
                                        else if(*tecla == 13)
                                        {
                                            if(opcion == 1)
                                            {
                                                ClearScreen(40, 7, 74, 23);
                                                salir2 = 1;
                                            }
                                            else if(opcion == 2)
                                            {
                                                ClearScreen(70, 20, 55, 13);
                                                PrintSolidSquare(41, 1, 68, 13);
                                                PrintString(82, 13, "MENU EMPRESAS", 160);
                                                PrintString(69, 17, "1-AGREGAR EMPRESA                      ", 160);
                                                PrintString(69, 19, "2-DAR DE BAJA EMPRESA                  ", 10);
                                                PrintString(69, 21, "3-LISTAR EMPRESAS                      ", 10);
                                                PrintSquare(40, 10 , 68, 14, 10);
                                                salir2 = 1;
                                                salir = 1;
                                            }
                                        }
                                    }
                                }
                            }
                            }
                        }
                    }    
                }
                else
                {
                    int opcion = 1;
                    int salir2 = 0;
                    PrintString(75, 24, "DESEA DAR DE BAJA LA EMPRESA?", 192);
                    PrintString(84, 27, "1-SI", 160); PrintString(90, 27, "2-NO", 10);
                    while(salir2 == 0)
                    {
                        *tecla = getch();
                        if(*tecla == 49)
                        {
                            PrintString(84, 27, "1-SI", 160); PrintString(90, 27, "2-NO", 10);
                            opcion = 1;
                        }
                        else if(*tecla == 50)
                        {
                            PrintString(84, 27, "1-SI", 10); PrintString(90, 27, "2-NO", 160);
                            opcion = 2;
                        }
                        else if(*tecla == 13)
                        {
                            if(opcion == 1)
                            {
                               int posArchivo = buscarUnaEmpresaXCuitEnArchivoYRetornaPosicionRegistro("Empresas", seguidoraEmpresas->empresa.cuit);
                               GoToxy(3, 0); printf("%d", posArchivo);
                               seguidoraEmpresas->empresa.activa_emp = 0;
                               Empresa aux = seguidoraEmpresas->empresa;
                               FILE* buf = fopen("Empresas", "r+b");
                               if(buf)
                               { 
                                    fseek(buf, (posArchivo * sizeof(Empresa)) - sizeof(Empresa), SEEK_SET);
                                    fwrite(&aux, sizeof(Empresa), 1, buf);
                                    fclose(buf); 


                                    ClearScreen(40, 7, 74, 23);
                                    PrintString(75, 24, "EMPRESA DADA DE BAJA CON EXITO", 160);
                                    PrintString(78, 27, "1-CONTINUAR", 160); PrintString(92, 27, "2-VOLVER", 10);
                                    opcion = 0;
                                    while(salir2 == 0)
                                    {
                                        *tecla = getch();
                                        if(*tecla == 49)
                                        {
                                            PrintString(78, 27, "1-CONTINUAR", 160); PrintString(92, 27, "2-VOLVER", 10);
                                            opcion = 1;
                                        }
                                        else if(*tecla == 50)
                                        {
                                            PrintString(78, 27, "1-CONTINUAR", 10); PrintString(92, 27, "2-VOLVER", 160);
                                            opcion = 2;
                                        }
                                        else if(*tecla == 13)
                                        {
                                            if(opcion == 1)
                                            {
                                                ClearScreen(40, 7, 74, 23);
                                                salir2 = 1;
                                            }
                                            else if(opcion == 2)
                                            {
                                                ClearScreen(70, 20, 55, 13);
                                                PrintSolidSquare(41, 1, 68, 13);
                                                PrintString(82, 13, "MENU EMPRESAS", 160);
                                                PrintString(69, 17, "1-AGREGAR EMPRESA                      ", 160);
                                                PrintString(69, 19, "2-DAR DE BAJA EMPRESA                  ", 10);
                                                PrintString(69, 21, "3-LISTAR EMPRESAS                      ", 10);
                                                PrintSquare(40, 10 , 68, 14, 10);
                                                salir2 = 1;
                                                salir = 1;
                                            }
                                        }
                                    }
                                }
                            }
                            else if(opcion == 2)
                            {
                                ClearScreen(40, 7, 74, 23);
                                salir2 = 1;
                            }
                        }
                    }  
                }
            }
        }
        else if(*tecla == 27)
        {
            ClearScreen(70, 20, 55, 13);
            PrintSolidSquare(41, 1, 68, 13);
            PrintString(82, 13, "MENU EMPRESAS", 160);
            PrintString(69, 17, "1-AGREGAR EMPRESA                      ", 160);
            PrintString(69, 19, "2-DAR DE BAJA EMPRESA                  ", 10);
            PrintString(69, 21, "3-LISTAR EMPRESAS                      ", 10);
            PrintSquare(40, 10 , 68, 14, 10);
            salir = 1;
        } 
    }
}

void MenuListarEmpresas(int* tecla)
{
    int opcionMenuListarEmpresas = 1;
    int salir = 0;
    PrintSolidSquare(41, 1, 68, 13);
    PrintString(82, 13, "LISTAR EMPRESAS", 160);
    PrintString(69, 18, "1-LISTAR UNA EMPRESA                   ", 160);
    PrintString(69, 20, "2-LISTAR TODAS                         ", 10);

    while(salir == 0)
    {
        *tecla = getch();
        if(*tecla == 49)
        {
            
            PrintString(69, 18, "1-LISTAR UNA EMPRESA                   ", 160);
            PrintString(69, 20, "2-LISTAR TODAS                         ", 10);
            opcionMenuListarEmpresas= 1;
        }
        else if(*tecla == 50)
        {
            PrintString(69, 18, "1-LISTAR UNA EMPRESA                   ", 10);
            PrintString(69, 20, "2-LISTAR TODAS                         ", 160);
            opcionMenuListarEmpresas = 2;
        }
        else if(*tecla == 27)
        {
            ClearScreen(39, 9, 69, 15);
            PrintSolidSquare(41, 1, 68, 13);
            PrintString(82, 13, "MENU EMPRESAS", 160);
            PrintString(69, 17, "1-AGREGAR EMPRESA                      ", 10);
            PrintString(69, 19, "2-DAR DE BAJA EMPRESA                  ", 10);
            PrintString(69, 21, "3-LISTAR EMPRESAS                      ", 160);
            salir = 1;
        }
        else if(*tecla == 13)
        {
            if(opcionMenuListarEmpresas == 2)
            {
                NodoEmpresa* listaEmpresas = PasarEmpresasFullDelArchivoAListaSimple("Empresas");
                PrintearTodasLasEmpresas(tecla, listaEmpresas);
            }
            else if(opcionMenuListarEmpresas == 1)
            {
                ClearScreen(42, 13, 67, 13);
                NodoPalabra* listaNombresEmpresas = PasarEmpresasDelArchivoAListaSimple("Empresas");
                NodoEmpresa* listaEmpresas = PasarEmpresasFullDelArchivoAListaSimple("Empresas");
                MostrarUnaEmpresa(tecla, listaEmpresas, listaNombresEmpresas);
            }
        }
    }    
}

void PrintearTodasLasEmpresas(int* tecla, NodoEmpresa* listaEmpresas)
{
    NodoEmpresa* seguidora = listaEmpresas;
    ClearScreen(42, 13, 67, 13);
    PrintSolidSquare(75, 1, 50, 7);
    PrintString(65, 7, "NOMBRE", 160);
    PrintString(96, 7, "CUIT", 160);
    PrintString(116, 7, "ESTADO", 160);

    int orden = 0;
    int y = 8; 
    
    while(seguidora != NULL)
    {
        if(orden == 0)
        {
            PrintString(50, y, seguidora->empresa.nombre, 15);
            PrintString(93, y, seguidora->empresa.cuit, 15);
            if(seguidora->empresa.activa_emp == 1)
            {
                PrintString(117, y, "ALTA", 15);
            }
            else
            {
                PrintString(117, y, "BAJA", 15);
            }
            orden = 1;
        }
        else
        {
            PrintSolidSquareWhite(75, 1, 50, y);
            PrintString(50, y, seguidora->empresa.nombre, 128);
            PrintString(93, y, seguidora->empresa.cuit, 128);
            if(seguidora->empresa.activa_emp == 1)
            {
                PrintString(117, y, "ALTA", 128);
            }
            else
            {
                PrintString(117, y, "BAJA", 128);
            }
            orden = 0;
        }
        y++;
        seguidora = seguidora->siguiente;
    }

   

    *tecla = 0;
    while(*tecla != 27)
    {
        *tecla = getch();
    }
    ClearScreen(80, y+2, 49, 6);
    PrintSolidSquare(41, 1, 68, 13);
    PrintString(82, 13, "LISTAR EMPRESAS", 160);
    PrintSquare(40, 10 , 68, 14, 10);
    PrintString(69, 18, "1-LISTAR UNA EMPRESA                   ", 10);
    PrintString(69, 20, "2-LISTAR TODAS                         ", 160);
}

void MostrarUnaEmpresa(int* tecla, NodoEmpresa* listaEmpresas, NodoPalabra* listaNombresEmpresas)
{
    PrintSolidSquare(61, 1, 58, 14);
    PrintString(82, 14, "MOSTRAR EMPRESA", 160);
    PrintSquare(60, 15 , 58, 15, 10);
    PrintString(59, 17, "NOMBRE", 10);
    PrintSquare(50, 2, 66, 16, 15);

    PrintString(60, 20, "CUIT", 10);
    PrintSquare(50, 2, 66, 19, 15);

    PrintString(59, 23, "ESTADO", 10);
    PrintSquare(50, 2, 66, 22, 15);

    char aux[50];
    int salir = 0;

    NodoPalabra* seguidoraNombresEmpresa = listaNombresEmpresas;
    NodoEmpresa* seguidoraEmpresas = listaEmpresas;


    while(salir == 0)
    {   
        aux[0] = 0;
        seguidoraNombresEmpresa = listaNombresEmpresas;
        seguidoraEmpresas = listaEmpresas;
        ClearScreen(49, 1, 67, 17);
        ClearScreen(49, 1, 67, 20);
        ClearScreen(49, 1, 67, 23);
        GetStringPredictivo(aux, 50, tecla, 67, 17, 15, seguidoraNombresEmpresa);


        if(*tecla == 13 || *tecla == 9)
        {
            while(seguidoraEmpresas != NULL && strcmp(seguidoraEmpresas->empresa.nombre, aux) != 0)
            {
                seguidoraEmpresas = seguidoraEmpresas->siguiente;
            }
            if(seguidoraEmpresas != NULL)
            {
                PrintString(67, 20, seguidoraEmpresas->empresa.cuit, 15);
                if(seguidoraEmpresas->empresa.activa_emp == 1)
                {
                    PrintString(67, 23, "ALTA", 15);
                }
                else
                {
                    PrintString(67, 23, "BAJA", 15);
                }
            }
            else
            {
                PrintString(80, 26, "NO SE ENCUENTA LA EMPRESA", 196);
            }

            PrintString(78, 27, "1-CONTINUAR", 160); PrintString(92, 27, "2-VOLVER", 10);
            int salir2 = 0;
            int opcion = 1;
            while(salir2 == 0)
            {
                *tecla = getch();
                if(*tecla == 49)
                {
                    PrintString(78, 27, "1-CONTINUAR", 160); PrintString(92, 27, "2-VOLVER", 10);
                    opcion = 1;
                }
                else if(*tecla == 50)
                {
                    PrintString(78, 27, "1-CONTINUAR", 10); PrintString(92, 27, "2-VOLVER", 160);
                    opcion = 2;
                }
                else if(*tecla == 13)
                {
                    if(opcion == 1)
                    {
                        ClearScreen(40, 4, 77, 25);
                        salir2 = 1;
                    }
                    else if(opcion == 2)
                    {
                        
                        salir2 = 1;
                        salir = 1;
                    }
                }
            }
        }
        else if(*tecla == 27)
        {
            salir = 1;
        }
    }
    ClearScreen(70, 20, 55, 13);
    PrintSolidSquare(41, 1, 68, 13);
    PrintString(82, 13, "LISTAR EMPRESAS", 160);
    PrintString(69, 18, "1-LISTAR UNA EMPRESA                   ", 160);
    PrintString(69, 20, "2-LISTAR TODAS                         ", 10);
    PrintSquare(40, 10 , 68, 14, 10);
}






void PersistirUnaEmpresaEnArchivo (char nombreArchEmpresas[], Empresa a)
{
    FILE *buf=fopen(nombreArchEmpresas,"ab");
    Empresa e=a;
    if(buf)
    {
        fwrite(&e,sizeof(Empresa),1,buf);
        fclose(buf);
    }
    
}

NodoPalabra* PasarEmpresasDelArchivoAListaSimple (char nombreArchEmpresas[])
{
    NodoPalabra *lista;
    IniciarListaPalabras(&lista);
    
    FILE *buf=fopen(nombreArchEmpresas,"rb");
    Empresa a;
    
    if(buf)
    {
        while(fread(&a,sizeof(Empresa),1,buf)>0)
        AgregarNodoPalabraAlfabeticamente(&lista, a.nombre);
        
        fclose(buf);
    }
    
    
    return lista;
}

NodoPalabra* PasarCuitDelArchivoAListaSimple (char nombreArchEmpresas[])
{
    NodoPalabra *lista;
    IniciarListaPalabras(&lista);
    
    FILE *buf=fopen(nombreArchEmpresas,"rb");
    Empresa a;
    
    if(buf)
    {
        while(fread(&a,sizeof(Empresa),1,buf)>0)
        AgregarNodoPalabraAlfabeticamente(&lista, a.cuit);
        
        fclose(buf);
    }
    
    
    return lista;
}

void IniciarListaEmpresa(NodoEmpresa** listaEmpresas)
{
    *listaEmpresas = NULL;
}

NodoEmpresa* CrearNodoEmpresa(Empresa empresa)
{
    NodoEmpresa* aux = malloc(sizeof(NodoEmpresa));
    aux->empresa = empresa;
    aux->siguiente = NULL;
    aux->anterior = NULL;

    return aux;
}

void AgregarNodoEmpresaAlfabeticamente(NodoEmpresa** listaEmpresas, Empresa empresa)
{
    NodoEmpresa* nuevoNodo = CrearNodoEmpresa(empresa);

    if((*listaEmpresas) == NULL)
    {
        (*listaEmpresas) = nuevoNodo;
       
    }
    else 
    {
        if(strcmpi((*listaEmpresas)->empresa.nombre, empresa.nombre) > 0)
        {
            nuevoNodo->siguiente = (*listaEmpresas);
            (*listaEmpresas)->anterior = nuevoNodo;
            (*listaEmpresas) = nuevoNodo;
            
        }
        else
        {
            NodoEmpresa* seg = (*listaEmpresas)->siguiente;
            NodoEmpresa* ant = (*listaEmpresas);

            while(seg != NULL && strcmpi((*listaEmpresas)->empresa.nombre, empresa.nombre) < 0)
            {
                ant = seg;
                seg = seg->siguiente;
            }
            if(seg != NULL)
            {
                ant->siguiente = nuevoNodo;
                nuevoNodo->anterior = ant;
                nuevoNodo->siguiente = seg;
                seg->anterior = nuevoNodo;
            }
            else
            {
                ant->siguiente = nuevoNodo;
                nuevoNodo->anterior = ant;
                
                
            }
        }
    } 
}

NodoEmpresa* PasarEmpresasFullDelArchivoAListaSimple (char nombreArchEmpresas[])
{
    NodoEmpresa *lista;
    IniciarListaEmpresa(&lista);
    
    FILE *buf=fopen(nombreArchEmpresas,"rb");
    Empresa a;
    
    if(buf)
    {
        while(fread(&a,sizeof(Empresa),1,buf)>0)
        {
            AgregarNodoEmpresaAlfabeticamente(&lista, a);

        }
        
        
        fclose(buf);
    }
    
    
    return lista;
}

int buscarUnaEmpresaXCuitEnArchivoYRetornaPosicionRegistro (char nombreArchEmpresas[],char cuit[])
{
    FILE *buf=fopen(nombreArchEmpresas,"rb");
    Empresa a;
    int num=0;
    
    if(buf)
    {
        while(fread(&a,sizeof(Empresa),1,buf)>0)
        {
            if(strcmpi(a.cuit,cuit)==0)
                num= ftell(buf)/sizeof(Empresa);
        }
    fclose(buf);    
    }
    
    return num;
}



void AltaFactura(int* posicionCursor, int* tecla, NodoPalabra* listaPalabras, Registro_Factura* aux)
{
    aux->neto = 0;
    aux->iva = 0;
    aux->total = 0;

    VentanaFacturaCompra();

    while(*tecla != 27)
    {
        SetPosicionCursor(tecla, posicionCursor);

        if(*posicionCursor == P_COMPROBANTE)
        {
            PrintString(28, 8, "COMPROBANTE", 160);
            *tecla = getch();
            
            if(*tecla != 13)//ENTER
            PrintString(28, 8, "COMPROBANTE", 10);
        }
        else if(*posicionCursor == P_PROVEEDOR)
        {
            GetStringPredictivo(aux->nombre_cliente_proveedor, 50, tecla, 66, 8, 15, listaPalabras);
            GoToxy(0, 0); printf("%s", aux->nombre_cliente_proveedor);
        }
        else if(*posicionCursor == P_FECHA_EMISION)
        {
            int salir = 0;
            AltaFechaChar(&aux->fecha_emision, tecla, 128, 8, &salir);
            GoToxy(0, 1); printf("%s/%s/%s", aux->fecha_emision.dia, aux->fecha_emision.mes, aux->fecha_emision.anio);
            salir = 0;
        }
        else if(*posicionCursor == P_FECHA_CONT)
        {
            int salir = 0;
            strcpy(aux->fecha_contabilizacion.dia, aux->fecha_emision.dia); 
            strcpy(aux->fecha_contabilizacion.mes, aux->fecha_emision.mes);
            strcpy(aux->fecha_contabilizacion.anio, aux->fecha_emision.anio);

            GoToxy(128, 11); printf("%s", aux->fecha_contabilizacion.dia);
            GoToxy(131, 11); printf("%s", aux->fecha_contabilizacion.mes);
            GoToxy(134, 11); printf("%s", aux->fecha_contabilizacion.anio);

            AltaFechaChar(&aux->fecha_contabilizacion, tecla, 128, 11, &salir);
            GoToxy(0, 2); printf("%s/%s/%s", aux->fecha_contabilizacion.dia, aux->fecha_contabilizacion.mes, aux->fecha_contabilizacion.anio);
            salir = 0;
        }
        else if(*posicionCursor == P_TIPO_PVENTA)
        {
            AltaTipoNumeroFactura(&aux->tipo, aux->punto_venta, tecla, 39, 11);
            GoToxy(0, 3); printf("%c-", aux->tipo); printf("%s", aux->punto_venta);
        }
        else if(*posicionCursor == P_NUMERO_FACTURA)
        {
            AltaNumeroFactura(aux->nro_comprobante, tecla, 50, 11);
            GoToxy(0, 4); printf("%s", aux->nro_comprobante);
        }
        else if(*posicionCursor == P_NETO_21)
        {
            AltaFloats(&aux->neto, tecla, 39, 23);

            aux->iva = (aux->neto * 0.21);
            GoToxy(39, 23); printf("%.2f", aux->neto);
            GoToxy(39, 26); printf("%.2f", aux->iva);

            
            GoToxy(102, 35); printf("%.2f", aux->iva);

            

            aux->total = aux->neto + aux->iva;
            GoToxy(81, 39); printf("%.2f", aux->total);

        }
        else if(*posicionCursor == P_NO_GRAVADO)    
        {
            AltaFloats(&aux->total, tecla, 39, 29);

            aux->total = aux->neto + aux->iva;
            GoToxy(81, 39); printf("%.2f", aux->total);
        }
        else if(*posicionCursor == P_CONFIRMNAR_FACTURA)
        {
            PrintString(71, 16, "DESEA CONFIRMAR EL COMPROBANTE?", 10);
            PrintString(80 , 18, "1-SI", 160); PrintString(87, 18, "2-NO", 10);
            int posOpcion = 0;
            while(*tecla != 13)
            {
                *tecla = getch();

                if(*tecla == 50 && posOpcion == 0)
                {
                    posOpcion++;
                    PrintString(80, 18, "1-SI", 10); PrintString(87, 18, "2-NO", 160);
                }
                else if(*tecla == 49 && posOpcion == 1)
                {
                    posOpcion--;
                    PrintString(80, 18, "1-SI", 160); PrintString(87, 18, "2-NO", 10);
                }
                else if(*tecla == 13)
                {
                    if(posOpcion == 0)
                    {
                        BorrarVentanaAuxiliar();
                        ClearScreen(49, 1, 66, 8);//BORRA BARRITA PROVEEDORES
                        ClearScreen(1, 1, 39, 11); 
                        ClearScreen(5, 1, 41, 11);//BORRA BARRITA TIPO PTO VENTA
                        ClearScreen(9, 1, 50, 11);//BORRA BARRITA NUMERO DE COMPROBANTE
                        ClearScreen(43, 1, 72, 11);//BORRA DESCRIPCION

                        ClearScreen(19, 1, 39, 23);//BORRA NETO 21
                        ClearScreen(19, 1, 66, 23);//BORRA NETO 105
                        ClearScreen(19, 1, 91, 23);//BORRA NETO 27
                        ClearScreen(19, 1, 119, 23);//BORRA NETO 588

                        ClearScreen(19, 1, 39, 26);//BORRA IVA 21
                        ClearScreen(19, 1, 66, 26);//BORRA IVA 105
                        ClearScreen(19, 1, 91, 26);//BORRA IVA 27
                        ClearScreen(19, 1, 119, 26);//BORRA IVA 588

                        ClearScreen(19, 1, 39, 29);//BORRA NO GRAVADO
                        ClearScreen(19, 1, 66, 29);//BORRA EXENTO
                        ClearScreen(19, 1, 91, 29);//BORRA P_IIBB
                        ClearScreen(19, 1, 119, 29);//BORRA P_IVA

                        ClearScreen(19, 1, 39, 32);//BORRA OI1
                        ClearScreen(19, 1, 66, 32);//BORRA OI2
                        ClearScreen(19, 1, 91, 32);//BORRA OI3
                        ClearScreen(19, 1, 119, 32);//BORRA OI4

                        ClearScreen(26, 1, 49, 35);//BORRA NETO GRAVADO TOTAL
                        ClearScreen(26, 1, 102, 35);//BORRA IVA TOTAL

                        ClearScreen(29, 1, 81, 39);//BORRA TOTAL COMPROBANTE


                        


                        int dia = atoi(aux->fecha_emision.dia);



                        
                        *tecla = getch();
                    }
                }
            } 
        }   
        else if(*posicionCursor == P_SELECCIONAR_COMPROBANTE)
        {
            int opcionComprobante = 1;
            //PrintSquare(70, 6, 50, 14, 10);
            PrintString(60, 15, "1-FACTURA", 160);
            PrintString(80, 15, "2-NOTA CREDITO", 10);
            PrintString(100, 15, "3-NOTA DEBITO", 10);
            PrintString(60, 16, "4-RECIBO", 10);
            PrintString(80, 16, "5-FAC. CRED. ELEC.", 10);
            PrintString(100, 16, "6-TICKET", 10);

            *tecla = 0;
            while(*tecla != 13)
            {
                *tecla = getch();

                if(*tecla == 49)
                {
                    PrintString(60, 15, "1-FACTURA", 160);
                    PrintString(80, 15, "2-NOTA CREDITO", 10);
                    PrintString(100, 15, "3-NOTA DEBITO", 10);
                    PrintString(60, 16, "4-RECIBO", 10);
                    PrintString(80, 16, "5-FAC. CRED. ELEC.", 10);
                    PrintString(100, 16, "6-TICKET", 10);

                    opcionComprobante = 1;
                }
                else if(*tecla == 50)
                {
                    PrintString(60, 15, "1-FACTURA", 10);
                    PrintString(80, 15, "2-NOTA CREDITO", 160);
                    PrintString(100, 15, "3-NOTA DEBITO", 10);
                    PrintString(60, 16, "4-RECIBO", 10);
                    PrintString(80, 16, "5-FAC. CRED. ELEC.", 10);
                    PrintString(100, 16, "6-TICKET", 10);

                    opcionComprobante = 2;
                }
                else if(*tecla == 51)
                {
                    PrintString(60, 15, "1-FACTURA", 10);
                    PrintString(80, 15, "2-NOTA CREDITO", 10);
                    PrintString(100, 15, "3-NOTA DEBITO", 160);
                    PrintString(60, 16, "4-RECIBO", 10);
                    PrintString(80, 16, "5-FAC. CRED. ELEC.", 10);
                    PrintString(100, 16, "6-TICKET", 10);

                    opcionComprobante = 3;
                }
                else if(*tecla == 52)
                {
                    PrintString(60, 15, "1-FACTURA", 10);
                    PrintString(80, 15, "2-NOTA CREDITO", 10);
                    PrintString(100, 15, "3-NOTA DEBITO", 10);
                    PrintString(60, 16, "4-RECIBO", 160);
                    PrintString(80, 16, "5-FAC. CRED. ELEC.", 10);
                    PrintString(100, 16, "6-TICKET", 10);

                    opcionComprobante = 4;
                }
                else if(*tecla == 53)
                {
                    PrintString(60, 15, "1-FACTURA", 10);
                    PrintString(80, 15, "2-NOTA CREDITO", 10);
                    PrintString(100, 15, "3-NOTA DEBITO", 10);
                    PrintString(60, 16, "4-RECIBO", 10);
                    PrintString(80, 16, "5-FAC. CRED. ELEC.", 160);
                    PrintString(100, 16, "6-TICKET", 10);

                    opcionComprobante = 5;
                }
                else if(*tecla == 54)
                {
                    PrintString(60, 15, "1-FACTURA", 10);
                    PrintString(80, 15, "2-NOTA CREDITO", 10);
                    PrintString(100, 15, "3-NOTA DEBITO", 10);
                    PrintString(60, 16, "4-RECIBO", 10);
                    PrintString(80, 16, "5-FAC. CRED. ELEC.", 10);
                    PrintString(100, 16, "6-TICKET", 160);

                    opcionComprobante = 6;
                }
                else if(*tecla == 13)
                {
                    if(opcionComprobante == 1)
                    {
                        strcpy(aux->comprobante, "FACTURA");
                        ClearScreen(10, 1, 42, 8);
                        PrintString(42, 8, "FACTURA", 15);
                    }
                    else if(opcionComprobante == 2)
                    {
                        strcpy(aux->comprobante, "N/C");
                        ClearScreen(10, 1, 42, 8);
                        PrintString(42, 8, "N/C", 15);
                    }
                    else if(opcionComprobante == 3)
                    {
                        strcpy(aux->comprobante, "N/D");
                        PrintString(42, 8, "N/D", 15);
                    }
                    else if(opcionComprobante == 4)
                    {
                        strcpy(aux->comprobante, "RECIBO");
                        PrintString(42, 8, "RECIBO", 15);
                    }
                    else if(opcionComprobante == 5)
                    {
                        strcpy(aux->comprobante, "F.EL.CRED");
                        PrintString(42, 8, "F.EL.CRED", 15);
                    }
                    else if(opcionComprobante == 6)
                    {
                        strcpy(aux->comprobante, "TICKET");
                        PrintString(42, 8, "TICKET", 15);
                    }
                    *posicionCursor = P_COMPROBANTE;
                    *tecla = 9;
                    BorrarVentanaAuxiliar();
                }
            }
        }
    }
}



























/*CargarComprobante(*int tecla, *posicionCursor)
{
    Registro_Factura aux;

    PrintString(41, 11, )

    while()
}*/



