#pragma once
#include <iostream>
#include "struct.h"
#include <iomanip>
using namespace std;

int total[2], agender[2], bigender[2], female[2], genderfluid[2], genderqueer[2], male[2], nonbinary[2], polygender[2], otro[2];
//[0] como aplazados y [1] como aprobados

void asignar_cero(){
    total[0]=0, agender[0]=0, bigender[0]=0, female[0]=0, genderfluid[0]=0, genderqueer[0]=0, male[0]=0, nonbinary[0]=0, polygender[0]=0, otro[0]=0;
    total[1]=0, agender[1]=0, bigender[1]=0, female[1]=0, genderfluid[1]=0, genderqueer[1]=0, male[1]=0, nonbinary[1]=0, polygender[1]=0, otro[1]=0;
}

void Sumatoria_Notas_Materia(int nota, string gender){
    if (nota<10){
        if(gender=="Agender"){
            total[0]+=1;
            agender[0]+=1;
            otro[0]+=1;
        } else if(gender=="Bigender"){
            total[0]+=1;
            bigender[0]+=1;
            otro[0]+=1;
        } else if(gender=="Female"){
            total[0]+=1;
            female[0]+=1;
        } else if(gender=="Genderfluid"){
            total[0]+=1;
            genderfluid[0]+=1;
            otro[0]+=1;
        } else if(gender=="Genderqueer"){
            total[0]+=1;
            genderqueer[0]+=1;
            otro[0]+=1;
        } else if(gender=="Male"){
            total[0]+=1;
            male[0]+=1;
        } else if(gender=="Non-binary"){
            total[0]+=1;
            nonbinary[0]+=1;
            otro[0]+=1;
        } else if(gender=="Polygender"){
            total[0]+=1;
            polygender[0]+=1;
            otro[0]+=1;
        }
    }else if (nota>=10){
        if(gender=="Agender"){
            total[1]+=1;
            agender[1]+=1;
            otro[1]+=1;
        } else if(gender=="Bigender"){
            total[1]+=1;
            bigender[1]+=1;
            otro[1]+=1;
        } else if(gender=="Female"){
            total[1]+=1;
            female[1]+=1;
        } else if(gender=="Genderfluid"){
            total[1]+=1;
            genderfluid[1]+=1;
            otro[1]+=1;
        } else if(gender=="Genderqueer"){
            total[1]+=1;
            genderqueer[1]+=1;
            otro[1]+=1;
        } else if(gender=="Male"){
            total[1]+=1;
            male[1]+=1;
        } else if(gender=="Non-binary"){
            total[1]+=1;
            nonbinary[1]+=1;
            otro[1]+=1;
        } else if(gender=="Polygender"){
            total[1]+=1;
            polygender[1]+=1;
            otro[1]+=1;
        }
    }
}

