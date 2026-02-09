import 'dart:io';

void main() {
  List<List<int>> matrix = [
    [9, 3, 4, 6],
    [9, 8, 6, 9],
    [7, 2, 1, 4],
    [8, 5, 7, 0],
  ];

  // printBoundry(matrix);
  // sortEachRow(matrix);
  sortMatrix(matrix);
}

void printBoundry(List<List<int>> matrix) {
  stdout.write("\n Boundry of matrix is: \n");
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (i == 0 || i == 3 || j == 0 || j == 3) {
        stdout.write("${matrix[i][j]} ");
      } else {
        stdout.write("  ");
      }
    }
    stdout.write("\n");
  }
}

void sortMatrix(List<List<int>> matrix) {
  List<int> tempMatrix = List.filled(16, 0);
  int k = 0;

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      tempMatrix[k++] = matrix[i][j];
    }
  }

  for (int z = 1; z < 16; z++) {
    int x = z;
    while (x > 0 && tempMatrix[x] < tempMatrix[x - 1]) {
      int temp = tempMatrix[x];
      tempMatrix[x] = tempMatrix[x - 1];
      tempMatrix[x - 1] = temp;
      x--;
    }
  }

  int a = 0;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      matrix[i][j] = tempMatrix[a];
      a++;
    }
  }

  for (int u = 0; u < 4; u++) {
    for (int t = 0; t < 4; t++) {
      stdout.write("${matrix[u][t]} ");
    }
    stdout.write("\n");
  }
}

void sortEachRow(List<List<int>> matrix) {
  for (int i = 0; i < 4; i++) {
    for (int j = 1; j < 4; j++) {
      int y = j;
      while (y > 0 && matrix[i][y] < matrix[i][y - 1]) {
        int temp = matrix[i][y];
        matrix[i][y] = matrix[i][y - 1];
        matrix[i][y - 1] = temp;
        y--;
      }
    }
  }

  for (int u = 0; u < 4; u++) {
    for (int t = 0; t < 4; t++) {
      stdout.write("${matrix[u][t]} ");
    }
    stdout.write("\n");
  }
}
