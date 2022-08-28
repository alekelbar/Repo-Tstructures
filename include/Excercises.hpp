

#ifndef __EXERCISES_H__
#define __EXERCISES_H__
#include <iostream>
using namespace std;
// ordenamiento de burbuja común...

void bubbleSort(int vect[], int size);

// ordenamiento de burbuja bidirecciónal
void bubbleSort_bidirectional(int vect[], int size);

// Ordenamiento por metodo de merge
void mergeSort(int vect[], int start, int end);

// Mezcla
void merge(int vect, int start, int middle, int end);

// algoritmo de busqueda binaria
int binary_search(int vect[], int start, int end, int target);

// algoritmo para dezplazar una matriz a la derecha...
const int COLUMNS = 3;
const int ROWS = 3;
void sliceMatRight(int mat[ROWS][COLUMNS]);
#endif // __EXERCISES_H__