#include "Crupier.h"
#include <iostream>

Crupier::Crupier() : Jugador("Crupier") {}

bool Crupier::quiereOtraCarta() const {
    return getValorMano() < 17;
}

void Crupier::mostrarMano() const {
    mostrarMano(false);
}

void Crupier::mostrarMano(bool mostrarTodas) const {
    std::cout << "\nCartas del Crupier:\n";
    if (mostrarTodas) {
        mano.mostrar();
    } else {
        std::cout << "- Carta oculta\n";
        if (!mano.getCartas().empty()) {
            std::cout << "- " << mano.getCartas()[0]->getNombre() 
                      << " de " << mano.getCartas()[0]->getPalo() << "\n";
        }
    }
}