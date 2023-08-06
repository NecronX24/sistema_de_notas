#pragma once
#include "struct.h"

void seleccion_genero_profesor(int i){
    int ciclo;
    do{
    cout<<"1. Male   2. Female   3. Agender   4. Bigender   5. Genderfluid   6. Genderqueer   7. Non-binary   8. Polygender\n>> ";
            int genero;
            cin>>genero;
                ciclo=0;
                switch(genero){
                    case 1:
                        datos_profesores[i].genero="Male";
                        break;
                    
                    case 2:
                        datos_profesores[i].genero="Female";
                        break;

                    case 3:
                        datos_profesores[i].genero="Agender";
                        break;

                    case 4:
                        datos_profesores[i].genero="Bigender";
                        break;

                    case 5:
                        datos_profesores[i].genero="Genderfluid";
                        break;
                       
                    case 6:
                        datos_profesores[i].genero="Genderqueer";
                        break;
                    
                    case 7:
                        datos_profesores[i].genero="Non-binary";
                        break;
                    
                    case 8:
                        datos_profesores[i].genero="Polygender";
                        break;
                    
                    default:
                        cout<<"Elige bien"<<endl;
                        ciclo=1;
                        break;
            }
            }while(ciclo==1);
}

/*
Se toma en cuenta que:
Matematicas ID = 1001
Sociales ID = 1002
Biologia ID = 1003
Educacion Fisica ID = 1004
Artes ID = 1005
*/
void seleccion_materia_profesor(int i){
    int ciclo;
    do{
    cout<<"1. Matematicas   2. Sociales   3. Biologia   4. EF   5. Artes\n>> ";
            int clase;
            cin>>clase;
                ciclo=0;
                switch(clase){
                    case 1:
                        datos_profesores[i].id_materia="1001";
                        break;
                    
                    case 2:
                        datos_profesores[i].id_materia="1002";
                        break;

                    case 3:
                        datos_profesores[i].id_materia="1003";
                        break;

                    case 4:
                        datos_profesores[i].id_materia="1004";
                        break;

                    case 5:
                        datos_profesores[i].id_materia="1005";
                        break;
                    
                    default:
                        cout<<"Elige bien"<<endl;
                        ciclo=1;
                        break;
            }
            }while(ciclo==1);
}

void agregar_profesor(int x){
    if (profesores>=lenght_profesores){
        extender_profesores();
    }
    datos_profesores[x].id= to_string(profesores+1);
    cout<<"Indica el nombre y el apellido del profesor\n>> ";
    cin>> datos_profesores[x].nombre>> datos_profesores[x].apellido;
    cout<<"Indica el genero del profesor\n>> ";
    seleccion_genero_profesor(x);
    cout<<"Indica el email del profesor\n>> ";
    cin>> datos_profesores[x].email;
    int ciclo;
    do{
        ciclo = 0;
        cout<<"Indica la seccion del profesor\n>> ";
        cin>> datos_profesores[x].seccion;
    if(datos_profesores[x].seccion !="A" && datos_profesores[x].seccion !="B" && datos_profesores[x].seccion !="C"&& datos_profesores[x].seccion !="D" && datos_profesores[x].seccion !="E" && datos_profesores[x].seccion !="F"){
            cout<< "Elige bien la seccion"<<endl;
            ciclo = 1;
        }
    }while(ciclo==1);
    cout<< "Indica la materia del profesor: "<<endl;
    seleccion_materia_profesor(x);
    profesores++;
}

