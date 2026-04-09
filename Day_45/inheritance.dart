void main() {}

class Person {
  String name = "";
  int id = 0;
  Person({this.name = "", this.id = 0});

  Person.setValuesConstructor({required String n, required int id}) {
    this.name = n;
    this.id = id;
  }

  void show() {
    print("Name: $name");
    print("Id: $id");
  }
}


class Student extends Person {
  String instituteName;
  Student({required this.instituteName});
}
