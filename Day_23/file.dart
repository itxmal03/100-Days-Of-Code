int main() {
  List<int> list = [1, 2, 3, 5, 6];
  int size = list.length;
  int target = 39;
  int index = linearSearch(list, size, target);
  print(index);
  return 0;
}

int linearSearch(List<int> list, int size, int target) {
  for (int i = 0; i < size; i++) {
    if (list[i] == target) return i;  //Found
  }
  return -1; //not found
}
