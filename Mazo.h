/*
PROYECTO BLACKJACK
Profesor: Victor Bucheli
Estudiante: Valentina Montezuma GOnzalez
Codigo: 202242058
Correo: Valentina.montezuma@correounivalle.edu.co



CLASE: MAZO
Representa el mazo de cartas (barajar, repartir, contar cartas restantes).



RELACIONES - De composicion con Carta:



*/


#ifndef MAZO_H
#define MAZO_H

#include "Carta.h"
#include <vector>

class Mazo {
public:
    Mazo();
    void barajar();
    Carta* repartirCarta();
    int cartasRestantes() const;

private:
    std::vector<Carta> cartas;
    size_t siguienteCarta;
};

#endif