
void main() {
  List<int> array = [1, 8, 6, 7];
  int size = array.length;

  // checkDiff(array, size);
  // checkAlternating(array, size);
  countPeakAndValleys(array, size);
}

// check whether absolute difference of adjacent elements is 1
void checkDiff(List<int> array, int size) {
  bool isYes = true;
  for (int i = 0; i < size - 1; i++) {
    if ((array[i] - array[i + 1]).abs() != 1) {
      isYes = false;
      break;
    }
  }
  if (isYes) {
    print("Yes! absolute difference of adjacent elements is 1");
  } else {
    print("No! absolute difference of adjacent elements is not 1");
  }
}

// check whether array is alternating
void checkAlternating(List<int> array, int size) {
  bool isAlternating = true;
  for (int i = 1; i < size - 1; i++) {
    if (!((array[i] < array[i - 1] && array[i] < array[i + 1]) ||
        (array[i] > array[i - 1] && array[i] > array[i + 1]))) {
      isAlternating = false;
      break;
    }
  }
  if (isAlternating) {
    print("Yes, array is alternating");
  } else {
    print("Array is not alternating");
  }
}

// count peaks and valleys
void countPeakAndValleys(List<int> array, int size) {
  int peaks = 0, valleys = 0;
  for (int i = 1; i < size - 1; i++) {
    if (array[i] < array[i - 1] && array[i] < array[i + 1]) {
      valleys++;
    }
    if (array[i] > array[i - 1] && array[i] > array[i + 1]) {
      peaks++;
    }
  }
  print("Total peaks are: $peaks and total valleys are: $valleys");
}
