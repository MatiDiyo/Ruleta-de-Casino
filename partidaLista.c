
/*********************************************************************************\
*   partidaLista.c                                                                *
*                                                                                 *
*   Esta librería contiene funciones del manejo de PARTIDA y JUGADOR, la cual     *
*   son dos estructuras que estan muy relacionas entre si y es imposible          *
*   separarlas. El proposito de esta librería es poder jugar una partida completa *
*   de ruleta con todas sus variables posibles, donde cada función de esta        *
*   librería le proporcionara los datos necesarios para completar con información *
*   valida todos los campos de ambas estructuras tanto para la struct PARTIDA,    *
*   como para la struct JUGADOR.                                                  *
*                                                                                 *
\*********************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "partidaLista.h"
#include "menu.h"
#include "tablero.h"

/****************************************************************************
	PROPOSITO: Borra la pantalla, imprime cabecera e imprime tablero.
	COMENTARIOS:
****************************************************************************/

void ImprimirJuego()
{
    system("cls");
    ImprimirCabecera("PARTIDA DE RULETA");
    ImprimirTablero();
}

/****************************************************************************
	PROPOSITO: Le pide al usuario una dificultad.
	COMENTARIOS:
****************************************************************************/

PARTIDA IngresarDificultad(PARTIDA jugada)
{
    do
    {
        ImprimirJuego();
        printf("\nPresione 0 (CERO) seguido de 'enter' \nsi desea volver al menu principal\n");
        printf("\n1.FACIL (MONTO = 5000)\n2.MEDIO (MONTO = 2500)\n3.DIFICIL (MONTO = 1000)\n0.CANCELAR APUESTA\n");
        printf("\nIngrese dificultad: ");
        fflush(stdin);
        scanf("%i", &jugada.dificultad);
    }while(jugada.dificultad < 0 || jugada.dificultad > 3);

    return jugada;
}

/****************************************************************************
	PROPOSITO: Setea el monto según la dificultad
	COMENTARIOS:
****************************************************************************/

JUGADOR InicializarMonto(JUGADOR player, PARTIDA jugada)
{
    switch(jugada.dificultad)
    {
        case 1: player.monto = 5000; break;
        case 2: player.monto = 2500; break;
        case 3: player.monto = 1000; break;
    }

    return player;
}

/****************************************************************************
	PROPOSITO: El usuario ingresa el dinero que le apetece, que se encuentre
	entre 0 y el monto del jugador.
	COMENTARIOS:
****************************************************************************/

PARTIDA RealizarApuestaPartida(PARTIDA jugada, JUGADOR player)
{
    do
    {
        ImprimirJuego();
        printf("\nPresione 0 (CERO) seguido de 'enter' \nsi desea volver al menu principal\n");
        printf("\nHaga su apuesta (Monto disponible: %i): ", player.monto);
        fflush(stdin);
        scanf("%i", &jugada.dineroApostado);
    }while(jugada.dineroApostado < 0 || jugada.dineroApostado > player.monto);

    return jugada;
}

/****************************************************************************
	PROPOSITO: Muestra los tipos de apuesta.
	COMENTARIOS:
****************************************************************************/

void MostrarTiposApuesta()
{
     printf("\n1.APOSTAR A UN NUMERO");
     printf("\n2.PRIMER DOCENA(1-12)");
     printf("\n2.PRIMER DOCENA(1-12)");
     printf("\n3.SEGUNDA DOCENA(13-24)");
     printf("\n4.TERCER DOCENA(25-36)");
     printf("\n5.FALTA(1-18)");
     printf("\n6.PASA(19-36)");
     printf("\n7.ROJO");
     printf("\n8.NEGRO");
     printf("\n9.PAR");
     printf("\n10.IMPAR");
     printf("\n0.CANCELAR APUESTA\n");
}

/****************************************************************************
	PROPOSITO: El usuario elige alguna de las opciones de apuesta.
	COMENTARIOS:
****************************************************************************/

