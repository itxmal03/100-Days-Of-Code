import 'dart:io';

void main() {
  List<int> array = [1, 2, 3, 5];
  int size = array.length;

  missingNumber(array, size);

  List<int> vec = [9, 9, 9, 0];

  print("\nVector before adding one:");
  for (int x in vec) {
    stdout.write("$x");
  }

  addOne(vec);

  print("\nVector after adding one:");
  for (int x in vec) {
    stdout.write("$x ");
  }
  print("");
}

void missingNumber(List<int> arr, int size) {
  // formula assumes numbers from 1 to (size + 1)
  int exactSum = ((size + 1) * (size + 2)) ~/ 2;
  print("\nTotal sum of consecutive ${size + 1} numbers: $exactSum");

  int sum = 0;
  for (int i = 0; i < size; i++) {
    sum += arr[i];
  }

  int missing = exactSum - sum;
  print("Missing number is: $missing");
}

void addOne(List<int> v) {
  // move from last digit to first
  for (int i = v.length - 1; i >= 0; i--) {
    if (v[i] == 9) {
      v[i] = 0; // carry continues
    } else {
      v[i] = v[i] + 1; // carry stops
      return;
    }
  }

  // if all digits were 9
  v.insert(0, 1);
}
