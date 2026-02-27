void main() {
  // unsorted array example
  List<int> array = [3, 5, 2, 1, 9, 0];
  List<int> result1 = pairSumBruteForce(array, 10);
  print("Brute Force Result: $result1");

  List<int> result2 = pairSumBruteForce2(array, 10);
  print("Brute Force 2 Result: $result2");

  // Sorted array example
  List<int> sortedArray = [1, 3, 5, 7, 9];
  List<int> result3 = pairSumOptimal(sortedArray, 14);
  print("Optimal (Two Pointer) Result: $result3");
}

// Brute Force (Unsorted Array)
List<int> pairSumBruteForce(List<int> arr, int target) {
  for (int i = 0; i < arr.length; i++) {
    for (int j = i + 1; j < arr.length; j++) {
      if (arr[i] + arr[j] == target) {
        return [i, j];
      }
    }
  }
  return [-1, -1];
}

// Brute Force (Checks all pairs including duplicates)
List<int> pairSumBruteForce2(List<int> arr, int target) {
  for (int i = 0; i < arr.length; i++) {
    for (int j = 0; j < arr.length; j++) {
      if (i != j && arr[i] + arr[j] == target) {
        return [i, j];
      }
    }
  }
  return [-1, -1];
}

// 3️⃣ Optimal Two Pointer (Works only for Sorted Array)
List<int> pairSumOptimal(List<int> arr, int target) {
  int i = 0;
  int j = arr.length - 1;

  while (i < j) {
    int sum = arr[i] + arr[j];

    if (sum > target) {
      j--;
    } else if (sum < target) {
      i++;
    } else {
      return [i, j];
    }
  }

  return [-1, -1];
}
