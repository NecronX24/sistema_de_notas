#pragma once
#include<iostream>
#include <iomanip>
#include "struct.h"
#include "Sort_And_Search.h"

void promedio_math(){
    cout<<"Top 10 de Matematicas:"<<endl;
    cout<<left<<setw(12)<<"Nombre"<<left<<setw(12)<<"Apellido"<<left<<setw(5)<<"Notas"<<endl;
    quicksort(datos_est,0,estudiantes-1,3);
    for(int i=0; i<10;i++){
        cout<<left<<setw(12)<<datos_est[i].nombre<<left<<setw(12)<<datos_est[i].apellido<<left<<setw(5)<<datos_est[i].math<<endl;
    }
}

void promedio_soci(){
    cout<<"Top 10 de Sociales:"<<endl;
    cout<<left<<setw(12)<<"Nombre"<<left<<setw(12)<<"Apellido"<<left<<setw(5)<<"Notas"<<endl;
    quicksort(datos_est,0,estudiantes-1,4);
    for(int i=0; i<10;i++){
        cout<<left<<setw(12)<<datos_est[i].nombre<<left<<setw(12)<<datos_est[i].apellido<<left<<setw(5)<<datos_est[i].sociales<<endl;
    }
}

void promedio_bio(){
    cout<<"Top 10 de Biologia:"<<endl;
    cout<<left<<setw(12)<<"Nombre"<<left<<setw(12)<<"Apellido"<<left<<setw(5)<<"Notas"<<endl;
    quicksort(datos_est,0,estudiantes-1,5);
    for(int i=0; i<10;i++){
        cout<<left<<setw(12)<<datos_est[i].nombre<<left<<setw(12)<<datos_est[i].apellido<<left<<setw(5)<<datos_est[i].biologia<<endl;
    }
}

void promedio_educ(){
    cout<<"Top 10 de Educacion Fisica:"<<endl;
    cout<<left<<setw(12)<<"Nombre"<<left<<setw(12)<<"Apellido"<<left<<setw(5)<<"Notas"<<endl;
    quicksort(datos_est,0,estudiantes-1,6);
    for(int i=0; i<10;i++){
        cout<<left<<setw(12)<<datos_est[i].nombre<<left<<setw(12)<<datos_est[i].apellido<<left<<setw(5)<<datos_est[i].EF<<endl;
    }
}

void promedio_art(){
    cout<<"Top 10 de Artes:"<<endl;
    cout<<left<<setw(12)<<"Nombre"<<left<<setw(12)<<"Apellido"<<left<<setw(5)<<"Notas"<<endl;
    quicksort(datos_est,0,estudiantes-1,7);
    for(int i=0; i<10;i++){
        cout<<left<<setw(12)<<datos_est[i].nombre<<left<<setw(12)<<datos_est[i].apellido<<left<<setw(5)<<datos_est[i].artes<<endl;
    }
}

void promedio_seccion(){
    cout<<"Indique la seccion de la que quiere ver el top (de la A a la F)\n>> ";
    cin>> seccion;
    cout<<"Top 10 de la seccion "<<seccion<<":"<<endl;
    cout<<left<<setw(12)<<"Nombre"<<left<<setw(12)<<"Apellido"<<left<<setw(5)<<"Promedio"<<endl;
    quicksort(datos_est,0,estudiantes-1,8);
    for(int i=0; i<10;i++){
        float promedio = promediar(i);
        cout<<left<<setw(12)<<datos_est[i].nombre<<left<<setw(12)<<datos_est[i].apellido<<left<<setw(5)<<fixed<<setprecision(2)<<promedio<<endl;
    }
}

void top(){
    cout<<"Elige el top a mostrar (si se encuentran estudiantes con la misma nota, se pondran de primeros los de mayor promedio)"<<endl;
    cout<<"1. Top 10 de Matematicas"<<endl;
    cout<<"2. Top 10 de Sociales"<<endl;
    cout<<"3. Top 10 de Biologia"<<endl;
    cout<<"4. Top 10 de Educacion Fisica"<<endl;
    cout<<"5. Top 10 de Artes"<<endl;
    cout<<"6. Top 10 de todas las materias"<<endl;
    cout<<"7. Top 10 de una seccion en especifico"<<endl;
    cout<<">> ";
    int eleccion=0;
    cin>>eleccion;
    switch(eleccion){
        case 1:
            promedio_math();
            break;

        case 2:
            promedio_soci();
            break;

        case 3:
            promedio_bio();
            break;
            
        case 4:
            promedio_educ();
            break;
            
        case 5:
            promedio_art();
            break;
            
        case 6:
            promedio_math();
            cout<<"\n";
            promedio_soci();
            cout<<"\n";
            promedio_bio();
            cout<<"\n";
            promedio_educ();
            cout<<"\n";
            promedio_art();
            cout<<"\n";
            break;
        case 7:
            promedio_seccion();
            break;
        default:
            cout<<"Elige bien"<<endl;
            top();
            break;   
    }
    quicksort(datos_est,0,estudiantes-1,2);
}
