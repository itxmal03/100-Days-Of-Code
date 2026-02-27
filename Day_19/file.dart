void main() {
  checkPrime(5);
}

void checkPrime(int n) {
  if (n <= 1) {
    print("not prime!");
    return;
  }

  bool isPrime = true;

  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      isPrime = false;
      break;
    }
  }

  if (isPrime) {
    print("yes prime!");
  } else {
    print("not prime!");
  }
}
