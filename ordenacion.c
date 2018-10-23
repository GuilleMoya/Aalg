/**
 *
 * Descripcion: Implementacion de funciones de ordenacion
 *
 * Fichero: ordenacion.c
 * Autor: Carlos Aguirre
 * Version: 1.0
 * Fecha: 16-09-2017
 *
 */


#include "ordenacion.h"

/***************************************************/
/* Funcion: InsertSort    Fecha:                   */
/* Vuestro comentario                              */
/***************************************************/
int SelectSort(int* tabla, int ip, int iu){
  int i=0, min=0, contador=0;

  if(tabla==NULL)  return ERR;

  for(i=ip, contador=1; i<=iu; i++, contador++){
    min=minimo(tabla, i, iu);
    swap(&tabla[i], &tabla[min]);
    }

  return contador;

}


int minimo(int* tabla, int ip, int iu){
  int m=ip, i=0;
  for(i=ip+1; i<=iu; i++){
    if(tabla[i]<tabla[m]){
       m=i;
    }
  }
  return m;
}

int minimoInv(int* tabla, int ip, int iu){
  int m=ip, i=0;
  for(i=ip-1; i>=iu; i--){
    if(tabla[i]<tabla[m]){
       m=i;
    }
  }
  return m;
}

int SelectSortInv(int* tabla, int ip, int iu){
  int i=0, min=0, contador=0;

  if(tabla==NULL)  return ERR;

  for(i=iu, contador=1; i>=ip; i--, contador++){
    min=minimoInv(tabla, i, ip);
    swap(&tabla[i], &tabla[min]);
  }

  return contador;

}
