#pragma once
#include <iostream>
#include "struct.h"

string seccion;

//Sacar promedio
float promediar(int i){
    int math = stoi(datos_est[i].math);
    int sociales = stoi(datos_est[i].sociales);
    int biologia = stoi(datos_est[i].biologia);
    int EF = stoi(datos_est[i].EF);
    int artes=stoi(datos_est[i].artes);
    float suma = (math+sociales+biologia+EF+artes);
    return suma / 5;
}

//Particiones para el Quick Sort
int partition_FirstName(datos arr[], int low, int high) {
  datos pivot = arr[high];
  int i = low - 1;
  int j = 0;
  for (j = low; j <= high - 1; j++) {
    if (arr[j].nombre < pivot.nombre) {
      i++;
      swap(arr[i], arr[j]);
    } else if (arr[j].nombre == pivot.nombre) {
      if (arr[j].apellido < pivot.apellido) {
        i++;
        swap(arr[i], arr[j]);
      }
    }
  }
  swap(arr[i + 1], arr[j]);
  return (i + 1);
}

//Ordenar para la forma inicial
int partition_ID(datos arr[], int low, int high) {
  datos pivot = arr[high];
  int i = low - 1;
  int j = 0;
  for (j = low; j <= high - 1; j++) {
    int arreglo = stoi(arr[j].id);
    int pivote = stoi(pivot.id);
    if (arreglo <= pivote) {
      i++;
      swap(arr[i], arr[j]);
    } 
  }
  swap(arr[i + 1], arr[j]);
  return (i + 1);
}

//Ordenar por notas
int partition_math(datos arr[], int low, int high) {
  datos pivot = arr[high];
  int i = low - 1;
  int j = 0;
  for (j = low; j <= high - 1; j++) {
    int num = stoi(arr[j].math);
    int pivote_int = stoi(pivot.math);
    if (num > pivote_int) {
      i++;
      swap(arr[i], arr[j]);
    } else if (num == pivote_int) {
      float promedio_a = promediar(j);
      float promedio_b = promediar(high);
      if (promedio_a > promedio_b) {
        i++;
        swap(arr[i], arr[j]);
      }
    }
  }
  swap(arr[i + 1], arr[j]);
  return (i + 1);
}

int partition_soci(datos arr[], int low, int high) {
  datos pivot = arr[high];
  int i = low - 1;
  int j = 0;
  for (j = low; j <= high - 1; j++) {
    int num = stoi(arr[j].sociales);
    int pivote_int = stoi(pivot.sociales);
    if (num > pivote_int) {
      i++;
      swap(arr[i], arr[j]);
    } else if (num == pivote_int) {
      float promedio_a = promediar(j);
      float promedio_b = promediar(high);
      if (promedio_a > promedio_b) {
        i++;
        swap(arr[i], arr[j]);
      }
    }
  }
  swap(arr[i + 1], arr[j]);
  return (i + 1);
}

int partition_bio(datos arr[], int low, int high) {
  datos pivot = arr[high];
  int i = low - 1;
  int j = 0;
  for (j = low; j <= high - 1; j++) {
    int num = stoi(arr[j].biologia);
    int pivote_int = stoi(pivot.biologia);
    if (num > pivote_int) {
      i++;
      swap(arr[i], arr[j]);
    } else if (num == pivote_int) {
      float promedio_a = promediar(j);
      float promedio_b = promediar(high);
      if (promedio_a > promedio_b) {
        i++;
        swap(arr[i], arr[j]);
      }
    }
  }
  swap(arr[i + 1], arr[j]);
  return (i + 1);
}



int partition_educ(datos arr[], int low, int high) {
  datos pivot = arr[high];
  int i = low - 1;
  int j = 0;
  for (j = low; j <= high - 1; j++) {
    int num = stoi(arr[j].EF);
    int pivote_int = stoi(pivot.EF);
    if (num > pivote_int) {
      i++;
      swap(arr[i], arr[j]);
    } else if (num == pivote_int) {
      float promedio_a = promediar(j);
      float promedio_b = promediar(high);
      if (promedio_a > promedio_b) {
        i++;
        swap(arr[i], arr[j]);
      }
    }
  }
  swap(arr[i + 1], arr[j]);
  return (i + 1);
}

