#include <iostream>
#include <cstdlib>
#include <ctime>


#include"visuales.h"
#include"chimpocos.h"

int obtenerNumeroRandom(int min, int max);

using namespace std;


int main()
{
    int option;
    int S = 4;
    int E = 5;
    int selected_chimpoco[S] = {};
    int enemies[E][S];
    int enemy[S];
    int random_attack;
    while (true)
    {
        system("cls");
        menu();
        cin>>option;
        switch (option)
        {
        case 1:
            choose_chimpoco(selected_chimpoco);
            for (int i = 0; i < S; i ++ ){
                cout << selected_chimpoco[i] << endl;
            }

            for (int j = 0; j < E; j ++ ){
                get_enemies(enemy);

            }
            //attack(selected_chimpoco , enemies)
            //aca calculamos el ataque entre el maxi y minimo del ataque del vector posision 1 (min ataque) posicion 2 (Max ataque)
            random_attack = obtenerNumeroRandom(selected_chimpoco[1], selected_chimpoco[2]);
            cout <<"El ataque del chimpoco es: " <<random_attack << endl;
            system("pause");
            break;
        case 2:
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



int obtenerNumeroRandom(int min, int max) {
    // Generar la semilla basada en el tiempo actual
    std::srand(std::time(nullptr));

    // Generar el número aleatorio entre min y max
    return min + std::rand() % ((max + 1) - min);
}
