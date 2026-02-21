import 'dart:math';

void main() {
  List<int> array = [1, -2, 4, 5, 6, -9];
  print("Max sum is: ${kadanesAlgorithm(array)}");
}

int kadanesAlgorithm(List<int> array) {
  if (array.isEmpty) return 0;
  int maxSum = array[0];
  int currentSum = 0;

  for (int i = 0; i < array.length; i++) {
    currentSum += array[i];
    maxSum = max(maxSum, currentSum);

    if (currentSum < 0) {
      currentSum = 0;
    }
  }

  return maxSum;
}
