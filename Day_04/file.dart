void main() {
  List<int> list = [1, 2, 3, 4, 5, 6, 7, 8, 9, 0];
  // Uncomment to test
  // sum3Elements(list);
  // sum3SlidingElements(list);
  smallestSubArraySum(list, 7); // Here, target sum = 7
}

// Function 1: Sum of 3 consecutive elements (non-overlapping)
void sum3Elements(List<int> list) {
  int setNo = 1;
  for (int i = 0; i + 2 < list.length; i += 3) {
    int sum = list[i] + list[i + 1] + list[i + 2];
    print("Sum of set $setNo of 3 numbers is $sum");
    setNo++;
  }
}

// Function 2: Sum of 3 consecutive elements (sliding window)
void sum3SlidingElements(List<int> list) {
  int sum = 0;
  int counter = 0;
  int setNo = 1;

  for (int i = 0; i < list.length; i++) {
    sum += list[i];
    counter++;

    if (counter == 3) {
      print("Sum of set $setNo of 3 numbers is $sum");
      sum = 0;
      counter = 0;
      setNo++;
      i = i - 2; // sliding window: move back 2 steps
    }
  }
}

// Function 3: Smallest subarray with sum >= target
void smallestSubArraySum(List<int> list, int target) {
  int windowSum = 0;
  int minLength = list.length + 1; // Dart equivalent of INT_MAX
  int start = 0;

  for (int end = 0; end < list.length; end++) {
    windowSum += list[end];

    // shrink window while condition is satisfied
    while (windowSum >= target) {
      int currentLength = end - start + 1;
      if (currentLength < minLength) {
        minLength = currentLength;
      }

      windowSum -= list[start];
      start++;
    }
  }

  if (minLength == list.length + 1) {
    print("No subarray found");
  } else {
    print("Length of smallest subarray with sum >= $target: $minLength");
  }
}
