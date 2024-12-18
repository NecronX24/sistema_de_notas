#pragma once
#include "struct.h"

string buscar_materia_por_ID(int i){
switch(i){
                case 1:
                    return "1001";
                    break;
                
                case 2:
                    return "1002";
                    break;

                case 3:
                    return "1003";
                    break;

                case 4:
                    return "1004";
                    break;
                
                case 5:
                    return "1005";
                    break;
            }
        return "Error";
}

void buscar_estudiante_profesor(){
    cout<< "Indique el ID del estudiante que desea buscar\n>> ";
    int id, ciclo, materia_buscar;
    int no_profesor=0;
    string materia;
    cin>> id;
    id--;
    cout<< "El estudiante buscado es "<<datos_est[id].nombre<<" "<< datos_est[id].apellido<<endl;
    do{
        ciclo = 0;
        cout<< "Indique la materia que quiere buscar:"<<endl;
        cout<< "1. Matematicas   2. Sociales   3. Biologia   4. EF    5. Artes\n>> ";
        cin>> materia_buscar;
        if (materia_buscar>0 && materia_buscar<6){
            materia = buscar_materia_por_ID(materia_buscar);
            for(int i=0; i<profesores; i++){
                if (datos_profesores[i].seccion==datos_est[id].seccion && materia== datos_profesores[i].id_materia){
                    if (no_profesor==0){
                        cout<<"Profesor:"<<endl;
                        no_profesor=1;
                    }
                    cout<< datos_profesores[i].nombre<<" "<<datos_profesores[i].apellido<<endl;
                }
            }
            if(no_profesor==0){
                cout<<"No hay profesor de la materia"<<endl;
            }
            
        }else{
            cout<<"Eleccion erronea"<<endl;
            ciclo =1;
        }
        }while(ciclo==1);
    }
