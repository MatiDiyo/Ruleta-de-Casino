
/*********************************************************************************\
*   arbolRanking.c                                                                *
*                                                                                 *
*   Esta librer�a contine funciones de arboles, la cual maneja como informaci�n   *
*   una struct de tipo SCORE, la que contiene el nombre y el puntaje de una       *
*   partida. El proposito de esta librer�a es mantener el ranking top 10          *
*   actualizado con los mejores puntajes, cuando se habla de puntaje              *
*   se refiere al dinero ganado en una SOLA partida.                              *
*                                                                                 *
*   Asi es como trabaja esta librer�a:                                            *
*                                                                                 *
*   - Le llega desde men�.c un determinado puntaje.                               *
*   - Inserta el puntaje en el �rbol.                                             *
*   - Busca el menor puntaje y lo borra.                                          *
\*********************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "menu.h"
#include "arbolRanking.h"

/****************************************************************************
	PROPOSITO: Inicializa el arbol asignadole NULL.
	COMENTARIOS:
****************************************************************************/

RANKING_ARBOL * InicializarArbol()
{
    return NULL;
}

/****************************************************************************
	PROPOSITO: Reserva espacio en memoria para la posterior creaci�n de un
	nuevo nodo y inicializandolo con los valores recibidos por parametros.
	COMENTARIOS:
****************************************************************************/

RANKING_ARBOL * CrearNodoArbol(SCORE score)
{
    RANKING_ARBOL * aux = (RANKING_ARBOL *)malloc(sizeof(RANKING_ARBOL));

    aux->score.puntaje = score.puntaje;
    strcpy(aux->score.nombre, score.nombre);

    aux->izq = NULL;
    aux->der = NULL;

    return aux;
}

/****************************************************************************
	PROPOSITO: Inserta ordenadamente en un arbol.
	COMENTARIOS:
	- Inserta con criterio al puntaje. (score.puntaje)
	- Si es menor a la izquierda, si es mayor a la derecha.
****************************************************************************/

RANKING_ARBOL * InsertarArbol(RANKING_ARBOL * arbol, SCORE score)
{
    if(arbol == NULL)
    {
        arbol = CrearNodoArbol(score);
    }
    else
    {
        if(score.puntaje > arbol->score.puntaje)
        {
            arbol->izq = InsertarArbol(arbol->izq, score);
        }
        else
        {
            arbol->der = InsertarArbol(arbol->der, score);
        }
    }
    return arbol;
}

/****************************************************************************
	PROPOSITO: Traspasa toda la informacion del SCORE que hay en un archivo
	a un arbol.
	COMENTARIOS:
****************************************************************************/

RANKING_ARBOL * ArchivoToArbol(char nombreArchivo[20])
{
    RANKING_ARBOL * arbol = InicializarArbol();
    FILE * archi = fopen(nombreArchivo, "rb");
    SCORE score;

    if(archi == NULL)
    {
        printf("\nError al abrir el archivo\n");
    }
    else
    {
        while(fread(&score, sizeof(SCORE), 1, archi) > 0)
        {
            arbol = InsertarArbol(arbol, score);
        }

        fclose(archi);
    }

    return arbol;
}

/****************************************************************************
	PROPOSITO: Recibe un arbol y guarda el contenido de cada nodo en un archivo.
	COMENTARIOS:
	- La funci�n es recursiva, asi que las operaciones de abrir y cerrar
	se deben realizar afuera de la funci�n.
****************************************************************************/

RANKING_ARBOL * ArbolToArchivo(RANKING_ARBOL * arbol, FILE * archi)
{
    SCORE aux;

    if(arbol != NULL)
    {
        arbol->izq = ArbolToArchivo(arbol->izq, archi);
        aux = arbol->score;
        fwrite(&aux, sizeof(SCORE), 1, archi);
        arbol->der = ArbolToArchivo(arbol->der, archi);
    }

    return arbol;
}

/****************************************************************************
	PROPOSITO: Retorna el nodo menor de los mayores.
	COMENTARIOS:
****************************************************************************/

RANKING_ARBOL * MenorMayores(RANKING_ARBOL * arbol)
{
    if(arbol->izq != NULL)
    {
        arbol = MenorMayores(arbol->izq);
    }

    return arbol;
}

/****************************************************************************
	PROPOSITO: Retorna el nodo mayor de los menores.
	COMENTARIOS:
****************************************************************************/

