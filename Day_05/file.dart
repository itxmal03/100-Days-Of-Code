import 'dart:io';

void main() {
  print("Enter size: ");
  int size = int.parse(stdin.readLineSync()!);

  // create dynamic list (array)
  List<int> list = List.filled(size, 0);

  for (int i = 0; i < size; i++) {
    print("Enter number on index [$i] : ");
    list[i] = int.parse(stdin.readLineSync()!);
  }

  for (int i = 0; i < size; i++) {
    print(list[i]);
  }
}
