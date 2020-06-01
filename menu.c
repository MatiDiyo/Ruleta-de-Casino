#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <conio.h>

#include "arbolRanking.h"
#include "partidaLista.h"
#include "menu.h"
#include "tablero.h"
#include "ruleta.h"
#include "gotoxy.h"

/****************************************************************************
	PROPOSITO: Centra el string que va ir adentro de la cabecera.
	COMENTARIOS:
****************************************************************************/

void CentrarCabecera(char cabecera[30])
{
    int i, x = ((50 - strlen(cabecera)) / 2);

    printf("%c", 186);
    gotoxy(x, 1);
    printf("%s", cabecera);

    if(strlen(cabecera) % 2 == 0)
    {
        x++;
    }
    else
    {
        x += 2;
    }

    for(i = 0;i < x;i++)
    {
        printf(" ");
    }

    printf("%c\n", 186);
}

/****************************************************************************
	PROPOSITO: Imprime una cabecera la cual tiene una longitud de 50.
	COMENTARIOS:
****************************************************************************/


void ImprimirCabecera(char cabecera[30])
{
    system("cls");
    int i;
    printf("%c", 201);
    for(i = 0;i < 50; i++)
    {
        printf("%c", 205);
    }
    printf("%c\n", 187);
    CentrarCabecera(cabecera);
    printf("%c", 200);
    for(i = 0;i < 50; i++)
    {
        printf("%c", 205);
    }
    printf("%c", 188);

    printf("\n\n");
}

/****************************************************************************
	PROPOSITO: Le pide al usuario una opción.
	COMENTARIOS:
****************************************************************************/

int IngresarOpcion()
{
    int opcion;
    printf("\nIngrese una opci%cn: ", 162);
    fflush(stdin);
    scanf("%i", &opcion);
    return opcion;
}

/****************************************************************************
	PROPOSITO: Imprime las opciones del menú principal.
	COMENTARIOS:
****************************************************************************/

void MenuPrincipal()
{
    ImprimirCabecera("RULETA");
    printf("1. Jugar");
    printf("\n2. Ranking");
    printf("\n3. Informaci%cn", 162);
    printf("\n0. Salir\n");
}

/****************************************************************************
	PROPOSITO: Función madre del programa la cual de estas funciones
	desembocan las demas.
	COMENTARIOS:
****************************************************************************/

void OpcionesMenuPrincipal()
{
    system("mode con: cols=52 lines=33");

    color(BLANCO_VERDE);
    SetConsoleTitle("Juego de Ruleta");
    MenuPrincipal();
    int opcion;
    do
    {
        opcion = IngresarOpcion();

        switch(opcion)
        {
            case 0:
                printf("\nSaliendo del sistema...\n");
                exit(EXIT_SUCCESS);
                break;
            case 1:
                JugarPartida();
                break;
            case 2:
                ImprimirCabecera("RANKING - TOP 10");
                CELDA celda[3];
                ArbolToArregloArboles(celda);
                MostrarArregloArboles(celda);
                printf("\nVolviendo al men%c principal...\n", 163);
                system("pause");
                OpcionesMenuPrincipal();
                break;
            case 3:
                ImprimirCabecera("INFORMACION");
                OpcionesInformacion();
                printf("\nVolviendo al men%c principal...\n", 163);
                system("pause");
                OpcionesMenuPrincipal();
                break;
            default:
                printf("Opcion incorrecta!\n");
        }
    }while(opcion != 0);
}

void OpcionesApuesta()
{
    int opc = IngresarOpcion();

    switch(opc)
    {
        case 1: JugarPartida(); break;
        default: OpcionesMenuPrincipal();
    }
}

/****************************************************************************
	PROPOSITO: Muestra un archivo de texto.
	COMENTARIOS:
****************************************************************************/

void MostrarArchivoTexto(char nombreArchivo[])
{
    FILE * archi = fopen(nombreArchivo, "r");
    char caracter;

    if(archi == NULL)
    {
        printf("\nEl archivo no pudo ser abierto.\n");
    }
    else
    {
        while((caracter = fgetc(archi)) != EOF)
        {
            printf("%c", caracter);
        }
    }

    printf("\n");

    fclose(archi);
}

/****************************************************************************
	PROPOSITO: Opciones del submenú de información.
	COMENTARIOS:
****************************************************************************/

void OpcionesInformacion()
{
    printf("1. Reglas");
    printf("\n2. Probabilidades");
    printf("\n0. Salir\n");

    int opc = IngresarOpcion();

    switch(opc)
    {
        case 1:
            system("mode con: cols=71 lines=33");
            ImprimirCabecera("REGLAS");
            MostrarArchivoTexto("reglas.txt");
            break;
        case 2:
            ImprimirCabecera("PROBABILIDADES");
            MostrarArchivoTexto("probabilidad.txt");
            break;
        default: OpcionesMenuPrincipal();
    }
}
