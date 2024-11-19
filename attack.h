#ifndef ATTACK_H_INCLUDED
#define ATTACK_H_INCLUDED

#include "constantes.h"

void atacar_chimpoco(int selected_chimpoco[], int enemigo[],bool &game_over,int cont_turnos,bool &congelado,bool &chimpoco_aturdido,bool &enemigo_control,bool &irritado);
void atacar_enemigo(int selected_chimpoco[], int enemigo[],bool &game_over, int cont_turnos,bool &congelado,bool &chimpoco_aturdido,bool &enemigo_control,bool &irritado);
void atacar_versus(int selected_chimpoco[], int enemigo[],int cont_turnos,bool &congelado);
#endif // ATTACK_H_INCLUDED
