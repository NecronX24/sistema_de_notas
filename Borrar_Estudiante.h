#pragma once
#include "struct.h"

void borrar_estudiante(){
    try{
        cout<<"Indique el ID del estudiante que desea eliminar\n>> ";
        int id_borrar;
        cin>> id_borrar;
        id_borrar--;
        if (id_borrar>=estudiantes){
            bool flag;
            throw flag;
        }
        int eleccion = 0;
        do{
            cout<<"Desea borrar a "<< datos_est[id_borrar].nombre<<" "<<datos_est[id_borrar].apellido<<" de ID: " << datos_est[id_borrar].id << "? (1 para si, 0 para no)\n>> ";
            cin>> eleccion;
            if (eleccion== 1){
                for (id_borrar; id_borrar<estudiantes; id_borrar++){
                    datos_est[id_borrar].id = to_string(id_borrar+1);
                    datos_est[id_borrar].nombre = datos_est[id_borrar+1].nombre;
                    datos_est[id_borrar].apellido = datos_est[id_borrar+1].apellido;
                    datos_est[id_borrar].genero = datos_est[id_borrar+1].genero;
                    datos_est[id_borrar].email = datos_est[id_borrar+1].email;
                    datos_est[id_borrar].seccion = datos_est[id_borrar+1].seccion;
                    datos_est[id_borrar].math = datos_est[id_borrar+1].math;
                    datos_est[id_borrar].sociales = datos_est[id_borrar+1].sociales;
                    datos_est[id_borrar].biologia = datos_est[id_borrar+1].biologia;
                    datos_est[id_borrar].EF = datos_est[id_borrar+1].EF;
                    datos_est[id_borrar].artes = datos_est[id_borrar+1].artes;
                }
                estudiantes--;
            } else if (eleccion!=0 && eleccion !=1){
                cout<<"Elige bien"<<endl;
            }
        } while (eleccion!=0 && eleccion !=1);
    }catch(bool flag){
        cout<< "El ID del estudiante indicado es mayor a la cantidad de estudiantes que existen"<<endl;
        borrar_estudiante();
    }
}