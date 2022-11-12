#ifndef RESUMENES_H_INCLUDED
#define RESUMENES_H_INCLUDED

#include "NodoSimpleEmpresa.h"

void listarTodasFacturasXOrdenFecha (nodoSimpleEmpresa *lista);

void listarFacturasDetEmpresaXPeriodo (nodoSimpleEmpresa *lista,char cuit[],Fecha fechaInicio,Fecha fechaFinal);

int retornaSiFechaEstaComprendidaEnPeriodoDado (Fecha dato, Fecha limInf, Fecha limSup);

#endif // RESUMENES_H_INCLUDED
