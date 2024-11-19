#include <iostream>

#include "visuales.h"
#include "constantes.h"
#include "items.h"
#include "attack.h"
#include "random.h"

using namespace std;


int batalla_versus(int selected_chimpoco[], int enemigo[S]) {
    bool turno_ataque_chimpoco = true;
    int random_attack;
    int accion;
    int cargas_ataque = 1,cargas_defensa = 1,cargas_vida = 2 ;
    int cargas_ataque2 = 1,cargas_defensa2 = 1,cargas_vida2 = 2 ;
    bool congelado = false;
    bool congelado2 = false;
    int turnos_congelado = 0;
    int turnos_congelado2 = 0;
    int cont_boost_ataque = 0;
    int cont_boost_defensa = 0;
    int cont_boost_ataque2 = 0;
    int cont_boost_defensa2 = 0;
    int ataque_reiniciado = 0;
    int defensa_reiniciado = 0;
    int ataque_reiniciado2 = 0;
    int defensa_reiniciado2 = 0;

    int cont_turnos = 1;

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
                system("pause");
                selected_chimpoco[DANIO_MIN] /= 1.30;
                selected_chimpoco[DANIO_MAX] /= 1.30;
                ataque_reiniciado = 1;
            }else if(cont_boost_defensa >= 2 && defensa_reiniciado == 0){
                system("cls");
                cout<<endl;
                cout<<"Se acabo el boost de defensa.."<<endl;
                system("pause");
                selected_chimpoco[VIDA_ACTUAL] -= (selected_chimpoco[VIDA] * 0.20);
                defensa_reiniciado = 1;
            }

            if(enemigo[PASIVA] == 4 && congelado == true && turnos_congelado == 0){
                turnos_congelado = 1;
            }
            if(congelado == true && turnos_congelado < 2){
                system("cls");
                cout<<"Tu chimpoco se encuentra congelado...No va a atacar..."<<endl;
                system("pause");
                turnos_congelado++;
                turno_ataque_chimpoco = !turno_ataque_chimpoco;
            }else {
                turnos_congelado = 0;
                congelado = false;
                system("cls");
                cout<<"turno del jugador 1.."<<endl;
                system("pause");
                menu_aventura();
                cin>>accion;


                random_attack = obtenerNumeroRandom(selected_chimpoco[DANIO_MIN], selected_chimpoco[DANIO_MAX]);
                selected_chimpoco[ATAQUE_ACTUAL] = random_attack;


                switch (accion){
                    case 1:
                        cout<<"el ataque de tu chimpoco es de : " << selected_chimpoco[ATAQUE_ACTUAL] << endl;
                        atacar_versus(selected_chimpoco,enemigo,cont_turnos,congelado2);
                        cout<<"la nueva vida del enemigo es de: " << enemigo[VIDA_ACTUAL] << endl;
                        system("pause");
                        turno_ataque_chimpoco = !turno_ataque_chimpoco;
                    break;
                    case 2:
                        if(cargas_ataque == 0 && cargas_defensa == 0 && cargas_vida == 0){
                            cout<<"No tienes mas posiciones.." << endl;
                            cout<<"La unica opcion valida es atacar.."<<endl;
                            atacar_versus(selected_chimpoco,enemigo,cont_turnos,congelado2);
                            cout<<"la nueva vida del enemigo es de: " << enemigo[VIDA_ACTUAL] << endl;
                            turno_ataque_chimpoco = !turno_ataque_chimpoco;
                        }else{
                            usar_item(selected_chimpoco,cargas_ataque,cargas_defensa,cargas_vida);
                        }
                    system("pause");
                    break;
                    default:
                        cout<<"Por favor elegi una opcion valida..." << endl;
                    system("pause");
                    break;
                }

            }


        } else {

            // aumentamos el contador del tiempo del boost
            if(cargas_ataque2 == 0 && ataque_reiniciado2 == 0){
                cont_boost_ataque2++;
            }
            if(cargas_defensa2 == 0 && defensa_reiniciado2 == 0){
                cont_boost_defensa2++;
            }
            //verificamos los tiempos del boost para reiniciar los stats
            if(cont_boost_ataque2 >= 2 && ataque_reiniciado2 == 0){
                system("cls");
                cout<<endl;
                cout<<"Se acabo el boost de ataque.."<<endl;
                system("pause");
                enemigo[DANIO_MIN] /= 1.30;
                enemigo[DANIO_MAX] /= 1.30;
                ataque_reiniciado2 = 1;
            }else if(cont_boost_defensa2 >= 2 && defensa_reiniciado2 == 0){
                system("cls");
                cout<<endl;
                cout<<"Se acabo el boost de defensa.."<<endl;
                system("pause");
                enemigo[VIDA_ACTUAL] -= (enemigo[VIDA] * 0.20);
                defensa_reiniciado2 = 1;
            }
            if(selected_chimpoco[PASIVA] == 4 && congelado2 == true && turnos_congelado2 == 0){
                turnos_congelado2 = 1;
            }
            if(congelado2 == true && turnos_congelado2 < 2){
                system("cls");
                cout<<"Tu chimpoco se encuentra congelado...No va a atacar..."<<endl;
                system("pause");
                turnos_congelado2++;
                turno_ataque_chimpoco = !turno_ataque_chimpoco;
            }else{
                turnos_congelado2 = 0;
                congelado2 = false;
                system("cls");
                cout<<"turno del jugador 2.."<<endl;
                system("pause");
                menu_aventura();
                cin>>accion;


                random_attack = obtenerNumeroRandom(enemigo[DANIO_MIN], enemigo[DANIO_MAX]);
                enemigo[ATAQUE_ACTUAL] = random_attack;


                switch (accion){
                    case 1:
                        cout<<"el ataque de tu chimpoco es de : " << enemigo[ATAQUE_ACTUAL] << endl;
                        atacar_versus(enemigo,selected_chimpoco,cont_turnos,congelado);
                        cout<<"la nueva vida del enemigo es de: " << selected_chimpoco[VIDA_ACTUAL] << endl;
                        system("pause");
                        turno_ataque_chimpoco = !turno_ataque_chimpoco;
                    break;
                    case 2:
                        if(cargas_ataque2 == 0 && cargas_defensa2 == 0 && cargas_vida2 == 0){
                            cout<<"No tienes mas posiciones.." << endl;
                            cout<<"La unica opcion valida es atacar.."<<endl;
                            cout<<"el ataque de tu chimpoco es de : " << enemigo[ATAQUE_ACTUAL] << endl;
                            atacar_versus(enemigo,selected_chimpoco,cont_turnos,congelado);
                            cout<<"la nueva vida del enemigo es de: " << selected_chimpoco[VIDA_ACTUAL] << endl;
                            turno_ataque_chimpoco = !turno_ataque_chimpoco;
                        }else{
                            usar_item(enemigo,cargas_ataque2,cargas_defensa2,cargas_vida2);
                        }
                        system("pause");
                    break;
                    default:
                        cout<<"Por favor elegi una opcion valida..." << endl;
                        system("pause");
                    break;
                }
            }

            cont_turnos++;
        }
    }

    return 0;
};
