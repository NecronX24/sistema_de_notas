#pragma once
#include "struct.h"
#include <iomanip>
#include <iostream>
using namespace std;

void rendimiento_profesor(){
    try{
        cout<<"Indica el ID del profesor a evaluar\n>> ";
        int id;
        cin>>id;
        if(id<1 || id>profesores){
            throw false;
        }
        id--;
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
                    cout<< estudiantes_seccion<<","<<aprobados<<endl;
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
        rendimiento = (aprobados/estudiantes_seccion) * 100;
        cout<<"El rendimiento del profesor "<<datos_profesores[id].nombre<<" "<<datos_profesores[id].apellido<<" es de "<<fixed<<setprecision(2)<<rendimiento<<"%"<<endl;
    }catch(bool flag){
        if(!flag){
            cout<<"El ID indicado es erroneo"<<endl;
            rendimiento_profesor();
        }

    }
}