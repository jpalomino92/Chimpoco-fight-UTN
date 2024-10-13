#include <iostream>
#include <cstdlib>
#include <string>


#include "visuales.h"
#include "chimpocos.h"
#include "attack.h"
#include "aventura.h"
#include "constantes.h"


using namespace std;


int main(){



    int option;

    int enemies[E][6] = {
    {150, 5, 15, 1,150,0},     // Enemigo 1
    {300, 25, 45, 2,300,0},    // Enemigo 2
    {450, 40, 55, 3,450,0},    // Enemigo 3
    {700, 55, 75, 4,700,0},    // Enemigo 4
    {1500, 25, 150, 5,1500,0}   // Enemigo 5
    };
    string nombre;

    int selected_chimpoco[S] = {};



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




