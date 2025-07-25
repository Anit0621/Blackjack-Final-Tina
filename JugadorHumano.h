/*
PROYECTO BLACKJACK
Profesor: Victor Bucheli
Estudiante: Valentina Montezuma Gonzalez
Codigo: 202242058
Correo: Valentina.montezuma@correounivalle.edu.co



CLASE: JUGADORHUMANO
Implementa acciones del jugador humano (decidir pedir carta, apostar, mostrar mano).



RELACIONES:
Usa a la clase Mano.
*/


#ifndef JUGADORHUMANO_H
#define JUGADORHUMANO_H

#include "Jugador.h"

class JugadorHumano : public Jugador {
public:
    JugadorHumano(const std::string& nombre);
    
    bool quiereOtraCarta() const override;
    void mostrarMano() const override;
    
    int getSaldo() const override; 
    void apostar(int cantidad) override;
    void ganarApuesta() override;
    void empateApuesta() override;
    
private:
    int saldo = 1000;
};

#endif