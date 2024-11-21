#include <iostream>
#include <cstdlib>
#include <ctime>

// Función para tirar un dado
int tirarDado() {
    srand(time(0));
    return rand() % 6 + 1; // Genera un número entre 1 y 6
}
