#include <iostream>

#include "constantes.h"
#include "pasivas.h"


using namespace std;


int imprimir_estadisticas_chimpo(int chimpo[]){

    cout <<"La vida es: " <<chimpo[VIDA]<<endl;
    cout <<"El danio Minimo es: "<<chimpo[DANIO_MIN] << endl;
    cout <<"El danio Maximo es: "<<chimpo[DANIO_MAX] << endl;
    cout <<"La pasiva es: ";
    imprimir_pasivas_chimpocos(chimpo[PASIVA]);
    system("pause");

 return 0;
}
