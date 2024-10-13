#include <iostream>
#include <ctime>


#include "visuales.h"
#include "constantes.h"
#include "items.h"


using namespace std;


int obtenerNumeroRandom(int min, int max);



int batalla(int selected_chimpoco[], int enemigo[S],bool game_over){

    bool turno_ataque_chimpoco = true;
    int cont_turnos = 0;
    int random_attack;
    int accion;

    while(enemigo[VIDA_ACTUAL] > 0 && selected_chimpoco[VIDA_ACTUAL] > 0){

        if (turno_ataque_chimpoco){
            //mover arriba en caso que el turno del enemigo tambien se contabilice.
            cont_turnos++;
            //aca calculamos el ataque entre el maxi y minimo del ataque del vector posision 1 (min ataque) posicion 2 (Max ataque)
            random_attack = obtenerNumeroRandom(selected_chimpoco[DANIO_MIN], selected_chimpoco[DANIO_MAX]);
            selected_chimpoco[ATAQUE_ACTUAL] = random_attack;

            menu_aventura();
            cin>>accion;
            switch (accion)
            {
            case 1:
                //atacar();
                cout<<"el ataque de tu chimpoco es de : " << selected_chimpoco[ATAQUE_ACTUAL] << endl;
                enemigo[VIDA_ACTUAL] -= selected_chimpoco[ATAQUE_ACTUAL];
                if(enemigo[VIDA_ACTUAL] < 0){ enemigo[VIDA_ACTUAL] = 0;}
                cout<<"la nueva vida del enemigo es de: " << enemigo[VIDA_ACTUAL] << endl;
                system("pause");
                break;
            case 2:
                usar_item();
                system("pause");
                break;
            default:
                cout<<"Por favor elegi una opcion valida..." << endl;
                system("pause");
                break;
            }
            turno_ataque_chimpoco = !turno_ataque_chimpoco;
        } else {
            system("cls");
            cout<<"turno del enemigo.."<<endl;
            turno_ataque_chimpoco = !turno_ataque_chimpoco;
            system("pause");
        }
    }
    return 0;
}


int obtenerNumeroRandom(int min, int max) {
    // Generar la semilla basada en el tiempo actual
    srand(time(nullptr));

    // Generar el número aleatorio entre min y max
    return min + rand() % ((max + 1) - min);
}
