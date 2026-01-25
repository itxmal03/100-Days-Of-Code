void main() {
  List<List<int>> matrix = [
    [1, 2, 3],
    [3, 4, 5],
    [5, 6, 6]
  ];

  //matrix into a 1D list
  List<int> tempArray = [];
  for (var row in matrix) {
    tempArray.addAll(row);
  }

  //Insertion sort
  for (int i = 1; i < tempArray.length; i++) {
    int currentIndex = i;
    while (currentIndex > 0 && tempArray[currentIndex] < tempArray[currentIndex - 1]) {
      int temp = tempArray[currentIndex];
      tempArray[currentIndex] = tempArray[currentIndex - 1];
      tempArray[currentIndex - 1] = temp;
      currentIndex--;
    }
  }

  print('Sorted Array: ${tempArray}');

  //Remove duplicates using logical size
  int tempSize = tempArray.length;
  int d = 1;
  while (d < tempSize) {
    if (tempArray[d] == tempArray[d - 1]) {
      // Shift elements left
      for (int j = d; j < tempSize - 1; j++) {
        tempArray[j] = tempArray[j + 1];
      }
      tempSize--; // reduce logical size
      // do not increment d to check the new value at this index
    } else {
      d++;
    }
  }

  //Fill remaining positions with -1
  for (int i = tempSize; i < tempArray.length; i++) {
    tempArray[i] = -1;
  }

  print('Duplicate removed Array: ${tempArray}');

  //Map back to 3x3 matrix
  int k = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      matrix[i][j] = tempArray[k++];
    }
  }

  print('Final 3x3 Matrix after duplicates removed:');
  for (var row in matrix) {
    print(row);
  }
}
