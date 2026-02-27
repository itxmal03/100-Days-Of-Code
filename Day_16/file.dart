void main() {
  List<List<int>> matrix = [
    [1, 1, 1],
    [1, 1, 1],
    [0, 0, 1],
  ];
  celebirty(matrix);
  // findCelebrity(matrix);
}

// Method 1
void celebirty(List<List<int>> matrix) {
  int size = matrix.length;
  bool celebirty = false;
  int candidate = -1;
  for (int i = 0; i < size; i++) {
    celebirty = true;
    for (int j = 0; j < size; j++) {
      if (matrix[i][j] == 1 && i != j) {
        celebirty = false;
        break;
      }
    }
    if (celebirty) {
      candidate = i;
    }
  }

  for (int x = 0; x < size; x++) {
    if (x != candidate && matrix[x][candidate] != 1) {
      celebirty = false;
    }
  }

  if (!(celebirty)) {
    print("No celebirty exists!");
  } else {
    print("Celeberty is: $candidate");
  }
}

// Method 2
void findCelebrity(List<List<int>> matrix) {
  int n = matrix.length;

  //find candidate
  int candidate = 0;
  for (int i = 1; i < n; i++) {
    if (matrix[i][candidate] != 1) {
      candidate = i;
    }
  }

  //verify candidate
  for (int j = 0; j < n; j++) {
    if (j == candidate) continue;

    if (matrix[j][candidate] != 1 || matrix[candidate][j] == 1) {
      print("No celebrity exists!");
      break;
    }
  }
  if (candidate == -1)
    print("No celebirty exists!");
  else
    print("Celebirty is: $candidate");
}
