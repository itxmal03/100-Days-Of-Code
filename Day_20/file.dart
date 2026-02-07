void main() {
  // decimalToBinary(5);
  // binaryToDecimal(101);
  // decimalToOctal(10);
  octalToDecimal(12);
}

void decimalToBinary(int n) {
  int originalNumber = n;
  int binary = 0;
  int power = 1;

  while (n > 0) {
    int rem = n % 2;
    n = n ~/ 2; // integer division in Dart
    binary += rem * power;
    power *= 10;
  }

  print("Binary form of $originalNumber is $binary");
}

void binaryToDecimal(int n) {
  int originalNum = n;
  int decimal = 0;
  int power = 1;

  while (n > 0) {
    int rem = n % 10;
    n = n ~/ 10;
    decimal += rem * power;
    power *= 2;
  }

  print("Decimal form of $originalNum is $decimal");
}

void decimalToOctal(int n) {
  int originalNumber = n;
  int octal = 0;
  int power = 1;

  while (n > 0) {
    int rem = n % 8;
    n = n ~/ 8;
    octal += rem * power;
    power *= 10;
  }

  print("Octal form of $originalNumber is $octal");
}

void octalToDecimal(int n) {
  int originalNum = n;
  int decimal = 0;
  int power = 1;

  while (n > 0) {
    int rem = n % 10;
    n = n ~/ 10;
    decimal += rem * power;
    power *= 8;
  }

  print("Decimal form of $originalNum is $decimal");
}
