/**
 *
 * Descripcion: Implementacion de funciones de generacion de permutaciones
 *
 * Fichero: permutaciones.c
 * Autor:
 * Version: 1.0
 * Fecha: 21-09-2017
 *
 */


#include "permutaciones.h"

void swap(int* i_prim, int* i_seg)
{
  int aux=0;



  aux = (*i_prim);

  (*i_prim) = (*i_seg);

  (*i_seg) = aux;

}
/***************************************************/
/* Funcion: aleat_num Fecha: 21/09/2018            */
/* Autores:                                        */
/*                                                 */
/* Rutina que genera un numero aleatorio           */
/* entre dos numeros dados                         */
/*                                                 */
/* Entrada:                                        */
/* int inf: limite inferior                        */
/* int sup: limite superior                        */
/* Salida: número aleatorio                        */
/* int: numero aleatorio                           */
/***************************************************/
int aleat_num (int inf, int sup)
{
  /*if(inf<0) return -1;*/
  int tam = sup-inf+1;
  double cte = (RAND_MAX)/tam;
  int numero = rand()/cte+inf;

  return numero;
}

/***************************************************/
/* Funcion: genera_perm Fecha: 28/09/2018          */
/* Autores:                                        */
/*                                                 */
/* Rutina que genera una permutacion               */
/* aleatoria                                       */
/*                                                 */
/* Entrada: número entero                          */
/* int n: Numero de elementos de la                */
/* permutacion                                     */
/* Salida:                                         */
/* int *: puntero a un array de enteros            */
/* que contiene a la permutacion                   */
/* o NULL en caso de error                         */
/***************************************************/


int* genera_perm(int N)
{
  int i=0;
  int *perm = NULL;

  perm = (int*)malloc(N*sizeof(int));
  if(!perm)
  {
    return NULL;
  }

  for(i=0; i<N; i++)
  {
    perm[i] = i+1;
  }
  for(i=0; i<N; i++)
  {
    swap(&perm[i], &perm[aleat_num(i, N-1)]);
  }


  return perm;
}


/***************************************************/
/* Funcion: genera_permutaciones Fecha:            */
/* Autores:                                        */
/*                                                 */
/* Funcion que genera n_perms permutaciones        */
/* aleatorias de tamanio elementos                 */
/*                                                 */
/* Entrada:                                        */
/* int n_perms: Numero de permutaciones            */
/* int N: Numero de elementos de cada              */
/* permutacion                                     */
/* Salida:                                         */
/* int**: Array de punteros a enteros              */
/* que apuntan a cada una de las                   */
/* permutaciones                                   */
/* NULL en caso de error                           */
/***************************************************/
int** genera_permutaciones(int n_perms, int N){

  int j=0, i=0;
  int **perm=NULL;
  perm = (int**)malloc(N*sizeof(int*));

	for (i=0;i<N;i++)
		perm[i] = (int*)malloc(sizeof(int));

  if(!perm)
  {
    return NULL;
  }

  for(j=0;j<n_perms;j++){
    perm[j]=genera_perm(N);
  }

  return perm;

}