PARTIDA EligirApuesta(PARTIDA jugada)
{
    do
    {
        ImprimirJuego();
        MostrarTiposApuesta();
        jugada.tipo = IngresarOpcion();
    }while(jugada.tipo < 0 || jugada.tipo > 10);

    return jugada;
}

/****************************************************************************
	PROPOSITO: Vuelve al menú principal.
	COMENTARIOS:
****************************************************************************/

void VolverMenuPrincipal(int num)
{
     if(num == 0)
     {
         OpcionesMenuPrincipal();
     }
}

/****************************************************************************
	PROPOSITO: Le pide al usuario un número, comprendido entre 0 y 36.
	y coloca el tipo de jugada en SIMPLE.
	COMENTARIOS:
****************************************************************************/

PARTIDA IngresarSimple(PARTIDA jugada)
{
    do
    {
        ImprimirJuego();
        printf("\nIngrese un numero (0-36): ");
        fflush(stdin);
        scanf("%i", &jugada.numeroElegido);
    }while( (jugada.numeroElegido < 0) || (jugada.numeroElegido > 36) );

    jugada.tipo = SIMPLE;

    return jugada;
}

/****************************************************************************
	PROPOSITO: Coloca el tipo de jugada en PRIMER_DOCENA.
	COMENTARIOS:
****************************************************************************/

PARTIDA IngresarPrimerDocena(PARTIDA jugada)
{
    jugada.tipo = PRIMER_DOCENA;
    return jugada;
}

/****************************************************************************
	PROPOSITO: Coloca el tipo de jugada en SEGUNDA_DOCENA.
	COMENTARIOS:
****************************************************************************/

PARTIDA IngresarSegundaDocena(PARTIDA jugada)
{
    jugada.tipo = SEGUNDA_DOCENA;
    return jugada;
}

/****************************************************************************
	PROPOSITO: Coloca el tipo de jugada en TERCER_DOCENA.
	COMENTARIOS:
****************************************************************************/

PARTIDA IngresarTercerDocena(PARTIDA jugada)
{
    jugada.tipo = TERCER_DOCENA;
    return jugada;
}

/****************************************************************************
	PROPOSITO: Coloca el tipo de jugada en FALTA.
	COMENTARIOS:
****************************************************************************/

PARTIDA IngresarFalta(PARTIDA jugada)
{
    jugada.tipo = FALTA;
    return jugada;
}

/****************************************************************************
	PROPOSITO: Coloca el tipo de jugada en PASA.
	COMENTARIOS:
****************************************************************************/

PARTIDA IngresarPasa(PARTIDA jugada)
{
    jugada.tipo = PASA;
    return jugada;
}

/****************************************************************************
	PROPOSITO: Coloca el tipo de jugada en PAR.
	COMENTARIOS:
****************************************************************************/

PARTIDA IngresarPar(PARTIDA jugada)
{
    jugada.tipo = PAR;
    return jugada;
}

/****************************************************************************
	PROPOSITO: Coloca el tipo de jugada en IMPAR.
	COMENTARIOS:
****************************************************************************/

PARTIDA IngresarImpar(PARTIDA jugada)
{
    jugada.tipo = IMPAR;
    return jugada;
}

/****************************************************************************
	PROPOSITO: Coloca el tipo de jugada en ROJO.
	COMENTARIOS:
****************************************************************************/

PARTIDA IngresarRojo(PARTIDA jugada)
{
    jugada.tipo = 6;
    return jugada;
}

/****************************************************************************
	PROPOSITO: Coloca el tipo de jugada en NEGRO.
	COMENTARIOS:
****************************************************************************/

PARTIDA IngresarNegro(PARTIDA jugada)
{
    jugada.tipo = NEGRO;
    return jugada;
}

/****************************************************************************
	PROPOSITO: Según la opción que le venga por parámetros colocara el
	tipo de apuesta que sea.
	COMENTARIOS:
****************************************************************************/

