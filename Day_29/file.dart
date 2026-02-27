void main() {
  Teacher t1 = Teacher();

  // here is diff btw dart and cpp that dart provides file level privacy mean private member can be accessed inside a single file
  t1._salary = 89;
  t1.salary = 655.76;
  print(t1.salary);
}

class Teacher {
  // private member
  double? _salary;

  //public members
  String? name;
  String? dept;

  //setter method  void keyword can be used or also without it works
  void set salary(double s) {
    _salary = s;
  }

  //getter method
  double? get salary => _salary;
}
