void main() {
  List<int> array = [2, 2, 3, 2, 1, 2, 3, 3, 3, 3, 4];
  List<int> array2 = [2, 2, 3, 3, 3];

  maxRepeatingNum(array);
  majorityElementBruteForce(array);
  majorityElementBruteForce2(array2);
  majorityElementOptimizedBruteForce(array2);
  majorityElementOptimizedBruteForce2(array2);
}

//  Find maximum repeating element (not necessarily majority)
void maxRepeatingNum(List<int> arr) {
  int mainCounter = 0;
  int element = arr[0];

  for (int i = 0; i < arr.length; i++) {
    int counter = 1;

    for (int j = 0; j < arr.length; j++) {
      if (arr[i] == arr[j] && i != j) {
        counter++;
      }
    }

    if (counter > mainCounter) {
      mainCounter = counter;
      element = arr[i];
    }
  }

  print("Element is: $element and number of repetition is: $mainCounter");
}

//  Brute force majority check
void majorityElementBruteForce(List<int> arr) {
  int mainCounter = 0;
  int element = arr[0];

  for (int i = 0; i < arr.length; i++) {
    int counter = 1;

    for (int j = 0; j < arr.length; j++) {
      if (arr[i] == arr[j] && i != j) {
        counter++;
      }
    }

    if (counter > mainCounter) {
      mainCounter = counter;
      element = arr[i];
    }
  }

  if (mainCounter > arr.length ~/ 2) {
    print("Element is: $element and number of repetition is: $mainCounter");
  } else {
    print("No majority element exists!");
  }
}

//  Cleaner brute force version
void majorityElementBruteForce2(List<int> arr) {
  for (int i = 0; i < arr.length; i++) {
    int freq = 0;

    for (int j = 0; j < arr.length; j++) {
      if (arr[i] == arr[j]) {
        freq++;
      }
    }

    if (freq > arr.length ~/ 2) {
      print("Majority element is: ${arr[i]}");
      return;
    }
  }

  print("No majority element exists!");
}

//  Optimized brute force (Insertion Sort + consecutive counting)
void majorityElementOptimizedBruteForce(List<int> arr) {
  // Insertion Sort
  for (int k = 1; k < arr.length; k++) {
    int x = k;

    while (x > 0 && arr[x] < arr[x - 1]) {
      int temp = arr[x];
      arr[x] = arr[x - 1];
      arr[x - 1] = temp;
      x--;
    }
  }

  int freq = 1;

  for (int i = 1; i < arr.length; i++) {
    if (arr[i] == arr[i - 1]) {
      freq++;
    } else {
      freq = 1;
    }

    if (freq > arr.length ~/ 2) {
      print("Majority element is: ${arr[i]}");
      return;
    }
  }

  print("No majority element exists!");
}

// Optimized version (Majority guaranteed to exist)
// Sort + middle index
void majorityElementOptimizedBruteForce2(List<int> arr) {
  arr.sort();

  int majorityIndex = arr.length ~/ 2;

  print("Majority element is: ${arr[majorityIndex]}");
}