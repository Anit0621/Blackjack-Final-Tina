/*
PROYECTO BLACKJACK
Profesor: Victor Bucheli
Estudiante: Valentina Montezuma GOnzalez
Codigo: 202242058
Correo: Valentina.montezuma@correounivalle.edu.co



CLASE: JUGADOR --- Clase Asbtracta
Define la interfaz común para jugadores (recibir carta, valor de mano, apuestas).



RELACIONES - De Herencia con:

JugadorHumano y Crupier heredan de Jugador.
Polimorfismo: Juego trata a ambos como Jugador para turnos y reglas comunes.

Tambien hay composicion con mano.

*/

#ifndef JUGADOR_H
#define JUGADOR_H

#include "Mano.h"
#include <string>

class Jugador {
public:
    Jugador(const std::string& nombre);
    virtual ~Jugador() = default;
    
    virtual bool quiereOtraCarta() const = 0;
    virtual void mostrarMano() const = 0;
    
    void recibirCarta(Carta* carta);
    int getValorMano() const;
    bool tieneBlackjack() const;
    bool sePaso() const;
    
    virtual int getSaldo() const = 0;
    virtual void apostar(int cantidad) = 0;
    virtual void ganarApuesta() = 0;
    virtual void empateApuesta() = 0;
    
    const std::string& getNombre() const { return nombre; }
    int getApuesta() const { return apuesta; }
    void limpiarMano() { mano.limpiar(); }

protected:
    Mano mano;
    std::string nombre;
    int apuesta = 0;
};

#endif