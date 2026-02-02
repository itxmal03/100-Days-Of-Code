void main() {
  List<int> list = [2, 3, 4, 4, 6];
  int target = 10;
  // checkSorted(array);
  // checkIncreasing(array);
  checkTargetSum(list, target);
}

// check whether array is sorted in ascending order
void checkSorted(List<int> arr) {
  bool isSorted = true;
  for (int i = 0; i < arr.length - 1; i++) {
    if (!(arr[i] <= arr[i + 1])) {
      isSorted = false;
      break;
    }
  }

  if (isSorted) {
    print("Yes, array is sorted in ascending order!");
  } else {
    print("No, array is not sorted in ascending order!");
  }
}

// check whether array is strictly increasing
void checkIncreasing(List<int> arr) {
  bool isIncreasing = true;

  for (int i = 0; i < arr.length - 1; i++) {
    if (arr[i + 1] <= arr[i]) {
      isIncreasing = false;
      break;
    }
  }

  if (isIncreasing) {
    print("Yes, array is strictly increasing");
  } else {
    print("No, array is not strictly increasing");
  }
}

// check whether a pair exists whose sum is equal to target
void checkTargetSum(List<int> arr, int target) {
  bool exists = false;
  List<int> pair = [0, 0];

  for (int i = 0; i < arr.length; i++) {
    for (int j = 0; j < arr.length; j++) {
      if (i != j && (arr[i] + arr[j] == target)) {
        pair[0] = arr[i];
        pair[1] = arr[j];
        exists = true;
        break;
      }
    }
    if (exists) break; // stop outer loop if pair found
  }

  if (exists) {
    print("Yes, a pair exists whose sum is equal to $target");
    print("And the pair is: ${pair[0]} ${pair[1]}");
  } else {
    print("No pair exists!");
  }
}
