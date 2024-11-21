#include <iostream>
#include <cstdlib>
#include <string>


#include "visuales.h"
#include "chimpocos.h"
#include "aventura.h"
#include "constantes.h"
#include "versus.h"
#include "dado.h"


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
    int dado,dado2;
    bool god_mode = false;


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
            empezar_aventura(selected_chimpoco,enemies,god_mode);


            system("pause");
            break;
        case 2:
            system("cls");
            cout << "Ingrese el nombre del jugador 1: " << endl;
            cin.ignore();
            getline( cin, nombre);

            system("cls");
            cout << "Ingrese el nombre del jugador 2: " << endl;
            cin.ignore();
            getline( cin, nombre2);

            system("cls");
            cout<<"Ambos Jugadores tiraran un dado, el que tenga el numero mas alto elige primero su chimpoco.."<<endl;
            cout<<"Tira el primer dado Jugador 1: "<<nombre<<endl;
            system("pause");
            dado = tirarDado();
            cout<<"El numero tirado fue:"<<dado<<endl;
            system("pause");
            system("cls");
            cout<<"Ahora tirara el dado el jugador 2:" <<nombre2<<endl;
            system("pause");
            dado2 = tirarDado();
            cout<<"El numero tirado fue: "<<dado2<<endl;
            system("pause");
            system("cls");

            if (dado > dado2){
                cout<<"elige primero el jugador: "<<nombre<<endl;
                system("pause");
                choose_chimpoco(selected_chimpoco);
            }else {
                system("cls");
                cout<<"elige primero el jugador: "<<nombre2<<endl;
                system("pause");
                choose_chimpoco(selected_chimpoco2);
            }

            if(dado > dado2) {
                system("cls");
                cout<<"elige el jugador: "<<nombre2<<endl;
                system("pause");
                choose_chimpoco(selected_chimpoco2);
            }else{
                system("cls");
                cout<<"elige primero el jugador: "<<nombre<<endl;
                system("pause");
                choose_chimpoco(selected_chimpoco);
            }

            batalla_versus(selected_chimpoco,selected_chimpoco2);

            if(selected_chimpoco[VIDA_ACTUAL] == 0) {
                system("cls");
                cout << "El ganador es el jugador: "<<nombre2 << endl;
                system("pause");
            }else{
                system("cls");
                cout << "El ganador es el jugador: "<<nombre << endl;
                system("pause");
            }

            break;
        case 3:
            god_mode = true;
            system("cls");
            cout<<"Ingresaste al modo Dios, la vida de tu chimpoco sera de 9999 y tendras 99 pociones y nunca se acaba el efecto..."<<endl;
            cout << "Ingrese su nombre: " << endl;
            cin.ignore();
            getline( cin, nombre);

            choose_chimpoco(selected_chimpoco);
            selected_chimpoco[VIDA] = 9999;
            empezar_aventura(selected_chimpoco,enemies,god_mode);
            god_mode = false;

            system("pause");
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            system("cls");
            cout<<"Saliendo del programa."<<endl;
            system("pause");
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




