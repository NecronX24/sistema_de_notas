#pragma once
#include <iostream>
#include "struct.h"
#include <iomanip>
#include "Agregar_Estudiante.h"

void editar_seleccionado(int i){
    cout<<"Elija el numero del dato a editar\n>> ";
    int eleccion;
    cin>> eleccion;
    int ciclo;
    switch(eleccion){
        case 1:
            cout<<"Elige el nuevo nombre\n>> ";
            cin>>datos_est[i].nombre;
            break;

        case 2:
            cout<<"Elige el nuevo apellido\n>> ";
            cin>>datos_est[i].apellido;
            break;

        case 3:
            cout<<"Elige el nuevo genero:"<<endl;
            seleccion_genero(i);
            break;

        case 4:{
            cout<<"Elige el nuevo email\n>> ";
            cin>>datos_est[i].email;
            break;
        }

        case 5:
            do{
                ciclo = 0;
                cout<<"Elige la nueva seccion\n>> ";
                cin>>datos_est[i].seccion;
                if(datos_est[i].seccion !="A" && datos_est[i].seccion !="B" && datos_est[i].seccion !="C"&& datos_est[i].seccion !="D" && datos_est[i].seccion !="E" && datos_est[i].seccion !="F"){
                    cout<< "Elige bien la seccion"<<endl;
                    ciclo = 1;
                }
            }while(ciclo==1);
            break;

        case 6:
            cout<<"Elige la nueva nota de Matematicas\n>> ";
            cin>>datos_est[i].math;
            break;

        case 7:
            cout<<"Elige la nueva nota de Sociales\n>> ";
            cin>>datos_est[i].sociales;
            break;

        case 8:
            cout<<"Elige la nueva nota de Biologia\n>> ";
            cin>>datos_est[i].biologia;
            break;

        case 9:
            cout<<"Elige la nueva nota de Educacion Fisica\n>> ";
            cin>>datos_est[i].EF;
            break;

        case 10:
            cout<<"Elige la nueva nota de Matematicas\n>> ";
            cin>>datos_est[i].math;
            break;

        default:
            cout<<"Elige bien"<<endl;
            editar_seleccionado(i);
            break;
    }
}

void editar(){
    int position;
    cout<<"Ingrese el ID del estudiante a buscar\n>> ";
    cin>> position;
    position--;
    try{
    if(position>=estudiantes) throw false;
    cout<<left<<setw(12)<<"1.Nombre"<<left<<setw(12)<<"2.Apellido"<<left<<setw(12)<<"3.Genero"<<left<<setw(33)<<"4.Email"<<left<<setw(10)<<"5.Seccion"<<left<<setw(8)<<"6.Maths"<<left<<setw(11)<<"7.Sociales"<<left<<setw(11)<<"8.Biologia"<<left<<setw(11)<<"9.E.Fisica"<<left<<setw(8)<<"10.Artes"<<endl;
    cout<<left<<setw(12)<<datos_est[position].nombre<<left<<setw(12)<<datos_est[position].apellido<<left<<setw(12)<<datos_est[position].genero<<left<<setw(33)<<datos_est[position].email<<left<<setw(10)<<datos_est[position].seccion<<left<<setw(8)<<datos_est[position].math<<left<<setw(11)<<datos_est[position].sociales<<left<<setw(11)<<datos_est[position].biologia<<left<<setw(11)<<datos_est[position].EF<<left<<setw(8)<<datos_est[position].artes<<endl;
    editar_seleccionado(position);
    }catch(bool flag){
        if (!flag){ 
            cout<<"No se encontro el estudiante que buscas"<<endl;
        }
    }
}