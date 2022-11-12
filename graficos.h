#ifndef GRAFICOS_H_INCLUDED
#define GRAFICOS_H_INCLUDED


#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>





void GoToxy(int x, int y);

void ClearScreen(int width, int length, int originX, int originY);

void ClearSquare(int width, int length, int originX, int originY);

void PrintSquare(int width, int length, int originX, int originY, int color);

void PrintSolidSquare(int width, int length, int originX, int originY);

void PrintString(int originX, int originY, char* string, int colour);

void GetString(char string[], int dimension, int* tecla, int x, int y, int color);


#endif  //GRAFICOS_H_INCLUDED


