#ifndef NODOSIMPLECP_H_INCLUDED
#define NODOSIMPLECP_H_INCLUDED






typedef struct nodoSimpleCP{
Cliente_Proveedor dato_cp;
struct nodoDobleFactura* fact;
struct nodoSimpleCP* sig;
}nodoSimpleCP;

nodoSimpleCP* inicListaSimpleCP();
nodoSimpleCP* crearNodoSimpleCP(Cliente_Proveedor CP);
nodoSimpleCP* agregarNodoAlPrincipioSimpleCP(nodoSimpleCP* lista, nodoSimpleCP* nuevoNodo);
nodoSimpleCP* buscarUltimoSimpleCP(nodoSimpleCP* lista);
nodoSimpleCP* buscarNodoXCuitSimpleCP(nodoSimpleCP* lista,char cuit[]);
nodoSimpleCP* agregarNodoAlFinalSimpleCP(nodoSimpleCP* lista,nodoSimpleCP* nuevoNodo);
nodoSimpleCP* borrarXCuitSimpleCP(nodoSimpleCP* lista, char cuit[]);
void mostrarListaSimpleCP(nodoSimpleCP* lista);



#endif // NODOSIMPLECP_H_INCLUDED