int partition_art(datos arr[], int low, int high) {
  datos pivot = arr[high];
  int i = low - 1;
  int j = 0;
  for (j = low; j <= high - 1; j++) {
    int num = stoi(arr[j].artes);
    int pivote_int = stoi(pivot.artes);
    if (num > pivote_int) {
      i++;
      swap(arr[i], arr[j]);
    } else if (num == pivote_int) {
      float promedio_a = promediar(j);
      float promedio_b = promediar(high);
      if (promedio_a > promedio_b) {
        i++;
        swap(arr[i], arr[j]);
      }
    }
  }
  swap(arr[i + 1], arr[j]);
  return (i + 1);
}

int partition_prom(datos arr[], int low, int high) {
  float pivot = promediar(high);
  int i = low - 1;
  int j = 0;
  for (j = low; j <= high - 1; j++) {
    float arreglo = promediar(j);
    if (arreglo >= pivot && datos_est[j].seccion==seccion){
      i++;
      swap(arr[i], arr[j]);
    } 
  }
  swap(arr[i + 1], arr[j]);
  return (i + 1);
}

int partition_aplazados(datos arr[], int low, int high) {
  int i = low - 1;
  int j = 0;
  for (j = low; j <= high - 1; j++) {
    int arreglo_math = stoi(arr[j].math);
    int arreglo_sociales = stoi(arr[j].sociales);
    int arreglo_biologia = stoi(arr[j].biologia);
    int arreglo_EF = stoi(arr[j].EF);
    int arreglo_artes = stoi(arr[j].artes);
    if (arreglo_math <= 9 && arreglo_sociales <= 9 && arreglo_biologia <= 9 && arreglo_EF <= 9 && arreglo_artes <= 9) {
      i++;
      swap(arr[i], arr[j]);
    } 
  }
  swap(arr[i + 1], arr[j]);
  return (i + 1);
}

// Quick Sort
void quicksort(datos arr[], int low, int high, int caso){
  if (low < high) {
    int pi;
    switch(caso){
        case 1:
          pi = partition_FirstName(arr, low, high);
          break;
        case 2:
          pi = partition_ID(arr, low, high);
          break;
        case 3:
          pi = partition_math(arr, low, high);
          break;
        case 4:
          pi = partition_soci(arr, low, high);
          break;
        case 5:
          pi = partition_bio(arr, low, high);
          break;
        case 6:
          pi = partition_educ(arr, low, high);
          break;
        case 7:
          pi = partition_art(arr, low, high);
          break;
        case 8:
          pi = partition_prom(arr, low, high);
          break;
        case 9:
          pi = partition_aplazados(arr, low, high);
          break;
        default:
          cout<<"Error desconocido";
          break;
    }
    quicksort(arr, low, pi - 1, caso);
    quicksort(arr, pi + 1, high, caso);
  }
}

//Exponential Search
int binarySearch(datos arr[], int l, int r, string x, string y)
{
    if (r >= l)
    {
        int mid = l + (r - l)/2;
        if (arr[mid].nombre == x){
          if (arr[mid].apellido == y){
              return mid;
          }
          else if (arr[mid].apellido > y)
           return binarySearch(arr, l, mid-1, x, y);
        }
        if (arr[mid].nombre > x)
            return binarySearch(arr, l, mid-1, x, y);
        return binarySearch(arr, mid+1, r, x, y);
    }
    throw false;
}

int exponentialSearch(datos arr[], int n, string x, string y)
{
    if (arr[0].nombre == x)
        return 0;
 
    int i = 1;
    while (i < n && arr[i].nombre <= x)
        i = i*2;
 
    return binarySearch(arr, i/2,min(i, n-1), x, y);
}