#include "Jugador.h"

Jugador::Jugador(const std::string& nombre) : nombre(nombre) {}

void Jugador::recibirCarta(Carta* carta) {
    mano.agregarCarta(carta);
}

int Jugador::getValorMano() const {
    return mano.calcularValor();
}

bool Jugador::tieneBlackjack() const {
    return mano.tieneBlackjack();
}

bool Jugador::sePaso() const {
    return mano.sePaso();
}