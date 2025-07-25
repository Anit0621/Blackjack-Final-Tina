/*
PROYECTO BLACKJACK
Profesor: Victor Bucheli
Estudiante: Valentina Montezuma GOnzalez
Codigo: 202242058
Correo: Valentina.montezuma@correounivalle.edu.co



CLASE: CARTA
Modela una carta individual (valor, palo, nombre).



*/

#ifndef CARTA_H
#define CARTA_H

#include <string>

class Carta {
public:
    struct Palo {   // Estructura pa agrupar las constantes palo
        static const std::string CORAZONES;
        static const std::string DIAMANTES;
        static const std::string TREBOLES;
        static const std::string PICAS;
    };

    Carta(int valor, const std::string& palo); 

    //METODOS
    int getValor() const;
    std::string getNombre() const;
    std::string getPalo() const;
    bool esAs() const;
    bool esFigura() const;

private:
    
    int valor;
    std::string palo;
};

#endif