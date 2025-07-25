#include <iostream>
#include "Juego.h"

int main() {
    try {
        std::string nombre;
        std::cout << "Ingresa tu nombre: ";
        std::getline(std::cin, nombre);
        
        Juego juego(nombre);
        juego.iniciar();
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}