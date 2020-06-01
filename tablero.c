
/*********************************************************************************\
*   tablero.c                                                                     *
*                                                                                 *
*   Esta librería contiene funciones visuales, para la impresión del tablero      *
*   del juego, en donde cada funciones represanta una fila del tablero o un borde *
*   del tablero (las funciones que tiene el guión bajo al principio del nombre de *
*   la función). Estas funciones pequeñas van a ser invocadas por una función     *
*   madre, ImprimirTablero(), la cual imprime el tablero tal cual lo vemos        *
*   en el programa.                                                               *
*                                                                                 *
\*********************************************************************************/

#include <stdio.h>

#include "tablero.h"

void _ImprimirBordeSuperior()
{
    int i;

    color(BLANCO_VERDE);
    printf("%c", 218);

    for(i = 0; i < 13; i++)
    {
        if(i < 4)
        {
            printf("%c%c", 196, 194);
        }
        else
        {
            printf("%c%c%c", 196, 196, 194);
        }

    }

    printf("%c%c%c", 196, 196, 196);

    color(BLANCO_VERDE);
    printf("%c\n", 191);
}

void _ImprimirPrimerFila()
{
    int i;

    color(BLANCO_VERDE);
    printf("%c %c", 179, 179);

    for(i = 3; i <= 36; i += 3)
    {
        switch(i)
        {
            case 3: color(ROJO_VERDE); printf("%i", i); break;
            case 6: color(NEGRO_VERDE); printf("%i", i); break;
            case 9: color(ROJO_VERDE); printf("%i", i); break;
            case 12: color(ROJO_VERDE); printf("%i", i); break;
            case 15: color(NEGRO_VERDE); printf("%i", i); break;
            case 18: color(ROJO_VERDE); printf("%i", i); break;
            case 21: color(ROJO_VERDE); printf("%i", i); break;
            case 24: color(NEGRO_VERDE); printf("%i", i); break;
            case 27: color(ROJO_VERDE); printf("%i", i); break;
            case 30: color(ROJO_VERDE); printf("%i", i); break;
            case 33: color(NEGRO_VERDE); printf("%i", i); break;
            case 36: color(ROJO_VERDE); printf("%i", i); break;
        }

        color(BLANCO_VERDE);
        printf("%c", 179);
    }

    printf("2-1%c\n", 179);
}

void _ImprimirBordeMedio()
{
    int i;

    printf("%c %c", 179, 195);

    for(i = 0; i < 12; i++)
    {
        if(i < 3)
        {
            printf("%c%c", 196, 197);
        }
        else
        {
            printf("%c%c%c", 196, 196, 197);
        }

    }

    printf("%c%c%c%c\n", 196, 196, 196, 180);
}

void _ImprimirSegundaFila()
{
    int i;

    color(BLANCO_VERDE);
    printf("%c0%c", 179, 179);

    for(i = 2; i <= 35; i += 3)
    {
        switch(i)
        {
            case 2: color(NEGRO_VERDE); printf("%i", i); break;
            case 5: color(ROJO_VERDE); printf("%i", i); break;
            case 8: color(NEGRO_VERDE); printf("%i", i); break;
            case 11: color(NEGRO_VERDE); printf("%i", i); break;
            case 14: color(ROJO_VERDE); printf("%i", i); break;
            case 17: color(NEGRO_VERDE); printf("%i", i); break;
            case 20: color(NEGRO_VERDE); printf("%i", i); break;
            case 23: color(ROJO_VERDE); printf("%i", i); break;
            case 26: color(NEGRO_VERDE); printf("%i", i); break;
            case 29: color(NEGRO_VERDE); printf("%i", i); break;
            case 32: color(ROJO_VERDE); printf("%i", i); break;
            case 35: color(NEGRO_VERDE); printf("%i", i); break;
        }

        color(BLANCO_VERDE);
        printf("%c", 179);
    }

    printf("2-1%c\n", 179);
}

