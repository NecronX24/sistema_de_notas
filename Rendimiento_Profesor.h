#pragma once
#include "struct.h"
#include <iomanip>
#include <iostream>
#include "Buscar_Estudiante_Profesor.h"
using namespace std;
//Funcion 12, obtener rendimiento individual
float obtener_rendimiento(int id){
    float rendimiento;
        int aprobados = 0;
        float estudiantes_seccion = 0;
        for(int i=0; i<estudiantes; i++){
            if (datos_profesores[id].seccion==datos_est[i].seccion){
                if (datos_profesores[id].id_materia == "1001"){
                    estudiantes_seccion ++;
                    int nota = stoi(datos_est[i].math);
                    if(nota>=10){
                        aprobados++;
                    }
                } else if (datos_profesores[id].id_materia == "1002"){
                    estudiantes_seccion ++;
                    int nota = stoi(datos_est[i].sociales);
                    if(nota>=10){
                        aprobados++;
                    }
                } else if (datos_profesores[id].id_materia == "1003"){
                    estudiantes_seccion ++;
                    int nota = stoi(datos_est[i].biologia);
                    if(nota>=10){
                        aprobados++;
                    }
                }else if (datos_profesores[id].id_materia == "1004"){
                    estudiantes_seccion ++;
                    int nota = stoi(datos_est[i].EF);
                    if(nota>=10){
                        aprobados++;
                    }
                } else if (datos_profesores[id].id_materia == "1005"){
                    estudiantes_seccion ++;
                    int nota = stoi(datos_est[i].artes);
                    if(nota>=10){
                        aprobados++;
                    }
                }
            }
        }
        return (aprobados/estudiantes_seccion) * 100;
}

void rendimiento_profesor(){
    try{
        cout<<"Indica el ID del profesor a evaluar\n>> ";
        int id;
        cin>>id;
        if(id<1 || id>profesores){
            throw false;
        }
        id--;
        float rendimiento = obtener_rendimiento(id);
        cout<<"El rendimiento del profesor "<<datos_profesores[id].nombre<<" "<<datos_profesores[id].apellido<<" es de "<<fixed<<setprecision(2)<<rendimiento<<"%"<<endl;
    }catch(bool flag){
        if(!flag){
            cout<<"El ID indicado es erroneo"<<endl;
            rendimiento_profesor();
        }

    }
}

//Funcion 13, mejor rendimiento
struct rendimiento_struct{
    int id;
    float porcentaje;
};

rendimiento_struct *mejor_rendimiento = new rendimiento_struct [1];
int lenght_rendimiento = 1;

void extender_mejor_rendimiento(){
    rendimiento_struct *temp= new rendimiento_struct[lenght_rendimiento];
            for (int i=0; i<lenght_rendimiento; i++){
                temp[i]=mejor_rendimiento[i];
            }
            delete[] mejor_rendimiento;
            lenght_rendimiento = lenght_rendimiento * 2;
            mejor_rendimiento = new rendimiento_struct [lenght];
            for (int i=0; i<(lenght_rendimiento/2); i++){
                mejor_rendimiento[i]=temp[i];
            }
            delete[] temp;
}

int contador=0;

void mejor_rendimiento_funcion(int i){ 
    float rendimiento =obtener_rendimiento(i);
    if (rendimiento>mejor_rendimiento[0].porcentaje){
        contador = 0;
        mejor_rendimiento[0].porcentaje = rendimiento;
        mejor_rendimiento[0].id = i;
        contador++;
    }else if(rendimiento==mejor_rendimiento[0].porcentaje){
           if(contador>=lenght_rendimiento){
             extender_mejor_rendimiento;
          }
           mejor_rendimiento[contador].porcentaje = rendimiento;
           mejor_rendimiento[contador].id = i;
           contador++;
    }
}

void mejor_rendimiento_en_pantalla(){
    mejor_rendimiento[0].id = 0;
    mejor_rendimiento[0].porcentaje = 0.00;
    int ciclo;
    do{
        ciclo = 0;
        cout<<"Elija su opcion\n1. Mejor rendimiento por seccion\n2. Mejor rendimiento por materia\n>> ";
        int eleccion, materia_rendimiento;
        cin>> eleccion;
        string seccion_rendimiento, materia_ID;

        switch(eleccion){
            case 1:
                do{
                    ciclo = 0;
                    cout<<"Indica la seccion a buscar\n>> ";
                    cin>> seccion_rendimiento;
                if(seccion_rendimiento !="A" && seccion_rendimiento !="B" && seccion_rendimiento !="C"&& seccion_rendimiento !="D" && seccion_rendimiento !="E" && seccion_rendimiento !="F"){
                        cout<< "Elige bien la seccion"<<endl;
                        ciclo = 1;
                    }
                }while(ciclo==1);
                for(int i=0; i<profesores; i++){
                    if (seccion_rendimiento == datos_profesores[i].seccion){
                        mejor_rendimiento_funcion(i);
                    }
                }
                break;

            case 2:
                cout<<"Elige la materia a buscar\n1. Matematicas   2. Sociales   3. Biologia   4. EF   5. Artes\n>> ";
                cin>> materia_rendimiento;
                while(materia_rendimiento<0 || materia_rendimiento>5){
                    cout<<"Elige bien\n>> ";
                    cin>>materia_rendimiento;
                }
                materia_ID = buscar_materia_por_ID(materia_rendimiento);
                for(int i=0; i<profesores; i++){
                    if (materia_ID == datos_profesores[i].id_materia){
                        mejor_rendimiento_funcion(i);
                    }
                }
                break;

            default:
                cout<<"Elige bien"<<endl;
                ciclo = 1;
                break;
        }
    }while(ciclo==1);

    cout<<left<<setw(12)<<"Nombre"<<left<<setw(18)<<"Apellido"<<left<<setw(11)<<"Rendimiento"<<endl;
    for(int i=0; i<contador ;i++){
        cout<<left<<setw(12)<<datos_profesores[mejor_rendimiento[i].id].nombre<<left<<setw(18)<<datos_profesores[mejor_rendimiento[i].id].apellido<<fixed<<setprecision(2)<<mejor_rendimiento[i].porcentaje<<"%"<<endl;
    }
}