void Crear_Archivo(){
    ofstream archivo_notas;
    archivo_notas.open("Materias con sus notas detallado.csv");
    archivo_notas<<"Materias,Total aprobados,Total aplazados,Hombres aprobados,Hombres aplazados,Mujeres aprobadas,Mujeres aplazadas,Agender aprobados,Agender aplazados,Bigender aprobados,Bigender aplazados,Genderfluid aprobados,Genderfluid aplazados,Genderqueer aprobados,Genderqueer aplazados,Non-binary aprobados,Non-binary aplazados,Polygender aprobados, Polygender aplazados"<<endl;
    for(int i=0; i<estudiantes; i++){
        string gender=datos_est[i].genero;
        int nota = stoi(datos_est[i].math);
        Sumatoria_Notas_Materia(nota, gender);
    }
    archivo_notas<<"Matematicas"<<","<<total[1]<<","<<total[0]<<","<<male[1]<<","<<male[0]<<","<<female[1]<<","<<female[0]<<","<<agender[1]<<","<<agender[0]<<","<<bigender[1]<<","<<bigender[0]<<","<<genderfluid[1]<<","<<genderfluid[0]<<","<<genderqueer[1]<<","<<genderqueer[0]<<","<<nonbinary[1]<<","<<nonbinary[0]<<","<<polygender[1]<<","<<polygender[0]<<endl;
    asignar_cero();
    for(int i=0; i<estudiantes; i++){
        string gender=datos_est[i].genero;
        int nota = stoi(datos_est[i].sociales);
        Sumatoria_Notas_Materia(nota, gender);
    }
    archivo_notas<<"Sociales"<<","<<total[1]<<","<<total[0]<<","<<male[1]<<","<<male[0]<<","<<female[1]<<","<<female[0]<<","<<agender[1]<<","<<agender[0]<<","<<bigender[1]<<","<<bigender[0]<<","<<genderfluid[1]<<","<<genderfluid[0]<<","<<genderqueer[1]<<","<<genderqueer[0]<<","<<nonbinary[1]<<","<<nonbinary[0]<<","<<polygender[1]<<","<<polygender[0]<<endl;
    asignar_cero();
    for(int i=0; i<estudiantes; i++){
        string gender=datos_est[i].genero;
        int nota = stoi(datos_est[i].biologia);
        Sumatoria_Notas_Materia(nota, gender);
    }
    archivo_notas<<"Biologia"<<","<<total[1]<<","<<total[0]<<","<<male[1]<<","<<male[0]<<","<<female[1]<<","<<female[0]<<","<<agender[1]<<","<<agender[0]<<","<<bigender[1]<<","<<bigender[0]<<","<<genderfluid[1]<<","<<genderfluid[0]<<","<<genderqueer[1]<<","<<genderqueer[0]<<","<<nonbinary[1]<<","<<nonbinary[0]<<","<<polygender[1]<<","<<polygender[0]<<endl;
    asignar_cero();
    for(int i=0; i<estudiantes; i++){
        string gender=datos_est[i].genero;
        int nota = stoi(datos_est[i].fisica);
        Sumatoria_Notas_Materia(nota, gender);
    }
    archivo_notas<<"Fisica"<<","<<total[1]<<","<<total[0]<<","<<male[1]<<","<<male[0]<<","<<female[1]<<","<<female[0]<<","<<agender[1]<<","<<agender[0]<<","<<bigender[1]<<","<<bigender[0]<<","<<genderfluid[1]<<","<<genderfluid[0]<<","<<genderqueer[1]<<","<<genderqueer[0]<<","<<nonbinary[1]<<","<<nonbinary[0]<<","<<polygender[1]<<","<<polygender[0]<<endl;
    asignar_cero();
    for(int i=0; i<estudiantes; i++){
        string gender=datos_est[i].genero;
        int nota = stoi(datos_est[i].EF);
        Sumatoria_Notas_Materia(nota, gender);
    }
    archivo_notas<<"Educ. Fisica"<<","<<total[1]<<","<<total[0]<<","<<male[1]<<","<<male[0]<<","<<female[1]<<","<<female[0]<<","<<agender[1]<<","<<agender[0]<<","<<bigender[1]<<","<<bigender[0]<<","<<genderfluid[1]<<","<<genderfluid[0]<<","<<genderqueer[1]<<","<<genderqueer[0]<<","<<nonbinary[1]<<","<<nonbinary[0]<<","<<polygender[1]<<","<<polygender[0]<<endl;
    asignar_cero();
    for(int i=0; i<estudiantes; i++){
        string gender=datos_est[i].genero;
        int nota = stoi(datos_est[i].artes);
        Sumatoria_Notas_Materia(nota, gender);
    }
    archivo_notas<<"Artes"<<","<<total[1]<<","<<total[0]<<","<<male[1]<<","<<male[0]<<","<<female[1]<<","<<female[0]<<","<<agender[1]<<","<<agender[0]<<","<<bigender[1]<<","<<bigender[0]<<","<<genderfluid[1]<<","<<genderfluid[0]<<","<<genderqueer[1]<<","<<genderqueer[0]<<","<<nonbinary[1]<<","<<nonbinary[0]<<","<<polygender[1]<<","<<polygender[0]<<endl;
    asignar_cero();
    archivo_notas.close();
}

void eleccion_repetir_menu(){
    cout<< "Desea un archivo con los generos detallados? (1 para si, 0 para no)\n>> ";
    int eleccion;
    cin>>eleccion;
    switch(eleccion){
        case 0:
            break;

        case 1:
            Crear_Archivo();
            break;
        
        default:
            cout<<"Elige bien"<<endl;
            eleccion_repetir_menu();
            break;
    }
}