void _ImprimirTercerFila()
{
    int i;

    color(BLANCO_VERDE);
    printf("%c %c", 179, 179);

    for(i = 1; i <= 34; i += 3)
    {
        switch(i)
        {
            case 1: color(ROJO_VERDE); printf("%i", i); break;
            case 4: color(NEGRO_VERDE); printf("%i", i); break;
            case 7: color(ROJO_VERDE); printf("%i", i); break;
            case 10: color(NEGRO_VERDE); printf("%i", i); break;
            case 13: color(NEGRO_VERDE); printf("%i", i); break;
            case 16: color(ROJO_VERDE); printf("%i", i); break;
            case 19: color(ROJO_VERDE); printf("%i", i); break;
            case 22: color(NEGRO_VERDE); printf("%i", i); break;
            case 25: color(ROJO_VERDE); printf("%i", i); break;
            case 28: color(NEGRO_VERDE); printf("%i", i); break;
            case 31: color(NEGRO_VERDE); printf("%i", i); break;
            case 34: color(ROJO_VERDE); printf("%i", i); break;
        }

        color(BLANCO_VERDE);
        printf("%c", 179);
    }

    printf("2-1%c\n", 179);
}

void _ImprimirBordeInferiorTercerFila()
{
    int i;

    printf("%c%c%c", 192, 196, 197);

    for(i = 0; i < 12; i++)
    {
        if(i < 3)
        {
            printf("%c%c", 196, 193);
        }
        else
        {
            switch(i)
            {
                case 4: printf("%c%c%c", 196, 196, 197); break;
                case 7: printf("%c%c%c", 196, 196, 197); break;
                case 11: printf("%c%c%c", 196, 196, 197); break;
                default: printf("%c%c%c", 196, 196, 193);
            }
        }

    }

    printf("%c%c%c%c\n", 196, 196, 196, 217);
}

void _ImprimirCuartaFila()
{
    printf("  %c   1a 12   %c 2a 12  %c   3a 12   %c    \n", 179, 179, 179, 179, 179);
}

void _ImprimirBordeInferiorCuartaFila()
{
    int i;

    printf("  %c", 195);

    for(i = 0; i < 32; i++)
    {
        switch(i)
        {
            case 8: printf("%c", 194); break;
            case 11: printf("%c", 197); break;
            case 14: printf("%c", 194); break;
            case 17: printf("%c", 194); break;
            case 20: printf("%c", 197); break;
            case 23: printf("%c", 194); break;
            default: printf("%c", 196);
        }
    }

    printf("%c    \n", 180);
}

void _ImprimirQuintaFila()
{
    printf("  %c 1 a 18 %cPa", 179, 179);

    printf("%c", 179);

    color(ROJO_VERDE);
    printf("%c%c", 254, 254);

    color(BLANCO_VERDE);
    printf("%c  %c", 179, 179);

    color(NEGRO_VERDE);
    printf("%c%c", 254, 254);

    color(BLANCO_VERDE);
    printf("%c", 179);

    printf("Im%c 19 a 36%c    \n", 179, 179);
}

void _ImprimirBordeInferior()
{
    int i;

    printf("  %c", 192);

    for(i = 0; i < 32; i++)
    {
        switch(i)
        {
            case 8: printf("%c", 193); break;
            case 11: printf("%c", 193); break;
            case 14: printf("%c", 193); break;
            case 17: printf("%c", 193); break;
            case 20: printf("%c", 193); break;
            case 23: printf("%c", 193); break;
            default: printf("%c", 196);
        }
    }

    printf("%c    \n", 217);
}

/****************************************************************************
	PROPOSITO: Ensambla todas las piezas (todas las filas y los bordes).
	Armando el tablero completo.
	COMENTARIOS:
****************************************************************************/

void ImprimirTablero()
{
    _ImprimirBordeSuperior();
    _ImprimirPrimerFila();
    _ImprimirBordeMedio();
    _ImprimirSegundaFila();
    _ImprimirBordeMedio();
    _ImprimirTercerFila();
    _ImprimirBordeInferiorTercerFila();
    _ImprimirCuartaFila();
    _ImprimirBordeInferiorCuartaFila();
    _ImprimirQuintaFila();
    _ImprimirBordeInferior();
}


