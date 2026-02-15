void main() {
  // Declare a growable List
  List<int> v = [4, 1, 2, 1, 2];


  // Basic List Functions
  // length → number of elements
  print("Length: ${v.length}");
  // add() → add element at end
  v.add(10);
  print("After add(10): $v");

  // removeLast() → remove last element
  v.removeLast();
  print("After removeLast(): $v");

  // first → first element
  print("First element: ${v.first}");

  // last → last element
  print("Last element: ${v.last}");

  //  elementAt() → access by index
  print("Element at index 2: ${v.elementAt(2)}");

  //  contains() → check existence
  print("Contains 4? ${v.contains(4)}");

  //  indexOf() → find index
  print("Index of 2: ${v.indexOf(2)}");



  int x = singleNumber(v);
  print("Single number is: $x");

  int target = 4;
  int y = linearSearch(v, target);
  print("Target number exists at index: $y");

  reverseVector(v);
}

/*
  Memory Concept in Dart:
  - Dart Lists are objects stored in heap memory.
  - Dart uses garbage collection.
  - Memory management is automatic.
*/

/*
  How List works internally?
  - Growable List resizes automatically when needed.
  - Internally it behaves like a dynamic array.
  - When space becomes insufficient, a larger memory block is created.
  - Old elements are copied into new memory.
  - Capacity is managed internally and not directly accessible.
*/

int singleNumber(List<int> v) {
  int ans = 0;

  for (int i in v) {
    ans ^= i;
  }

  /*
    XOR properties:
    n ^ n = 0
    n ^ 0 = n

    This works only when:
    - Every element appears exactly twice
    - Except one element
  */

  return ans;
}

int linearSearch(List<int> v, int target) {
  for (int i = 0; i < v.length; i++) {
    if (v[i] == target) {
      return i;
    }
  }

  return -1; // target not found
}

void reverseVector(List<int> v) {
  int start = 0;
  int end = v.length - 1;

  while (start < end) {
    int temp = v[start];
    v[start] = v[end];
    v[end] = temp;

    start++;
    end--;
  }

  print("Reversed List:");
  for (int element in v) {
    print(element);
  }
}
