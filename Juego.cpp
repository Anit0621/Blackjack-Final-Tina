#include "Juego.h"
#include <iostream>

Juego::Juego(const std::string& nombreJugador) {
    jugador = new JugadorHumano(nombreJugador);
    crupier = new Crupier();
}

Juego::~Juego() {
    delete jugador;
    delete crupier;
}

void Juego::iniciar() {
    char continuar;
    do {
        std::cout << "\n=== BLACKJACK ===\n";
        std::cout << "Cartas restantes en el mazo: " << mazo.cartasRestantes() << "\n";
        
        if (mazo.cartasRestantes() < 15) {
            mazo.barajar();
            std::cout << "El mazo ha sido barajado. Nuevas cartas: " << mazo.cartasRestantes() << "\n";
        }

        int apuesta;
        std::cout << "\nSaldo actual: " << jugador->getSaldo() << " fichas\n";
        std::cout << "Ingresa tu apuesta (0 para salir): ";
        std::cin >> apuesta;
        
        if (apuesta == 0) break;
        
        try {
            jugador->apostar(apuesta);
        } catch (const std::runtime_error& e) {
            std::cout << "Error: " << e.what() << "\n";
            continue;
        }

        repartirCartasIniciales();
        jugador->mostrarMano();
        crupier->mostrarMano();

        if (jugador->tieneBlackjack()) {
            std::cout << "\n¡Tienes Blackjack!\n";
        } else {
            turnoJugador();
        }

        if (!jugador->sePaso()) {
            turnoCrupier();
        }
        determinarGanador();

        std::cout << "\n¿Quieres jugar otra mano? (s/n): ";
        std::cin >> continuar;
    } while (continuar == 's' || continuar == 'S');
}

void Juego::repartirCartasIniciales() {
    // Usamos el nuevo método público en lugar de acceder a mano directamente
    jugador->limpiarMano();
    crupier->limpiarMano();
    
    jugador->recibirCarta(mazo.repartirCarta());
    crupier->recibirCarta(mazo.repartirCarta());
    jugador->recibirCarta(mazo.repartirCarta());
    crupier->recibirCarta(mazo.repartirCarta());
}

void Juego::turnoJugador() {
    while (jugador->quiereOtraCarta()) {
        jugador->recibirCarta(mazo.repartirCarta());
        jugador->mostrarMano();
        if (jugador->sePaso()) {
            std::cout << "¡Te pasaste de 21!\n";
            break;
        }
    }
}

void Juego::turnoCrupier() {
    crupier->mostrarMano(true);
    std::cout << "Turno del crupier...\n";
    
    while (crupier->quiereOtraCarta()) {
        crupier->recibirCarta(mazo.repartirCarta());
        crupier->mostrarMano(true);
        if (crupier->sePaso()) {
            std::cout << "¡El crupier se pasó!\n";
            break;
        }
    }
}

void Juego::determinarGanador() {
    int valorJugador = jugador->getValorMano();
    int valorCrupier = crupier->getValorMano();

    std::cout << "\n=== RESULTADO ===\n";
    std::cout << jugador->getNombre() << ": " << valorJugador << " vs ";
    std::cout << "Crupier: " << valorCrupier << "\n";

    if (jugador->sePaso()) {
        std::cout << "Perdiste. Te pasaste de 21.\n";
    } 
    else if (crupier->sePaso()) {
        std::cout << "¡Ganaste! El crupier se pasó.\n";
        jugador->ganarApuesta();
    } 
    else if (jugador->tieneBlackjack() && !crupier->tieneBlackjack()) {
        std::cout << "¡Blackjack! Ganas 3:2\n";
        jugador->ganarApuesta();
    }
    else if (valorJugador > valorCrupier) {
        std::cout << "¡Ganaste!\n";
        jugador->ganarApuesta();
    } 
    else if (valorJugador < valorCrupier) {
        std::cout << "Perdiste.\n";
    } 
    else {
        std::cout << "Empate.\n";
        jugador->empateApuesta();
    }
    
    std::cout << "Nuevo saldo: " << jugador->getSaldo() << "\n";
}