 void main() {
  List<int> array = [1, 2, 4];
  missingNumber(array);

}

void missingNumber(List<int> array) {
  // Mehtod 1 - Sort array
  // for (int i = 1; i < 4; i++)
  // {
  //     int x = i;
  //     while (x > 0 && arr[x] < arr[x - 1])
  //     {
  //         swap(arr[x], arr[x - 1]);
  //         x--;
  //     }
  // }
  // int missingNum;
  // bool miss = false;
  // for (int n = 0; n < 3; n++)
  // {
  //     if ((arr[n] + 1) != arr[n + 1])
  //     {
  //         miss = true;
  //         missingNum = arr[n] + 1;
  //     }
  // }
  // if (miss)
  //      print("Missing number is: $missingNum");
  // else
  //     print("No number is missing");

  // Method 2
  int exactSum = ((4 + 1) * (4 + 2)) ~/ 2;
  print("total sum of consective first 4 numbers!: $exactSum");
  int sum = 0;
  for (int i = 0; i < 4; i++) {
    sum += array[i];
  }
  print("Missing number is: ${exactSum - sum} ");
}
