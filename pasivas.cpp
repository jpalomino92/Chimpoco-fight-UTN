#include <iostream>
using namespace std;

void imprimir_pasivas_enemigos(int pasiva){

        switch (pasiva) {
        case 1:
            cout << "Al tercer turno entra en un ataque de ira, lo que aumenta sus puntos de vida en 150 y su da�o de 15 a 45." << endl;
            break;
        case 2:
            cout << "Cada 4 turnos se pone a cantar, lo que aturde a los chimpocos y les hace perder un turno." << endl;
            break;
        case 3:
            cout << "El primer turno recibe un 15% m�s de da�o, pero el segundo un 30% menos. Contin�a esa iteraci�n todo el combate." << endl;
            break;
        case 4:
            cout << "Cada 3 turnos comanda el turno del chimpoco, lo que puede hacer que tome una poci�n, o ataque de forma aleatoria." << endl;
            break;
        case 5:
            cout << "Cada dos turnos se r�e, lo que irrita y desconcierta a los chimpocos, haciendo que su da�o se reduzca en un 20% y reciban un 15% m�s de da�o el turno siguiente." << endl;
            break;
        }
}

void imprimir_pasivas_chimpocos(int pasiva){

        switch (pasiva) {
        case 1:
            cout << "Reducci�n de da�o recibido 15%" << endl;
            break;
        case 2:
            cout << "15% chance de golpe cr�tico (da�o *2)" << endl;
            break;
        case 3:
            cout << "15% chance de congelar al enemigo al atacar o defender (el enemigo congelado pierde los siguientes 2 turnos )" << endl;
            break;
        case 4:
            cout << "25% chance de paralizar por 1 turno al enemigo." << endl;
            break;

    }

}
