#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "nodoSimple.h"
#include "Empresa.h"

nodoSimpleEmpresa* inicListaEmpresa()
{
    return NULL;
}

nodoSimpleEmpresa* crearNodo(Empresa e)
{
    nodoSimpleEmpresa* nn = malloc(sizeof(nodoSimpleEmpresa));
    nn->sig = NULL;
    nn->dato = e;
    return nn;
}

nodoSimpleEmpresa* agregarAlPpio(nodoSimpleEmpresa* lista,nodoSimpleEmpresa* nn)
{
    if(!lista)
    {
        lista = nn;
    }
    else
    {
        nn->sig = lista;
        lista = nn;
    }
    return lista;
}

nodoSimpleEmpresa* buscarUltimo(nodoSimpleEmpresa* lista)
{
    nodoSimpleEmpresa* aux=NULL;
    if(lista)
    {
        while(lista->sig)
        {
            lista = lista->sig;
        }
        aux = lista;
    }
    else
    {
        printf("Lista vacia...\n");
    }
    return aux;
}

nodoSimpleEmpresa* agregarAlFinal(nodoSimpleEmpresa* lista,nodoSimpleEmpresa* nn)
{
    if(!lista)
    {
        lista = nn;
    }
    else
    {
        nodoSimpleEmpresa* ultimo = buscarUltimo(lista);
        ultimo->sig = nn;
    }
    return lista;
}

nodoSimpleEmpresa* buscarXcuit(nodoSimpleEmpresa* lista,char CUIT[])
{
    nodoSimpleEmpresa* encontrado = NULL;
    if(lista)
    {
        if(strcmp(lista->dato.cuit,CUIT)==0)
        {
            encontrado = lista;
        }
        else
        {
            nodoSimpleEmpresa* seg = lista;
            while(seg && strcmp(seg->dato.cuit,CUIT)!=0)
            {
                seg = seg->sig;
            }
            if(seg)
            {
                encontrado = seg;
            }
        }
    }
    else
    {
        printf("Lista vacia...\n");
    }
    return encontrado;
}

nodoSimpleEmpresa* borrarXcuit(nodoSimpleEmpresa* lista, char CUIT[])
{
    nodoSimpleEmpresa* ante=NULL;
    nodoSimpleEmpresa* seg = NULL;;
    if(lista != NULL && strcmp(lista->dato.cuit,CUIT)==0)
    {
        nodoSimpleEmpresa* aux = lista;
        lista = lista->sig;
        free(aux);
    }
    else
    {
        seg = lista;
        while(seg != NULL && strcmp(seg->dato.cuit,CUIT)!=0)
        {
            ante = seg;
            seg = seg->sig;
        }

        if(seg != NULL)
        {
            ante->sig = seg->sig;
            free(seg);
        }
    }
    return lista;
}

void mostrarListaSimple(nodoSimpleEmpresa* lista)
{
    if(lista)
    {
        while(lista)
        {
            mostrarEmpresa(lista->dato);
            printf("-----------------\n");
            lista = lista->sig;
        }
    }
    else
    {
        printf("Lista vacia...\n");
    }
}
void testLibreriaNodoSimple()
{
    nodoSimpleEmpresa* lista;
    lista = inicListaEmpresa();

    lista = agregarAlPpio(lista,crearNodo(crearEmpresa(1,"Coca Cola","12332122329","RI",1)));
    lista = agregarAlPpio(lista,crearNodo(crearEmpresa(2,"Coca Cola","12332122329","RI",1)));
    lista = agregarAlPpio(lista,crearNodo(crearEmpresa(3,"Coca Cola","12332122329","RI",1)));
    lista = agregarAlFinal(lista,crearNodo(crearEmpresa(4,"Croco Cola","12335122329","RI",1)));

    mostrarListaSimple(lista);
    printf("Eliminando dato por cuit: Croco Cola\n");
    system("pause");
    system("cls \n");
    lista = borrarXcuit(lista,"12335122329");
    mostrarListaSimple(lista);

}
