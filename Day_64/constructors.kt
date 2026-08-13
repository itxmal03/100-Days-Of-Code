
fun main() {
    val a1 = Animal("Cow", 20) // Uses Primary Constructor
    val a2 = Animal("c2") // Uses Secondary Constructor
}

class Animal(name: String, age: Int) {
    // Primary constructor parameters
    var name: String = name
    var age: Int = age

    // Secondary Constructor - calls the primary with a default age
    constructor(name: String) : this(name, 2) {
        println("Secondary constructor body runs LAST")
    }

    init {
        println("Init 1: Age is $age")
    }
    init {
        println("Init 2: Name is $name")
    }
}

// here all the parameters will also act a data memebers , if we use var or val then there is no
// need to provide data members in class
class Animal2(var name: String, var age: Int) {}
