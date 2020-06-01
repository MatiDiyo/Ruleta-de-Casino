#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include "partidaLista.h"

enum
{
    FACIL = 1,
    MEDIO,
    DIFICIL,
};

int IngresarOpcion();
void MostrarSubmenuPartida();
void SubmenuPartida();
void MenuPrincipal();
void OpcionesMenuPrincipal();
void OpcionesApuesta();
void ApuestaSimple();
void IngresarNumeros();
void ImprimirJuego();
PARTIDA MenuApuestas(JUGADOR player, PARTIDA jugada);

#endif // MENU_H_INCLUDED
