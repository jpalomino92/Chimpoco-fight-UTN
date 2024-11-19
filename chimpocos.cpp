#include <iostream>
#include <ctime>

using namespace std;


int choose_chimpoco(int selected_chimpoco[]){
    system("cls");

    cout << "En un mundo muy muy lejano," << endl;
    cout << "existe una raza de animales extraordinarios" << endl;
    cout << "con habilidades especiales, hoy tendras el honor" << endl;
    cout << "de elegir a tu compa�ero de batalla," << endl;
    cout << "a tu primer Chimpoco!" << endl;
    cout << "Estas listo para el gran torneo y convertirte en el campion de los chimpocos?!" << endl;
    cout << "Vamos!" << endl;

    system("pause");

    while(true){
        system("cls");

        int champion;
        cout << "1 - Rockito " << endl;
        cout << "2 - Picante " << endl;
        cout << "3 - Freddy " << endl;
        cout << "4 - Rayin " << endl;
        cout << "Elige a tu campion! " << endl;
        cout <<" ----------------------" << endl;
        cin >> champion;

        switch(champion){
        case 1:
            selected_chimpoco[0] = 1200;
            selected_chimpoco[1] = 40;
            selected_chimpoco[2] = 50;
            selected_chimpoco[3] = 1;
            selected_chimpoco[4] = 1200;
            selected_chimpoco[5] = 0;
            system("cls");
            return 0;
            break;
        case 2:
            selected_chimpoco[0] = 500;
            selected_chimpoco[1] = 55;
            selected_chimpoco[2] = 65;
            selected_chimpoco[3] = 2;
            selected_chimpoco[4] = 500;
            selected_chimpoco[5] = 0;
            system("cls");
            return 0;
            break;
        case 3:
            selected_chimpoco[0] = 700;
            selected_chimpoco[1] = 35;
            selected_chimpoco[2] = 55;
            selected_chimpoco[3] = 3;
            selected_chimpoco[4] = 700;
            selected_chimpoco[5] = 0;
            system("cls");
            return 0;
            break;
        case 4:
            selected_chimpoco[0] = 600;
            selected_chimpoco[1] = 15;
            selected_chimpoco[2] = 85;
            selected_chimpoco[3] = 4;
            selected_chimpoco[4] = 600;
            selected_chimpoco[5] = 0;
            system("cls");

            return 0;
            break;
        default:
            cout << "por favor elige una opcion valida: " << endl;
            system("pause");
            break;
        }

    }

return 0;
}


