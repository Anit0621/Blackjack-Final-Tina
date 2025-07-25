#include "JugadorHumano.h"
#include <iostream>

JugadorHumano::JugadorHumano(const std::string& nombre) : Jugador(nombre) {}

bool JugadorHumano::quiereOtraCarta() const {
    char respuesta;
    std::cout << "¿Quieres otra carta? (s/n): ";
    std::cin >> respuesta;
    return (respuesta == 's' || respuesta == 'S');
}

void JugadorHumano::mostrarMano() const {
    std::cout << "\nCartas de " << nombre << ":\n";
    mano.mostrar();
    std::cout << "Apuesta actual: " << apuesta << "\n";
}

void JugadorHumano::apostar(int cantidad) {
    if (cantidad <= 0 || cantidad > saldo) {
        throw std::runtime_error("Apuesta inválida. Ingresa un valor entre 1 y " + std::to_string(saldo));
    }
    apuesta = cantidad;
    saldo -= cantidad;
    std::cout << "Apuesta de " << apuesta << " colocada. Saldo restante: " << saldo << "\n";
}

void JugadorHumano::ganarApuesta() {
    if (tieneBlackjack()) {
        int ganancia = apuesta * 1.5; // 3:2 = 1.5x
        saldo += apuesta + ganancia;
        std::cout << "¡Blackjack! Ganas " << ganancia << " fichas (3:2)\n";
    } else {
        saldo += apuesta * 2;
        std::cout << "¡Ganaste " << apuesta << " fichas!\n";
    }
    std::cout << "Nuevo saldo: " << saldo << "\n";
    apuesta = 0;
}

void JugadorHumano::empateApuesta() {
    saldo += apuesta;
    std::cout << "Empate. Recuperas tu apuesta de " << apuesta << " fichas.\n";
    std::cout << "Saldo actual: " << saldo << "\n";
    apuesta = 0;
}

int JugadorHumano::getSaldo() const {
    return saldo;
}