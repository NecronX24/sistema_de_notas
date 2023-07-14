#pragma once
#include <iostream>
#include "struct.h"

int partion_Nombre(inventario arr[], int low, int high){
  inventario pivote = arr[high];
  int i = low-1;
  int j=0;
  for (j=low; j<=high-1; j++){
    if(arr[j].nombre<=pivote.nombre){
      i++;
      swap(arr[i],arr[j]);
    }
  }
  swap(arr[i+1],arr[j]);
  return (i+1);
}

int partion_Apellido(inventario arr[], int low, int high){
  inventario pivote = arr[high];
  int i = low-1;
  int j=0;
  for (j=low; j<=high-1; j++){
    if(arr[j].nombre == pivote.nombre){
        if(arr[j].apellido<=pivote.apellido){
        i++;
        swap(arr[i],arr[j]);
        }
    }
  }
  swap(arr[i+1],arr[j]);
  return (i+1);
}

void quicksort (inventario arr[], int low, int high, int eleccion){
  if (low<high){
    int pi;
    switch (eleccion){
    case 1:
      pi=partion_Nombre(arr,low,high);
      break;

    case 2:
      pi=partion_Apellido(arr,low,high);
      break;

    default:
      cout<<"Error desconocido";
      break;
    }
    quicksort(arr,low,pi-1, eleccion);
    quicksort(arr,pi+1,high, eleccion);
  }
}