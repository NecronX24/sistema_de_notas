#pragma once
#include <iostream>
#include <iomanip>
#include "struct.h"
#include "Sort_And_Search.h"
using namespace std;

void boleta_archivo(int position){
    outfile.open("Boleta_Estudiante.csv");
    outfile<<"Nombre,Apellido,Email,Genero,Matematicas,Sociales,Biologia,Educacion Fisica,Artes"<<endl;
    outfile<<datos_est[position].nombre<<","<<datos_est[position].apellido<<","<<datos_est[position].genero<<","<<datos_est[position].email<<","<<datos_est[position].seccion<<","<<datos_est[position].math<<","<<datos_est[position].sociales<<","<<datos_est[position].biologia<<","<<datos_est[position].EF<<","<<datos_est[position].artes<<endl;
    outfile.close();
}

void hacer_boleta(){
    cout<<"Coloca el nombre y el apellido del estudiante a buscar\n>> ";
    string nombre, apellido;
    cin>>nombre>>apellido;
    quicksort(datos_est,0,estudiantes-1,1);
    try{
    int position = exponentialSearch(datos_est, estudiantes-1, nombre, apellido);
    cout<<left<<setw(19)<<"Nombre y apellido: "<<datos_est[position].nombre<<" "<<datos_est[position].apellido<<endl;
    cout<<left<<setw(19)<<"Genero: "<<datos_est[position].genero<<endl;
    cout<<left<<setw(19)<<"Email: "<<datos_est[position].email<<endl;
    cout<<left<<setw(19)<<"Seccion: "<<datos_est[position].seccion<<endl;
    cout<<left<<setw(19)<<"Matematicas: "<<datos_est[position].math<<endl;
    cout<<left<<setw(19)<<"Sociales: "<<datos_est[position].sociales<<endl;
    cout<<left<<setw(19)<<"Biologia: "<<datos_est[position].biologia<<endl;
    cout<<left<<setw(19)<<"Educacion Fisica: "<<datos_est[position].EF<<endl;
    cout<<left<<setw(19)<<"Artes: "<<datos_est[position].artes<<endl;
    int eleccion, ciclo;
    do{
        ciclo = 0;
        cout<<"Quiere pasar los datos a archivo .csv? (1 para si, 0 para no)\n>> ";
        cin>>eleccion;
        if(eleccion==1){
            boleta_archivo(position);
        }else if (eleccion!=0){
            cout<<"Elige bien"<<endl;
            ciclo=1;
        }
    }while(ciclo==1);

    }catch(bool flag){
        if (!flag){ 
            cout<<"No se encontro el estudiante que buscas"<<endl;
        }
    }

    quicksort(datos_est,0,estudiantes-1,2);
}