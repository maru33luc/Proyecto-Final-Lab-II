#ifndef NODODOBLEFACTURA_H_INCLUDED
#define NODODOBLEFACTURA_H_INCLUDED

typedef struct  nodoDobleFactura{
Factura dato;
struct nodoDobleFactura* sig;
struct nodoDobleFactura* ante;
}nodoDobleFactura;


nodoDobleFactura *inicListaDoble ();
nodoDobleFactura *crearNodoDoble (Factura a);
nodoDobleFactura *agregarAlPrincipioDoble (nodoDobleFactura *lista,nodoDobleFactura *nuevo);
nodoDobleFactura *buscarUltimoDoble (nodoDobleFactura *lista);
nodoDobleFactura *agregarAlFinalDoble (nodoDobleFactura *lista,nodoDobleFactura *nuevo);
void mostrarListaDoble (nodoDobleFactura *lista);
nodoDobleFactura *borrarnodoDobleFacturaXNumComprobante (nodoDobleFactura *lista,char numComprob []);
nodoDobleFactura *insertarOrdenadoDobleXNumComprob (nodoDobleFactura *lista,nodoDobleFactura *nuevo);
nodoDobleFactura *buscarFacturaDobleXNumComprob (nodoDobleFactura *lista,char numComprob[]);


#endif // NODODOBLEFACTURA_H_INCLUDED
