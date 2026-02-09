import 'dart:io';

void main() {
  // List<int> list = [8, 8, 3, 3, 8, 4, 5, 3, 8];
  // List<List<int>> matrix = [
  //   [3, 2, 1],
  //   [4, 7, 8],
  //   [2, 1, 6],
  // ];


  // dupliFinder(list);
  // palindromeCheck(010, "racecar");
  // fibonacci(10);
  // factorial(4);
  // patterns();
  // transpose(matrix);
  // rotateImage(matrix);
  // identityMatrix(matrix);
}

void dupliFinder(List<int> list) {
  for (int i = 1; i < 9; i++) {
    int x = i;
    while (x > 0 && list[x] < list[x - 1]) {
      list[x] = list[x] + list[x - 1];
      list[x - 1] = list[x] - list[x - 1];
      list[x] = list[x] - list[x - 1];
      x--;
    }
  }

  // sorted list
  print("Sorted ~");
  for (int j = 0; j < 9; j++) {
    stdout.write("${list[j]} ");
  }

  int duplicate = -1;
  for (int z = 1; z < 9; z++) {
    if (list[z] == list[z - 1]) {
      duplicate = list[z];
    }
  }
  print("\n duplicate is: $duplicate");

  int counter = 1;
  int dupli = -1;
  int mainCounter = 1;
  int secondDupli = -2;
  int secondCounter = 1;

  for (int y = 1; y < 9; y++) {
    if (list[y] == list[y - 1]) {
      counter++;
    } else {
      if (counter > mainCounter) {
        secondCounter = mainCounter;
        mainCounter = counter;
        dupli = list[y - 1];
        secondDupli = list[y - counter];
      }
      counter = 1;
    }
  }

  if (counter > mainCounter) {
    secondCounter = mainCounter;
    mainCounter = counter;
    dupli = list[8];
  }

  if (dupli != -1) {
    print("\nthe number: $dupli repeats $mainCounter times!");
  }
  if (secondDupli != -2) {
    print("Second duplicate number repeats : $secondCounter times");
  }
}

void palindromeCheck(int num, String s) {
  int originalNum = num;
  String originalString = s;
  int reversedNum = 0;
  String reversedString = "";

  int tempNum = num;
  while (tempNum > 0) {
    reversedNum = reversedNum * 10 + tempNum % 10;
    tempNum = tempNum ~/ 10; // ~/ works same as / in cpp
  }

  print("Reversed number: $reversedNum");
  if (reversedNum == originalNum) {
    print("Number is palindrome!");
  } else {
    print("Number is not palindrome!");
  }

  int strLength = s.length - 1;
  while (strLength >= 0) {
    reversedString += s[strLength];
    strLength--;
  }

  print("Reversed String is: $reversedString");
  if (reversedString == originalString) {
    print("String is palindrome!");
  } else {
    print("String is not palindrome!");
  }
}

void fibonacci(int n) {
  int start = 0;
  int second = 1;
  int next = 0;
  print("Fibonacci Series:");
  for (int i = 0; i < n; i++) {
    stdout.write("$start ");
    next = start + second;
    start = second;
    second = next;
  }
}

void factorial(int num) {
  int fac = 1;
  for (int i = num; i > 0; i--) {
    fac = fac * i;
  }
  print("Factorial of: $num is: $fac");
}

void patterns() {
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j <= i; j++) {
      stdout.write("*");
    }
    print("");
  }

  print("");
  for (int x = 0; x < 5; x++) {
    for (int y = 5; y > x; y--) {
      stdout.write("*");
    }
    print("");
  }

  print("");
  for (int x = 0; x < 5; x++) {
    for (int i = 5; i > x; i--) {
      stdout.write(" ");
    }

    for (int y = 0; y <= x; y++) {
      stdout.write("* ");
    }
    print("");
  }
}

void transpose(List<List<int>> matrix) {
  List<List<int>> transpose = List.generate(3, (_) => List.filled(3, 0));

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      transpose[i][j] = matrix[j][i];
    }
  }

  for (int x = 0; x < 3; x++) {
    for (int y = 0; y < 3; y++) {
      stdout.write("${transpose[x][y]} ");
    }
    print("");
  }
}

void rotateImage(List<List<int>> matrix) {
  List<List<int>> transpose = List.generate(3, (_) => List.filled(3, 0));

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      transpose[i][j] = matrix[j][i];
    }
  }

  for (int x = 0; x < 3; x++) {
    int start = 0, end = 2;
    while (start < end) {
      int temp = transpose[x][start];
      transpose[x][start] = transpose[x][end];
      transpose[x][end] = temp;
      start++;
      end--;
    }
  }

  print("rotated image");
  for (int x = 0; x < 3; x++) {
    for (int y = 0; y < 3; y++) {
      stdout.write("${transpose[x][y]} ");
    }
    print("");
  }
}

void identityMatrix(List<List<int>> matrix) {
  bool identity = true;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (i == j && matrix[i][j] != 1) {
        identity = false;
      }
      if (i != j && matrix[i][j] != 0) {
        identity = false;
      }
    }
  }

  if (identity) {
    print("Yes identity matrix!");
  } else {
    print("Not identity!");
  }
}
