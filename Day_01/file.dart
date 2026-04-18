import 'dart:io';

void main() {
  clearScreen();
  int direction;
  double speed1, speed2, distance, relativeSpeed;
  stdout.write("Enter speed of 1st person m/s: ");
  speed1 = double.parse(stdin.readLineSync()!);
  stdout.write("Enter speed of 2nd person m/s: ");
  speed2 = double.parse(stdin.readLineSync()!);
  stdout.write("Enter distance btw persons in meters: ");
  distance = double.parse(stdin.readLineSync()!);

  do {
    stdout.write(
      "Enter 1 if they are moving towards each other & 2 if moving apart: ",
    );
    direction = int.parse(stdin.readLineSync()!);
    if (direction != 1 && direction != 2) {
      print("invalid input");
      continue;
    }
  } while (direction != 1 && direction != 2);




  if (direction == 1) {
    relativeSpeed = speed1 + speed2;
    double time = distance / relativeSpeed;
    print("They will meet after ${time.toStringAsFixed(1)} seconds");
  } else {
    relativeSpeed = (speed1 - speed2).abs();
    if (relativeSpeed == 0) {
      print("They will never meet!");
    } else {
      double time = distance / relativeSpeed;
      print("They will meet after ${time.toStringAsFixed(1)} seconds");
    }
  }
}



// for clear screen
void clearScreen() {
  print('\x1B[2J\x1B[0;0H');
}
