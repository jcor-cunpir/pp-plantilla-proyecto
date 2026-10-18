// include/habitacion.hpp — CLASE DE EJEMPLO.
// Sustituidla por las clases de vuestro proyecto (y borrad este fichero).
#pragma once

class Habitacion {
public:
    Habitacion(int numero, double precioPorNoche);   // lanza std::invalid_argument si el precio <= 0
    bool reservar();                                  // false si ya estaba ocupada
    void liberar();
    int getNumero() const;
    double getPrecio() const;
    bool estaOcupada() const;

private:
    int numero_;
    double precioPorNoche_;
    bool ocupada_;
};
