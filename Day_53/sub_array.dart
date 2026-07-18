import 'dart:io';

void printSubArray() {
  List<int> list = [1, 2, 3, 4, 5];

  for (int start = 0; start < list.length; start++) {
    for (int end = start; end < list.length; end++) {
      for (int i = start; i <= end; i++) {
        stdout.write(list[i]);
      }
      stdout.write(" ");
    }
    print('');
  }
}

void main() {
  printSubArray();
}
