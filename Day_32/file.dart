void main() {
  Student s1 = Student(89);
}


class Student {
  double? _marks;
  String? name;
  // non parameterized or default conrstructor automatically called on creation of object , can also be used to give default values
  // Student() {
  //   print("Default construcor called");
  // }

  Student(this._marks);

  // named paramterized constructor
  // Student.marks(double m) {
  //   _marks = m;
  // }


  void getInfo() {
    print(_marks);
  }
}
