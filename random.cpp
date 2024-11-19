#include <cstdlib>
#include <ctime>

int obtenerNumeroRandom(int min, int max) {
    // Generar la semilla basada en el tiempo actual
    srand(time(nullptr));

    // Generar el n�mero aleatorio entre min y max
    return min + rand() % ((max + 1) - min);
}