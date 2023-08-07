#pragma once
#include <iostream>
#include "struct.h"
using namespace std;

void seleccion_genero(int i){
    int ciclo;
    do{
    cout<<"1. Male   2. Female   3. Agender   4. Bigender   5. Genderfluid   6. Genderqueer   7. Non-binary   8. Polygender\n>> ";
            int genero;
            cin>>genero;
                ciclo=0;
                switch(genero){
                    case 1:
                        datos_est[i].genero="Male";
                        break;
                    
                    case 2:
                        datos_est[i].genero="Female";
                        break;

                    case 3:
                        datos_est[i].genero="Agender";
                        break;

                    case 4:
                        datos_est[i].genero="Bigender";
                        break;

                    case 5:
                        datos_est[i].genero="Genderfluid";
                        break;
                       
                    case 6:
                        datos_est[i].genero="Genderqueer";
                        break;
                    
                    case 7:
                        datos_est[i].genero="Non-binary";
                        break;
                    
                    case 8:
                        datos_est[i].genero="Polygender";
                        break;
                    
                    default:
                        cout<<"Elige bien"<<endl;
                        ciclo=1;
                        break;
            }
            }while(ciclo==1);
}

void agregar_notas(int x){
    int ciclo;
    do{
        ciclo = 0;
        cout<<"Quieres anadir notas al estudiante?(1 para si, 0 para no)\n>> ";
        int eleccion;
        cin>> eleccion;
        switch(eleccion){
            case 0:
                datos_est[x].math = "0";
                datos_est[x].sociales = "0";
                datos_est[x].biologia = "0";
                datos_est[x].EF = "0";
                datos_est[x].artes = "0";
                break;
            case 1:
                cout<<"Indica la nota de Matematicas\n>> ";
                cin>> datos_est[x].math;
                cout<<"Indica la nota de Sociales\n>> ";
                cin>> datos_est[x].sociales;
                cout<<"Indica la nota de Biologia\n>> ";
                cin>> datos_est[x].biologia;
                cout<<"Indica la nota de Educacion Fisica\n>> ";
                cin>> datos_est[x].EF;
                cout<<"Indica la nota de Artes\n>> ";
                cin>> datos_est[x].artes;
                break;
            default:
                cout<<"Elige bien"<<endl;
                ciclo=1;
                break;
        }
    }while(ciclo == 1);
}

void agregar(int x){
    datos_est[x].id= to_string(estudiantes+1);
    cout<<"Indica el nombre y el apellido del estudiante\n>> ";
    cin>> datos_est[x].nombre>> datos_est[x].apellido;
    cout<<"Indica el genero del estudiante\n>> ";
    seleccion_genero(x);
    cout<<"Indica el email del estudiante\n>> ";
    cin>> datos_est[x].email;
    int ciclo;
    do{
        ciclo = 0;
        cout<<"Indica la seccion del estudiante (de la A a la F)\n>> ";
        cin>> datos_est[x].seccion;
    if(datos_est[x].seccion !="A" && datos_est[x].seccion !="B" && datos_est[x].seccion !="C"&& datos_est[x].seccion !="D" && datos_est[x].seccion !="E" && datos_est[x].seccion !="F"){
            cout<< "Elige bien la seccion"<<endl;
            ciclo = 1;
        }
    }while(ciclo==1);
    agregar_notas(x);
}