void Materias_y_Alumnos(){
    cout<<"El numero de la izquierda representa los aprobados, los de la derecha los aplazados"<<endl;
    cout<<left<<setw(14)<<"Materias"<<"|"<<left<<setw(11)<<"Total"<<"|"<<left<<setw(11)<<"Hombres"<<"|"<<left<<setw(11)<<"Mujeres"<<"|"<<left<<setw(11)<<"Otros"<<"|"<<endl;
    for(int i=0; i<estudiantes; i++){
        string gender=datos_est[i].genero;
        int nota = stoi(datos_est[i].math);
        Sumatoria_Notas_Materia(nota, gender);
    }
    cout<<left<<setw(14)<<"Matematicas"<<"|"<<left<<setw(5)<<total[1]<<" "<<left<<setw(5)<<total[0]<<"|"<<left<<setw(5)<<male[1]<<" "<<left<<setw(5)<<male[0]<<"|"<<left<<setw(5)<<female[1]<<" "<<left<<setw(5)<<female[0]<<"|"<<left<<setw(5)<<otro[1]<<" "<<left<<setw(5)<<otro[0]<<"|"<<endl;
    asignar_cero();
    for(int i=0; i<estudiantes; i++){
        string gender=datos_est[i].genero;
        int nota = stoi(datos_est[i].sociales);
        Sumatoria_Notas_Materia(nota, gender);
    }
    cout<<left<<setw(14)<<"Sociales"<<"|"<<left<<setw(5)<<total[1]<<" "<<left<<setw(5)<<total[0]<<"|"<<left<<setw(5)<<male[1]<<" "<<left<<setw(5)<<male[0]<<"|"<<left<<setw(5)<<female[1]<<" "<<left<<setw(5)<<female[0]<<"|"<<left<<setw(5)<<otro[1]<<" "<<left<<setw(5)<<otro[0]<<"|"<<endl;
    asignar_cero();
    for(int i=0; i<estudiantes; i++){
        string gender=datos_est[i].genero;
        int nota = stoi(datos_est[i].biologia);
        Sumatoria_Notas_Materia(nota, gender);
    }
    cout<<left<<setw(14)<<"Biologia"<<"|"<<left<<setw(5)<<total[1]<<" "<<left<<setw(5)<<total[0]<<"|"<<left<<setw(5)<<male[1]<<" "<<left<<setw(5)<<male[0]<<"|"<<left<<setw(5)<<female[1]<<" "<<left<<setw(5)<<female[0]<<"|"<<left<<setw(5)<<otro[1]<<" "<<left<<setw(5)<<otro[0]<<"|"<<endl;
    asignar_cero();
    for(int i=0; i<estudiantes; i++){
        string gender=datos_est[i].genero;
        int nota = stoi(datos_est[i].fisica);
        Sumatoria_Notas_Materia(nota, gender);
    }
    cout<<left<<setw(14)<<"Fisica"<<"|"<<left<<setw(5)<<total[1]<<" "<<left<<setw(5)<<total[0]<<"|"<<left<<setw(5)<<male[1]<<" "<<left<<setw(5)<<male[0]<<"|"<<left<<setw(5)<<female[1]<<" "<<left<<setw(5)<<female[0]<<"|"<<left<<setw(5)<<otro[1]<<" "<<left<<setw(5)<<otro[0]<<"|"<<endl;
    asignar_cero();
    for(int i=0; i<estudiantes; i++){
        string gender=datos_est[i].genero;
        int nota = stoi(datos_est[i].EF);
        Sumatoria_Notas_Materia(nota, gender);
    }
    cout<<left<<setw(14)<<"Educ. Fisica"<<"|"<<left<<setw(5)<<total[1]<<" "<<left<<setw(5)<<total[0]<<"|"<<left<<setw(5)<<male[1]<<" "<<left<<setw(5)<<male[0]<<"|"<<left<<setw(5)<<female[1]<<" "<<left<<setw(5)<<female[0]<<"|"<<left<<setw(5)<<otro[1]<<" "<<left<<setw(5)<<otro[0]<<"|"<<endl;
    asignar_cero();
    for(int i=0; i<estudiantes; i++){
        string gender=datos_est[i].genero;
        int nota = stoi(datos_est[i].artes);
        Sumatoria_Notas_Materia(nota, gender);
    }
    cout<<left<<setw(14)<<"Artes"<<"|"<<left<<setw(5)<<total[1]<<" "<<left<<setw(5)<<total[0]<<"|"<<left<<setw(5)<<male[1]<<" "<<left<<setw(5)<<male[0]<<"|"<<left<<setw(5)<<female[1]<<" "<<left<<setw(5)<<female[0]<<"|"<<left<<setw(5)<<otro[1]<<" "<<left<<setw(5)<<otro[0]<<"|"<<endl;
    asignar_cero();
    eleccion_repetir_menu();
}