PARTIDA InicializarTipoApuesta(PARTIDA jugada, int opc)
{
    switch(opc)
    {
        case 0: OpcionesMenuPrincipal(); break;
        case 1: jugada = IngresarSimple(jugada); break;
        case 2: jugada = IngresarPrimerDocena(jugada); break;
        case 3: jugada = IngresarSegundaDocena(jugada); break;
        case 4: jugada = IngresarTercerDocena(jugada); break;
        case 5: jugada = IngresarFalta(jugada); break;
        case 6: jugada = IngresarPasa(jugada); break;
        case 7: jugada = IngresarRojo(jugada); break;
        case 8: jugada = IngresarNegro(jugada); break;
        case 9: jugada = IngresarPar(jugada); break;
        case 10: jugada = IngresarImpar(jugada); break;
        default: OpcionesApuesta();
    }

    return jugada;
}

/****************************************************************************
	PROPOSITO: Retorna un número pseudo random entre 0 a 36.
	COMENTARIOS:
****************************************************************************/

PARTIDA NumeroRandom(PARTIDA jugada)
{
    srand(time(NULL));
    jugada.numeroGanador = rand() % 36;

    return jugada;
}

/****************************************************************************
	PROPOSITO: Muestra el número random que retorno la funcion NumeroRandom().
	COMENTARIOS:
****************************************************************************/

void MostrarNumeroGanador(PARTIDA jugada)
{
    printf("\nNumero ganador: %i ", jugada.numeroGanador);

    if(jugada.tipo == NEGRO)
    {
        color(NEGRO_VERDE);
        printf("NEGRO\n");
        color(BLANCO_VERDE);
    }
    else if(jugada.numeroGanador == 0)
    {
        printf("VERDE\n");
    }
    else
    {
        color(ROJO_VERDE);
        printf("ROJO\n");
        color(BLANCO_VERDE);
    }
}

void MostrarMontoActual(JUGADOR player)
{
    printf("\nEl monto actual: %i", player.monto);
}

void MostrarResultadoPartida(PARTIDA jugada, JUGADOR player)
{
    MostrarPartida(jugada);
    MostrarMontoActual(player);

}

/****************************************************************************
	PROPOSITO: Retorna flag 1, si el número ganador se encuentra entre 1 y 18.
	COMENTARIOS:
****************************************************************************/

PARTIDA VerificarFalta(PARTIDA jugada)
{
    if(jugada.numeroGanador >= 1 && jugada.numeroGanador <= 18)
    {
        jugada.victoria = 1;
    }

    return jugada;
}

/****************************************************************************
	PROPOSITO: Retorna flag 1, si el número ganador se encuentra entre 19 y 36.
	COMENTARIOS:
****************************************************************************/

PARTIDA VerificarPasa(PARTIDA jugada)
{
    if(jugada.numeroGanador >= 19 && jugada.numeroGanador <= 36)
    {
        jugada.victoria = 1;
    }

    return jugada;
}

/****************************************************************************
	PROPOSITO: Retorna flag 1, si el número ganador es par y NO es 0.
	COMENTARIOS:
	- El número 0 no pertenece a ningún tipo de apuesta, es un número independiente.
****************************************************************************/

PARTIDA VerificarPar(PARTIDA jugada)
{
    if(jugada.numeroGanador % 2 == 0 && jugada.numeroGanador != 0)
    {
        jugada.victoria = 1;
    }

    return jugada;
}

/****************************************************************************
	PROPOSITO: Retorna flag 1, si el número ganador es impar.
	COMENTARIOS:
****************************************************************************/

PARTIDA VerificarImpar(PARTIDA jugada)
{
    if(jugada.numeroGanador % 2 == 1)
    {
        jugada.victoria = 1;
    }

    return jugada;
}

/****************************************************************************
	PROPOSITO: Retorna flag 1, si el número ganador se encuentra entre 1 y 12.
	COMENTARIOS:
****************************************************************************/

