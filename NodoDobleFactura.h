#ifndef NODODOBLEFACTURA_H_INCLUDED
#define NODODOBLEFACTURA_H_INCLUDED

typedef struct NodoDobleFactura
{
    Factura dato;
    struct NodoDobleFactura *ant;
    struct NodoDobleFactura * sig;
} NodoDobleFactura;

NodoDobleFactura *inicListaDoble ();
NodoDobleFactura *crearNodoDoble (Factura a);
NodoDobleFactura *agregarAlPrincipioDoble (NodoDobleFactura *lista,NodoDobleFactura *nuevo);
NodoDobleFactura *buscarUltimoDoble (NodoDobleFactura *lista);
NodoDobleFactura *agregarAlFinalDoble (NodoDobleFactura *lista,NodoDobleFactura *nuevo);
void mostrarListaDoble (NodoDobleFactura *lista);
NodoDobleFactura *borrarNodoDobleFacturaXNumComprobante (NodoDobleFactura *lista,char numComprob []);
NodoDobleFactura *insertarOrdenadoDobleXNumComprob (NodoDobleFactura *lista,NodoDobleFactura *nuevo);
NodoDobleFactura *buscarFacturaDobleXNumComprob (NodoDobleFactura *lista,char numComprob[]);


#endif // NODODOBLEFACTURA_H_INCLUDED
