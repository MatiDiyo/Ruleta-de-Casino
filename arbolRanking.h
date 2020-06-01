#ifndef ARBOLRANKING_H_INCLUDED
#define ARBOLRANKING_H_INCLUDED

typedef struct
{
    int puntaje;
    char nombre[30];
}SCORE;

typedef struct
{
    SCORE score;
    struct rankingArbol * der;
    struct rankingArbol * izq;
}RANKING_ARBOL;

typedef struct
{
    RANKING_ARBOL * arbol;
}CELDA;

RANKING_ARBOL * InicializarArbol();
RANKING_ARBOL * CrearNodoArbol(SCORE score);
RANKING_ARBOL * InsertarArbol(RANKING_ARBOL * arbol, SCORE score);
RANKING_ARBOL * ArchivoToArbol(char nombreArchivo[20]);
RANKING_ARBOL * ArbolToArchivo(RANKING_ARBOL * arbol, FILE * archi);
RANKING_ARBOL * MenorMayores(RANKING_ARBOL * arbol);
RANKING_ARBOL * MayorMenores(RANKING_ARBOL * arbol);
RANKING_ARBOL * BorrarNodoArbol(RANKING_ARBOL * arbol, SCORE score);
void MostrarScore(SCORE score);
void MostrarRanking(char nombreArchivo[20]);
SCORE IngresarScore(int puntaje);
void ModificarRanking(int puntaje, int dificultad);
char * AbrirRanking(int dificultad);
void ArbolToArregloArboles(CELDA celda[3]);
void MostrarInOrder(RANKING_ARBOL * arbol);
void MostrarArregloArboles(CELDA celda[3]);

#endif // ARBOLRANKING_H_INCLUDED