RANKING_ARBOL * MayorMenores(RANKING_ARBOL * arbol)
{
    if(arbol->der != NULL)
    {
        arbol = MayorMenores(arbol->der);
    }

    return arbol;
}

/****************************************************************************
	PROPOSITO: Borra el nodo (si existe), buscandolo con el score enviado por
	parametros.
	COMENTARIOS:
	- Busca en criterio del puntaje (score.puntaje)
****************************************************************************/

RANKING_ARBOL * BorrarNodoArbol(RANKING_ARBOL * arbol, SCORE score)
{
    if(arbol != NULL)
    {
        if(arbol->score.puntaje == score.puntaje)
        {
            if(arbol->izq != NULL)
            {
                RANKING_ARBOL * masIzquierda = MayorMenores(arbol->izq);
                arbol->score = masIzquierda->score;
                arbol->izq = BorrarNodoArbol(arbol->izq, masIzquierda->score);
            }

            if(arbol->der != NULL)
            {
                RANKING_ARBOL * masDerecha = MenorMayores(arbol->der);
                arbol->score = masDerecha->score;
                arbol->der = BorrarNodoArbol(arbol->der, masDerecha->score);
            }

            if( (arbol->izq == NULL) && (arbol->der == NULL) )
            {
                free(arbol);
                arbol = NULL;
            }
        }
        else
        {
            if(arbol->score.puntaje < score.puntaje)
            {
                arbol->izq = BorrarNodoArbol(arbol->izq, score);
            }
            else
            {
                arbol->der = BorrarNodoArbol(arbol->der, score);
            }
        }
    }

    return arbol;
}

/****************************************************************************
	PROPOSITO: Funci�n auxiliar de Mostrar score sirve para contar los
	digitos de un n�mero.
	COMENTARIOS:
****************************************************************************/

int ContarDigitos(int num)
{
    int i = 0;

    while(num != 0)
    {
        num = num / 10;
        i++;
    }

    return i;
}

/****************************************************************************
	PROPOSITO: Muestra UNA sola variable de tipo struct SCORE.
	COMENTARIOS:
****************************************************************************/

void MostrarScore(SCORE score)
{
    printf("%c%s", 179, score.nombre);

    int i;

    for(i = 0; i < 6 - strlen(score.nombre); i++)
    {
        printf(" ");
    }

    printf("%c%i", 179, score.puntaje);

    for(i = 0; i < 7 - ContarDigitos(score.puntaje); i++)
    {
        printf(" ");
    }

    printf("%c\n", 179);
}

/****************************************************************************
	PROPOSITO: Abre el archivo y muestra un struct de tipo SCORE
	COMENTARIOS:
	- Nombre Puntaje
      XXXXXX 0
      XXXXXX 0
      XXXXXX 0
****************************************************************************/

void MostrarRanking(char nombreArchivo[])
{
    SCORE score;
    FILE * archi = fopen(nombreArchivo, "rb");

    if(archi == NULL)
    {
        printf("Error al abrir el archivo\n");
    }
    else
    {
       printf("Nombre\tPuntaje\n");
       while( fread(&score, sizeof(SCORE), 1, archi) > 0)
       {
           MostrarScore(score);
       }
       fclose(archi);
    }
}

/****************************************************************************
	PROPOSITO: Carga un nombre a la struct SCORE, el puntaje viene por
	par�metros
	COMENTARIOS:
****************************************************************************/

SCORE IngresarScore(int puntaje)
{
    SCORE score;

    do
    {
        ImprimirJuego();
        printf("\nFelicidades entraste al ranking!\n");
        printf("\nIngrese su nombre: ");
        fflush(stdin);
        scanf("%s", score.nombre);
    }while(strlen(score.nombre) > 6);

    score.puntaje = puntaje;

    return score;
}

/****************************************************************************
	PROPOSITO: Esta funci�n se encargar de interactuar con el men�, modifica
	un determinado ranking, ya sea facil, medio, dificil.
	COMENTARIOS:
****************************************************************************/

void ModificarRanking(int puntaje, int dificultad)
{
    char nombreArchivo[20];
    strcpy(nombreArchivo, AbrirRanking(dificultad));
    RANKING_ARBOL * arbol = ArchivoToArbol(nombreArchivo);

    if(puntaje > MayorMenores(arbol)->score.puntaje)
    {
        SCORE score = IngresarScore(puntaje);
        arbol = InsertarArbol(arbol, score);
        arbol = BorrarNodoArbol(arbol, MayorMenores(arbol)->score);

        FILE * archi = fopen(nombreArchivo, "wb");
        arbol = ArbolToArchivo(arbol, archi);
        fclose(archi);
    }
}

