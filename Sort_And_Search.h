#pragma once
#include <iostream>
#include "struct.h"

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
    return -1;
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