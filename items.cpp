#include <iostream>

#include "constantes.h"


using namespace std;

int usar_item(int selected_chimpoco[],int &cargas_ataque,int &cargas_defensa,int &cargas_vida){
    int item_seleccionado;
    bool hay_posiones = false;
    while(hay_posiones == false){
        system("cls");
        cout<<" --- MENU Items ---"<<endl;
        cout<<" 1 - Boost de Ataque por 2 turnos (+30% Ataque) -  " << cargas_ataque << " Carga" <<endl;
        cout<<" 2 - Boost de Defensa por 2 turnos (+20% Defensa) -  " << cargas_defensa << " Carga" <<endl;
        cout<<" 3 - Poción de vida (Cura 50% de la vida total) -  " << cargas_vida << " Carga" <<endl;
        cin>> item_seleccionado;

        switch (item_seleccionado)
            {
            case 1:
                if(cargas_ataque == 0){
                    system("cls");
                    cout<<"no tiene mas posiones de ataque disponibles..."<<endl;
                    cout<<"Por favor elija una opcion valida."<<endl;
                    system("pause");
                    break;
                }
                hay_posiones = true;
                break;
            case 2:
                if(cargas_defensa == 0){
                    system("cls");
                    cout<<"no tiene mas posiones de ataque disponibles..."<<endl;
                    cout<<"Por favor elija una opcion valida."<<endl;
                    system("pause");
                    break;
                }
                hay_posiones = true;
                break;
            case 3:
                if(cargas_vida == 0){
                    system("cls");
                    cout<<"no tiene mas posiones de ataque disponibles..."<<endl;
                    cout<<"Por favor elija una opcion valida."<<endl;
                    system("pause");
                    break;
                }
                hay_posiones = true;
                break;
            default:
                cout<<"Por favor elegi una opcion valida..." << endl;
                system("pause");
                break;
            }

    }


    switch (item_seleccionado)
    {
        case 1:
            selected_chimpoco[DANIO_MIN] *= 1.30;
            selected_chimpoco[DANIO_MAX] *= 1.30;
            cargas_ataque-- ;
            cout<<"cargas de ataque disponibles: "<< cargas_ataque<<endl;

            cout<<"Los nuevos ataques son : " <<endl;
            cout<<"Danio Minimo: "<< selected_chimpoco[DANIO_MIN] << endl;
            cout<<"Danio Maximo: "<< selected_chimpoco[DANIO_MAX] << endl;
            break;
        case 2:
            selected_chimpoco[VIDA_ACTUAL] += (selected_chimpoco[VIDA] * 0.20);
            cargas_defensa--;
            cout<<"Los Nueva vida es : " <<endl;
            cout<<"Vida: "<< selected_chimpoco[VIDA_ACTUAL] << endl;
            break;
        case 3:
            selected_chimpoco[VIDA_ACTUAL] += (selected_chimpoco[VIDA] * 0.50);
            cargas_vida--;
            if(selected_chimpoco[VIDA_ACTUAL] > selected_chimpoco[VIDA]) selected_chimpoco[VIDA_ACTUAL] = selected_chimpoco[VIDA];
            cout<<"Los Nueva vida es : " <<endl;
            cout<<"Vida: "<< selected_chimpoco[VIDA_ACTUAL] << endl;
            break;
    }

 return 0;
}
