// src/habitacion.cpp — IMPLEMENTACIÓN DE EJEMPLO.
#include "habitacion.hpp"
#include <stdexcept>

Habitacion::Habitacion(int numero, double precioPorNoche)
    : numero_(numero), precioPorNoche_(precioPorNoche), ocupada_(false) {
    if (precioPorNoche <= 0) throw std::invalid_argument("Precio invalido");
}

bool Habitacion::reservar() {
    if (ocupada_) return false;
    ocupada_ = true;
    return true;
}

void Habitacion::liberar() { ocupada_ = false; }
int Habitacion::getNumero() const { return numero_; }
double Habitacion::getPrecio() const { return precioPorNoche_; }
bool Habitacion::estaOcupada() const { return ocupada_; }