void editar_profesor(){
    cout<<"Ingrese el ID profesor a buscar\n>> ";
    int busqueda;
    cin>> busqueda;
    busqueda--;
    if(busqueda<profesores){
    cout<<left<<setw(12)<<"1.Nombre"<<left<<setw(12)<<"2.Apellido"<<left<<setw(12)<<"3.Genero"<<left<<setw(33)<<"4.Email"<<left<<setw(10)<<"5.Seccion"<<left<<setw(8)<<"6.ID_Materia"<<endl;
    cout<<left<<setw(12)<<datos_profesores[busqueda].nombre<<left<<setw(12)<<datos_profesores[busqueda].apellido<<left<<setw(12)<<datos_profesores[busqueda].genero<<left<<setw(33)<<datos_profesores[busqueda].email<<left<<setw(10)<<datos_profesores[busqueda].seccion<<left<<setw(8)<<datos_profesores[busqueda].id_materia<<endl;
    int ciclo;
    do{
        ciclo = 0;
        cout<<"Elija el numero del dato a editar\n>> ";
        int eleccion;
        cin>> eleccion;
        int ciclo_dos;
        switch(eleccion){
            case 1:
                cout<<"Elige el nuevo nombre\n>> ";
                cin>>datos_profesores[busqueda].nombre;
                break;

            case 2:
                cout<<"Elige el nuevo apellido\n>> ";
                cin>>datos_profesores[busqueda].apellido;
                break;

            case 3:
                cout<<"Elige el nuevo genero:"<<endl;
                seleccion_genero_profesor(busqueda);
                break;

            case 4:{
                cout<<"Elige el nuevo email\n>> ";
                cin>>datos_profesores[busqueda].email;
                break;
            }

            case 5:
                do{
                    ciclo_dos = 0;
                    cout<<"Elige la nueva seccion\n>> ";
                    cin>>datos_profesores[busqueda].seccion;
                    if(datos_profesores[busqueda].seccion !="A" && datos_profesores[busqueda].seccion !="B" && datos_profesores[busqueda].seccion !="C"&& datos_profesores[busqueda].seccion !="D" && datos_profesores[busqueda].seccion !="E" && datos_profesores[busqueda].seccion !="F"){
                        cout<< "Elige bien la seccion"<<endl;
                        ciclo_dos = 1;
                    }
                }while(ciclo_dos==1);
                break;

            case 6:
                cout<<"Elige la nueva materia del profesor\n>> ";
                seleccion_materia_profesor(busqueda);
                break;

            default:
                cout<<"Elige bien"<<endl;
                ciclo = 1;
                break;
        }

    }while(ciclo==1);
    }else{
            cout<<"No se encontro el profesor que buscas"<<endl;
        
    }
}

void borrar_profesor(){
    try{
        cout<<"Indique el ID del profesor que desea eliminar\n>> ";
        int id_borrar;
        cin>> id_borrar;
        id_borrar--;
        if (id_borrar>=profesores){
            bool flag;
            throw flag;
        }
        int eleccion = 0;
        do{
            cout<<"Desea borrar "<< datos_profesores[id_borrar].nombre<<" "<<datos_profesores[id_borrar].apellido<<" de ID: " << datos_profesores[id_borrar].id << "? (1 para si, 0 para no)\n>> ";
            cin>> eleccion;
            if (eleccion== 1){
                for (id_borrar; id_borrar<profesores; id_borrar++){
                    datos_profesores[id_borrar].id = to_string(id_borrar+1);
                    datos_profesores[id_borrar].nombre = datos_profesores[id_borrar+1].nombre;
                    datos_profesores[id_borrar].apellido = datos_profesores[id_borrar+1].apellido;
                    datos_profesores[id_borrar].genero = datos_profesores[id_borrar+1].genero;
                    datos_profesores[id_borrar].email = datos_profesores[id_borrar+1].email;
                    datos_profesores[id_borrar].seccion = datos_profesores[id_borrar+1].seccion;
                    datos_profesores[id_borrar].id_materia = datos_profesores[id_borrar+1].id_materia;
                }
                profesores--;
            } else if (eleccion!=0 && eleccion !=1){
                cout<<"Elige bien"<<endl;
            }
        } while (eleccion!=0 && eleccion !=1);
    }catch(bool flag){
        cout<< "El ID del profesor indicado es mayor a la cantidad de profesores que existen"<<endl;
        borrar_estudiante();
    }
}

void menu_modificar_profesor(){
    int ciclo;
    do{
        ciclo = 0;
        cout<<"Elige lo que quiere hacer:\n1. Agregar profesor\n2. Editar datos de un profesor\n3. Borrar un profesor\n>> ";
        int eleccion;
        cin>> eleccion;
        switch(eleccion){
            case 1:
                agregar_profesor(profesores);
                break;

            case 2:
                editar_profesor();
                break;

            case 3:
                borrar_profesor();
                break;

            default:
                cout<<"Elige bien"<<endl;
                ciclo= 1;
                break;

        }    
    }while(ciclo==1);
}