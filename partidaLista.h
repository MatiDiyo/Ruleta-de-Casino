#ifndef PARTIDALISTA_H_INCLUDED
#define PARTIDALISTA_H_INCLUDED

enum
{
    SIMPLE = 1,
    PRIMER_DOCENA, /// 1 a 12
    SEGUNDA_DOCENA, /// 13 a 24
    TERCER_DOCENA, /// 25 a 36
    FALTA, /// 1 a 18
    PASA, /// 19 a 36
    ROJO,
    NEGRO,
    PAR,
    IMPAR
};

typedef struct
{
    char nombre[30];
    int monto;
}JUGADOR;

typedef struct
{
    int numeroElegido; /// Solo jugada simple
    int numeroGanador;
    int dineroApostado;
    int tipo;
    int victoria; /// flag
    int dificultad;
}PARTIDA;

typedef struct
{
    PARTIDA jugada;
    struct NODO * siguiente;
}NODO;

void ImprimirJuego();
PARTIDA IngresarDificultad(PARTIDA jugada);
JUGADOR InicializarMonto(JUGADOR player, PARTIDA jugada);
PARTIDA RealizarApuestaPartida(PARTIDA jugada, JUGADOR player);
void MostrarTiposApuesta();
PARTIDA EligirApuesta(PARTIDA jugada);
void VolverMenuPrincipal(int num);
PARTIDA IngresarSimple(PARTIDA jugada);
PARTIDA IngresarPrimerDocena(PARTIDA jugada);
PARTIDA IngresarSegundaDocena(PARTIDA jugada);
PARTIDA IngresarTercerDocena(PARTIDA jugada);
PARTIDA IngresarFalta(PARTIDA jugada);
PARTIDA IngresarPasa(PARTIDA jugada);
PARTIDA IngresarPar(PARTIDA jugada);
PARTIDA IngresarImpar(PARTIDA jugada);
PARTIDA IngresarRojo(PARTIDA jugada);
PARTIDA IngresarNegro(PARTIDA jugada);
PARTIDA InicializarTipoApuesta(PARTIDA jugada, int opc);
PARTIDA NumeroRandom();
void MostrarNumeroGanador(PARTIDA jugada);
PARTIDA VerificarFalta(PARTIDA jugada);
PARTIDA VerificarPasa(PARTIDA jugada);
PARTIDA VerificarPar(PARTIDA jugada);
PARTIDA VerificarImpar(PARTIDA jugada);
PARTIDA VerificarPrimerDocena(PARTIDA jugada);
PARTIDA VerificarSegundaDocena(PARTIDA jugada);
PARTIDA VerificarTercerDocena(PARTIDA jugada);
PARTIDA VerificarRojo(PARTIDA jugada);
PARTIDA VerificarNegro(PARTIDA jugada);
PARTIDA VerificarPartida(PARTIDA jugada);
int EntregarPremio(int monto, PARTIDA jugada);
void GuardarResultadoPartida(char nombreArchivo[], PARTIDA jugada);
char VolverApostar();
void JugarPartida();

#endif // PARTIDALISTA_H_INCLUDED
