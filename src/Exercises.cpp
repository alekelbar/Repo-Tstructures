

#include "../include/Excercises.hpp"

void bubbleSort(int vect[], int size) {

  for (size_t j = 0; j < size; j++) {

    for (size_t i = 0; i < size - j; i++) {
      if (vect[i] > vect[i + 1]) {
        int aux = vect[i];
        vect[i] = vect[i + 1];
        vect[i + 1] = aux;
      }
    }
  }
}

void bubbleSort_bidirectional(int vect[], int size) {
  int right = size - 1;
  int left = 0;

  while (left < right) {
    for (size_t i = left; i < right; i++) {
      if (vect[i] > vect[i + 1]) {
        int aux = vect[i];
        vect[i] = vect[i + 1];
        vect[i + 1] = aux;
      }
    }

    for (size_t i = right; i > left; i--) {
      if (vect[i] < vect[i - 1]) {
        int aux = vect[i];
        vect[i] = vect[i - 1];
        vect[i - 1] = aux;
      }
    }

    right--;
    left++;
  }
}

void merge(int vect[], int start, int middle, int end) {
  // Necesitamos construir indices para recorrer las listas
  // - Inidice izq para recorrer la lista izquierda
  // se inicializa con start...
  // - Indice der para recorrer la lista derecha
  // se inicializa con middle + 1...
  // - Indice k que resulta auxiliar para ordenar
  // se inicializa con 0
  int izq = start;
  int der = middle + 1;
  int k = 0;
  int aux[100];

  // mientras ningun indice haya desbordado
  while (izq <= middle && der <= end) {
    // Al estar ordenados ambos, el menor de ambas listas
    // será el menor de todos...
    if (vect[izq] < vect[der]) {
      aux[k] = vect[izq];
      izq++;
    } else {
      aux[k] = vect[der];
      der++;
    }
    k++;
  }

  // La finalización del ciclo implica que alguna de las dos listas se
  // acabo(desbordo) entonces toca crear un algoritmo para llenar la lista con
  // el resto de elementos...

  // Si fuese el caso de la izquierda...
  for (size_t idx = der; idx <= end; idx++) {
    aux[k] = vect[idx];
    k++;
  }
  // si fuese el caso de la derecha...
  for (size_t idx = izq; idx <= middle; idx++) {
    aux[k] = vect[idx];
    k++;
  }

  // Finalmente el vector auxiliar es una copia ordenada de toda la lista
  // pasada...
  for (size_t idx = 0; idx < k; idx++) {
    vect[start + idx] = aux[idx];
  }
}

void mergeSort(int vect[], int start, int end) {
  // Algoritmo de ordenamiento por mezcla...
  // 1) Ordenar la mitad izquierda...
  // 2) Ordenar la mitad derecha...
  // 3) Mezcla las dos mitades...
  // localizar el valor medio del arreglo...

  int middle = (start + end) / 2; // División entera...
  if (start < end) {              // si La lista tiene al menos dos elementos...
    mergeSort(vect, start, middle);   // ordeno la mitad izquierda
    mergeSort(vect, middle + 1, end); // ordeno la mitad derecha
    merge(vect, start, middle, end);  // ordeno toda la lista...
  }
}

// algoritmo de busqueda binaria...
int binary_search(int vect[], int start, int end, int target) {
  if (start <= end) {
    int middle = (start + end) / 2;
    if (vect[middle] == target)
      return middle; // encontrado...

    if (vect[middle] < target) {
      start = middle + 1;
    } else {
      end = middle - 1;
    }
    return binary_search(vect, start, end, target);
  }
  return -1;
}

// Representa una posición en un espacio de dos dimenciones...
struct vect2D {
  int posX;
  int posY;
  vect2D(int x, int y) : posX(x), posY(y) {}
  vect2D() {} // by default

  // Sobrecarga del operador de comparación...
  bool operator!=(const vect2D &other) const {
    return !(posX == other.posX && posY == other.posY);
  }
};

// algoritmo para desplazar a la derecha una matriz ....
void sliceMatRight(int mat[ROWS][COLUMNS]) {
  int i, j;
  // posición previa..
  vect2D prev{ROWS - 1, COLUMNS - 1}; /*Se inicializa con la ultima posición*/

  // primera posición del recorrido...
  vect2D first{ROWS - 1, COLUMNS - 1}; /*Se inicializa con la ultima posición*/

  // posición actual del recorrido
  vect2D current{0, 0}; /*Puede inicializarse en cero...*/

  // ultimo elemento de la matriz..
  int aux = mat[ROWS - 1]
               [COLUMNS - 1]; /*Corresponde al ultimo elemento de la matriz...*/

  for (i = COLUMNS - 1; i >= 0; i--) {
    for (j = ROWS - 1; j >= 0; j--) {
      current = {j, i}; // Se actualiza el elemento actual...

      if (first != current) {
        /*
         * No se accede a hacer el cambio con el elemento actual, porque solo
         * importa a parti del primero..
         * */
        mat[prev.posX][prev.posY] = mat[current.posX][current.posY];
        prev = {current.posX, current.posY}; // posición anterior recorrida...
      }
    }
  }
  mat[0][0] = aux;
}
