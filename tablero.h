#ifndef TABLERO_H_INCLUDED
#define TABLERO_H_INCLUDED

void _ImprimirBordeSuperior();
void _ImprimirBordeMedio();
void _ImprimirSegundaFila();
void _ImprimirTercerFila();
void _ImprimirBordeInferiorTercerFila();
void _ImprimirCuartaFila();
void _ImprimirBordeInferiorCuartaFila();
void _ImprimirQuintaFila();
void _ImprimirBordeInferior();

void ImprimirTablero();

/// FUENTE_FONDO
enum COLORES
{
    NEGRO_VERDE = 32,
    ROJO_VERDE = 44,
    BLANCO_VERDE = 47,
};

#endif // TABLERO_H_INCLUDED