PARTIDA VerificarPrimerDocena(PARTIDA jugada)
{
    if(jugada.numeroGanador >= 1 && jugada.numeroGanador <= 12)
    {
        jugada.victoria = 1;
    }

    return jugada;
}

/****************************************************************************
	PROPOSITO: Retorna flag 1, si el número ganador se encuentra entre 13 y 24.
	COMENTARIOS:
****************************************************************************/

PARTIDA VerificarSegundaDocena(PARTIDA jugada)
{
    if(jugada.numeroGanador >= 13 && jugada.numeroGanador <= 24)
    {
        jugada.victoria = 1;
    }

    return jugada;
}

/****************************************************************************
	PROPOSITO: Retorna flag 1, si el número ganador se encuentra entre 25 y 36.
	COMENTARIOS:
****************************************************************************/

PARTIDA VerificarTercerDocena(PARTIDA jugada)
{
    if(jugada.numeroGanador >= 25 && jugada.numeroGanador <= 36)
    {
        jugada.victoria = 1;
    }

    return jugada;
}

/****************************************************************************
	PROPOSITO: Retorna flag 1, si el número ganador es rojo.
	COMENTARIOS:
	- Los números rojos son: 1,3,5,7,9,12,14,16,18,19,21,23,25,27,30,32,34,36
****************************************************************************/

PARTIDA VerificarRojo(PARTIDA jugada)
{
    switch(jugada.numeroGanador)
    {
        case 1: jugada.victoria = 1; break;
        case 3: jugada.victoria = 1; break;
        case 5: jugada.victoria = 1; break;
        case 7: jugada.victoria = 1; break;
        case 9: jugada.victoria = 1; break;
        case 12: jugada.victoria = 1; break;
        case 14: jugada.victoria = 1; break;
        case 16: jugada.victoria = 1; break;
        case 18: jugada.victoria = 1; break;
        case 19: jugada.victoria = 1; break;
        case 21: jugada.victoria = 1; break;
        case 23: jugada.victoria = 1; break;
        case 25: jugada.victoria = 1; break;
        case 27: jugada.victoria = 1; break;
        case 30: jugada.victoria = 1; break;
        case 32: jugada.victoria = 1; break;
        case 34: jugada.victoria = 1; break;
        case 36: jugada.victoria = 1; break;
    }

    return jugada;
}

/****************************************************************************
	PROPOSITO: Retorna flag 1, si el número ganador es negro.
	COMENTARIOS:
	- Los números negros son: 2,4,6,8,10,11,13,15,17,20,22,24,26,28,29,31,33,35
****************************************************************************/

PARTIDA VerificarNegro(PARTIDA jugada)
{
    switch(jugada.numeroGanador)
    {
        case 2: jugada.victoria = 1; break;
        case 4: jugada.victoria = 1; break;
        case 6: jugada.victoria = 1; break;
        case 8: jugada.victoria = 1; break;
        case 10: jugada.victoria = 1; break;
        case 11: jugada.victoria = 1; break;
        case 13: jugada.victoria = 1; break;
        case 15: jugada.victoria = 1; break;
        case 17: jugada.victoria = 1; break;
        case 20: jugada.victoria = 1; break;
        case 22: jugada.victoria = 1; break;
        case 24: jugada.victoria = 1; break;
        case 26: jugada.victoria = 1; break;
        case 28: jugada.victoria = 1; break;
        case 29: jugada.victoria = 1; break;
        case 31: jugada.victoria = 1; break;
        case 33: jugada.victoria = 1; break;
        case 35: jugada.victoria = 1; break;
    }

    return jugada;
}

/****************************************************************************
	PROPOSITO: Retorna flag 1, si el número enviado por parametros coincide
	con el tipo de jugada y el número ganador.
	COMENTARIOS:
****************************************************************************/

