#pragma once
#include <iostream>
#include "struct.h"

//Sacar promedio
float promediar(int i){
    int math = stoi(datos_est[i].math);
    int sociales = stoi(datos_est[i].sociales);
    int biologia = stoi(datos_est[i].biologia);
    int fisica = stoi(datos_est[i].fisica);
    int EF = stoi(datos_est[i].EF);
    int artes=stoi(datos_est[i].artes);
    float suma = (math+sociales+biologia+fisica+EF+artes);
    return suma / 6;
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
    if (arr[j].id <= pivot.id) {
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

int partition_fisi(datos arr[], int low, int high) {
  datos pivot = arr[high];
  int i = low - 1;
  int j = 0;
  for (j = low; j <= high - 1; j++) {
    int num = stoi(arr[j].fisica);
    int pivote_int = stoi(pivot.fisica);
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
          pi = partition_fisi(arr, low, high);
          break;
        case 7:
          pi = partition_educ(arr, low, high);
          break;
        case 8:
          pi = partition_art(arr, low, high);
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