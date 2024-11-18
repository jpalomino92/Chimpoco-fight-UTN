#include <iostream>
#include <ctime>


#include "visuales.h"
#include "constantes.h"
#include "pasivas.h"


using namespace std;

void atacar_chimpoco(int selected_chimpoco[], int enemigo[],bool &game_over,int cont_turnos,bool &congelado,bool &chimpoco_aturdido){
    //llamo pasiva
    if(enemigo[PASIVA] == 3){pasiva_enemigo(enemigo,cont_turnos,chimpoco_aturdido,selected_chimpoco);}
    if(selected_chimpoco[PASIVA] != 1){pasiva_chimpoco(selected_chimpoco,enemigo,cont_turnos,congelado);}
    enemigo[VIDA_ACTUAL] -= selected_chimpoco[ATAQUE_ACTUAL];
    if(enemigo[VIDA_ACTUAL] < 0){
        enemigo[VIDA_ACTUAL] = 0;

    }


}


void atacar_enemigo(int selected_chimpoco[], int enemigo[],bool &game_over,int cont_turnos,bool &congelado,bool &chimpoco_aturdido){
    //llamo pasiva
    if(selected_chimpoco[PASIVA] == 1){pasiva_chimpoco(selected_chimpoco,enemigo,cont_turnos,congelado);}
    if(enemigo[PASIVA] != 3){pasiva_enemigo(enemigo,cont_turnos,chimpoco_aturdido,selected_chimpoco);}
    selected_chimpoco[VIDA_ACTUAL] -= enemigo[ATAQUE_ACTUAL];
    if(selected_chimpoco[VIDA_ACTUAL] < 0){
            selected_chimpoco[VIDA_ACTUAL] = 0;
            game_over= true;
    }
}
