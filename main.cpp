#include <iostream>
#include "struct.h"
using namespace std;

void volver_a_inicio();
void inicio();
void menu_eleccion(int temp);

int main(){
    infile.open("Datos_Estudiantes_revisado.csv");
    if(!infile){
        cout<<"Error abriendo el archivo"<<endl;
        return 0;
    }
    csv_to_struct();
    infile.close();
    outfile.open("Prueba.csv");
    struct_to_csv();
    return 0;
}

void menu_eleccion(int temp){
    switch (temp)
    {
    case 1:
        //Importa si cambia el orden inicial?. Preguntar como plantea la busqueda por estudiante
        break;

    case 2:
        
        break;

    case 3:
        
        break;

    case 4:
        
        break;

    case 5:
        
        break;

    case 6:
        
        break;

    case 7:
        
        break;

    default:
        cout<<"Eleccion erronea"<<endl;
        inicio();
        break;
    }
    volver_a_inicio();
}

void volver_a_inicio(){
    cout<< "Quiere volver al menu para seleccionar otra opcion? (1 para si y 0 para no)"<<endl;
    cout<<">> ";
    int eleccion;
    cin>> eleccion;
    switch(eleccion){
        case 0:
            struct_to_csv();
            break;
        case 1:
            inicio();
            break;
        default:
            cout<<"Elige bien";
            volver_a_inicio();
            break;
    }
}

void inicio(){
    int eleccion;
    cout<< "Programa de Sistema de Notas de Estudiantes, elige tu opcion"<<endl;
    cout<< "1. Mostrar un estudiante o todos y su nota promedio"<<endl;
    cout<< "2. Mostrar materias y la cantidad de alumnos (total, raspados y aprobados)" <<endl;
    //por genero para mas puntos
    cout<< "3. Editar informacion de estudiantes" <<endl;
    cout<< "4. Agregar estudiante nuevo" <<endl;
    cout<< "5. Top 10 estudiantes por materia" <<endl;
    cout<< "6. Crear boleta" <<endl;
    cout<< "7. Reporte de ventas (100 mejores)" <<endl;
    cout<< ">> "; 
    cin>> eleccion;
    menu_eleccion(eleccion);
}