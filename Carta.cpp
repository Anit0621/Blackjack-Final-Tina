#include "Carta.h"
#include <map>

const std::string Carta::Palo::CORAZONES = "Corazones";
const std::string Carta::Palo::DIAMANTES = "Diamantes";
const std::string Carta::Palo::TREBOLES = "Tréboles";
const std::string Carta::Palo::PICAS = "Picas";

Carta::Carta(int valor, const std::string& palo) : valor(valor), palo(palo) {}

int Carta::getValor() const {
    return (valor >= 10) ? 10 : valor;
}

std::string Carta::getNombre() const {
    static std::map<int, std::string> nombres = {
        {1, "As"}, {11, "Jota"}, {12, "Reina"}, {13, "Rey"}
    };
    return (nombres.count(valor)) ? nombres[valor] : std::to_string(valor);
}

std::string Carta::getPalo() const { return palo; }
bool Carta::esAs() const { return valor == 1; }
bool Carta::esFigura() const { return valor >= 11 && valor <= 13; }