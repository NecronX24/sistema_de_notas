#include <iostream>
#include <fstream>
#include <string>
using namespace std;

ifstream infile;
ofstream outfile;

int productos=0;
string titulo;

struct inventario{
string nombre, apellido, email, genero, math, sociales, biologia, fisica, EF, artes;
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
                getline(infile,dato,';');
                datos_est[productos].nombre=dato;
                break;
            case 2:
                getline(infile,dato,';');
                datos_est[productos].apellido=dato;
                break;
            case 3:
                getline(infile,dato,';');
                datos_est[productos].email=dato;
                break;
            case 4:
                getline(infile,dato,';');
                datos_est[productos].genero=dato;
                break;
            case 5:
                getline(infile,dato,';');
                datos_est[productos].math=dato;
                break;
            case 6:
                getline(infile,dato,';');
                datos_est[productos].sociales=dato;
                break;
            case 7:
                getline(infile,dato,';');
                datos_est[productos].biologia=dato;
                break;
            case 8:
                getline(infile,dato,';');
                datos_est[productos].fisica=dato;
                break;
            case 9:
                getline(infile,dato,';');
                datos_est[productos].EF=dato;
                break;
            case 10:
                getline(infile,dato,'\n');
                datos_est[productos].artes=dato;
                i=0;
                productos++;
                break;
        }
    }
}

void struct_to_csv(){
    int i = 0;
    outfile.open("datos_estentario.csv");
    outfile<<titulo<<endl;
    while(outfile){ 
        if(i<productos){
            outfile<<datos_est[i].nombre<<";"<<datos_est[i].apellido<<";"<<datos_est[i].email<<";"<<datos_est[i].genero<<";"<<datos_est[i].math<<";"<<datos_est[i].sociales<<";"<<datos_est[i].biologia<<";"<<datos_est[i].fisica<<";"<<datos_est[i].EF<<datos_est[i].artes<<endl;
        }
        else{
            outfile.close();
        }
        i++;
    }
}