PARTIDA VerificarPartida(PARTIDA jugada)
{
    jugada.victoria = 0;

    switch(jugada.tipo)
    {
        case SIMPLE:
        {
            if(jugada.numeroElegido == jugada.numeroGanador)
                jugada.victoria = 1;
            break;
        }
        case PRIMER_DOCENA:
        {
            jugada = VerificarPrimerDocena(jugada);
            break;
        }
        case SEGUNDA_DOCENA:
        {
            jugada = VerificarSegundaDocena(jugada);
            break;
        }
        case TERCER_DOCENA:
        {
            jugada = VerificarTercerDocena(jugada);
            break;
        }
        case FALTA:
        {
            jugada = VerificarFalta(jugada);
            break;
        }
        case PASA:
        {
            jugada = VerificarPasa(jugada);
            break;
        }
        case ROJO:
        {
            jugada = VerificarRojo(jugada);
            break;
        }
        case NEGRO:
        {
            jugada = VerificarNegro(jugada);
            break;
        }
        case PAR:
        {
            jugada = VerificarPar(jugada);
            break;
        }
        case IMPAR:
        {
            jugada = VerificarImpar(jugada);
            break;
        }
    }

    return jugada;
}

/****************************************************************************
	PROPOSITO: Si gana, retorna el premio según el tipo de jugada.
	COMENTARIOS:
****************************************************************************/

int EntregarPremio(int monto, PARTIDA jugada)
{
    if(jugada.victoria == 1)
    {
        if(jugada.tipo == SIMPLE)
        {
            monto += jugada.dineroApostado + (jugada.dineroApostado * 35);
        }
        else if(jugada.tipo == PRIMER_DOCENA || jugada.tipo == SEGUNDA_DOCENA || jugada.tipo == TERCER_DOCENA)
        {
            monto += jugada.dineroApostado + (jugada.dineroApostado * 2);
        }
        else
        {
            monto += jugada.dineroApostado + jugada.dineroApostado;
        }
    }
    else
    {
        monto -= jugada.dineroApostado;
    }

    return monto;
}

/****************************************************************************
	PROPOSITO: Guarda en un archivo la información de una partida.
	COMENTARIOS:
****************************************************************************/

void GuardarResultadoPartida(char nombreArchivo[], PARTIDA jugada)
{
    FILE * archi = fopen(nombreArchivo, "ab");
    fwrite(&jugada, sizeof(PARTIDA), 1, archi);
    fclose(archi);
}

/****************************************************************************
	PROPOSITO: Le pregunta la usuario si quiere volver a apostar.
	COMENTARIOS:
****************************************************************************/

char VolverApostar()
{
    char control;

    printf("\nIngrese 's' para volver a apostar: ");
    fflush(stdin);
    control = getche();
    printf("\n");

    return control;
}

/****************************************************************************
	PROPOSITO: Juega una partida completa.
	COMENTARIOS:
	- Realiza su apuesta, ingresa dinero que no sea mayor al que tiene actualmente (RealizarApuesta()). Hecho
	- Aparecen todos los tipos de apuestas, en el cual el usuario debera elegir uno (MostrarTiposApuesta()).
	- Muestra el resultado de la partida y su monto actual (MostrarResultadoPartida()).
	- Guarda el resultado de la partida en un archivo (GuardarResultadoPartida()).
	- Pregunta si quiere volver a jugar.
	- Si acepta se repite el proceso, si no se termina el juego.
****************************************************************************/

