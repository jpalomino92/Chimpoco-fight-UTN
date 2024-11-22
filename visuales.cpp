#include <iostream>
#include "constantes.h"
using namespace std;

void menu(){
    cout<<" --- MENU PRINCIPAL ---"<<endl;
    cout<<" 1 - Aventura / elegir chimpoco"<<endl;
    cout<<" 2 - Versus "<<endl;
    cout<<" 3 - God Mode "<<endl;
    cout<<" 4 - Estadisticas "<<endl;
    cout<<" 5 - Manual "<<endl;
    cout<<" 6 - Salir "<<endl;
    cout<<" ----------------------"<<endl;
    cout<<"Ingrese la opcion deseada: "<<endl;
}

void menu_aventura(){
    system("cls");
    cout<<" --- MENU Turno ---"<<endl;
    cout<<" 1 - Atacar "<<endl;
    cout<<" 2 - Usar Item "<<endl;
}

void menu_aventura_god() {
    system("cls");
    cout<<" --- MENU Turno ---"<<endl;
    cout<<" 1 - Atacar "<<endl;
    cout<<" 2 - Usar Item "<<endl;
    cout<<" 3 - Salir "<<endl;
}

void menu_estadisticas(int estadisticas[][S]) {
    for (int i = 0; i < E; i++) {
        system("cls");
        cout<<" --- MENU Estadisticas ---"<<endl;
        cout<<" ------------------------------------------------------------------ "<<endl;
        cout<<" --- MENU Turno Aventura N: "<<i+1<<" ---"<<endl;
        cout<<" Danio Realizado: "<<estadisticas[i][DANIO_REALIZADO] <<endl;
        cout<<" Danio Recibido: "<<estadisticas[i][DANIO_RECIBIDO] <<endl;
        cout<<" Posiones de Ataque utilizadas: "<<estadisticas[i][BOOST_ATAQUE] <<endl;
        cout<<" Posiones de Defensa utilizadas: "<<estadisticas[i][BOOST_DEFENSA] <<endl;
        cout<<" Turnos Sobrevividos: "<<estadisticas[i][TURNOS_SOBREVIVIDOS] <<endl;
        system("pause");
    }
}

void menu_manual() {
    system("cls");
    cout << "Manual De Juego"<<endl;

    cout << "Menu"<<endl;
    
    cout << "Aventura"<<endl;
    cout << "Esta opcion permite a una persona iniciar su aventura de"<<endl;
    cout << "pelear contra los 5 enemigos de los chimpoco. Al elegir comenzar partida, quien"<<endl;
    cout << "este jugando debera ingresar su nombre y luego el programa le ofrecera la"<<endl;
    cout << "opcion de seleccionar el chimpoco que sera su representante en las peleas."<<endl;
    cout << "Luego de elegirlo, comenzara la batalla contra el primer oponente. El"<<endl;
    cout << "ChimpocoTournament consiste en 5 combates de dificultad creciente. Si logran"<<endl;
    cout << "derrotar a los 5 oponentes se consagraran como ChimpocoMasters."<<endl;
    system("pause");
    system("cls");
    cout << "Versus"<<endl;
    cout << "Esta modalidad permitira a dos jugadores enfrentarse entre"<<endl;
    cout << "si en un combate de chimpocomones."<<endl;
    system("pause");
    system("cls");
    cout << "God Mode"<<endl;
    cout << "La modalidad es identica a la Aventura pero tu chimpoco"<<endl;
    cout << "tiene vida 9999 y 99 de cada pocion para utilizar en los combates."<<endl;
    system("pause");
    system("cls");
    cout << "Estadisticas"<<endl;
    cout << "Muestra las estadisticas de las ultimas 5 batallas."<<endl;
    cout << "Danio Realizado, Danio Recibido, Pociones utilizadas y turnos"<<endl;
    cout << "que sobrevivio el chimpoco."<<endl;
    system("pause");
    system("cls");
    cout << "Combates."<<endl;
    cout << "Tiene un sistema de turnos donde en el turno del jugador"<<endl;
    cout << "puedes elegir entre atacar o utilizar pociones."<<endl;
    cout << "El ataque es un ataque aleatoreo entre el ataque maximo y minimo"<<endl;
    cout << "de tu chimpoco."<<endl;
    cout << "Las pociones tenes 1 pociones de ataque, 1 pocion de defensa"<<endl;
    cout << "y 2 pociones de Vida."<<endl;
    system("pause");
    system("cls");
    cout << "Pociones."<<endl;
    cout << "La pocion de Ataque va a brindar un boost de 30% a tu"<<endl;
    cout << "chimpoco en ataque, el efecto dura 2 turnos."<<endl;
    cout << "La pocion de Defensa va a brindad un boost de 20% a tu"<<endl;
    cout << "chimpoco en defensa, ele efecto dura 2 turnos"<<endl;
    cout << "La pocion de Vida cura un 50% de la vida total de tu"<<endl;
    cout << "chimpoco."<<endl;
    system("pause");
    system("cls");
    cout << "Creditos."<<endl;
    cout << "Desarrollado por Juan Palomino"<<endl;
    system("pause");

}

