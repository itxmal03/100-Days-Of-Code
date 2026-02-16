void main() {
  List<int> list1 = [2, 4, 5, 6];
  List<int> list2 = [1, 2, 4];
  intersection(list1, list2);
 
}

void intersection(List<int> list1, List<int> arr2) {
  for (int i = 0; i < 4; i++) {
    bool isCommon = false;
    for (int j = 0; j < 3; j++) {
      if (list1[i] == arr2[j]) {
        isCommon = true;
        break;
      }
    }
    if (!isCommon) list1[i] = 0;
  }

 // list1.sort((a, b) => b.compareTo(a));

  list1.sort();
 list1 =  list1.reversed.toList();

  for (int x = 0; x < 4; x++) {
    print(list1[x]);
  }
}
