#include <iostream>

#include "pasivas.h"
#include "visuales.h"
#include "items.h"
#include "batalla.h"
#include "constantes.h"
#include "estadisticas.h"

using namespace std;

int empezar_aventura(int selected_chimpoco[], int enemies[][S]){


    bool game_over = false;


/// imprimimos las estadisticas del chimpoco.
    system("cls");
    cout<<"Las estadisticas de tu chimpo son:" << endl;
    imprimir_estadisticas_chimpo(selected_chimpoco);

    int enemigo_indice = 0 ;
    int enemigo[6] = {};

    while(game_over == false){
            system("cls");

            for (int i = 0; i < S; i ++ ){
                enemigo[i] = enemies[enemigo_indice][i];//enemigo_indice
            }
            cout<<"Las estadisticas del enemigo son:" << endl;
            imprimir_estadisticas_chimpo(enemigo);
            int cont_turnos = 1;
            selected_chimpoco[VIDA_ACTUAL]= selected_chimpoco[VIDA];
            batalla(selected_chimpoco,enemigo,game_over,cont_turnos);

            if(game_over == false){
                enemigo_indice++;
            }else{
                cout<<"Tu chimpoco fue vencido..."<<endl;
            }


            if(enemigo_indice == 5){
                    //hacer una funcion y que muestre algo mas aparte de esto
                cout<<"sos el chimpocoMaster" << endl;
                game_over = true;
            }
        }



return 0;
}
