// tests/test_habitacion.cpp — TESTS DE EJEMPLO con GoogleTest.
// Son los mismos que en las diapositivas de testing. Cread un fichero test_<clase>.cpp
// por cada clase vuestra (la Entrega 2 pide al menos 5 tests que pasen en el pipeline).
#include <gtest/gtest.h>
#include <stdexcept>
#include "habitacion.hpp"

TEST(HabitacionTest, ConstructorInicializaCorrectamente) {
    Habitacion h(101, 80.0);
    EXPECT_EQ(h.getNumero(), 101);
    EXPECT_DOUBLE_EQ(h.getPrecio(), 80.0);
    EXPECT_FALSE(h.estaOcupada());
}

TEST(HabitacionTest, ReservarCambiaEstado) {
    Habitacion h(101, 80.0);
    EXPECT_TRUE(h.reservar());
    EXPECT_TRUE(h.estaOcupada());
}

TEST(HabitacionTest, ReservarDobleVezDevuelveFalse) {
    Habitacion h(101, 80.0);
    h.reservar();
    EXPECT_FALSE(h.reservar());
}

TEST(HabitacionTest, PrecioNegativoLanzaExcepcion) {
    EXPECT_THROW(Habitacion(101, -50.0), std::invalid_argument);
}

TEST(HabitacionTest, LiberarDejaLaHabitacionLibre) {
    Habitacion h(101, 80.0);
    h.reservar();
    h.liberar();
    EXPECT_FALSE(h.estaOcupada());
}
