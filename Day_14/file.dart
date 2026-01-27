void main() {
  // swapVal(44, 55);
  // oddEven(229);
  // checkDigit("wr3t");

  List<int> arr = [2, 1, 3, 0, 5, 8, 4, 9];
  waveArray(arr);
}

// Swap values (pass by value concept still applies)
void swapVal(int a, int b) {
  print("value of first number before swap: $a");
  print("value of second number before swap: $b");

  a = (a + b) - (b = a);

  print("value of first number after swap: $a");
  print("value of second number after swap: $b");
}

// Odd / Even using bitwise operator
void oddEven(int n) {
  if ((n & 1) == 1) {
    print("number is odd!");
  } else {
    print("number is even!");
  }
}

// Check if string contains a digit
void checkDigit(String s) {
  for (int i = 0; i < s.length; i++) {
    if (isDigit(s[i])) {
      print("it contains digit");
      return;
    }
  }
}

// helper function for digit check
bool isDigit(String c) {
  return c.codeUnitAt(0) >= '0'.codeUnitAt(0) &&
      c.codeUnitAt(0) <= '9'.codeUnitAt(0);
}

//Wave Array
void waveArray(List<int> array) {
  print("Original array!");
  print(array.join(" "));


   // Method 1: Local wave fixing (NOT guaranteed for all inputs)
  // for (int i = 1; i < array.length - 1; i += 2) {
  //   if (array[i] < array[i - 1] && array[i] < array[i + 1]) {
  //     int temp = array[i];
  //     array[i] = array[i + 1];
  //     array[i + 1] = temp;
  //   }
  // }

  // Insertion sort
  for (int m = 0; m < array.length; m++) {
    int x = m;
    while (x > 0 && array[x] < array[x - 1]) {
      int temp = array[x];
      array[x] = array[x - 1];
      array[x - 1] = temp;
      x--;
    }
  }

 

  // Swap adjacent pairs for wave form
  for (int n = 0; n < array.length - 1; n += 2) {
    int temp = array[n];
    array[n] = array[n + 1];
    array[n + 1] = temp;
  }

  print("Arranged array in wave form!");
  print(array.join(" "));
}
