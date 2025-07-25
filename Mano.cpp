#include "Mano.h"
#include <iostream>

void Mano::agregarCarta(Carta* carta) {
    if (carta) cartas.push_back(carta);
}

int Mano::calcularValor() const {
    int valor = 0;
    int ases = 0;
    
    for (const auto& carta : cartas) {
        valor += carta->getValor();
        if (carta->esAs()) ases++;
    }
    
    while (valor > 21 && ases > 0) {
        valor -= 10;
        ases--;
    }
    
    return valor;
}

void Mano::mostrar() const {
    for (const auto& carta : cartas) {
        std::cout << "- " << carta->getNombre() << " de " << carta->getPalo() << "\n";
    }
    std::cout << "Total: " << calcularValor() << "\n";
}

void Mano::limpiar() { cartas.clear(); }

bool Mano::tieneBlackjack() const {
    return cartas.size() == 2 && calcularValor() == 21;
}

bool Mano::sePaso() const {
    return calcularValor() > 21;
}

const std::vector<Carta*>& Mano::getCartas() const {
    return cartas;
}