#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

ifstream infile;
ofstream outfile;

int estudiantes=0;
string titulo;

struct datos{
string nombre, apellido, email, genero, math, sociales, biologia, fisica, EF, artes;
int id;
}datos_est[10000];

void csv_to_struct(){
    string dato;
    int get_title=0;
    int i = 0;
    while(infile){
        if(get_title==0){
            getline(infile,dato,'\n');
            titulo=dato;
            get_title=1;
        }
        i++;
        switch(i){
            case 1:
                getline(infile,dato,',');
                datos_est[estudiantes].nombre=dato;
                break;
            case 2:
                getline(infile,dato,',');
                datos_est[estudiantes].apellido=dato;
                break;
            case 3:
                getline(infile,dato,',');
                datos_est[estudiantes].email=dato;
                break;
            case 4:
                getline(infile,dato,',');
                datos_est[estudiantes].genero=dato;
                break;
            case 5:
                getline(infile,dato,',');
                datos_est[estudiantes].math=dato;
                break;
            case 6:
                getline(infile,dato,',');
                datos_est[estudiantes].sociales=dato;
                break;
            case 7:
                getline(infile,dato,',');
                datos_est[estudiantes].biologia=dato;
                break;
            case 8:
                getline(infile,dato,',');
                datos_est[estudiantes].fisica=dato;
                break;
            case 9:
                getline(infile,dato,',');
                datos_est[estudiantes].EF=dato;
                break;
            case 10:
                getline(infile,dato,'\n');
                datos_est[estudiantes].artes=dato;
                i=0;
                datos_est[estudiantes].id=estudiantes;
                estudiantes++;
                break;
        }
    }
    infile.close();
}

//Se usa ',' en ves de ';' para que el archivo resultante se encuentre como el original
void struct_to_csv(){
    int i = 0;
    outfile<<titulo<<endl;
    while(outfile){ 
        if(i<estudiantes){
            outfile<<datos_est[i].nombre<<","<<datos_est[i].apellido<<","<<datos_est[i].email<<","<<datos_est[i].genero<<","<<datos_est[i].math<<","<<datos_est[i].sociales<<","<<datos_est[i].biologia<<","<<datos_est[i].fisica<<","<<datos_est[i].EF<<","<<datos_est[i].artes<<endl;
        }
        else{
            outfile.close();
        }
        i++;
    }
}