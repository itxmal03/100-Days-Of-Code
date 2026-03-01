void main() {
  List<int> list = [1, 4, 3, 4, 4];
  print(majorityElement(list));

  List<int> list2 = [1, 2, 3, 4, 5];
  print(majorityElement2(list2));
}

int majorityElement(List<int> arr) {
  int freq = 0;
  int ans = 0;

  for (int i = 0; i < arr.length; i++) {
    if (freq == 0) {
      ans = arr[i];
    }

    if (ans == arr[i]) {
      freq++;
    } else {
      freq--;
    }
  }

  return ans;
}

int majorityElement2(List<int> arr) {
  int freq = 0;
  int ans = 0;

  for (int i = 0; i < arr.length; i++) {
    if (freq == 0) {
      ans = arr[i];
    }

    if (ans == arr[i]) {
      freq++;
    } else {
      freq--;
    }
  }

  int count = 0;

  for (int i = 0; i < arr.length; i++) {
    if (arr[i] == ans) {
      count++;
    }
  }

  if (count > arr.length ~/ 2) {
    return ans;
  } else {
    return -1;
  }
}