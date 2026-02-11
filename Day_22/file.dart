void main() {
  bitwiseOperators(3, 3);
}

void bitwiseOperators(int a, int b) {
  // AND operator
  print("& of $a and $b is: ${a & b}");

  // OR operator
  print("| of $a and $b is: ${a | b}");

  // XOR operator
  print("^ of $a and $b is: ${a ^ b}");

  // Left shift
  print("<< of $a with $b is: ${a << b}");
  // Works like: a * (2^b)

  // Right shift
  print(">> of $a with $b is: ${a >> b}");
  // Works like: a ~/ (2^b)  (integer division)
}
