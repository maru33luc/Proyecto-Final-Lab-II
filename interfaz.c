//cd desktop/vs projects/tp 2
//gcc -o tp2test main.c libreria.c

#include "graficos.h"
#include "interfaz.h"


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

    int posicionCursor = 0;
    int tecla = 0;
    Fullscreen();
    AltaFacturaCompra(&posicionCursor, &tecla, listaPalabras);

   // MenuPrincipal(&tecla, &posicionCursor); 

    system("pause");

    
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

void AltaFacturaCompra(int* posicionCursor, int* tecla, NodoPalabra* listaPalabras)
{
    Factura aux;

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
}

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

void MenuPrincipal(int* tecla, int* posicionCursor)
{
    int opcionMenuPrincipal = 0;
    int salir = 0;
    PrintSquare(40, 10 ,40, 10, 10);
    PrintString(41, 11, "1-CARGAR COMPROBANTE                     ", 160);
    PrintString(41, 12, "2-MODIFICAR COMPROBANTE                  ", 10);
    PrintString(41, 13, "3-LISTAR COMPROBANTES                    ", 10);
    PrintString(41, 14, "4-INFORMACION DE EMPRESAS                ", 10);

    while(salir == 0)
    {
        if(*tecla == 49)
        {
            ClearScreen(39, 9, 39, 9);
            CargarComprobante(tecla, posicionCursor);
        }
    }

}

CargarComprobante(*int tecla, *posicionCursor)
{
    char nombreEmpresa[50];
    char cuit[12];
    int activa_empresa;

    PrintString(41, 11, )

    while()
}



