/*
PROYECTO BLACKJACK
Profesor: Victor Bucheli
Estudiante: Valentina Montezuma GOnzalez
Codigo: 202242058
Correo: Valentina.montezuma@correounivalle.edu.co



CLASE: MANO
Gestiona las cartas de un jugador (calcular valor, mostrar, limpiar).



RELACIONES - De agregacion con Carta

Mano usa Carta:
Las manos temporales agrupan cartas del mazo.

*/


#ifndef MANO_H
#define MANO_H

#include "Carta.h"
#include <vector>

class Mano {
public:
    void agregarCarta(Carta* carta);
    int calcularValor() const;
    void mostrar() const;
    void limpiar();
    bool tieneBlackjack() const;
    bool sePaso() const;
    const std::vector<Carta*>& getCartas() const;

private:
    std::vector<Carta*> cartas;
};

#endif