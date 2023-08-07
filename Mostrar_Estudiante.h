#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "struct.h"
using namespace std;

void mostrar_individual(){
    cout<<"Escribe el ID de la persona a buscar\n>> ";
    int position;
    cin>>position;
    position--;
    try{
    if(position>=estudiantes) throw false;
    float promedio = promediar(position);
    cout<< datos_est[position]. nombre<<" "<< datos_est[position].apellido <<" de genero "<< datos_est[position].genero<< " tiene un promedio de " << fixed <<setprecision(2)<<promedio<< ", su correo es "<<datos_est[position].email<< " y su seccion es la "<< datos_est[position].seccion<<endl;
    }catch(bool flag){
        if (!flag){ 
            cout<<"No se encontro el estudiante que buscas"<<endl;
        }
    }
}

void pasar_a_archivo(){
    outfile.open("Estudiantes_y_Promedio.csv");
    outfile<<"Nombre,Apellido,Genero,Email,Seccion,Notas Promedio"<<endl;
    for (int i=0; i<estudiantes; i++){
        float promedio = promediar(i);
        outfile<<datos_est[i].nombre<<","<<datos_est[i].apellido<<","<< datos_est[i].genero<<","<<datos_est[i].email<<","<< datos_est[i].seccion<<","<< fixed <<setprecision(2)<<promedio<<endl;
    }    
    outfile.close();
}

void eleccion_archivo(){
    int ciclo;
    do{
        ciclo = 0;
        cout<<"Quiere guardar las notas en un archivo? (1 para si, 0 para no)\n>> ";
        int eleccion;
        cin>>eleccion;
        switch(eleccion){
            case 0:
                break;

            case 1:
                pasar_a_archivo();
                break;
            
            default:
                cout<<"Elige bien"<<endl;
                ciclo = 1;
                break;
        }
    }while(ciclo==1);
}

void mostrar_total(){
    cout<< "Se mostraran los alumnos con su nota promedio:"<<endl;
    cout<<left<<setw(12)<<"Nombre"<<left<<setw(18)<<"Apellido"<<left<<setw(12)<<"Genero"<<left<<setw(38)<<"Email"<<left<<setw(8)<<"Seccion"<<left<<setw(14)<<"Notas promedio"<<endl;
    for (int i=0; i<estudiantes; i++){
        float promedio = promediar(i);
        cout<<left<<setw(12)<<datos_est[i].nombre<<left<<setw(18)<<datos_est[i].apellido<<left<<setw(12)<<datos_est[i].genero<<left<<setw(38)<<datos_est[i].email<<left<<setw(8)<<datos_est[i].seccion<<left<<setw(14)<< fixed <<setprecision(2) << promedio<<endl;
    }    
    eleccion_archivo();
}

void menu_mostrar_Estudiante(){
    int ciclo;
    do{
        ciclo = 0;
        cout<<"Elige la opcion que prefieras\n1. Buscar estudiante individual\n2. Promedio de notas de todos los estudiantes\n>> ";
        int eleccion;
        cin>>eleccion;
        if(eleccion==1)
            mostrar_individual();
        else if(eleccion==2)
            mostrar_total();
        else{
            cout<<"Elige bien"<<endl;
            ciclo=1;
        }
    }while(ciclo==1);
}
