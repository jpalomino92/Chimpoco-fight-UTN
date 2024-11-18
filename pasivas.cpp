#include <iostream>
#include <cstdlib>
#include <ctime>

#include "constantes.h"



using namespace std;

void imprimir_pasivas_enemigos(int pasiva){

        switch (pasiva) {
        case 1:
            cout << "Al tercer turno entra en un ataque de ira, lo que aumenta sus puntos de vida en 150 y su daño de 15 a 45." << endl;
            break;
        case 2:
            cout << "Cada 4 turnos se pone a cantar, lo que aturde a los chimpocos y les hace perder un turno." << endl;
            break;
        case 3:
            cout << "El primer turno recibe un 15% más de daño, pero el segundo un 30% menos. Continúa esa iteración todo el combate." << endl;
            break;
        case 4:
            cout << "Cada 3 turnos comanda el turno del chimpoco, lo que puede hacer que tome una poción, o ataque de forma aleatoria." << endl;
            break;
        case 5:
            cout << "Cada dos turnos se ríe, lo que irrita y desconcierta a los chimpocos, haciendo que su daño se reduzca en un 20% y reciban un 15% más de daño el turno siguiente." << endl;
            break;
        }
}

void imprimir_pasivas_chimpocos(int pasiva){

        switch (pasiva) {
        case 1:
            cout << "Reducción de daño recibido 15%" << endl;
            break;
        case 2:
            cout << "15% chance de golpe crítico (daño *2)" << endl;
            break;
        case 3:
            cout << "15% chance de congelar al enemigo al atacar o defender (el enemigo congelado pierde los siguientes 2 turnos )" << endl;
            break;
        case 4:
            cout << "25% chance de paralizar por 1 turno al enemigo." << endl;
            break;

    }

}

void pasiva_chimpoco(int selected_chimpoco[],int enemigo[],int turno,bool &congelado){
    srand(static_cast<unsigned int>(time(0)));
    int probabilidad = rand() % 100 + 1;
    switch (selected_chimpoco[PASIVA]) {
        case 1:
            cout<<" Se activa pasiva de Rockito..ataque del enemigo disminuido.."<<endl;
            cout<<"EL ataque del enemigo era de: " <<enemigo[ATAQUE_ACTUAL]<<endl;
            enemigo[ATAQUE_ACTUAL] = enemigo[ATAQUE_ACTUAL] * 0.85;
            cout<<" el nuevo ataque es de: " <<enemigo[ATAQUE_ACTUAL]<<endl;
            break;
        case 2:
            if (probabilidad <= 15){
                cout<<" Se activa la pasiva de Picante.."<<endl;
                cout<<"El ataque del chimpoco era de :"<<selected_chimpoco[ATAQUE_ACTUAL]<<endl;
                selected_chimpoco[ATAQUE_ACTUAL] *= 2;
                cout<<"El nuevo ataque del chimpoco es de :"<<selected_chimpoco[ATAQUE_ACTUAL]<<endl;
            }
            break;
        case 3:
            if (probabilidad <= 15){
                cout<<" Se activa la pasiva de Freddy.."<<endl;
                congelado = true;

            }
            break;
        case 4:
            if (probabilidad <= 25){
                cout<<" Se activa la pasiva de Rayin.."<<endl;
                congelado = true;
            }


            break;
    }


};


void pasiva_enemigo(int enemigo[],int turno){
    cout<<"Esta es el numero de pasiva enemigo " <<enemigo[PASIVA]<<endl;

};
