#include "../include/Excercises.hpp"

using namespace std;
const int TAM = 7;
int vect[TAM] = {1, 2, 3, 6, 4, 9, 0};
int vect2[TAM] = {6, 5, 4, 3, 2, 1, 0};

void showMat(int mat[ROWS][COLUMNS]) {
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLUMNS; j++) {
      cout << mat[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

int main(int argc, char const *argv[]) {
  int mat[ROWS][COLUMNS] = {{2, 3, 1}, {6, 1, 2}, {9, 8, 3}};
  showMat(mat);
  sliceMatRight(mat);
  showMat(mat);
  return 0;
}
