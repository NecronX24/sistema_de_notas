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
  swap(arr[i + 1], arr[high]);
  return (i + 1);
}

void quicksort(inventario arr[], int low, int high, int caso){
  if (low < high) {
    int pi;
    switch(caso){
        case 1:
            pi = partition_FirstName(arr, low, high);
            break;
        default:
            cout<<"Error desconocido";
            break;
    }
    quicksort(arr, low, pi - 1, 1);
    quicksort(arr, pi + 1, high, 1);
  }
}
