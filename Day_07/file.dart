import 'dart:math';

void smallestSubArr(List<int> array, int target) {
  int sum = 0;
  int minLength = 1 << 30; // similar to INT_MAX
  int startIndex = 0;

  for (int currentIndex = 0; currentIndex < array.length; currentIndex++) {
    sum += array[currentIndex];

    while (sum >= target) {
      int currentLength = currentIndex - startIndex + 1;
      minLength = min(minLength, currentLength);
      sum -= array[startIndex];
      startIndex++;
    }
  }

  if (minLength == (1 << 30)) {
    print("No subarray found");
  } else {
    print(
      "The min length of subarray whose sum is equal to or greater than $target is: $minLength",
    );
  }
}

void largestSubArr(List<int> array, int target) {
  int sum = 0;
  int maxLength = 0;
  int startIndex = 0;

  for (int currentIndex = 0; currentIndex < array.length; currentIndex++) {
    sum += array[currentIndex];

    if (sum >= target) {
      int currentLength = currentIndex - startIndex + 1;
      maxLength = max(maxLength, currentLength);
    }
  }

  if (maxLength == 0) {
    print("No subarray found");
  } else {
    print(
      "The max length of subarray whose sum is equal to or greater than $target is: $maxLength",
    );
  }
}

void equalSubArr(List<int> array, int target) {
  int sum = 0;
  int maxLength = 0;
  int startIndex = 0;

  for (int currentIndex = 0; currentIndex < array.length; currentIndex++) {
    sum += array[currentIndex];

    while (sum > target) {
      sum -= array[startIndex];
      startIndex++;
    }

    if (sum == target) {
      maxLength = max(maxLength, currentIndex - startIndex + 1);
    }
  }

  if (maxLength == 0) {
    print("No subarray found");
  } else {
    print(
      "The max length of subarray whose sum is equal to $target is: $maxLength",
    );
  }
}

void main() {
  List<int> array = [1, 2, 4, 6, 9];

   smallestSubArr(array, 11);
   largestSubArr(array, 17);
  equalSubArr(array, 5);
}
