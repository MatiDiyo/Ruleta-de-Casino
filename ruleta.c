
/*********************************************************************************\
*   ruleta.c                                                                      *
*                                                                                 *
*   Esta librería contiene funciones visuales, para la impresión de una ruleta la *
*   cual simula el movimiento de la bola que gira adentro de la ruleta a la hora  *
*   de la elección de un número. Basicamente lo que hace, printea la ficha en una *
*   determinada posición con gotoxy y despues de un tiempo definido, vuelve a esa *
*   misma posición e imprime una espacio pisando el lugar donde estaba ficha, si  *
*   este proceso se va repitiendo e imprime la ficha en posiciones especificadas  *
*   por parámetros, como por ejemplo en forma de circulo alrededor de la ruleta,  *
*   de tal forma, se lograra el efecto que se ve en pantalla que pareciera que se *
*   esta moviendo la ficha dentro de la ruleta.                                   *
*                                                                                 *
\*********************************************************************************/

#include "ruleta.h"
#include "tablero.h"

/****************************************************************************
	PROPOSITO: Imprime la ruleta y gira la ficha adentro de la ruleta.
	COMENTARIOS:
****************************************************************************/

void DibujarRuleta(int x, int y) /// FUNCION GLOBAL
{
    color(BLANCO_VERDE);
    int i = y;

    gotoxy(x, y);
    printf("            ---------------            \n");
    y++;

    gotoxy(x, y);
    printf("         --                 --         \n");
    y++;

    gotoxy(x, y);
    printf("      ---                     ---      \n");
    y++;

    gotoxy(x, y);
    printf("    --                           --    \n");
    y++;

    gotoxy(x, y);
    printf("  --                               --  \n");
    y++;

    gotoxy(x, y);
    printf(" -                                   - \n");
    y++;

    gotoxy(x, y);
    printf("-              ..........             -\n");
    y++;

    gotoxy(x, y);
    printf("|            ..............           |\n");
    y++;

    gotoxy(x, y);
    printf("|           ......----......          |\n");
    y++;

    gotoxy(x, y);
    printf("-          ......|....|......         -\n");
    y++;

    gotoxy(x, y);
    printf("-          ......|----.......         -\n");
    y++;

    gotoxy(x, y);
    printf("-           .....|..%c.......          -\n",92);
    y++;

    gotoxy(x, y);
    printf("|           .....|...%c......          |\n",92);
    y++;

    gotoxy(x, y);
    printf("|             ............            |\n");
    y++;

    gotoxy(x, y);
    printf("-                 ....                -\n");
    y++;

    gotoxy(x, y);
    printf(" -                                   - \n");
    y++;

    gotoxy(x, y);
    printf("  --                               --  \n");
    y++;

    gotoxy(x, y);
    printf("    --                           --    \n");
    y++;

    gotoxy(x, y);
    printf("      ---                     ---      \n");
    y++;

    gotoxy(x, y);
    printf("         --                 --         \n");
    y++;

    gotoxy(x, y);
    printf("            ---------------            \n");
    y++;

    GiroFicha(x, i);
}

/****************************************************************************
	PROPOSITO: Imprime la ficha y luego de un determinado tiempo la
	borra pisandola con un espacio.
	COMENTARIOS:
****************************************************************************/

void PrintFicha(int x, int y)
{
    int i = 0;
    gotoxy(x, y);

    hidecursor(0);
    printf("%c", 207);   /// LA FICHA

    while(i < 7970000) /// TIEMPO ENTRE VUELTAS
    {
        i++;
    }

    gotoxy(x, y);
    printf(" ");
}

/****************************************************************************
	PROPOSITO: Produce la acción de girar la ficha adentro del tableor
	COMENTARIOS:
****************************************************************************/

void GiroFicha(int x, int y) /// SOLO IMPRIME LAS FICHAS
{
    int i = 0;

    while (i < 4) /// VUELTAS
    {
        PrintFicha(x + 15, y + 1);
        PrintFicha(x + 19, y + 1);
        PrintFicha(x + 23, y + 1);
        PrintFicha(x + 27, y + 2);
        PrintFicha(x + 30, y + 3);
        PrintFicha(x + 33, y + 4);
        PrintFicha(x + 35, y + 6);
        PrintFicha(x + 36, y + 8);
        PrintFicha(x + 36, y + 10);
        PrintFicha(x + 36, y + 12);
        PrintFicha(x + 35, y + 14);
        PrintFicha(x + 33, y + 15);
        PrintFicha(x + 30, y + 17);
        PrintFicha(x + 27, y + 18);
        PrintFicha(x + 23, y + 19);
        PrintFicha(x + 19, y + 19);
        PrintFicha(x + 15, y + 19);
        PrintFicha(x + 11, y + 18);
        PrintFicha(x + 8, y + 17);
        PrintFicha(x + 5, y + 15);
        PrintFicha(x + 3, y + 14);
        PrintFicha(x + 2, y + 12);
        PrintFicha(x + 2, y + 10);
        PrintFicha(x + 2, y + 8);
        PrintFicha(x + 3, y + 6);
        PrintFicha(x + 5, y + 4);
        PrintFicha(x + 8, y + 3);
        PrintFicha(x + 11, y + 2);

        i++;
    }
}
