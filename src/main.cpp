// src/main.cpp — punto de entrada del programa.
// De momento solo usa la clase de ejemplo: cambiadlo por el menú de vuestro gestor.
#include <iostream>
#include "habitacion.hpp"

int main() {
    Habitacion h(101, 80.0);
    std::cout << "Proyecto compilado con CMake. Habitacion de ejemplo: " << h.getNumero() << "\n";
    std::cout << (h.reservar() ? "Reservada" : "Ya estaba ocupada") << "\n";
    return 0;
}
