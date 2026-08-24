fun main() {

    var obj = Student(name = "Ali", grade = "A")
    var obj1 = Student(name = "Ali", grade = "A")
    var obj2 = Student(name = "Ali", grade = "A")

    println(obj.hashCode())
    println(obj1.hashCode())
    println(obj2.hashCode())

    var x = obj.component1()
    println(x)

    /*
    data_class.kt:11:23: error: destructuring declaration initializer of type Student must have a 'component3()' function
    */
  //  val (v1, v2, v3) = obj // destructuring is giving error here 
    // println(v1)
    // println(v2)
    // println(v3)
}

data class Student(val name: String, var grade: String)

/*
for data classes hashcodes of all the objects containing same data
are same .

*/
