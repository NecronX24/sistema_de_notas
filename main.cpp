#include <iostream>
#include "struct.h"
#include "Sort_And_Search.h"
#include "Mostrar_Estudiante.h"
#include "Materias_con_Cantidad_Alumnos.h"
#include "Editar_Informacion_Estudiante.h"
#include "Promedio_Notas_Materia.h"
#include "Top_estudiantes.h"
#include "Boleta.h"
#include "Borrar_Estudiante.h"
#include "Estudiantes_Aplazados.h"
#include "Modificar_Datos_Profesor.h"
using namespace std;

void inicio();

int main(){
    infile.open("datos_estudiantes.csv");
    if(!infile){
        cout<<"Error abriendo el archivo"<<endl;
        return 0;
    }
    csv_to_struct();

    infile.open("datos_profesores.csv");
    if(!infile){
        cout<<"Error abriendo el archivo"<<endl;
        return 0;
    }
    csv_to_struct_profesor();

    inicio();

    outfile.open("Prueba.csv");
    struct_to_csv();

    outfile.open("Prueba_profesor.csv");
    struct_to_csv_profesor();
    return 0;
}

void inicio(){
     int ciclo;
    do{
        ciclo=0;
        int ciclo_dos;
        do{
            ciclo_dos=0;
            int eleccion;
            cout<< "Programa de Sistema de Notas de Estudiantes, elige tu opcion:"<<endl;
            cout<< " 1. Mostrar un estudiante o todos y su nota promedio"<<endl;
            cout<< " 2. Mostrar materias y la cantidad de alumnos (total, raspados y aprobados)" <<endl;
            cout<< " 3. Editar informacion de estudiantes" <<endl;
            cout<< " 4. Agregar estudiante nuevo" <<endl;
            cout<< " 5. Promedio de notas por materia" <<endl;
            cout<< " 6. Top 10 estudiantes por materia" <<endl;
            cout<< " 7. Crear boleta" <<endl;
            cout<< " 8. Borrar estudiante" <<endl;
            cout<< " 9. Mostrar estudiante/s con mayor cantidad de materias aplazadas" <<endl;
            cout<< "10. Agregar, editar o borrar profesor" <<endl;
            cout<< ">> "; 
            cin>> eleccion;
            switch (eleccion){
            case 1:
                menu_mostrar_Estudiante();
                break;

            case 2:
                Materias_y_Alumnos();
                break;

            case 3:
                editar();
                break;

            case 4:
                if (estudiantes>=lenght){
                    extender_datos_est();
                }
                agregar(estudiantes);
                estudiantes++;
                break;

            case 5:
                promedio_notas();
                break;

            case 6:
                top();
                break;

            case 7:
                hacer_boleta();
                break;

            case 8:
                borrar_estudiante();
                break;

            case 9:
                mostrar_estudiantes_aplazados();
                break;

            case 10:
                menu_modificar_profesor();
                break;

            default:
                cout<<"Eleccion erronea"<<endl;
                ciclo_dos=1;
                break;
            }
        }while(ciclo_dos==1);
        do{
            cout<< "Quiere volver al menu para seleccionar otra opcion? (1 para si y 0 para no)"<<endl;
            cout<<">> ";
            int eleccion;
            cin>> eleccion;
            ciclo_dos=0;
            switch(eleccion){
                case 0:
                    struct_to_csv();
                    break;
                case 1:
                    ciclo=1;
                    break;
                default:
                    cout<<"Elige bien"<<endl;
                    ciclo_dos =1;
                    break;
            }
        }while (ciclo_dos==1);
    }while(ciclo == 1);
}