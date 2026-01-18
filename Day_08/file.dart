void main() {
  List<List<int>> matrix = [
    [4, 3, 6],
    [11, 1, 12],
    [0, 2, -1]
  ];

  // Sort each row
  sortEachRow(matrix);

  // Print the sorted matrix
  for (var row in matrix) {
    print(row);
  }
}

// Function to sort each row of a 2D matrix using insertion sort
void sortEachRow(List<List<int>> matrix) {
  for (int i = 0; i < matrix.length; i++) { // Step 1: select row
    for (int j = 1; j < matrix[i].length; j++) { // Step 2: start from 2nd element
      int key = matrix[i][j]; // Step 3: element to insert
      int k = j - 1;

      // Step 4: shift elements greater than key
      while (k >= 0 && matrix[i][k] > key) {
        matrix[i][k + 1] = matrix[i][k];
        k--;
      }

      // Step 5: insert element
      matrix[i][k + 1] = key;
    }
  }
}
