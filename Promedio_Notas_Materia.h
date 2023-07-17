#pragma once
#include <iostream>
#include <iomanip>
#include "struct.h"
using namespace std;

void promedio_notas(){
    cout<<left<<setw(13)<<"Matematicas"<<left<<setw(10)<<"Sociales"<<left<<setw(10)<<"Biologia"<<left<<setw(8)<<"Fisica"<<left<<setw(14)<<"Educ. Fisica"<<left<<setw(7)<<"Artes"<<endl;
    float prom_math=0, prom_soci=0, prom_bio=0, prom_fis=0, prom_educ=0, prom_art=0;
    for(int i=0;i<estudiantes;i++){
        int num = stoi(datos_est[i].math);
        prom_math +=num;
        num = stoi(datos_est[i].sociales);
        prom_soci +=num;
        num = stoi(datos_est[i].biologia);
        prom_bio +=num;
        num = stoi(datos_est[i].fisica);
        prom_fis +=num;
        num = stoi(datos_est[i].EF);
        prom_educ +=num;
        num = stoi(datos_est[i].artes);
        prom_art +=num;
    }
    prom_math = prom_math / estudiantes;
    prom_soci = prom_soci / estudiantes;
    prom_bio = prom_bio / estudiantes;
    prom_fis = prom_fis / estudiantes;
    prom_educ = prom_educ / estudiantes;
    prom_art = prom_art / estudiantes;
    cout<<left<<setw(13)<<fixed<<setprecision(2)<<prom_math<<left<<setw(10)<<fixed<<setprecision(2)<<prom_soci<<left<<setw(10)<<fixed<<setprecision(2)<<prom_bio<<left<<setw(8)<<fixed<<setprecision(2)<<prom_fis<<left<<setw(14)<<fixed<<setprecision(2)<<prom_educ<<left<<setw(7)<<fixed<<setprecision(2)<<prom_art<<endl;
}