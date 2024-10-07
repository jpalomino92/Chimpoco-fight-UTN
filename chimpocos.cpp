#include <iostream>
using namespace std;

int choose_chimpoco(int selected_chimpoco[]){

    while(true){
        system("cls");

        int champion;
        cout << "1 - Rockito " << endl;
        cout << "2 - Picante " << endl;
        cout << "3 - Freddy " << endl;
        cout << "4 - Rayin " << endl;
        cout << "Choose your champion! " << endl;
        cout <<" ----------------------" << endl;
        cin >> champion;

        switch(champion){
        case 1:
            selected_chimpoco[0] = 1200;
            selected_chimpoco[1] = 40;
            selected_chimpoco[2] = 50;
            selected_chimpoco[3] = 1;
            system("cls");
            return 0;
            break;
        case 2:
            selected_chimpoco[0] = 500;
            selected_chimpoco[1] = 55;
            selected_chimpoco[2] = 65;
            selected_chimpoco[3] = 2;
            system("cls");
            return 0;
            break;
        case 3:
            selected_chimpoco[0] = 700;
            selected_chimpoco[1] = 35;
            selected_chimpoco[2] = 55;
            selected_chimpoco[3] = 3;
            system("cls");
            return 0;
            break;
        case 4:
            selected_chimpoco[0] = 600;
            selected_chimpoco[1] = 15;
            selected_chimpoco[2] = 85;
            selected_chimpoco[3] = 4;
            system("cls");
            return 0;
            break;
        default:
            cout << "please choose a valid option: " << endl;
            system("pause");
            break;
        }

    }

return 0;
}


int get_enemies(int enemy []){
    cout<< "lets get the enemies ready..." << endl;


return 0;
}
