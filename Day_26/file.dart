import 'dart:io';
import 'dart:math';

void main() {
  List<int> list = [1, 2, 3, 4, 5];
  printSubArrays(list, 5);
  print('\n');
  maxSubArrSum(list, 5);
}

void printSubArrays(List<int> list, int size) {
  for (int start = 0; start < size; start++) {
    for (int end = start; end < size; end++) {
      for (int i = start; i <= end; i++) {
        stdout.write(list[i]);
      }
      stdout.write(' ');
    }
    print('');
  }
}

void maxSubArrSum(List<int> list, int size) {
  int maxSum = -123445567888;
  for (int start = 0; start < size; start++) {
    int currSum = 0;
    for (int end = start; end < size; end++) {
      currSum += list[end];
      maxSum = max(currSum, maxSum);
    }
  }
  print("max subarray sum is: $maxSum");
}
