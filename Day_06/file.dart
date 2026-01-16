void main() {
  List<int> array1 = [1, 0, 2, 0, 4, 0, 9];
  List<int> array2 = [1, 8, 9, 0, 4, 0, 9];

  // -------------------------------
  // Method 1: Bubble-like approach
  // -------------------------------
  for (int i = 0; i < array1.length; i++) {
    int x = i;
    while (x < array1.length - 1) {
      if (array1[x] == 0) {
        int temp = array1[x];
        array1[x] = array1[x + 1];
        array1[x + 1] = temp;
      }
      x++;
    }
  }

  print("Method 1 Result:");
  print(array1);

  // --------------------------------
  // Method 2: Two-pointer approach
  // --------------------------------
  int n = 0;
  for (int c = 0; c < array2.length; c++) {
    if (array2[c] != 0) {
      int temp = array2[c];
      array2[c] = array2[n];
      array2[n] = temp;
      n++;
    }
  }

  print("Method 2 Result:");
  print(array2);
}
