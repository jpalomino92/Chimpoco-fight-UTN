#include <iostream>
#include <cstdlib>
#include <ctime>

// Funci�n para tirar un dado
int tirarDado() {
    srand(time(0));
    return rand() % 6 + 1; // Genera un n�mero entre 1 y 6
}
