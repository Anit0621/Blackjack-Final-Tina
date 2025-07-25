/*
PROYECTO BLACKJACK
Profesor: Victor Bucheli
Estudiante: Valentina Montezuma GOnzalez
Codigo: 202242058
Correo: Valentina.montezuma@correounivalle.edu.co



CLASE: CRUPIER
Implementa lógica del crupier (pedir carta hasta 17, mostrar mano parcial/completa)



RELACIONES:
Usa a la clase Mano.
*/



#ifndef CRUPIER_H
#define CRUPIER_H

#include "Jugador.h"

class Crupier : public Jugador {
public:
    Crupier();
    
    bool quiereOtraCarta() const override;
    void mostrarMano() const override;
    void mostrarMano(bool mostrarTodas) const;
    
    int getSaldo() const override { return 0; }
    void apostar(int cantidad) override {}
    void ganarApuesta() override {}
    void empateApuesta() override {}
};

#endif