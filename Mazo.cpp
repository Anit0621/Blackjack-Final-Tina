#include "Mazo.h"
#include <algorithm>
#include <ctime>
#include <cstdlib>

Mazo::Mazo() : siguienteCarta(0) {
    const std::string palos[] = {
        Carta::Palo::CORAZONES, Carta::Palo::DIAMANTES,
        Carta::Palo::TREBOLES, Carta::Palo::PICAS
    };
    
    for (const auto& palo : palos) {
        for (int valor = 1; valor <= 13; ++valor) {
            cartas.emplace_back(valor, palo);
        }
    }
    barajar();
}

void Mazo::barajar() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    std::random_shuffle(cartas.begin(), cartas.end());
    siguienteCarta = 0;
}

Carta* Mazo::repartirCarta() {
    if (siguienteCarta >= cartas.size()) {
        barajar(); // Rebarajar si se acaban las cartas
    }
    return &cartas[siguienteCarta++];
}

int Mazo::cartasRestantes() const {
    return static_cast<int>(cartas.size() - siguienteCarta);
}