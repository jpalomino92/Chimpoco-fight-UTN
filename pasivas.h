#ifndef PASIVAS_H_INCLUDED
#define PASIVAS_H_INCLUDED


void imprimir_pasivas_chimpocos(int pasiva);
void imprimir_pasivas_enemigos(int pasiva);
void pasiva_chimpoco(int selected_chimpoco[],int enemigo[],int turno,bool &congelado);
void pasiva_enemigo(int enemigo[],int turno,bool &chimpoco_aturdido,int selected_chimpoco[],bool &enemigo_control,bool &irritado);


#endif // PASIVAS_H_INCLUDED
