void main() {
  List<int> array = [1, 2, 1, 2, 4];

  int result = findUnique(array);
  print(result);
}

// XOR operator - find unique element
// Condition: all elements repeat twice except one

int findUnique(List<int> array) {
  int y = 0;

  for (int x in array) {
    y = y ^ x;
  }

  return y;
}

void unique3Char(String str) {
  for (int i = 0; i < str.length - 1; i++) {
    int x = i + 1;

    while (x < str.length && str[i] != str[x]) {
      // logic will be added later
      x++;
    }
  }
}