void JugarPartida()
{
    PARTIDA jugada;
    JUGADOR player;

    char control = 's';

    while( (control == 's' || control == 'S') && (player.monto > 0) )
    {
        if(jugada.dificultad != 1 && jugada.dificultad != 2 && jugada.dificultad != 3)
        {
            jugada = IngresarDificultad(jugada);

            VolverMenuPrincipal(jugada.dificultad);

            player = InicializarMonto(player, jugada);
        }

        jugada = RealizarApuestaPartida(jugada, player);

        VolverMenuPrincipal(jugada.dineroApostado);

        jugada = EligirApuesta(jugada);

        if(jugada.tipo == SIMPLE)
        {
            jugada = IngresarSimple(jugada);
        }

        ImprimirCabecera("PARTIDA DE RULETA");

        DibujarRuleta(5, 4);

        ImprimirJuego();

        jugada = NumeroRandom(jugada);

        ImprimirJuego();

        jugada = VerificarPartida(jugada);

        player.monto = EntregarPremio(player.monto, jugada);

        MostrarResultadoPartida(jugada, player);

        GuardarResultadoPartida("partidas.bin", jugada);

        if(player.monto != 0)
        {
            control = VolverApostar();
        }
    }

    ModificarRanking(player.monto, jugada.dificultad);

    printf("\nJUEGO TERMINADO\n");
    if(player.monto == 0)
    {
        printf("\nHas perdido todo el dinero :(");
    }
    system("pause");
    OpcionesMenuPrincipal();
}

/****************************************************************************
	PROPOSITO: Inicializa la lista asignadole NULL.
	COMENTARIOS:
****************************************************************************/

NODO * InicializarLista()
{
    return NULL;
}

/****************************************************************************
	PROPOSITO: Reserva espacio en memoria para la posterior creación de un
	nuevo nodo y inicializandolo con los valores recibidos por parametros.
	COMENTARIOS:
****************************************************************************/

NODO * CrearNodoLista(PARTIDA jugada)
{
    NODO * nuevo = (NODO *)malloc(sizeof(NODO));
    nuevo->jugada = jugada;
    nuevo->siguiente = NULL;
    return nuevo;
}

/****************************************************************************
	PROPOSITO: Busca y retorna el último nodo de la lista
	COMENTARIOS:
****************************************************************************/

NODO * BuscarUltimo(NODO * lista)
{
    NODO * seguidora = lista;

    while(seguidora->siguiente != NULL)
    {
        seguidora = seguidora->siguiente;
    }

    return seguidora;
}

/****************************************************************************
	PROPOSITO: Agrega al final de la lista el nodo enviado por parámetros
	COMENTARIOS:
****************************************************************************/

NODO * AgregarFinal(NODO * lista, NODO * nuevo)
{
    if(lista == NULL)
    {
        lista = nuevo;
    }
    else
    {
        NODO * seguidora = lista;
        seguidora = BuscarUltimo(seguidora);
        seguidora->siguiente = nuevo;
    }

    return lista;
}

/****************************************************************************
	PROPOSITO: Transfiere la información que hay en un archivo a un struct
	de tipo PARTIDA.
	COMENTARIOS:
****************************************************************************/

NODO * ArchivoToLista(char nombreArchivo[])
{
    NODO * lista = InicializarLista();
    PARTIDA jugada;
    FILE * archi = fopen(nombreArchivo, "rb");

    if(archi == NULL)
    {
        printf("\nError al abrir el archivo\n");
    }
    else
    {
        while(fread(&jugada, sizeof(PARTIDA), 1, archi) > 0)
        {
            lista = AgregarFinal(lista, CrearNodoLista(jugada));
        }

        fclose(archi);
    }

    return lista;
}

/****************************************************************************
	PROPOSITO: Retorna un diferente string dependiendo la dificultad
	COMENTARIOS:
****************************************************************************/

char * RetornarDificultad(int dificultad)
{
    char * nombre = (char *)malloc(sizeof(char) * 10);

    switch(dificultad)
    {
        case 1: strcpy(nombre, "Facil"); break;
        case 2: strcpy(nombre, "Medio"); break;
        case 3: strcpy(nombre, "Dificil"); break;
    }

    return nombre;
}

/****************************************************************************
	PROPOSITO: Retorna un diferente string dependiendo el tipo de apuesta
	COMENTARIOS:
****************************************************************************/

