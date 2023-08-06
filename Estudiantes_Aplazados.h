#pragma once
#include "struct.h"
#include "Sort_And_Search.h"
#include <iomanip>

void mostrar_estudiantes_aplazados(){
    quicksort(datos_est, 0, estudiantes-1, 9);
    cout<<left<<setw(12)<<"Nombre"<<left<<setw(18)<<"Apellido"<<left<<setw(18)<<"Materias Aplazadas"<<endl;
    for(int i=0; i<estudiantes; i++){
        int math = stoi(datos_est[i].math);
        int sociales = stoi(datos_est[i].sociales);
        int biologia = stoi(datos_est[i].biologia);
        int EF = stoi(datos_est[i].EF);
        int artes = stoi(datos_est[i].artes);
        if(math < 10 && sociales < 10 && biologia < 10 && EF < 10 && artes < 10){
            cout<<left<<setw(12)<<datos_est[i].nombre<<left<<setw(18)<<datos_est[i].apellido<<left<<setw(18)<<"5"<<endl;
        }
    }

    quicksort(datos_est,0,estudiantes-1,2);
}