/****************************************************************************
	PROPOSITO: Retorna el nombre del archivo a abrir.
	COMENTARIOS:
****************************************************************************/

char * AbrirRanking(int dificultad)
{
    char * nombreArchivo = (char *)malloc(sizeof(char) * 20);

    switch(dificultad)
    {
        case 1: strcpy(nombreArchivo, "RankingFacil.bin"); break;
        case 2: strcpy(nombreArchivo, "RankingMedio.bin"); break;
        case 3: strcpy(nombreArchivo, "RankingDificil.bin"); break;
    }

    return nombreArchivo;
}

/****************************************************************************
	PROPOSITO: Traslada la informaci�n que hay un arbol a una posici�n determinada
	de un arreglo de arboles.
	COMENTARIOS:
****************************************************************************/

void ArbolToArregloArboles(CELDA celda[3])
{
    int i;

    for(i = 0; i < 3; i++)
    {
        celda[i].arbol = ArchivoToArbol(AbrirRanking(i + 1));
    }
}

/****************************************************************************
	PROPOSITO: Muestra "In order".
	COMENTARIOS:
****************************************************************************/

void MostrarInOrder(RANKING_ARBOL * arbol)
{
    if(arbol != NULL)
    {
        MostrarInOrder(arbol->izq);
        ImprimirFilaIntermediaRanking();
        MostrarScore(arbol->score);
        MostrarInOrder(arbol->der);
    }
}

/****************************************************************************
	PROPOSITO: Ingresa un entero y muestra un string por pantalla.
	COMENTARIOS:
****************************************************************************/

void MostrarCabeceraDificultad(int dificultad)
{
    switch(dificultad)
    {
        case FACIL: ImprimirCabecera("RANKING - TOP 10: FACIL"); break;
        case MEDIO: ImprimirCabecera("RANKING - TOP 10: MEDIO"); break;
        case DIFICIL: ImprimirCabecera("RANKING - TOP 10: DIFICIL"); break;
    }
}

/****************************************************************************
	PROPOSITO: Imprime la primer fila del cuadro del ranking.
	COMENTARIOS:
****************************************************************************/

void ImprimirFilaPrimeraRanking()
{
    int i;

    printf("%c", 218);

    for(i = 0; i < 6; i++)
    {
        printf("%c", 196);
    }

    printf("%c", 194);

    for(i = 0; i < 7; i++)
    {
        printf("%c", 196);
    }

    printf("%c\n", 191);
}

/****************************************************************************
	PROPOSITO: Imprime la fila del medio del cuadro del ranking.
	COMENTARIOS:
****************************************************************************/

void ImprimirFilaIntermediaRanking()
{
    int i;

    printf("%c", 195);

    for(i = 0; i < 6; i++)
    {
        printf("%c", 196);
    }

    printf("%c", 197);

    for(i = 0; i < 7; i++)
    {
        printf("%c", 196);
    }

    printf("%c\n", 180);
}

/****************************************************************************
	PROPOSITO: Imprime la �ltima fila del cuadro del ranking.
	COMENTARIOS:
****************************************************************************/

void ImprimirFilaUltimaRanking()
{
    int i;

    printf("%c", 192);

    for(i = 0; i < 6; i++)
    {
        printf("%c", 196);
    }

    printf("%c", 193);

    for(i = 0; i < 7; i++)
    {
        printf("%c", 196);
    }

    printf("%c\n", 217);
}

/****************************************************************************
	PROPOSITO: Muestra un arreglo de arboles.
	COMENTARIOS:
****************************************************************************/

void MostrarArregloArboles(CELDA celda[3])
{
    int i = 0;
    char tecla;

    while(tecla != 13)
    {
        MostrarCabeceraDificultad(i + 1);

        ImprimirFilaPrimeraRanking();
        printf("%cNombre%cPuntaje%c\n", 179, 179, 179);

        MostrarInOrder(celda[i].arbol);
        ImprimirFilaUltimaRanking();

        RecorrerLista(i + 1);

        gotoxy(1, 26);
        printf("\nPara salir pulse 'ENTER' ");

        tecla = getch();

        if(tecla == 77 && i != 2)
        {
            i++;
        }

        if(tecla == 75 && i != 0)
        {
            i--;
        }
    }
}
