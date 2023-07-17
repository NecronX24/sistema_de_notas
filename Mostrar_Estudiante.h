#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "Sort_And_Search.h"
#include "struct.h"
using namespace std;

void mostrar_individual(){
    quicksort(datos_est,0,estudiantes-1,1);
    cout<<"Escribe el nombre y apellido de la persona a buscar\n>> ";
    string nombre, apellido;
    cin>>nombre>>apellido;
    try{
    int position = exponentialSearch(datos_est, estudiantes-1, nombre, apellido);
    float promedio = promediar(position);
    cout<< datos_est[position]. nombre<<" "<< datos_est[position].apellido << " tiene un promedio de " << fixed <<setprecision(2) << promedio<<endl;
    }catch(bool flag){
        if (!flag){ 
            cout<<"No se encontro el estudiante que buscas"<<endl;
        }
    }
    quicksort(datos_est,0,estudiantes-1,2);
}

void pasar_a_archivo(){
    outfile.open("Estudiantes_y_Promedio.csv");
    outfile<<"Nombre,Apellido,Notas Promedio"<<endl;
    for (int i=0; i<estudiantes; i++){
        float promedio = promediar(i);
        outfile<<datos_est[i].nombre<<","<<datos_est[i].apellido<<","<< fixed <<setprecision(2) << promedio<<endl;
    }    
    outfile.close();
}

void eleccion_archivo(){
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
            eleccion_archivo();
            break;
    }
}

void mostrar_total(){
    cout<< "Se mostraran los alumnos con su nota promedio:"<<endl;
    cout<<left<<setw(12)<<"Nombre"<<left<<setw(12)<<"Apellido"<<left<<setw(14)<<"Notas promedio"<<endl;
    for (int i=0; i<estudiantes; i++){
        float promedio = promediar(i);
        cout<<left<<setw(12)<<datos_est[i].nombre<<left<<setw(12)<<datos_est[i].apellido<<left<<setw(14)<< fixed <<setprecision(2) << promedio<<endl;
    }    
    eleccion_archivo();
}

void menu_mostrar_Estudiante(){
    cout<<"Elige la opcion que prefieras\n1. Buscar estudiante individual\n2. Promedio de notas de todos los estudiantes\n>> ";
    int eleccion;
    cin>>eleccion;
    if(eleccion==1)
        mostrar_individual();
    else if(eleccion==2)
        mostrar_total();
    else{
        cout<<"Elige bien"<<endl;
        menu_mostrar_Estudiante();
    }
}
