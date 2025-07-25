/*
PROYECTO BLACKJACK
Profesor: Victor Bucheli
Estudiante: Valentina Montezuma GOnzalez
Codigo: 202242058
Correo: Valentina.montezuma@correounivalle.edu.co

CLASE: JUEGO --- Clase controladora

Maneja el flujo del juego (iniciar, repartir cartas, turnos, determinar ganador).

RELACIONES - De composicion con:

1 Mazo (vida dependiente del juego).
1 JugadorHumano (el jugador principal).
1 Crupier (el dealer).

*/

#ifndef JUEGO_H
#define JUEGO_H

#include "Mazo.h"
#include "JugadorHumano.h"
#include "Crupier.h"

class Juego {
public:
    Juego(const std::string& nombreJugador);
    ~Juego();
    void iniciar();

private:
    Mazo mazo;
    JugadorHumano* jugador;
    Crupier* crupier;
    
    void repartirCartasIniciales();
    void turnoJugador();
    void turnoCrupier();
    void determinarGanador();
    void nuevaMano();
};

#endif