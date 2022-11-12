#include "graficos.h"



void GoToxy(int x, int y)
{
    HANDLE ventana;
    ventana = GetStdHandle(STD_OUTPUT_HANDLE);

    COORD coordenadas;
    coordenadas.X = x;
    coordenadas.Y = y;

    SetConsoleCursorPosition(ventana, coordenadas);

}



///////////////////////////////////////////////////////////////////////////////////////////

void PrintSquare(int width, int length, int originX, int originY, int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color); 

    int i = 0;

    GoToxy(originX, originY);

    while(i <= width)  /*Print Horizontal Lines*/
    {
        while(i <= width)
        {
            printf("%c", 196);
            i++;
        }

        i = 0;

        GoToxy(originX, originY + length);

        while(i <= width)
        {
            printf("%c", 196);
            i++;
        }
    }

    i = 1;

    GoToxy(originX, originY);  /*Print Left Top Vertice*/
    printf("%c", 218);

    while(i < length)  /*Print Vertical Lines*/
    {
        GoToxy(originX, originY + i);
        printf("%c", 179);
        i++;
    }

    GoToxy(originX, originY + length);  /*Print Left Bot Vertice*/
    printf("%c", 192);

    GoToxy(originX + width, originY);  /*Print Top Right Vertice*/
    printf("%c", 191);

    i = 1;

    while(i < length)
    {
        GoToxy(originX + width, originY + i);
        printf("%c", 179);
        i++;
    }

    GoToxy(originX + width, originY + length);  /*Printf Right Down Vertice*/
    printf("%c", 217);

    
}

//////////////////////////////////////////////////////////////////////////////////////////////

void PrintSolidSquare(int width, int length, int originX, int originY)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);

    int i = 0;
    int j = 0;

    while(i < length)
    {
        while(j < width)
        {
            GoToxy(originX + j, originY + i);
            printf("%c", 219);
            j++;
        }
        j = 0;
        i++;

    }
}

///////////////////////////////////////////////////////////////////////////////////////////



void ClearScreen(int width, int length, int originX, int originY)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);

    int i = 0;
    int j = 0;

    while(i < length)
    {
        while(j < width)
        {
            GoToxy(originX + j, originY + i);
            printf("%c", 255);
            j++;
        }
        j = 0;
        i++;

    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////


void PrintString(int originX, int originY, char* string, int colour)
{
    
    GoToxy(originX, originY);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colour);
    puts(string);
    
    
}


////////////////////////////////////////////////////////////////////////////////////////////////


void ClearSquare(int width, int length, int originX, int originY)
{

    ClearScreen(width + 1, 1, originX, originY);
    ClearScreen(width + 1, 1, originX, originY + length);
    ClearScreen(1, length + 1, originX, originY);
    ClearScreen(1, length + 1, originX + width, originY);

}

////////////////////////////////////////////////////////////////////////////////////////////////////


void GetString(char string[], int dimension, int* tecla, int x, int y, int color)
{
    
    int i = 0;
    int posicionXCursor = x;
    GoToxy(x, y);

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
    
    
    while(*tecla != 27)
    {
        *tecla = getch();
        if((*tecla >= 65 && *tecla <= 122) || (*tecla == 32) || (*tecla >= 48 && *tecla <= 57))
        {
            if(i < dimension)
            {
                string[i] = *tecla;
                printf("%c", string[i]);
                i++;
                posicionXCursor++;
            }
            

        }
        else if(*tecla == 13)//ENTER
        {
            break;
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
        }
    }
}    



 