char * RetornarTipoApuesta(int tipo)
{
    char * nombre = (char *)malloc(sizeof(char) * 15);

    switch(tipo)
    {
        case 1: strcpy(nombre, "Simple"); break;
        case 2: strcpy(nombre, "Primer docena"); break;
        case 3: strcpy(nombre, "Segunda docena"); break;
        case 4: strcpy(nombre, "Tercer docena"); break;
        case 5: strcpy(nombre, "Pasa"); break;
        case 6: strcpy(nombre, "Falta"); break;
        case 7: strcpy(nombre, "Rojo"); break;
        case 8: strcpy(nombre, "Negro"); break;
        case 9: strcpy(nombre, "Par"); break;
        case 10: strcpy(nombre, "Impar"); break;
    }

    return nombre;
}

/****************************************************************************
	PROPOSITO: Muestra un struct de PARTIDA
	COMENTARIOS:
****************************************************************************/

void MostrarPartida(PARTIDA jugada)
{
    printf("\nDinero apostado: $%i", jugada.dineroApostado);
    if(jugada.tipo == SIMPLE)
    {
        printf("\nN%cmero elegido: %i", 163, jugada.numeroElegido);
    }
    printf("\nN%cmero ganador: %i", 163, jugada.numeroGanador);
    printf("\nDificultad: %s", RetornarDificultad(jugada.dificultad));
    printf("\nTipo de jugada: %s", RetornarTipoApuesta(jugada.tipo));
    printf("\nResultado: ");
    if(jugada.victoria == 1)
    {
        printf("Victoria\n");
    }
    else
    {
        printf("Derrota\n");
    }
}

/****************************************************************************
	PROPOSITO: Muestra una lista hasta que seguidora sea distinto de NULL
	COMENTARIOS:
****************************************************************************/

void MostrarLista(NODO * lista)
{
    NODO * seguidora = lista;

    while(seguidora != NULL)
    {
        MostrarPartida(seguidora->jugada);
        seguidora = seguidora->siguiente;
    }
}

/****************************************************************************
	PROPOSITO: Muestra una información general de todas las partidas jugadas
	para una dificultad en particular.
	COMENTARIOS:
****************************************************************************/

void MostrarInformacionPartidas(int dineroApostado, int dineroGanado, int partidasJugadas, int victorias)
{
    /// Coordenadas donde va ubicado el texto a continuación.
    int x = 18, y = 5;

    gotoxy(x, y);
    printf("Estad%csticas de partidas", 161);
    y += 2;

    gotoxy(x, y);
    printf("Partidas jugadas: %i", partidasJugadas);
    y++;

    gotoxy(x, y);
    printf("Partidas ganadas: %i", victorias);
    y++;

    gotoxy(x, y);
    printf("Partidas p%crdidas: %i", 130, partidasJugadas - victorias);
    y++;

    gotoxy(x, y);
    printf("Total dinero apostado: $%i", dineroApostado);
    y++;

    gotoxy(x, y);
    printf("Total dinero ganado: $%i", dineroGanado);
    y++;

    gotoxy(x, y);
    printf("Total dinero perdido: $%i", dineroGanado - dineroApostado);
    y++;
}

/****************************************************************************
	PROPOSITO: Recibe información de un archivo, y con esa información
	recolectara lo principal para mostrar una información general de todas

	COMENTARIOS:
****************************************************************************/

void RecorrerLista(int dificultad)
{
    NODO * lista = ArchivoToLista("partidas.bin");

    int dineroApostado = 0;
    int dineroGanado = 0;
    int partidasJugadas = 0;
    int victorias = 0;

    while(lista != NULL)
    {
        if(lista->jugada.dificultad == dificultad)
        {
            partidasJugadas++;
            dineroApostado += lista->jugada.dineroApostado;

            if(lista->jugada.victoria == 1)
            {
                victorias++;
                dineroGanado = EntregarPremio(dineroGanado, lista->jugada);
            }
        }

        lista = lista->siguiente;
    }

    MostrarInformacionPartidas(dineroApostado, dineroGanado, partidasJugadas, victorias);
}
