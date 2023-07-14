#pragma once
#include <iostream>
#include "struct.h"

int partition_FirstName(inventario arr[], int low, int high) {
  inventario pivot = arr[high];
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

int partition_ID(inventario arr[], int low, int high) {
  inventario pivot = arr[high];
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

void quicksort(inventario arr[], int low, int high, int caso){
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
