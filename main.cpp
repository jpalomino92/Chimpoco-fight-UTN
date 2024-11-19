#include <iostream>
#include <cstdlib>
#include <string>


#include "visuales.h"
#include "chimpocos.h"
#include "attack.h"
#include "aventura.h"
#include "constantes.h"
#include "versus.h"


using namespace std;


int main(){



    int option;

    int enemies[E][6] = {
    {150, 5, 15, 1,150,0},     // Enemigo 1 Stitchard
    {300, 25, 45, 2,300,0},    // Enemigo 2 FurbyZhor
    {450, 40, 55, 3,450,0},    // Enemigo 3 HelloCathy
    {700, 55, 75, 4,700,0},    // Enemigo 4 BabyYorda
    {1500, 25, 150, 5,1500,0}   // Enemigo 5 TioMickey
    };
    string nombre;
    string nombre2;

    int selected_chimpoco[S] = {};
    int selected_chimpoco2[S] = {};



    while (true)
    {
        system("cls");
        menu();
        cin>>option;
        switch (option)
        {
        case 1:
            system("cls");
            cout << "Ingrese su nombre: " << endl;
            cin.ignore();
            getline( cin, nombre);

            choose_chimpoco(selected_chimpoco);
            empezar_aventura(selected_chimpoco,enemies);


            system("pause");
            break;
        case 2:
            system("cls");
            cout << "Ingrese el nombre del jugador 1: " << endl;
            cin.ignore();
            getline( cin, nombre);
            choose_chimpoco(selected_chimpoco);

            system("cls");
            cout << "Ingrese el nombre del jugador 2: " << endl;
            cin.ignore();
            getline( cin, nombre2);
            choose_chimpoco(selected_chimpoco2);

            batalla_versus(selected_chimpoco,selected_chimpoco2);

            if(selected_chimpoco[VIDA_ACTUAL] == 0) {
                system("cls");
                cout << "El ganador es el jugador: "<<nombre2 << endl;
                system("pause");
            }else {
                system("cls");
                cout << "El ganador es el jugador: "<<nombre << endl;
                system("pause");
            }

            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            cout<<"Saliendo del programa."<<endl;
            return 0;
            break;
        default:
            cout<<"Por favor elegi una opcion valida..." << endl;
            system("pause");
            break;
        }
    }        ;
    return 0;
}




