void main() {
  List<int> list;
  list = [2, 4, 1, 3, 6, 8, 7, 5, 0, 9];
  sortList(list, list.length);
 // list.sort();  can also use this built in function 
  print(list);
}

void sortList(List<int> list, int size) {
  for (int i = 1; i < size; i++) {
    int x = i;
    while (x > 0 && list[x] < list[x - 1]) {
      // this will work but in case of large value in & int data type it will cause overflow during addition 
      //so better to use sort function
      int temp = list[x];
      list[x] = list[x - 1];
      list[x - 1] = temp;
      // list[x] = list[x] + list[x - 1];
      // list[x - 1] = list[x] - list[x - 1];
      // list[x] = list[x] - list[x - 1];
      x--;
    }
  }
}
