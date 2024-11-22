#include <iostream>

#include "visuales.h"
#include "constantes.h"
#include "items.h"
#include "attack.h"
#include "random.h"

using namespace std;



int batalla(int selected_chimpoco[], int enemigo[S],bool &game_over,int cont_turnos,bool god_mode,int estadisticas[][S],int aventura){

    bool turno_ataque_chimpoco = true;
    int random_attack;
    int accion;
    int cargas_ataque = 1,cargas_defensa = 1,cargas_vida = 2 ;
    bool congelado = false;
    bool chimpoco_aturdido = false;
    int turnos_congelado = 0;
    int cont_boost_ataque = 0;
    int cont_boost_defensa = 0;
    int ataque_reiniciado = 0;
    int defensa_reiniciado = 0;
    bool enemigo_control = false;
    bool irritado = false;

    if(god_mode){cargas_ataque = 99,cargas_defensa = 99,cargas_vida = 99;}

    while(enemigo[VIDA_ACTUAL] > 0 && selected_chimpoco[VIDA_ACTUAL] > 0){
        system("cls");
        cout<<"turno numero: " << cont_turnos <<endl;
        system("pause");


        if (turno_ataque_chimpoco){

            // aumentamos el contador del tiempo del boost
            if(cargas_ataque == 0 && ataque_reiniciado == 0){
                cont_boost_ataque++;
            }
            if(cargas_defensa == 0 && defensa_reiniciado == 0){
                cont_boost_defensa++;
            }
            //verificamos los tiempos del boost para reiniciar los stats
            if(cont_boost_ataque >= 2 && ataque_reiniciado == 0){
                system("cls");
                cout<<endl;
                cout<<"Se acabo el boost de ataque.."<<endl;
                selected_chimpoco[DANIO_MIN] /= 1.30;
                selected_chimpoco[DANIO_MAX] /= 1.30;
                ataque_reiniciado = 1;
            }else if(cont_boost_defensa >= 2 && defensa_reiniciado == 0){
                system("cls");
                cout<<endl;
                cout<<"Se acabo el boost de defensa.."<<endl;
                selected_chimpoco[VIDA_ACTUAL] -= (selected_chimpoco[VIDA] * 0.20);
                defensa_reiniciado = 1;
            }

            //en caso de estar aturdido se va a saltar el turno del chimpoco

            if(chimpoco_aturdido == false ){
                // verifico si el enemigo esta en control o no, si esta en control no pido la entrada de datos del cliente y configuro un numero random
                if(enemigo_control == true) {
                    system("cls");
                    cout<<"Se activo la pasiva de BabyYorda!..."<<endl;
                    cout<<"Baby Yorda a tomado el control de tu chimpoco.."<<endl;
                    accion=obtenerNumeroRandom(1,2);
                    cout<<accion<<endl;
                    enemigo_control = false;
                    system("pause");
                }else {
                    if(god_mode) {
                        menu_aventura_god();
                        cin>>accion;
                        if(accion == 3){return 1;}
                    }else {
                        menu_aventura();
                        cin>>accion;
                    }

                }
                if(irritado == true) {
                    random_attack = obtenerNumeroRandom(selected_chimpoco[DANIO_MIN], selected_chimpoco[DANIO_MAX]);
                    selected_chimpoco[ATAQUE_ACTUAL] = random_attack * 0.80;

                }else {
                    random_attack = obtenerNumeroRandom(selected_chimpoco[DANIO_MIN], selected_chimpoco[DANIO_MAX]);
                    selected_chimpoco[ATAQUE_ACTUAL] = random_attack;
                }

                switch (accion){
                    case 1:
                        cout<<"el ataque de tu chimpoco es de : " << selected_chimpoco[ATAQUE_ACTUAL] << endl;
                        atacar_chimpoco(selected_chimpoco,enemigo,game_over,cont_turnos,congelado,chimpoco_aturdido,enemigo_control,irritado, estadisticas,aventura);
                        cout<<"la nueva vida del enemigo es de: " << enemigo[VIDA_ACTUAL] << endl;
                        system("pause");
                        break;
                    case 2:
                        if(cargas_ataque == 0 && cargas_defensa == 0 && cargas_vida == 0){
                            cout<<"No tienes mas posiciones.." << endl;
                            cout<<"La unica opcion valida es atacar.."<<endl;
                            atacar_chimpoco(selected_chimpoco,enemigo,game_over,cont_turnos,congelado,chimpoco_aturdido,enemigo_control,irritado, estadisticas,aventura);
                            cout<<"la nueva vida del enemigo es de: " << enemigo[VIDA_ACTUAL] << endl;
                        }else{
                            usar_item(selected_chimpoco,cargas_ataque,cargas_defensa,cargas_vida, estadisticas,aventura);
                        }
                        system("pause");
                        break;
                    default:
                        cout<<"Por favor elegi una opcion valida..." << endl;
                        system("pause");
                        break;
                }
            }else{
                system("cls");
                cout<<"El chimpoco se encuentra aturdido...Se pierde un turno."<<endl;
                chimpoco_aturdido = false;
                system("pause");
            }

            turno_ataque_chimpoco = !turno_ataque_chimpoco;
        } else {
            // Chequeamos si esta congelado, en el primero solamente estaria"paralizado"
            // por lo que modifico el contador para que dure solo 1 turno
            if(selected_chimpoco[PASIVA] == 4 && congelado == true && turnos_congelado == 0){
                turnos_congelado = 1;
            }
            if(congelado == true && turnos_congelado < 2){
                system("cls");
                cout<<"El enemigo se encuentra congelado...No va a atacar..."<<endl;
                turnos_congelado++;
                turno_ataque_chimpoco = !turno_ataque_chimpoco;
            }else{
                turnos_congelado = 0;
                congelado = false;
                system("cls");
                cout<<"turno del enemigo.."<<endl;
                if (irritado) {
                    random_attack = obtenerNumeroRandom(enemigo[DANIO_MIN], enemigo[DANIO_MAX]);
                    enemigo[ATAQUE_ACTUAL] = random_attack * 1.15;
                    irritado = false;
                }else {
                    random_attack = obtenerNumeroRandom(enemigo[DANIO_MIN], enemigo[DANIO_MAX]);
                    enemigo[ATAQUE_ACTUAL] = random_attack;
                }
                cout<<"el ataque del enemigo es de : " << enemigo[ATAQUE_ACTUAL] << endl;
                atacar_enemigo(selected_chimpoco,enemigo,game_over,cont_turnos,congelado,chimpoco_aturdido,enemigo_control,irritado, estadisticas,aventura);
                cout<<"la nueva vida del chimpoco es de: " << selected_chimpoco[VIDA_ACTUAL] << endl;
                turno_ataque_chimpoco = !turno_ataque_chimpoco;
            }
            cont_turnos++;
            estadisticas[aventura][TURNOS_SOBREVIVIDOS]++;
            system("pause");
        }
    }
     if(ataque_reiniciado == 0 && cargas_ataque == 0){
                selected_chimpoco[DANIO_MIN] /= 1.30;
                selected_chimpoco[DANIO_MAX] /= 1.30;}

    return 0;
}



