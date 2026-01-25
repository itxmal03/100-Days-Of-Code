void main() {
  String str = "AatabAli";
  unique3Char(str);
}

// first 3 unique characters in string
void unique3Char(String str) {
  String uniqueChars = "";

  for (int i = 0; i < str.length; i++) {
    bool isUnique = true;

    for (int j = 0; j < uniqueChars.length; j++) {
      if (str[i] == uniqueChars[j]) {
        isUnique = false;
        break;
      }
    }

    if (isUnique) {
      uniqueChars += str[i];
    }

    if (uniqueChars.length == 3) {
      break;
    }
  }

  print("unique 3 character: $uniqueChars");
}
