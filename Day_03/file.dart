void main() {
  List<int> list = [1, 2, 4, 5, 6, 7, 19, 25, 30, 40, 41, 42, 43, 44];
  int counter;
  for (int i = 0; i < 14; i++) {
    int n = list[i];
    counter = 0;
    for (int j = 0; j < i; j++) {
      if (n - list[j] < 10) {
        counter++;
      }
    }
    if (counter < 3) {
      print("Request at $n s is allowed!");
    } else {
      print("Request at $n s is blocked!");
    }
  }
}
