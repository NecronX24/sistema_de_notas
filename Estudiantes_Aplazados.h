#pragma once
#include "struct.h"
#include "Sort_And_Search.h"
#include <iomanip>

void mostrar_estudiantes_aplazados(){
    quicksort(datos_est, 0, estudiantes-1, 9);
    cout<<left<<setw(12)<<"Nombre"<<left<<setw(18)<<"Apellido"<<left<<setw(18)<<"Materias Aplazadas"<<endl;

    int comprobacion=0;

    for(int i=0; i<estudiantes; i++){
        int math = stoi(datos_est[i].math);
        int sociales = stoi(datos_est[i].sociales);
        int biologia = stoi(datos_est[i].biologia);
        int EF = stoi(datos_est[i].EF);
        int artes = stoi(datos_est[i].artes);
        if(math < 10 && sociales < 10 && biologia < 10 && EF < 10 && artes < 10){
            cout<<left<<setw(12)<<datos_est[i].nombre<<left<<setw(18)<<datos_est[i].apellido<<left<<setw(18)<<"Todas"<<endl;
        }

        /*Esta parte del codigo es funcional y fue una prueba para verificar si podia crear una parte
        condicional en la que agarra todos los estudiantes con 4 materias raspadas, sin embargo
        no logre acomodar el quick sort para ello sin tener que crear un monton de particiones y 
        condicionales, por lo que solo queda como una muestra de que es posible hacerlo para 4 materias 
        raspadas y menos raspadas, aunque no de la manera que hubiese querido*/
        int suma=0;
        if (math<10) suma++;
        if (sociales<10) suma++;
        if (biologia<10) suma++;
        if (EF<10) suma++;
        if (artes<10) suma++;
        if (suma == 5) comprobacion=1;
        if (comprobacion==0){
            if(suma==4){
            cout<<left<<setw(12)<<datos_est[i].nombre<<left<<setw(18)<<datos_est[i].apellido<<left<<setw(18)<<"4"<<endl;
            }
        }
    }
    quicksort(datos_est,0,estudiantes-1,2);
}