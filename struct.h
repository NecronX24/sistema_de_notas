#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

ifstream infile;
ofstream outfile;

int estudiantes=0;
int profesores=0;
string titulo, titulo_profesor;

struct datos{
string id, nombre, apellido, genero, email, seccion, math, sociales, biologia, EF, artes;
};

int lenght = 1001;
datos *datos_est=new datos [1001];

void extender_datos_est(){
    datos *temp= new datos[lenght];
            for (int i=0; i<estudiantes; i++){
                temp[i]=datos_est[i];
            }
            delete[] datos_est;
            lenght = lenght * 2;
            datos_est = new datos [lenght];
            for (int i=0; i<estudiantes; i++){
                datos_est[i]=temp[i];
            }
            delete[] temp;
}

struct prof{
    string id, nombre, apellido, genero, email, seccion, id_materia;
};

int lenght_profesores = 21;
prof *datos_profesores=new prof [21];

void extender_profesores(){
    prof *temp= new prof [lenght_profesores];
            for (int i=0; i<profesores; i++){
                temp[i]=datos_profesores[i];
            }
            delete[] datos_profesores;
            lenght_profesores = lenght_profesores * 2;
            datos_profesores = new prof [lenght_profesores];
            for (int i=0; i<profesores; i++){
                datos_profesores[i]=temp[i];
            }
            delete[] temp;
}

void csv_to_struct_profesor(){
    string dato;
    int get_title=0;
    int i = 0;
    while(infile){
        if (estudiantes>=lenght){
            extender_profesores();
        }
        if(get_title==0){
            getline(infile,dato,'\n');
            titulo_profesor=dato;
            get_title=1;
        }
        i++;
        switch(i){
            case 1:
                getline(infile,dato,',');
                datos_profesores[profesores].id=dato;
                break;
            case 2:
                getline(infile,dato,',');
                datos_profesores[profesores].nombre=dato;
                break;
            case 3:
                getline(infile,dato,',');
                datos_profesores[profesores].apellido=dato;
                break;
            case 4:
                getline(infile,dato,',');
                datos_profesores[profesores].genero=dato;
                break;
            case 5:
                getline(infile,dato,',');
                datos_profesores[profesores].email=dato;
                break;
            case 6:
                getline(infile,dato,',');
                datos_profesores[profesores].seccion=dato;
                break;
            
            case 7:
                getline(infile,dato,'\n');
                datos_profesores[profesores].id_materia=dato;
                i=0;
                profesores++;
                break;
        }
    }
    infile.close();
}

void csv_to_struct(){
    string dato;
    int get_title=0;
    int i = 0;
    while(infile){
        if (estudiantes>=lenght){
            extender_datos_est();
        }
        if(get_title==0){
            getline(infile,dato,'\n');
            titulo=dato;
            get_title=1;
        }
        i++;
        switch(i){
            case 1:
                getline(infile,dato,',');
                datos_est[estudiantes].id=dato;
                break;
            case 2:
                getline(infile,dato,',');
                datos_est[estudiantes].nombre=dato;
                break;
            case 3:
                getline(infile,dato,',');
                datos_est[estudiantes].apellido=dato;
                break;
            case 4:
                getline(infile,dato,',');
                datos_est[estudiantes].genero=dato;
                break;
            case 5:
                getline(infile,dato,',');
                datos_est[estudiantes].email=dato;
                break;
            case 6:
                getline(infile,dato,',');
                datos_est[estudiantes].seccion=dato;
                break;
            case 7:
                getline(infile,dato,',');
                datos_est[estudiantes].math=dato;
                break;
            case 8:
                getline(infile,dato,',');
                datos_est[estudiantes].sociales=dato;
                break;
            case 9:
                getline(infile,dato,',');
                datos_est[estudiantes].biologia=dato;
                break;
            case 10:
                getline(infile,dato,',');
                datos_est[estudiantes].EF=dato;
                break;
            case 11:
                getline(infile,dato,'\n');
                datos_est[estudiantes].artes=dato;
                i=0;
                estudiantes++;
                break;
        }
    }
    infile.close();
}

//Se usa ',' en ves de ';' para que el archivo resultante se encuentre como el original
void struct_to_csv_profesor(){
    int i = 0;
    outfile<<titulo_profesor<<endl;
    while(outfile){ 
        if(i<profesores){
            outfile<<datos_profesores[i].id<<","<<datos_profesores[i].nombre<<","<<datos_profesores[i].apellido<<","<<datos_profesores[i].genero<<","<<datos_profesores[i].email<<","<<datos_profesores[i].seccion<<","<<datos_profesores[i].id_materia<<endl;
        }
        else{
            outfile.close();
        }
        i++;
    }
}

void struct_to_csv(){
    int i = 0;
    outfile<<titulo<<endl;
    while(outfile){ 
        if(i<estudiantes){
            outfile<<datos_est[i].id<<","<<datos_est[i].nombre<<","<<datos_est[i].apellido<<","<<datos_est[i].genero<<","<<datos_est[i].email<<","<<datos_est[i].seccion<<","<<datos_est[i].math<<","<<datos_est[i].sociales<<","<<datos_est[i].biologia<<","<<datos_est[i].EF<<","<<datos_est[i].artes<<endl;
        }
        else{
            outfile.close();
        }
        i++;
    }
}